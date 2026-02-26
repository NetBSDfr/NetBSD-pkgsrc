$NetBSD$

Fix starting Salt on NetBSD and OpenBSD.

--- salt/grains/core.py.orig	2026-02-26 16:13:28.607968513 +0000
+++ salt/grains/core.py
@@ -2783,7 +2783,7 @@ def os_data():
             grains["osrelease"] = grains["kernelrelease"].split("-")[0]
         grains.update(_bsd_cpudata(grains))
     elif grains["kernel"] in ("OpenBSD", "NetBSD"):
-        grains["os_family"] = grains["os"] = grains["kernel"]
+        grains["os_family"] = grains["osfullname"] = grains["os"] = grains["kernel"]
         grains.update(_bsd_cpudata(grains))
         grains["osrelease"] = grains["kernelrelease"].split("-")[0]
         if grains["kernel"] == "NetBSD":
