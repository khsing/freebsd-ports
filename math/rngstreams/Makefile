# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	rngstreams
PORTVERSION=	1.0.1
CATEGORIES=	math
MASTER_SITES=	http://statmath.wu-wien.ac.at/software/RngStreams/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A C implementation of a high-quality uniform random number generator

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
USE_LDCONFIG=	yes
PLIST_FILES=	lib/librngstreams.a \
		lib/librngstreams.la \
		lib/librngstreams.so.0 \
		lib/librngstreams.so \
		include/RngStream.h
PORTDOCS=	rngstreams.txt
PORTEXAMPLES=	example1.c

NO_STAGE=	yes
post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for DD in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${DD} ${DOCSDIR}
.endfor
.endif
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for EE in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${EE} ${EXAMPLESDIR}
.endfor
.endif

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
