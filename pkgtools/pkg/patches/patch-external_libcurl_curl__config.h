$NetBSD$

--- external/libcurl/curl_config.h.orig	2026-03-03 19:12:54.265031291 +0000
+++ external/libcurl/curl_config.h
@@ -455,7 +455,7 @@
 /* #undef HAVE_MACH_ABSOLUTE_TIME */
 
 /* Define to 1 if you have the memrchr function or macro. */
-#define HAVE_MEMRCHR 1
+/* #undef HAVE_MEMRCHR */
 
 /* Define to 1 if you have the MSG_NOSIGNAL flag. */
 #define HAVE_MSG_NOSIGNAL 1
