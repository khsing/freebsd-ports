# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	ibus-m17n
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	The m17n IMEngine for IBus framework

LIB_DEPENDS=	ibus-1.0:${PORTSDIR}/textproc/ibus \
		m17n.4:${PORTSDIR}/devel/m17n-lib
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus

PROJECTHOST=	ibus

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

NO_STAGE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/m17n|$${pkgdatadir}|g' \
		${WRKSRC}/src/m17n.xml.in*

.include <bsd.port.mk>
