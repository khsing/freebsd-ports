# Created by: Aaron Zauner <az_mail@gmx.at>
# $FreeBSD$

PORTNAME=	ipgrab
PORTVERSION=	0.9.10
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPgrab is a verbose packet sniffer for UNIX hosts

BUILD_DEPENDS=	${LOCALBASE}/include/pcap.h:${PORTSDIR}/net/libpcap

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
INFO=		ipgrab
MAN8=		ipgrab.8
DOCS=		README AUTHORS COPYING ChangeLog \
		DEVELOPER-HOWTO INSTALL NEWS TODO

PLIST_FILES=	bin/ipgrab

PORTDOCS=	README AUTHORS COPYING ChangeLog DEVELOPER-HOWTO \
		INSTALL NEWS TODO

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/doc/,} ${MANPREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/doc/ipgrab.info ${PREFIX}/info/
	${INSTALL_PROGRAM} ${WRKSRC}/src/ipgrab ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
