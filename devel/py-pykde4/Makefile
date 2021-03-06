# $FreeBSD$

PORTNAME=	pykde4
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for KDE

LIB_DEPENDS=	libqwt.so:${PORTSDIR}/x11-toolkits/qwt5

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtDesigner.so:${PORTSDIR}/devel/py-qt4-designer \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_SITELIBDIR}/PyQt4/QtOpenGL.so:${PORTSDIR}/x11/py-qt4-opengl \
		${PYTHON_SITELIBDIR}/PyQt4/QtSql.so:${PORTSDIR}/databases/py-qt4-sql \
		${PYTHON_SITELIBDIR}/PyQt4/QtXml.so:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtWebKit.so:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_SITELIBDIR}/PyQt4/phonon.so:${PORTSDIR}/multimedia/py-qt4-phonon \
		${PYTHON_SITELIBDIR}/PyQt4/QtDeclarative.so:${PORTSDIR}/devel/py-qt4-declarative
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:${PORTSDIR}/devel/py-qt4-dbussupport

USE_KDE4=	kdehier kdelibs kdeprefix okular pimlibs \
		akonadi automoc4 soprano
USE_PYTHON=	2
USE_QT4=	corelib dbus designer_build gui network xml \
		qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USES=		cmake:outsource
CMAKE_ARGS+=	-DWITH_PolkitQt:BOOL=FALSE

SUB_FILES=	kdebindings4.pth
SUB_LIST=	PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR}

PLIST_SUB+=	SIPDIR=share/sip

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${FIND} -d ${PATCH_WRKSRC}/sip -name "*.orig" -delete

pre-configure:
	${REINPLACE_CMD} -e '/add_subdirectory(examples)/ d' \
		-e '/add_subdirectory(tools)/ d' \
		${WRKSRC}/CMakeLists.txt
	${RM} ${WRKSRC}/examples/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKDIR}/kdebindings4.pth ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
