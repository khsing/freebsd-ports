# $FreeBSD$

PORTNAME=	gwenview
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and browser for KDE 4

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexiv2.so:${PORTSDIR}/graphics/exiv2

USE_KDE4=	kactivities kdehier kdelibs kdeprefix libkipi libkonq \
		automoc4 soprano
USES=		cmake:outsource
USE_QT4=	corelib gui opengl qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
