# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	20110905
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
		http://homepage.boetes.org/software/mg/

MAINTAINER=	darcsis@gmail.com
COMMENT=	A small, fast Emacs-like editor

PLIST_FILES=	bin/mg man/man1/mg.1.gz
PORTDOCS=	README tutorial

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${REINPLACE_CMD} -e 's|-Wno-error=unused-but-set-variable||g' \
		-e '/^CC=/d' -e 's|-g -Wall|-Wall|' -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
