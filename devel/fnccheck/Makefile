# $FreeBSD$

PORTNAME=	fnccheck
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	FunctionCheck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Profiling library/utilities for C/C++ programs

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BROKEN=		Missing header

USE_BINUTILS=	yes
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
LIBTOOLIZE_ARGS=--force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--force-missing --add-missing --foreign
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

STRIP=		# none

INFO=		libfc

NO_STAGE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

# should be same as binutils
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-lintl
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl -lpthread|| ; \
		 s|-lbfd$$|-lbfd -liberty| ; \
		 s|-Wall -O3|-Wall|'
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|test||' ${WRKSRC}/Makefile.am

# XXX: work around an issue with automake-1.13 erroring out on a
#      non-existent m4 directory before libtoolize creates it
pre-configure::
	@${MKDIR} ${WRKSRC}/m4

.include <bsd.port.mk>
