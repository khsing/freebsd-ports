# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xinfocom
PORTVERSION=	1.8m
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://ftp.giga.or.at/pub/ifarchive/interpreters-infocom-zcode/old/itf/
MASTER_SITE_SUBDIR=	mph
DISTNAME=	unix8m
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An Infocom game interpreter for X11

USES=		imake
USE_XORG=	xt sm ice xext x11
WRKSRC=		${WRKDIR}/xinfocom
PLIST_FILES=	bin/xinfocom

.include <bsd.port.mk>
