# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	kcachegrind
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Profiler frontend for KDE

USE_XZ=		yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USES=		cmake:outsource
USE_QT4=	moc_build qmake_build rcc_build uic_build \
		corelib dbus gui

OPTIONS_DEFINE=	DOT VALGRIND

DOT_DESC=		Use GraphViz/dot to render call graphs
DOT_RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

VALGRIND_DESC=		Install devel/valgrind
VALGRIND_RUN_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind

.include <bsd.port.mk>
