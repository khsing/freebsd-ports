# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/eggdbus/Makefile,v 1.3 2009/11/24 01:46:27 marcus Exp $

PORTNAME=	eggdbus
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus bindings for GObject

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_GNOME=	glib20 gnomehack
USES=		gettext gmake pkgconfig
MAKE_JOBS_UNSAFE=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml \
    		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

MAN1=	eggdbus-binding-tool.1
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-Wl,--as-needed||' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
