# Created by: ijliao
# $FreeBSD$

PORTNAME=	gettext-lint
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check the validity and consistency of PO and POT files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes

USES=		gettext:run
USE_PYTHON_RUN=	yes

MAN1=		POFileChecker.1 POFileClean.1 POFileConsistency.1 \
		POFileEquiv.1 POFileFill.1 POFileGlossary.1 \
		POFileSpell.1 POFileStatus.1

NO_STAGE=	yes
post-patch:
.for i in POFileChecker POFileClean POFileConsistency POFileEquiv POFileFill \
	POFileGlossary POFileSpell POFileStatus
	cd ${WRKSRC}/src && ${SED} -e 's|@PYTHON@|${PYTHON_CMD}|g ; \
		 s|@prefix@/share/@PACKAGE@|${PYTHON_SITELIBDIR}/${PORTNAME}|g' ${i}.in > ${i}
.endfor

do-install:
.for i in POFileChecker POFileClean POFileConsistency POFileEquiv POFileFill \
	POFileGlossary POFileSpell POFileStatus
	${INSTALL_SCRIPT} ${WRKSRC}/src/${i} ${PREFIX}/bin/${i}
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${MANPREFIX}/man/man1/${i}.1
.endfor
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/*.py ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/*.css ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/*.xsl ${DATADIR}

.include <bsd.port.mk>
