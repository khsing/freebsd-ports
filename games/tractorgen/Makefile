# Created by: elfrink@introcom.nl
# $FreeBSD$

PORTNAME=	tractorgen
PORTVERSION=	0.31.7
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.vergenet.net/~conrad/software/tractorgen/dl/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	elfrink@introweb.nl
COMMENT=	Generates ASCII tractors

GNU_CONFIGURE=	yes

MAN6=		tractorgen.6
PLIST_FILES=	bin/tractorgen
PORTDOCS=	AUTHORS ChangeLog NEWS README

NO_STAGE=	yes
post-install:
	${INSTALL_MAN} ${FILESDIR}/tractorgen.6 ${PREFIX}/man/man6/tractorgen.6
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
