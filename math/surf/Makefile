# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	surf
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visualize some real algebraic geometry

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libgmp.so:${PORTSDIR}/math/gmp

USE_XORG=	x11 xmu
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-cups --datadir=${PREFIX}/share

CONFLICTS=	surf-0* # www/surf

OPTIONS_DEFINE=	DOCS

PORTDOCS=	manual.sgml
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/${PORTNAME}.xpm \
		man/man1/${PORTNAME}.1.gz
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|@CUPS_TRUE@|#|g ; \
		 s|@CUPS_FALSE@||g'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
