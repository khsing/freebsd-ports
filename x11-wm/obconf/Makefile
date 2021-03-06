# Created by: trevor
# $FreeBSD$

PORTNAME=	obconf
PORTVERSION=	2.0.4
CATEGORIES=	x11-wm
MASTER_SITES=	http://openbox.org/dist/obconf/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Preferences manager for the Openbox window manager

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		obrender:${PORTSDIR}/x11-wm/openbox

USES=		pkgconfig
USE_GNOME=	gnomehier libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENBOX_CFLAGS="`pkg-config --cflags obrender-3.5 obt-3.5`" \
		OPENBOX_LIBS="`pkg-config --libs obrender-3.5 obt-3.5`"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/openbox
MAKE_ARGS=	mkdir_p='${MKDIR}'

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	ABOUT-NLS AUTHORS README TODO

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
