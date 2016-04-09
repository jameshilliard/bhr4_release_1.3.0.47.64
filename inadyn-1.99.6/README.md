README
======

Inadyn is a simple and small dynamic DNS (DDNS) client written in C.
DDNS is a popular service for Internet users with dynamically allocated
IP addresses.

If your ISP provides you with a DHCP or PPPoE/PPPoA connection you risk
losing your IP address every time you reconnect, or in DHCP even when
the lease is renegotiated.

By using a DDNS client such as inadyn you can register an Internet name
at certain providers that the DDNS client updates, periodically and/or
on demand when your IP changes.

Inadyn can maintain multiple host names with the same IP address, and
has a web based IP detection which runs well behind a NAT router.

Common DDNS service providers supported by inadyn:

* http://www.dyndns.org
* http://freedns.afraid.org
* http://www.zoneedit.com
* http://www.no-ip.com
* http://www.easydns.com
* http://www.tzo.com
* http://www.3322.org
* http://www.dnsomatic.com
* http://www.tunnelbroker.net
* http://dns.he.net/
* http://www.dynsip.org
* http://www.sitelutions.com
* http://www.dnsexit.com
* http://www.changeip.com

Some of these services are free of charge for non-commercial use, others
take a small fee, but also provide more domains to choose from.

Multiple Accounts Support
=========================

Inadyn supports updating several DDNS servers, several accounts even on
different DDNS providers.  The following example config file illustrates
how it can be used.

Feature is courtesy of [Christian Eyrich](http://eyrich-net.org/programmiertes.html)

Example /etc/inadyn.conf:

    background
    verbose 1
    period  300
    logfile /var/log/inadyn.log
    pidfile /var/run/inadyn.pid
    
    system default@dyndns.org
      username yxxx
      password xyxx
      alias yyyy
      alias yyyy
    
    system default@no-ip.com
      username xxyx
      password xxxy
      alias yyyy

In a multi-user setup, make sure to chmod your .conf to 600 (read-write
only by you/root) to prevent other users from accessing your DDNS server
credentials.

