# $FreeBSD$

PORTNAME=	ksystemlog
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE system log application

USE_XZ=		yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USES=		cmake:outsource
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
