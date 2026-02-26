$NetBSD$

Avoid crashes on NetBSD in the OS version check when the part after "_"
is unknown to Version(). (e.g., "STABLE" as opposed to "BETA")

--- salt/utils/network.py.orig	2026-02-26 17:20:28.241786674 +0000
+++ salt/utils/network.py
@@ -1099,7 +1099,7 @@ def netbsd_interfaces():
     address)
     """
     # NetBSD versions prior to 8.0 can still use linux_interfaces()
-    if Version(os.uname()[2]) < Version("8.0"):
+    if Version(os.uname()[2].split('_')[0]) < Version("8.0"):
         return linux_interfaces()
 
     ifconfig_path = salt.utils.path.which("ifconfig")
