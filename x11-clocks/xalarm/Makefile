# Created by: desmo@bandwidth.org
# $FreeBSD$

PORTNAME=	xalarm
PORTVERSION=	3.06
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X based alarm clock

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
IS_INTERACTIVE=	yes

MAN1=		xalarm.1 xmemo.1 xfortune.1 xyow.1

NO_STAGE=	yes
pre-install:
	(cd ${WRKSRC} ; ${CP} XAlarm.ad XAlarm-color.ad)

.include <bsd.port.mk>
