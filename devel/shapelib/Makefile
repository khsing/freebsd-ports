# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	shapelib
PORTVERSION=	1.3.0
PORTREVISION=	6
CATEGORIES=	devel geography
MASTER_SITES=	http://download.osgeo.org/shapelib/ \
		ftp://ftp.remotesensing.org/shapelib/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles

LICENSE=	LGPL20

OPTIONS_DEFINE=	DOCS PROJ
OPTIONS_SUB=	yes

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

PROJ_LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROJ}
PROJ=		-DPROJ4
.else
PROJ=		-DNO_PROJ4
.endif

.include <bsd.port.pre.mk>

# Ref: /usr/share/mk/bsd.endian.mk
.if ${ARCH} == "amd64" || ${ARCH} == "arm" || ${ARCH} == "i386" || ${ARCH} == "ia64"
ENDIAN=		-D_LITTLE_ENDIAN
.else
ENDIAN=		-D_BIG_ENDIAN	# mips*eb, powerpc, powerpc64 and sparc
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%ENDIAN%%|${ENDIAN}|g' \
		-e 's|%%PROJ%%|${PROJ}|g' \
			${WRKSRC}/Makefile ${WRKSRC}/contrib/Makefile

post-install:
	${LN} -s libshp.so.1 ${STAGEDIR}${PREFIX}/lib/libshp.so
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/web/*.html ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
