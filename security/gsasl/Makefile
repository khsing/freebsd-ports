# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsasl
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU SASL Library

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libntlm.so:${PORTSDIR}/security/libntlm

USES=		charsetfix pathfix perl5 pkgconfig
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

INFO=		gsasl

CPPFLAGS+=	-nostdinc -I/usr/include -I${LOCALBASE}/include
LDFLAGS+=	-L/usr/lib -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^en@/d' \
		${WRKSRC}/lib/po/LINGUAS ${WRKSRC}/po/LINGUAS

.include <bsd.port.options.mk>

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgsasl.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/reference
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/reference/html/* \
		${STAGEDIR}${DOCSDIR}/reference
.endif

.include <bsd.port.mk>
