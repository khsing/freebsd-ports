# $FreeBSD$

PORTNAME=	lskat
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USE_KDE4=	kdehier kdelibs kdeprefix libkdegames automoc4
USES=		cmake:outsource
USE_QT4=	corelib gui gui svg \
		moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
