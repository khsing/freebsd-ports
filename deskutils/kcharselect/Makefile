# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kcharselect
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Character selector for KDE

USE_XZ=		yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs
USES=		cmake:outsource
USE_QT4=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
