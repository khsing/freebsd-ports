# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	sshsudo
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	#
EXTRACT_ONLY=	#

MAINTAINER=	gaod@hychen.org
COMMENT=	A bash script to run sudo command on multiple remote computers

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		sshpass>=0:${PORTSDIR}/security/sshpass

PROJECTHOST=	sshsudo

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/sshsudo

NO_STAGE=	yes
post-patch:
	${SED} -e "s,/bin/bash,${LOCALBASE}/bin/bash," -e "s,mktemp,mktemp -t sshsudo," \
	<${DISTDIR}/${DISTNAME} >${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
