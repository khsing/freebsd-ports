# $FreeBSD$

PORTNAME=	pkgconf
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://rabbit.dereferenced.org/~nenolod/distfiles/ \
		http://files.etoilebsd.net/pkgconf/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to help to configure compiler and linker flags

LICENSE=	ISCL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${PREFIX}/libdata/pkgconfig:/usr/libdata/pkgconfig \
		--with-system-libdir=/usr/lib \
		--with-system-includedir=/usr/include
USE_BZIP2=	yes
MAKE_ARGS=	MANDIR="${MAN1PREFIX}/man/man1"

CONFLICTS_INSTALL=	pkg-config-*

post-install:
	${LN} -sf pkgconf ${STAGEDIR}${PREFIX}/bin/pkg-config
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pkgconf

.include <bsd.port.mk>
