# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	man
PORTVERSION=	1.1j
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		${MASTER_SITE_PORTS_JP}
DISTNAME=	jp-${PORTNAME}-${PORTVERSION}

PATCH_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/
PATCHFILES=	jp-man-1.1j-ex-20020115.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A manual display command for Japanese (EUC)

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

MAKE_ENV=	GZCAT=${GZCAT} GZIP_CMD="${GZIP_CMD}"

MANLANG=	"" ja
MAN1=		jman.1 jmanpath.1 japropos.1 \
		jwhatis.1 jmakewhatis.1 jcatman.1
MAN8=		jmakewhatis.local.8 jcatman.local.8
MANCOMPRESSED=	yes

NO_STAGE=	yes
post-patch:
.for file in	apropos/apropos.sh catman/catman.perl \
		makewhatis/jmakewhatis.local.man \
		makewhatis/jmakewhatis.local.man.eng \
		makewhatis/makewhatis.local.sh \
		man/locale.c manpath/manpath.config
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/${file}
.endfor

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
