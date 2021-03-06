# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ming
PORTVERSION=	0.2a.${RUBY_MING_VERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	japanese graphics ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	mingruby
DISTNAME=	${PORTNAME}-ruby-${RUBY_MING_VERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	don@na.rim.or.jp
COMMENT=	Yet another Ming module for Ruby built with Japanese support

LIB_DEPENDS=	ming:${PORTSDIR}/japanese/ming

RUBY_MING_VERSION=	0.1.6

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
CONFIGURE_ARGS=	-- --with-ming-include=${PREFIX}/include/ming --with-ming-lib=${PREFIX}/lib

DOCS_EN=	ChangeLog README.en Usage_en.txt fonts.en
DOCS_JA=	README.ja Usage_ja.txt fonts.ja progress.rd

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONSFILE=	${PORT_DBDIR}/ja-ruby-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
