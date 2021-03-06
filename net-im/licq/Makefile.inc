# Common stuff for Licq-based ports
# $FreeBSD$

PKGNAMEPREFIX=		licq-
LICQ_VER=		1.8.0
.if ${PORTNAME} != "base"
BUILD_DEPENDS+=		licq:${PORTSDIR}/${LICQ_PORT}
RUN_DEPENDS+=		licq:${PORTSDIR}/${LICQ_PORT}
WRKSRC?=		${WRKDIR}/${DISTNAME}/plugins/${PORTNAME}
.endif
MASTER_SITES=		SF/licq/licq/${LICQ_VER}
DISTNAME=		${PKGNAMEPREFIX}${LICQ_VER}
DISTFILES=		${DISTNAME}.tar.bz2
DISTINFO_FILE?=		${PORTSDIR}/${LICQ_PORT}/distinfo
USE_BZIP2=		yes
