# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_purchase_invoice_line_standalone
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_purchase_invoice_line_standalone/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_purchase_invoice_line_standalone-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Purchase Invoice Line Standalone Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_purchase>=2.8.0:${PORTSDIR}/finance/trytond28_purchase \
		trytond28_account_invoice_line_standalone>=2.8.0:${PORTSDIR}/finance/trytond28_account_invoice_line_standalone

CONFLICTS=	trytond_purchase_invoice_line_standalone-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
