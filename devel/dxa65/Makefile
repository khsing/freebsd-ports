# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	dxa
PORTVERSION=	0.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.floodgap.com/retrotech/xa/dists/
PKGNAMESUFFIX=	65

MAINTAINER=	uffe@uffe.org
COMMENT=	Disassembler for MOS 6502 and compatible CPUs

OPTIONS_DEFINE=	DOCS

USES=		gmake

PLIST_FILES=	bin/dxa65 man/man1/dxa.1.gz
PORTDOCS=	INSTALL

post-patch-script:
	@${REINPLACE_CMD} 's|CC = |CC ?= |g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|CFLAGS = |CFLAGS ?= |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dxa ${STAGEDIR}${PREFIX}/bin/dxa65
	${INSTALL_MAN} ${WRKSRC}/dxa.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
