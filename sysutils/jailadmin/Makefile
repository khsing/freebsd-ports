# Created by: Kirk Strauser <kirk@strauser.com>
# $FreeBSD$

PORTNAME=	jailadmin
PORTVERSION=	1.8
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://subwiki.honeypot.net/pub/Freebsd/JailAdmin/
DISTNAME=	jailadmin-${PORTVERSION}

MAINTAINER=	kirk@strauser.com
COMMENT=	A system for managing a set of named jails

USES=		perl5

PORTDOCS=	INSTALL README

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_SNMP)
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
PLIST_SUB+=	SNMP=""
.else
INSTALL_TARGET=	installbase
PLIST_SUB+=	SNMP="@comment "
.endif

pre-everything::
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO} "WITH_SNMP     install the additional SNMP management components"
	@${ECHO}

post-patch:
	@${REINPLACE_CMD} -e "s#^SITEPERLDIR=.*#SITEPERLDIR= ${SITE_PERL}#" ${WRKSRC}/Makefile
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '/share\/doc/s/^[[:blank:]]/#&/' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
