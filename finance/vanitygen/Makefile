# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vanitygen
PORTVERSION=	0.21
CATEGORIES=	finance
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone vanity address generator for bitcoin

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	samr7
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	20130402
PLIST_FILES=	bin/keyconv bin/vanitygen

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} \
	    	-e 's|CFLAGS=|CFLAGS=-I${LOCALBASE}/include -L${LOCALBASE}/lib |g' \
		-e 's| oclvanitygen oclvanityminer||g' \
	    	${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keyconv ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/vanitygen ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
