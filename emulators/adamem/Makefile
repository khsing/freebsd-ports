# Created by: Jeremy Karlson
# $FreeBSD$

PORTNAME=	adamem
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/~dekogel/files/coleco/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ADAMEm is a portable Coleco ADAM and ColecoVision emulator

NO_WRKSUBDIR=	yes
USE_XORG=	sm x11 xau xext xfixes xi xrandr
ALL_TARGET=	x

PROGDIR=	${PREFIX}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${MKDIR} ${PROGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/adamem ${PROGDIR}
	${LN} -s adamem ${PROGDIR}/cvem
	${INSTALL_DATA} ${WRKSRC}/adamem.snd ${PROGDIR}
	${INSTALL_DATA} ${WRKSRC}/OS7.rom ${PROGDIR}
	${INSTALL_DATA} ${WRKSRC}/WP.rom ${PROGDIR}
	${INSTALL_DATA} ${WRKSRC}/EOS.rom ${PROGDIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/adamem.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
