/*
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "curl_client.h"
#include "debug_if.h"

void *myrealloc(void *ptr, size_t size)
{
	/* wrapper around realloc in case NULL pointers are a problem */
	if(ptr)
		return (void*) realloc(ptr, size);
	else
		return (void*) malloc(size);
}

size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)data;

	mem->memory = (char *)myrealloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory) {
		memcpy(&(mem->memory[mem->size]), ptr, realsize);
		mem->size += realsize;
		mem->memory[mem->size] = 0;
	}
	return realsize;
}

void trim_end(char *str) 
{
	static int space_bytes[256] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,     /*   0 -  15 */
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,     /*  16 -  31 */
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /*  32 -  47 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /*  48 -  63 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /*  64 -  79 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /*  80 -  95 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /*  96 - 111 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,     /* 112 - 127 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 128 - 143 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 144 - 159 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 160 - 175 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 176 - 191 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 192 - 207 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 208 - 223 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 224 - 239 */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* 240 - 255 */
	};
	int i = strlen(str) - 1;
	while (i > 0 && space_bytes[(int)(unsigned char)str[i]]) {
		str[i] = 0;
		i++;
	}
}

int curl_client(char *url, char *userpwd, char *ua, char *buffer, size_t buffersize, char *proxy_host, int proxy_port, char* hostname)
{
	CURL *curl;
	CURLcode res;

	struct MemoryStruct chunk;
	char *proxy_uri = NULL;
	size_t proxy_host_len = 0;
	chunk.memory=NULL; /* we expect realloc(NULL, size) to work */
	chunk.size = 0;    /* no data at this point */

	/*build headers*/
	curl = curl_easy_init();
	if(curl) {
		/* trim whitespace out of url */
		trim_end(url);
		/* set request parameters */
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_USERPWD, userpwd);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, ua);
		/* include headers in response */
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);
		/* follow redirects  */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
		/* set response callback */
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		/* set response stream */
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) &chunk);
		/* no progress meter please */
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1);
#ifdef CURLOPT_MUTE
		/* shut up completely */
		curl_easy_setopt(curl, CURLOPT_MUTE, 1);
#endif /* CURLOPT_MUTE */
		/*enforce valid certs */
	    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
		/* enforce matching of certname */
	    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
		/* PROXY SUPPORT */
		proxy_host_len = strlen(proxy_host);
		if (proxy_host_len>0) {
			/* 7 => max_port_size + : + NULL */
			proxy_uri = calloc(1, proxy_host_len+7);
			sprintf(proxy_uri, "%s:%d", proxy_host, proxy_port);
			curl_easy_setopt(curl, CURLOPT_PROXY, proxy_uri);
			/*curl_easy_setopt(curl, CURLOPT_PROXYUSERPWD,  "user:password");*/
		}

		/* perform request */
	    res = curl_easy_perform(curl);

		/* always cleanup */
		curl_easy_cleanup(curl);
		if (proxy_uri) {
			free(proxy_uri);
		}
		/* process result */
		if(chunk.memory) {
			memcpy(buffer, chunk.memory, buffersize);
			free(chunk.memory);
		}
	}
	if (res!=0) {
		logit(LOG_WARNING, "%s - %s", hostname, curl_easy_strerror(res));
		return 0x31;
	} 
	return 0;
}
