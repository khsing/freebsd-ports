# Created by: ijliao
# $FreeBSD$

PORTNAME=	dynamechs
PORTVERSION=	4.0.p1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/4.0pre1
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multibody Dynamic Simulation Library

USE_BZIP2=	yes
USES=		gmake perl5
USE_GL=		glut
USE_PERL5=	build
MAKE_ENV=	OPENGLINCDIR="${LOCALBASE}/include" \
		OPENGLLIBDIR="${LOCALBASE}/lib"
ALL_TARGET=	freebsd
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|.SILENT:||' ${WRKSRC}/Makefile

do-configure:
	@${CP} -f ${FILESDIR}/make.platform.freebsd ${WRKSRC}/make/

do-install:
.for dir in dm dmu dmGL
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/${dir}
	(cd ${WRKSRC}/${dir} && ${FIND} . -name  "*.h" -or -name "*.hpp" | \
		${XARGS} -J % ${INSTALL_DATA} % \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}/${dir})
	(cd ${WRKSRC}/lib/platform.freebsd && ${INSTALL_LIB} lib${dir}.so \
		${STAGEDIR}${PREFIX}/lib)
.endfor

.include <bsd.port.mk>
