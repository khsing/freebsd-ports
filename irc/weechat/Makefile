# Created by: clement
# $FreeBSD$

PORTNAME=	weechat
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://weechat.org/files/src/ \
		http://perturb.me.uk/distfiles/weechat/:mandocs \
		${MASTER_SITE_LOCAL:S/$/:mandocs/}
MASTER_SITE_SUBDIR=	jase/weechat/:mandocs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jase@FreeBSD.org
COMMENT=	A lightweight and user friendly ncurses based IRC client

LICENSE=	GPLv3

CONFLICTS=	weechat-devel-0.*

USE_LDCONFIG=	yes
USES=		cmake iconv ncurses
CMAKE_ARGS+=	-DENABLE_GUILE=no
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

OPTIONS_DEFINE=	RUBY PYTHON PERL TCL LUA CHARSET BACKTRACE ASPELL \
		GNUTLS NLS ICON MANPAGES DOCS
OPTIONS_DEFAULT=RUBY PYTHON PERL TCL LUA CHARSET BACKTRACE ASPELL \
		GNUTLS ICON MANPAGES

BACKTRACE_DESC=	Provide crash backtraces
CHARSET_DESC=	Charset conversion support
LUA_DESC=	Lua scripting support
PERL_DESC=	Perl scripting support
PYTHON_DESC=	Python scripting support
RUBY_DESC=	Ruby scripting support
TCL_DESC=	Tcl scripting support
ICON_DESC=	Desktop icon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHARSET}
PLIST_SUB+=	CHARSET=""
.else
CMAKE_ARGS+=	-DENABLE_CHARSET=no
PLIST_SUB+=	CHARSET="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS=no
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MASPELL}
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL=""
.else
CMAKE_ARGS+=	-DENABLE_ASPELL=no
PLIST_SUB+=	ASPELL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2
CMAKE_ARGS+=	-DBSD_PYTHON_CMD=${PYTHON_CMD} \
		-DBSD_PYTHON_VER=${PYTHON_VERSION}
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_PYTHON=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
CMAKE_ARGS+=	-DBSD_RUBY_CMD=${RUBY} \
		-DBSD_RUBY_VER=${RUBY_NAME}
PLIST_SUB+=	RUBY=""
.else
CMAKE_ARGS+=	-DENABLE_RUBY=no
PLIST_SUB+=	RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
USES+=		pkgconfig
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
.else
CMAKE_ARGS+=	-DENABLE_GNUTLS=no
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
PLIST_SUB+=	PERL=""
.else
CMAKE_ARGS+=	-DENABLE_PERL=no
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=		tcl:85+
CMAKE_ARGS+=	-DBSD_TCL_VER=${TCL_VER} \
		-DBSD_TCL_LIBDIR=${LOCALBASE}/lib \
		-DBSD_TCL_INCDIR=${TCL_INCLUDEDIR}
PLIST_SUB+=	TCL=""
.else
CMAKE_ARGS+=	-DENABLE_TCL=no
PLIST_SUB+=	TCL="@comment "
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1+
CMAKE_ARGS+=	-DBSD_LUA_LIBDIR=${LUA_LIBDIR} \
		-DBSD_LUA_INCDIR=${LUA_INCDIR}
PLIST_SUB+=	LUA=""
.else
CMAKE_ARGS+=	-DENABLE_LUA=no
PLIST_SUB+=	LUA="@comment "
.endif

.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
		asciidoc:${PORTSDIR}/textproc/asciidoc \
		source-highlight>=3.1.5:${PORTSDIR}/textproc/source-highlight
CMAKE_ARGS+=	-DENABLE_MAN=yes -DMANDIR=${MANPREFIX}/man -DENABLE_DOC=yes
.else
CMAKE_ARGS+=	-DENABLE_MAN=no -DENABLE_DOC=no
.endif

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	DOCS=""
.if !defined(MAINTAINER_MODE)
DISTFILES+=	${DISTNAME}-docs.txz:mandocs
.endif
.else
PLIST_SUB+=	DOCS="@comment "
.endif

.if ${PORT_OPTIONS:MMANPAGES}
PLIST_SUB+=	MANPAGES=""
.if !defined(MAINTAINER_MODE)
DISTFILES+=	${DISTNAME}-manpages.txz:mandocs
.endif
.else
PLIST_SUB+=	MANPAGES="@comment "
.endif

.if ${PORT_OPTIONS:MBACKTRACE}
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

.if ${PORT_OPTIONS:MICON}
PLIST_SUB+=	ICON=""
.else
PLIST_SUB+=	ICON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|INSTALL|#INSTALL|' ${WRKSRC}/doc/CMakeLists.txt
.for f in src/CMakeLists.txt src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${f}
.endfor
.if empty(PORT_OPTIONS:MBACKTRACE)
	@${REINPLACE_CMD} -e '/IF.*FreeBSD/,/ENDIF.*FreeBSD/d' ${WRKSRC}/src/core/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MICON)
	@${REINPLACE_CMD} -e '/^# icon$$/,/^$$/d' ${WRKSRC}/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MMANPAGES} && !defined(MAINTAINER_MODE)
	${INSTALL_MAN} ${WRKDIR}/manpages/weechat.1 ${STAGEDIR}${PREFIX}/man/man1
.for f in de fr it ja pl
	@${MKDIR} ${STAGEDIR}${PREFIX}/man/${f}/man1
	${INSTALL_MAN} ${WRKDIR}/manpages/${f}/weechat.1 ${STAGEDIR}${PREFIX}/man/${f}/man1
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS} && !defined(MAINTAINER_MODE)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/docs/* ${STAGEDIR}${DOCSDIR}/
.endif
	${LN} -sf ${PREFIX}/bin/weechat ${STAGEDIR}${PREFIX}/bin/weechat-curses

.include <bsd.port.mk>
