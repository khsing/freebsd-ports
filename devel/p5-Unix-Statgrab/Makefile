# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	Unix-Statgrab
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Perl extension for collecting information about the machine

LIB_DEPENDS=	libstatgrab.so:${PORTSDIR}/devel/libstatgrab

USES=		perl5 pkgconfig
USE_PERL5=	configure

CONFIGURE_ARGS+=	INC="`pkg-config libstatgrab --cflags`" \
			LIBS="`pkg-config libstatgrab --libs`"

.include <bsd.port.mk>
