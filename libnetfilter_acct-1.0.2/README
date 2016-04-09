= nfacct: the extended accounting infrastructure for Netfilter =

Netfilter provides three accounting mechanisms:

* flow-based accounting through ctnetlink
* packet-based accounting through NFLOG
* extended accounting through nfacct (since Linux 3.3)

The libnetfilter_acct library provides the programming interface (API)
for the extended accounting infrastructure.

== Flow-based accounting through ctnetlink ==

This mechanism allows you to account the number of packets and bytes
of one given flow. This information is obtained via netlink event once
the flow is closed with:

 # conntrack -E

You can get real-time accounting packets and bytes per flow by polling:

 # conntrack -L

== Packet-based accounting through NFLOG ==

This mechanism allows you to add specific iptables rules to log packets
that match some specific condition:

 # iptables -I INPUT -p tcp --dport 80 -j LOG --log-prefix "http: "

== nfacct: extended accounting infrastructure ==

This mechanism allows you to create one accounting object:

 libnetfilter_acct/examples# ./nfacct-add http-traffic

Then, you can use it in iptables:

 # iptables -I INPUT -p tcp --dport 80 -m nfacct --nfacct-name http-traffic
 # iptables -I OUTPUT -p tcp --sport 80 -m nfacct --nfacct-name http-traffic

You can obtain the counters via libnetfilter_acct:

 libnetfilter_acct/examples# ./nfacct-get
 http-traffic = { pkts = 000000061152,   bytes = 000082999936 };

To enable the extended accounting infrastructure in kernel-space, make sure
you enable NFNETLINK_ACCT and XT_MATCH_NFACCT config options in your Linux
kernel.

For further information, please refer to the doxygen documentation available.

== Compilation & Installation ==

First, you have to run:

 autoreconf -fi

If you got a working copy from git. Then:

 ./configure --prefix=/usr
 make
 make check # if you want to build the library examples
 sudo make install

== Licensing terms ==

This library is licensed under LGPLv2.1+.

--
(c) 2011 Pablo Neira Ayuso <pablo@netfilter.org>
(c) 2011 Intra2Net AG <http://www.intra2net.com>
