# Created by: aaron@FreeBSD.org
# $FreeBSD$

PORTNAME=	libs11n
PORTVERSION=	1.2.10
CATEGORIES=	devel
MASTER_SITES=	SF/s11n/s11n/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-nobuildfiles
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for easily serializing a wide variety of objects

USES=		uidfix
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LDCONFIG=	yes

post-extract:
	@${CP} ${PATCHDIR}/Makefile.bsd ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/io
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/nodeutil
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/proxy
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/proxy/pod
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/proxy/std

.include <bsd.port.mk>
