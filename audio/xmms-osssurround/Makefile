# Created by: Amar Takhar <verm@drunkmonk.net>
# $FreeBSD$

PORTNAME=	xmms-osssurround
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/xmms-a52dec/xmms-a52dec/1.0
DISTNAME=	xmms-a52dec-1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OSSSuround adds Surround Sound capabilities to XMMS

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-23

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_CSTD=	gnu89
CFLAGS+=	-fPIC `xmms-config --cflags`

BUILD_WRKSRC=	${WRKSRC}/OSSSurround-${PORTVERSION}

PLIST_FILES=	lib/xmms/Output/libOSSSurround.so

do-build:
	cd ${BUILD_WRKSRC} && \
	 ${CC} ${CFLAGS} -c *.c && \
	 ${CC} -shared -olibOSSSurround.so about.o audio.o configure.o convert.o init.o mixer.o OSS.o

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Output/
	${INSTALL_PROGRAM} ${WRKSRC}/OSSSurround-0.1/libOSSSurround.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Output/

.include <bsd.port.mk>
