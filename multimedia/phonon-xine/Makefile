# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.4.4
PORTREVISION=	6
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-xine
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The xine backend for Phonon

LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_KDE4=	kdehier automoc4 kdeprefix
USE_QT4=	corelib dbus gui phonon \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	xcb

post-install:
	${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/phonon_backend
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_xine.so \
		${STAGEDIR}${QT_PLUGINDIR}/phonon_backend/libphonon_xine.so

.include <bsd.port.mk>
