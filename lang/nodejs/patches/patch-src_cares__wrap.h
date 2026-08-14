$NetBSD$

Fix the build on macOS:

../src/cares_wrap.cc:1740:3: error: no matching function for call to 'ares_gethostbyaddr'

--- src/cares_wrap.h.orig	2026-08-14 19:48:30.469391717 +0000
+++ src/cares_wrap.h
@@ -352,7 +352,7 @@ class QueryWrap final : public AsyncWrap
       void* arg,
       int status,
       int timeouts,
-      struct hostent* host) {
+      const struct hostent* host) {
     QueryWrap<Traits>* wrap = FromCallbackPointer(arg);
     if (wrap == nullptr) return;
 
