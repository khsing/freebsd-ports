# Created by: Hideki Machida <hido@neojapangz.com>
# $FreeBSD$

PORTNAME=	hlstats
PORTVERSION=	1.62
CATEGORIES=	games www
MASTER_SITES=	http://www.hlstats-community.org/wordpulse/site/hlscom/upload/Multimedia/download/${PORTVERSION}/
DISTNAME=	HLStats-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A real-time statistics generator for Half-Life and its mods

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-07

LICENSE=	CDDL

RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

USES=		perl5
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	yes
USE_PERL5=	run
HLSTATS?=	www/${PORTNAME}
PLIST_SUB+=	HLSTATS=${HLSTATS}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/${HLSTATS}
	cd ${WRKSRC} && ${TAR} cf - ChangeLog README* [a-z]* | ${TAR} xf - \
		-C ${PREFIX}/${HLSTATS}

.include <bsd.port.mk>
