# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drexelsnmp
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	java devel net-mgmt
MASTER_SITES=	http://gicl.cs.drexel.edu/people/sevy/snmp/
DISTNAME=	source_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java SNMP protocol implementation

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

USE_JAVA=	yes
USE_ZIP=	yes

CLASSDIR=	${PREFIX}/share/java/classes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/java/classes/snmp.jar

NO_STAGE=	yes
do-build:
	${MKDIR} ${WRKSRC}/build_library
	(cd ${WRKSRC} && ${JAVAC} -sourcepath source -d build_library source/snmp/*.java && ${JAR} cvf snmp.jar -C build_library/ .)

do-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${CLASSDIR}
	${INSTALL_DATA} ${WRKSRC}/snmp.jar ${CLASSDIR}/

.include <bsd.port.mk>
