# $FreeBSD$

PORTNAME=	pandas
PORTVERSION=	0.13.0
CATEGORIES=	math devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	Flexible, high-performance data analysis in Python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		cython:${PORTSDIR}/lang/cython
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
TEST_DEPENDS=	nosetests:${PORTSDIR}/devel/py-nose \
		cython:${PORTSDIR}/lang/cython \
		${PYTHON_PKGNAMEPREFIX}numexpr>0:${PORTSDIR}/math/py-numexpr \
		${PYTHON_PKGNAMEPREFIX}tables>0:${PORTSDIR}/devel/py-tables \
		${PYTHON_PKGNAMEPREFIX}scipy>0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:${PORTSDIR}/textproc/py-xlrd \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:${PORTSDIR}/textproc/py-xlwt \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:${PORTSDIR}/textproc/py-openpyxl \
		${PYTHON_PKGNAMEPREFIX}statsmodels>0:${PORTSDIR}/math/py-statsmodels \
		${PYTHON_PKGNAMEPREFIX}bottleneck>0:${PORTSDIR}/math/py-bottleneck \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml

SUB_FILES=	pkg-message

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

# Uncomment the following line to enable regression-test
# on a headless (X11-less) host (eg: RedPorts)
#USES=		display:regression-test

regression-test: build
	@(cd ${WRKSRC} && \
		${PYTHON_CMD} ${PYSETUP} build_ext --inplace && \
		${PYTHON_CMD} ci/print_versions.py \
		ci/script.sh \
		${PYTHON_CMD} ci/print_skipped.py \
	)

.include <bsd.port.mk>
