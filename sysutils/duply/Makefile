# Created by: Michael Ranner <michael@ranner.eu>
# $FreeBSD$

PORTNAME=	duply
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/ftplicity/${PORTNAME}%20%28simple%20duplicity%29/1.6.x/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael@ranner.eu
COMMENT=	Shell front end for the duplicity backup tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

RUN_DEPENDS=	duplicity:${PORTSDIR}/sysutils/duplicity \
				bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

PORTDOCS=	INSTALL.txt gpl-2.0.txt
PLIST_FILES=	bin/duply

post-patch:
	${REINPLACE_CMD} -e "s,/etc/duply,${ETCDIR},g" ${WRKSRC}/duply

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/duply ${STAGEDIR}${PREFIX}/bin/duply
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for i in ${PORTDOCS}
	  ${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.	endfor

.include <bsd.port.mk>
