--- libs/std/md5.c.orig	2012-12-05 14:07:07.000000000 +0900
+++ libs/std/md5.c	2012-12-05 14:07:20.000000000 +0900
@@ -16,7 +16,7 @@
 /* ************************************************************************ */
 #include <neko.h>
 #include <string.h>
-#include "sha1.h"
+#include "../common/sha1.h"
 
 /**
 	<doc>
