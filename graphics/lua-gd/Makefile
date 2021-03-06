# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	lua-gd
PORTVERSION=	2.0.33r2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://files.luaforge.net/releases/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}forLua5.1/

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	GD bindings for the Lua programming language

LICENSE=	MIT

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_LUA=	5.1

CFLAGS+=	-I${LUA_INCDIR} -I${LOCALBASE}/include
LDFLAGS+=	-shared -L${LOCALBASE}/lib -lgd -L${LUA_LIBDIR} -llua -lm
GDFEATURES=	`gdlib-config --features |sed -e "s/GD_/-DGD_/g"`

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} ==	"amd64"
CFLAGS+=	-fPIC
.endif

do-build:
	${CC} -o ${WRKSRC}/gd.so ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${GDFEATURES} ${WRKSRC}/luagd.c

LUA_MODLIBDIR=	${PREFIX}/lib/lua/${LUA_VER}

do-install:
	${MKDIR} ${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gd.so ${LUA_MODLIBDIR}
	${LUA_CMD} ${WRKSRC}/test_features.lua
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} * ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}"
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demos && ${INSTALL_DATA} * ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}"
.endif

.include <bsd.port.mk>
