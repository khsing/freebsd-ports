# $FreeBSD$
#   $MCom: ports/accessibility/ruby-atk/Makefile,v 1.2 2005/10/17 07:05:39 mezz Exp $

PORTNAME=	atk
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	accessibility devel ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	${RUBY_GNOME_DIST_SUBDIR}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for ATK

BUILD_DEPENDS+=	rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/glib2.so:${PORTSDIR}/devel/ruby-glib2 \
		rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config

NO_STAGE=	yes
USE_RUBY=	yes
USE_GNOME=	atk
USE_RUBY_EXTCONF=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${LOCALBASE}/libdata/pkgconfig

MASTERDIR=	${.CURDIR}/../../x11/ruby-gnome2
PKGDIR=		${.CURDIR}

DEPRECATED=	Use rubygem-atk instead
EXPIRATION_DATE=2014-03-23

.include "${MASTERDIR}/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/atk
INSTALL_TARGET=	site-install install

DOCS=		COPYING.LIB README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${RUBY_VER} != 1.9
BROKEN=		Does not work with Ruby 2.x
.endif

.include <bsd.port.post.mk>
