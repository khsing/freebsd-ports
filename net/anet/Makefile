# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anet
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.codelabs.ch/download/
DISTNAME=	libanet-${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Networking library for Ada

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

USES=		ada
USE_BZIP2=	yes
ALL_TARGET=	build_lib
MAKE_ARGS+=	NUM_CPUS=${MAKE_JOBS_NUMBER} \
		LIBRARY_KIND=static

OPTIONS_DEFINE=	TEST #DOCS
TEST_DESC=	Run unit test suite before installation

.include <bsd.port.options.mk>

.if ${OPSYS} == DragonFly && ${ARCH} == i386
IGNORE=		will not build; atomics are not supported on DF i386
.endif

.if ${PORT_OPTIONS:MTEST}
BUILD_DEPENDS+=	${LOCALBASE}/lib/gnat/ahven.gpr:${PORTSDIR}/devel/ahven
ALL_TARGET+=	tests
.endif

# DOCS disabled -- asciidoc generation missing source highlights
#.if ${PORT_OPTIONS:MDOCS}
#BUILD_DEPENDS+= asciidoc:${PORTSDIR}/textproc/asciidoc
#ALL_TARGET+=	doc
#USES+=		gmake
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"lo"|"lo0"|g' \
		${WRKSRC}/tests/net_ifaces_tests.adb \
		${WRKSRC}/tests/socket_tests.adb \
		${WRKSRC}/tests/type_tests.adb
	@${REINPLACE_CMD} -e 's|dynamic|static|g' \
		${WRKSRC}/gnat/anet.gpr
	@${REINPLACE_CMD} -e 's|DESTDIR|DEST2|g' \
		${WRKSRC}/doc/Makefile

do-build:
	${MKDIR} ${WRKSRC}/doc/html
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/anet \
		${STAGEDIR}${PREFIX}/include/anet
	${INSTALL_DATA} ${WRKSRC}/src/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/anet
	${INSTALL_DATA} ${WRKSRC}/lib/static/* ${STAGEDIR}${PREFIX}/lib/anet
	${INSTALL_DATA} ${WRKSRC}/gnat/anet.gpr ${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
