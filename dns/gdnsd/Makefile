# Created by: Allan Jude <ports@scaleengine.com>
# $FreeBSD$

PORTNAME=	gdnsd
PORTVERSION=	1.11.1
CATEGORIES=	dns
MASTER_SITES=	https://github.com/blblack/gdnsd/releases/download/v${PORTVERSION}/ \
		http://gdnsd.scaleengine.net/gdnsd/

FETCH_ARGS=	-Fpr

MAINTAINER=	ports@scaleengine.com
COMMENT=	Authoritative-only GeoIP-aware DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --with-rootdir=${LOCALBASE}/etc/gdnsd
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

USE_RC_SUBR=	gdnsd

USERS?=		gdnsd
GROUPS?=	gdnsd

OPTIONS_DEFINE=	DOCS GEOIP URCU

GEOIP_DESC=		Enable GeoIP Support
GEOIP_RUN_DEPENDS=	${LOCALBASE}/share/GeoIP/GeoIP.dat:${PORTSDIR}/net/GeoIP

URCU_DESC=		Read-Copy-Update Support (Faster Zone Parsing)
URCU_CONFIGURE_WITH=	urcu
URCU_LIB_DEPENDS=	liburcu.so:${PORTSDIR}/sysutils/liburcu

.include <bsd.port.mk>
