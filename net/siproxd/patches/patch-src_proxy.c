$NetBSD$

Remove the Route headers

--- src/proxy.c.orig	2019-11-09 17:42:04.000000000 +0000
+++ src/proxy.c
@@ -356,6 +356,7 @@ sts=sip_obscure_callid(ticket);
    if (is_empty_sockaddr(&ticket->next_hop) == STS_FAILURE) {
       DEBUGC(DBCLASS_PROXY, "proxy_request: pre-set next-hop: %s:%i",
              utils_inet_ntoa(ticket->next_hop.sin_addr), ticket->next_hop.sin_port);
+#if 0 /* FIXME khorben */
    /*
     * Route present?
     * If so, fetch address from topmost Route: header and remove it.
@@ -370,6 +371,7 @@ sts=sip_obscure_callid(ticket);
       }
       DEBUGC(DBCLASS_PROXY, "proxy_request: have Route header to %s:%i",
              utils_inet_ntoa(ticket->next_hop.sin_addr), ticket->next_hop.sin_port);
+#endif
    /*
     * fixed or domain outbound proxy defined ?
     */
@@ -381,6 +383,12 @@ sts=sip_obscure_callid(ticket);
     * destination from SIP URI
     */
    } else {
+      if (!osip_list_eol(&(request->routes), 0)) {
+	      while (!osip_list_eol(&(request->routes), 0)) {
+		      osip_list_remove(&(request->routes), 0);
+	      }
+      }
+
       /* get the destination from the SIP URI */
 
       /* 1) try SRV record */
