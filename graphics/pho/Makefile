# Created by: Roland Jesse <roland.jesse@gmx.net>
# $FreeBSD$

PORTNAME=	pho
DISTVERSION=	0.9.8
CATEGORIES=	graphics
MASTER_SITES=	http://shallowsky.com/software/pho/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight image viewer

LICENSE=	GPLv2

USES=		gmake pkgconfig
USE_GNOME=	gtk20
MAKE_ARGS=	INSTALLPREFIX="${PREFIX}"
ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|make|$$(MAKE)| ; \
		/bin/s|$$(INSTALL)|${INSTALL_PROGRAM}| ; \
		/man/s|$$(INSTALL)|${INSTALL_MAN}| ; \
		/CFLAGS/s|-g ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-Wall -g -O2 ||' ${WRKSRC}/exif/Makefile

.include <bsd.port.mk>
