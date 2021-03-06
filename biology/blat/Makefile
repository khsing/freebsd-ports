# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	blat
PORTVERSION=	35
CATEGORIES=	biology
MASTER_SITES=	http://hgwdev.cse.ucsc.edu/~kent/src/ \
		http://users.soe.ucsc.edu/~kent/src/
DISTNAME=	${PORTNAME}Src${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast tool for local sequence similarity searches

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}Src

USES=		gmake
USE_OPENSSL=	yes
MAKEFILE=	makefile
MAKE_ENV=	MACHTYPE="${ARCH}" HOME="${WRKSRC}/${BINDIR}" STRIP="${TRUE}"

CPPFLAGS+=	$$(libpng-config --cflags)
LDFLAGS+=	$$(libpng-config --ldflags)

SUB_FILES=	pkg-message

PORTDOCS=	README
PLIST_FILES=	${EXECUTABLES:S,^,bin/,} \
		lib/blat/webBlat/webBlat \
		lib/blat/webBlat/install.txt
PLIST_DIRS=	lib/blat/webBlat \
		lib/blat

EXECUTABLES=	blat faToNib faToTwoBit gfClient gfServer nibFrag \
		pslPretty pslReps pslSort twoBitInfo twoBitToFa

.include <bsd.port.options.mk>

post-patch:
	@${MKDIR} ${WRKSRC}/bin/${ARCH}
	@${MKDIR} ${WRKSRC}/lib/${ARCH}
	@${FIND} ${WRKSRC} -name "makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${DESTDIR}||g'
	@${REINPLACE_CMD} -e \
		's|cd |$$(MAKE) -C | ; \
		 s| &&.*||' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^COPT=.*|COPT=$${CPPFLAGS}| ; \
		 s|^L=.*|L=$${LDFLAGS}|' ${WRKSRC}/inc/common.mk

do-install:
.for exe in ${EXECUTABLES}
	(cd ${WRKSRC}/bin/${ARCH} && ${INSTALL_PROGRAM} ${exe} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/blat/webBlat
	(cd ${WRKSRC}/webBlat && ${INSTALL_PROGRAM} webBlat \
		${STAGEDIR}${PREFIX}/lib/blat/webBlat)
	(cd ${WRKSRC}/webBlat && ${INSTALL_DATA} install.txt \
		${STAGEDIR}${PREFIX}/lib/blat/webBlat)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
