# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	crashme
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=kris
DISTNAME=	crashme
EXTRACT_SUFX=	.tgz

MAINTAINER=	gjc@alum.mit.edu
COMMENT=	A tool to test an operating system's robustness

# according to license.rtf, and using the most restrictive one:
LICENSE=	LGPL21

USES=		gmake
NO_WRKSUBDIR=	yes

MAKEFILE=	makefile
PLIST_FILES=	bin/crashme bin/pddet man/man1/crashme.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crashme ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pddet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/crashme.man \
		${STAGEDIR}${MANPREFIX}/man/man1/crashme.1

.include <bsd.port.mk>
