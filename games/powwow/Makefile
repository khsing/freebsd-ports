# Created by: Juraj Lutter <otis@sk.freebsd.org>
# $FreeBSD$

PORTNAME=	powwow
PORTVERSION=	1.2.17
CATEGORIES=	games
MASTER_SITES=	http://hoopajoo.net/static/projects/ \
		ftp://ftp.wilbury.sk/pub/FreeBSD/local/distfiles/

MAINTAINER=	otis@sk.FreeBSD.org
COMMENT=	Client to play MUDs

GNU_CONFIGURE=	yes

MAN6=		powwow.6

NO_STAGE=	yes
pre-build:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/defines.h \
		${WRKSRC}/list.c ${WRKSRC}/main.c ${WRKSRC}/cmd2.c ${WRKSRC}/beam.c
	@${REINPLACE_CMD} -e 's|^DEFS = |DEFS = -DPOSIX |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/powwow-movieplay ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/powwow-muc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/catrw ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/follow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${PREFIX}/man/man6
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${DATADIR}

.include <bsd.port.mk>
