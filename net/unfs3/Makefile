# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unfs3
PORTVERSION=	0.9.22
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-space implementation of the NFSv3 server specification

USE_AUTOTOOLS=	autoconf
USES=		bison

PLIST_FILES=	sbin/unfsd man/man7/tags.7.gz man/man8/unfsd.8.gz

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	CLUSTER_EXT
CLUSTER_EXT_CONFIGURE_ON=	--enable-cluster

.include <bsd.port.mk>
