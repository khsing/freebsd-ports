# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-selenium2library
PORTVERSION=	1.5.0
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Web testing library for Robot Framework

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:${PORTSDIR}/devel/py-robotframework \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:${PORTSDIR}/devel/py-decorator

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
