# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpegthumbs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kdemultimedia-
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FFmpeg-based thumbnail generator for video files

LICENSE=	GPLv2

LIB_DEPENDS=	swscale:${PORTSDIR}/multimedia/ffmpeg

USES=		cmake:outsource pkgconfig
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

.include <bsd.port.mk>
