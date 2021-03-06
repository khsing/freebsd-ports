# Created by: ijliao
# $FreeBSD$

PORTNAME=	help2man
PORTVERSION=	1.43.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	GNU/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically generating simple manual pages from program output

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS

CFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USES=		gmake perl5

INFO=		${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/help2man.1.gz

LANGS=		de el eo fi fr hr it pl pt_BR ru sr sv uk vi
LANGS_MTREE=	ja	# languages that already exist in BSD.local.dist

NLS_BUILD_DEPENDS=	p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext
NLS_CFLAGS=		-lintl
NLS_CONFIGURE_ENABLE=	nls
NLS_PLIST_FILES=	lib/bindtextdomain.so
NLS_RUN_DEPENDS=	p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext
NLS_USES=		gettext

.for lang in ${LANGS} ${LANGS_MTREE}
NLS_PLIST_FILES+=	man/${lang}/man1/help2man.1.gz \
			share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.for lang in ${LANGS}
NLS_PLIST_DIRSTRY+=	man/${lang}/man1 \
			man/${lang}
.endfor

.include <bsd.port.options.mk>

# Add temporary note of build failure caused by Perl infrastructure change in 20130612
.if ${PORT_OPTIONS:MNLS}
CONFIGURE_FAIL_MESSAGE=	Please read UPDATING entry 20130612 \(http://svnweb.freebsd.org/ports/head/UPDATING\?r1=320405\&r2=32067\) and PR/184276 \(http://www.freebsd.org/cgi/query-pr.cgi\?pr=ports/184276\) to fix your Perl installation if you got the error message \"configure: error: perl module Locale::gettext required\".
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^pkglibdir/ s|/${PORTNAME}$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
