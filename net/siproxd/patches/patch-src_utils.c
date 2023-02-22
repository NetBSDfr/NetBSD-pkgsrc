$NetBSD$

Use the last match from getifaddrs()

--- src/utils.c.orig	2020-07-07 22:05:48.000000000 +0000
+++ src/utils.c
@@ -499,7 +499,9 @@ int get_ip_by_ifname(char *ifname, struc
          ifflags=ifa->ifa_flags;
          DEBUGC(DBCLASS_BABBLE,"getifaddrs - MATCH, sin_addr=%s",
                 utils_inet_ntoa(ifaddr));
+#if 0
          break;
+#endif
       }
    }
    freeifaddrs(ifa_list);
