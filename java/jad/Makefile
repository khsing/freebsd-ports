# Created by: Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	jad
PORTVERSION=	1.5.8c
CATEGORIES=	java devel
MASTER_SITES=	http://www.varaneckas.com/sites/default/files/jad/
DISTNAME=	jad158c.freebsd
EXTRACT_SUFX=	.zip

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java Decompiler

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/jad

PORTDOCS=	*

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jad ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
