# Created by: Peter Schmiedeskamp <pschmied@qwest.net>
# $FreeBSD$

PORTNAME=	libexif
PORTVERSION=	0.6.21
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	marius@nuenneri.ch
COMMENT=	Library to read digital camera file meta-data

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS NLS

USES=		libtool gmake pathfix pkgconfig
USE_BZIP2=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENV_OFF=	am_cv_func_iconv=no
NLS_CONFIGURE_ENABLE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|doc||g ; \
		 /^am__installdirs =/s|$$(docdir)||g ; \
		 /^install-data-am:/s|install-docDATA||g' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
