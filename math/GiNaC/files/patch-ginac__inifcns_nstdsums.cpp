--- ginac/inifcns_nstdsums.cpp.orig	2011-05-10 15:22:53.000000000 -0500
+++ ginac/inifcns_nstdsums.cpp	2014-01-12 19:46:05.000000000 -0600
@@ -2601,7 +2601,7 @@
 		ex addzeta = convert_H_to_zeta(newparameter);
 		return e.subs(h == (addzeta-H(newparameter, h.op(1)).hold())).expand();
 	} else {
-		return e * (-H(lst(0),1/arg).hold());
+		return e * (-H(lst(ex(0)),1/arg).hold());
 	}
 }
 
@@ -2632,7 +2632,7 @@
 		newparameter.prepend(1);
 		return e.subs(h == H(newparameter, h.op(1)).hold());
 	} else {
-		return e * H(lst(1),1-arg).hold();
+		return e * H(lst(ex(1)),1-arg).hold();
 	}
 }
 
@@ -2664,8 +2664,8 @@
 		ex addzeta = convert_H_to_zeta(newparameter);
 		return e.subs(h == (addzeta-H(newparameter, h.op(1)).hold())).expand();
 	} else {
-		ex addzeta = convert_H_to_zeta(lst(-1));
-		return (e * (addzeta - H(lst(-1),1/arg).hold())).expand();
+		ex addzeta = convert_H_to_zeta(lst(ex(-1)));
+		return (e * (addzeta - H(lst(ex(-1)),1/arg).hold())).expand();
 	}
 }
 
@@ -2696,7 +2696,7 @@
 		newparameter.prepend(-1);
 		return e.subs(h == H(newparameter, h.op(1)).hold()).expand();
 	} else {
-		return (e * H(lst(-1),(1-arg)/(1+arg)).hold()).expand();
+		return (e * H(lst(ex(-1)),(1-arg)/(1+arg)).hold()).expand();
 	}
 }
 
@@ -2727,7 +2727,7 @@
 		newparameter.prepend(1);
 		return e.subs(h == H(newparameter, h.op(1)).hold()).expand();
 	} else {
-		return (e * H(lst(1),(1-arg)/(1+arg)).hold()).expand();
+		return (e * H(lst(ex(1)),(1-arg)/(1+arg)).hold()).expand();
 	}
 }
 
@@ -2806,7 +2806,7 @@
 					// leading one
 					map_trafo_H_1mx recursion;
 					map_trafo_H_mult unify;
-					ex res = H(lst(1), arg).hold() * H(newparameter, arg).hold();
+					ex res = H(lst(ex(1)), arg).hold() * H(newparameter, arg).hold();
 					std::size_t firstzero = 0;
 					while (parameter.op(firstzero) == 1) {
 						firstzero++;
@@ -2870,7 +2870,7 @@
 					}
 					if (allthesame) {
 						map_trafo_H_mult unify;
-						return unify((pow(H(lst(-1),1/arg).hold() - H(lst(0),1/arg).hold(), parameter.nops())
+						return unify((pow(H(lst(ex(-1)),1/arg).hold() - H(lst(ex(0)),1/arg).hold(), parameter.nops())
 						       / factorial(parameter.nops())).expand());
 					}
 				} else {
@@ -2882,7 +2882,7 @@
 					}
 					if (allthesame) {
 						map_trafo_H_mult unify;
-						return unify((pow(H(lst(1),1/arg).hold() + H(lst(0),1/arg).hold() + H_polesign, parameter.nops())
+						return unify((pow(H(lst(ex(1)),1/arg).hold() + H(lst(ex(0)),1/arg).hold() + H_polesign, parameter.nops())
 						       / factorial(parameter.nops())).expand());
 					}
 				}
@@ -2925,7 +2925,7 @@
 					// leading one
 					map_trafo_H_1overx recursion;
 					map_trafo_H_mult unify;
-					ex res = H(lst(1), arg).hold() * H(newparameter, arg).hold();
+					ex res = H(lst(ex(1)), arg).hold() * H(newparameter, arg).hold();
 					std::size_t firstzero = 0;
 					while (parameter.op(firstzero) == 1) {
 						firstzero++;
@@ -2981,7 +2981,7 @@
 					}
 					if (allthesame) {
 						map_trafo_H_mult unify;
-						return unify((pow(-H(lst(1),(1-arg)/(1+arg)).hold() - H(lst(-1),(1-arg)/(1+arg)).hold(), parameter.nops())
+						return unify((pow(-H(lst(ex(1)),(1-arg)/(1+arg)).hold() - H(lst(ex(-1)),(1-arg)/(1+arg)).hold(), parameter.nops())
 						       / factorial(parameter.nops())).expand());
 					}
 				} else if (parameter.op(0) == -1) {
@@ -2993,7 +2993,7 @@
 					}
 					if (allthesame) {
 						map_trafo_H_mult unify;
-						return unify((pow(log(2) - H(lst(-1),(1-arg)/(1+arg)).hold(), parameter.nops())
+						return unify((pow(log(2) - H(lst(ex(-1)),(1-arg)/(1+arg)).hold(), parameter.nops())
 						       / factorial(parameter.nops())).expand());
 					}
 				} else {
@@ -3005,7 +3005,7 @@
 					}
 					if (allthesame) {
 						map_trafo_H_mult unify;
-						return unify((pow(-log(2) - H(lst(0),(1-arg)/(1+arg)).hold() + H(lst(-1),(1-arg)/(1+arg)).hold(), parameter.nops())
+						return unify((pow(-log(2) - H(lst(ex(0)),(1-arg)/(1+arg)).hold() + H(lst(ex(-1)),(1-arg)/(1+arg)).hold(), parameter.nops())
 						       / factorial(parameter.nops())).expand());
 					}
 				}
@@ -3048,7 +3048,7 @@
 					// leading one
 					map_trafo_H_1mxt1px recursion;
 					map_trafo_H_mult unify;
-					ex res = H(lst(1), arg).hold() * H(newparameter, arg).hold();
+					ex res = H(lst(ex(1)), arg).hold() * H(newparameter, arg).hold();
 					std::size_t firstzero = 0;
 					while (parameter.op(firstzero) == 1) {
 						firstzero++;
