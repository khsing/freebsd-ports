# Created by: Benno Rice <benno@netizen.com.au>
# $FreeBSD$

PORTNAME=	sgmltools-lite
PORTVERSION=	3.0.3
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates various output formats from DocBook SGML documents

BUILD_DEPENDS+=	openjade:${PORTSDIR}/textproc/openjade
RUN_DEPENDS+=	docbook<2:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular

USE_PYTHON_BUILD=	yes
USE_TEX=	latex:build
MAN1=		sgmltools-lite.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-etcsgml=${PREFIX}/etc/sgml --datadir=${PREFIX}/share

NO_STAGE=	yes
pre-configure:
	${RM} -f ${WRKSRC}/config.cache

pre-install:
	${MKDIR} ${PREFIX}/etc/sgml

post-install:
	${ECHO_CMD} "3.0.3" > ${PREFIX}/share/sgml/misc/sgmltools/VERSION

.include <bsd.port.mk>
