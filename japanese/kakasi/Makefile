# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kakasi
PORTVERSION=	2.3.5
CATEGORIES=	japanese textproc
MASTER_SITES=	http://kakasi.namazu.org/stable/

MAINTAINER=	ota@j.email.ne.jp
COMMENT=	Kanji-Kana Simple Inverter, language filter for Japanese

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		iconv libtool:oldver
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		NEWS README README-ja TODO \
		doc/ChangeLog.lib doc/JISYO \
		doc/README.lib doc/README.wakati

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/-Wno-unused-result//' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/kakasi.1.ja \
		${STAGEDIR}${MAN1PREFIX}/man/ja/man1/kakasi.1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
