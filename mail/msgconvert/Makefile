# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	msgconvert
PORTVERSION=	20060330
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.webonaut.com/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=	.bz2

MAINTAINER=	klammer@webonaut.com
COMMENT=	Convert .MSG files to multipart MIME messages (mbox)

RUN_DEPENDS=	p5-OLE-Storage_Lite>=0:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		shebangfix perl5
USE_BZIP2=	yes
EXTRACT_CMD=	${BZCAT}
EXTRACT_BEFORE_ARGS=	
EXTRACT_AFTER_ARGS=	> ${PORTNAME}.pl
SHEBANG_FILES=	${PORTNAME}.pl

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}.pl
	${LN} -s ${PREFIX}/bin/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
