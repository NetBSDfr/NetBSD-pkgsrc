$NetBSD$

Fix the build on macOS.

--- zlib/zutil.h.orig	2026-07-29 02:03:00.559686541 +0000
+++ zlib/zutil.h
@@ -135,10 +135,6 @@ extern z_const char * const z_errmsg[10]
 #  ifndef Z_SOLO
 #    if defined(__MWERKS__) && __dest_os != __be_os && __dest_os != __win32_os
 #      include <unix.h> /* for fdopen */
-#    else
-#      ifndef fdopen
-#        define fdopen(fd,mode) NULL /* No fdopen() */
-#      endif
 #    endif
 #  endif
 #endif
