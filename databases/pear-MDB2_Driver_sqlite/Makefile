# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MDB2_Driver_sqlite
PORTVERSION=	1.5.0b4
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR sqlite MDB2 driver

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS:=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2

USE_PHP=	sqlite
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
MANUAL_PACKAGE_BUILD=  it needs an old PHP version
PEAR_AUTOINSTALL=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
