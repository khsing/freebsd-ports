# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	uird
PORTVERSION=	1.1
CATEGORIES=	comms
MASTER_SITES=	http://kbinstuff.googlepages.com/ \
		http://redundancy.redundancy.org/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	The Universal IR Receiver Daemon

USES=		perl5 gmake

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/uird
PORTDOCS=	Documentation

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}\ $${CFLAGS}|; /strip/d' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uird ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
