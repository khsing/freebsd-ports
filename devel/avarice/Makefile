# Created by: Brian Dean <bsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avarice
PORTVERSION=	2.13
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Atmel AVR JTAG programmer and debugging interface for avr-gdb

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd \
		${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty

USE_BZIP2=	yes
USES=		perl5

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
