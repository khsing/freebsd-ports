# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	netwox
PORTVERSION=	5.38.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwox/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/netwox/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/netwox/download/v5/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz ${PORTNAME}-${PORTVERSION}-doc_html.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Netwox a network testing toolbox

BUILD_DEPENDS=	netwib-config:${PORTSDIR}/net/netwib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/src
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)\.[0-9]*/\1\2/}
MAN1=		netwox.1 netwox${SHORTPORTVERSION}.1

PLIST_SUB+=	SHORTPORTVERSION=${SHORTPORTVERSION}

NO_STAGE=	yes
do-configure:
		@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%CFLAGS%%|${CFLAGS}|' \
		-e 's|gcc|${CC}|' \
		${WRKSRC}/config.dat
		(cd ${WRKSRC} ; ${SH} ${WRKSRC}/genemake )

post-install:
		${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
.ifndef(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${CP} -R ${WRKSRC}/../../${PORTNAME}-${PORTVERSION}-doc_html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
