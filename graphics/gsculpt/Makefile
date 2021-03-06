# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsculpt
PORTVERSION=	0.99.47
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME:S,-src,,}
DISTNAME=	gSculpt-${PORTVERSION}-alpha-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Opensource 3D modelling application

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opengl>0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}gtkglext>0:${PORTSDIR}/x11-toolkits/py-gtkglext

WRKSRC=		${WRKDIR}/${DISTNAME:S,-src,,}

USES=		pkgconfig scons
USE_GNOME=	pygtk2
USE_GL=		glu
USE_XORG=	x11
USE_PYTHON=	2
USE_LDCONFIG=	${PREFIX}/lib/gSculpt

DATADIR=	${PREFIX}/share/gSculpt

DESKTOP_ENTRIES="gSculpt" "" \
		"${DATADIR}/gsimages/gSculpt_Glass_Master_by_Gary_Rose.png" \
		"${PORTNAME}" "Graphics;GTK;" ""

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${ARCH} == "i386"
CFLAGS+=	-DGSCULPT_FPU_X86
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"s| gsculpt.py| ${PYTHONPREFIX_SITELIBDIR}/gSculpt/gsculpt.py|" \
		${WRKSRC}/gsculpt
	@${REINPLACE_CMD} -e \
		"s|'-Werror'|''| ; \
		 s|'-g'|''| ; \
		 s|'-DGSCULPT_FPU_X86'|''| ; \
		 s|'[(]-O2.*-O[)]'|''| ; \
		 /^cppLibs/s|BackgroundModel|BackgroundMesh|" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e \
		"/^prefix/s|=.*|= '${STAGEDIR}${PREFIX}'| ; \
		 /^gSculptStartDir/s|=.*|= os.path.join( pysitelibdir )|" \
		${WRKSRC}/SConstruct-install
	@${REINPLACE_CMD} -e \
		"s|#GSCULPT_LIBRARY_PATH#|${LOCALBASE}/lib/gSculpt|; \
		 s|python|${PYTHON_CMD}|; \
		 s|#GSCULPT_START#|${PYTHONPREFIX_SITELIBDIR}/gsculpt.py|" \
		${WRKSRC}/posixbuild/gsculpt

do-install:
	@(cd ${WRKSRC} && ${SCONS} -f SConstruct-install install)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Britefury \
		-name "*.so" -exec ${STRIP_CMD} {} \;
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gSculpt/*.so

.include <bsd.port.post.mk>
