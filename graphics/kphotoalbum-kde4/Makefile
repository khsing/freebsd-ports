# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kphotoalbum
PORTVERSION=	4.4
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexiv2.so:${PORTSDIR}/graphics/exiv2

USE_KDE4=	kdehier kdelibs kdeprefix libkdcraw libkipi automoc4
USE_QT4=	phonon sql \
		qmake_build moc_build rcc_build uic_build
USE_BZIP2=	yes
USES=		cmake:outsource

OPTIONS_DEFINE=	MARBLE NLS
OPTIONS_DEFAULT=	MARBLE
OPTIONS_SUB=	yes # NLS

MARBLE_DESC=	Geolocation support
MARBLE_USE=	KDE4=marble
MARBLE_CMAKE_OFF=	-DWITH_Marble:BOOL=Off

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

.include <bsd.port.mk>
