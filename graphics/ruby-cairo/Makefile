# $FreeBSD$
#   $MCom: ports/graphics/ruby-cairo/Makefile,v 1.9 2008/10/19 23:20:49 mezz Exp $

PORTNAME=	cairo
PORTVERSION=	1.12.2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	r${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Cairo

BUILD_DEPENDS=	rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USES=		pkgconfig
USE_RUBY=	yes
USE_RUBY_EXTCONF=yes
CONFIGURE_ARGS+=--ruby=${RUBY}

DOCS=		AUTHORS COPYING GPL NEWS

DEPRECATED=	Use rubygem-cairo instead
EXPIRATION_DATE=2014-03-23

NO_STAGE=	yes
post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/agg
	@${INSTALL_DATA} ${WRKSRC}/samples/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/samples/agg/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/agg/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.pre.mk>

.if ${RUBY_VER} != 1.9
BROKEN=		 Does not work with Ruby 2.x
.endif

.include <bsd.port.post.mk>
