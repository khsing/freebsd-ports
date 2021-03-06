# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	q4m
PORTVERSION=	0.9.13
CATEGORIES=	databases
MASTER_SITES=	http://q4m.kazuhooku.com/dist/
PKGNAMEPREFIX=	${_MYSQL_SERVER:T:C/-server$/-/}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A message queue that works as a pluggable storage engine of MySQL

FETCH_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/${_MYSQL_SERVER}:build

USES=		gmake perl5
USE_AUTOTOOLS=	libtool
USE_MYSQL=	server
USE_GCC=	any
USE_PERL5=	run

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DDBUG_OFF
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib/mysql/plugin" \
		--with-mysql="$$(cd ${PORTSDIR}/${_MYSQL_SERVER}; ${MAKE} -V WRKSRC)"

COPYTREE_AUTO=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
					2>&1) && \
					${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
					${FIND} $$1 -type d -exec chmod 755 {} \; && \
					${FIND} $$1 -type f \! -perm +100 -exec chmod ${SHAREMODE} {} \; && \
					${FIND} $$1 -type f -perm +100 -exec ${CHOWN} ${BINOWN}:${BINGRP} {} \; && \
					${FIND} $$1 -type f -perm +100 -exec chmod ${BINMODE} {} \;' --

NO_STAGE=	yes
post-extract:
	${CP} -p ${WRKSRC}/support-files/install.sql ${WRKSRC}/examples/

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog README doc
PORTEXAMPLES=	crawler install.sql

post-patch:
	@${REINPLACE_CMD} -e 's|/include/mysql|/include/mysql/mysql|g' ${WRKSRC}/configure

post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	cd ${WRKSRC}; ${COPYTREE_SHARE} ${f} ${DOCSDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples; ${COPYTREE_AUTO} ${f} ${EXAMPLESDIR}
.endfor
.endif

install-functions:
	mysql -u root -p -f mysql < ${EXAMPLESDIR}/install.sql

test:
	cd ${WRKSRC}; ./run_tests.pl

.include <bsd.port.mk>
