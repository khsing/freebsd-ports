# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME?=	sync-engine
PORTVERSION=	0.14
CATEGORIES?=	palm
MASTER_SITES=	SF/synce/SynCE/${PORTVERSION}
DISTNAME=	synce-sync-engine-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Synchronization Engine for Windows Mobile devices

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/pyrtfcomp.so:${PORTSDIR}/archivers/py-librtfcomp \
		${PYTHON_SITELIBDIR}/pyrra.so:${PORTSDIR}/palm/py-synce-librra \
		${PYTHON_SITELIBDIR}/pyrapi2.so:${PORTSDIR}/palm/py-synce-librapi2

.if defined(ENGINE_VER) && defined(PLUGINDIR)
NO_BUILD=	yes
USE_PYTHON_RUN=	yes
PLIST_SUB=	PLUGINDIR=${PLUGINDIR}
PLIST=		${PKGDIR}/pkg-plist.plugin
.else
PKGNAMEPREFIX=	synce-
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	synce_sync_engine
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(ENGINE_VER) && defined(PLUGINDIR)
do-install:
	@${MKDIR} ${PREFIX}/${PLUGINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/synce-opensync-plugin-${ENGINE_VER}x.py \
		${PREFIX}/${PLUGINDIR}/synce-opensync-plugin.py
.endif

.include <bsd.port.post.mk>
