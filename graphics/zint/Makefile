# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	zint
PORTVERSION=	2.4.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Zint Barcode Generator

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USES=		cmake
USE_LDCONFIG=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build designer

DESKTOP_ENTRIES="Zint" "Barcode generator" "" "zint-qt" "" false

NO_STAGE=	yes
.include <bsd.port.mk>
