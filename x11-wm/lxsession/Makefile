# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxsession
PORTVERSION=	0.4.6.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/lxde/LXSession%20%28session%20manager%29/LXSession%20${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	LXDE Session Manager

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libhal.so:${PORTSDIR}/sysutils/hal \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gmake iconv pkgconfig
USE_GNOME=	gtk20 intlhack libxslt
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

# Wrong versioning upstream
PORTSCOUT=      skipv:0.4.9.2

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
