# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PKGNAMEPREFIX=	bmp-

COMMENT=	Beep-media-player plugin for playing .nsf and .hes audio files

LICENSE=	GPLv2

MASTERDIR=	${.CURDIR}/../festalon

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-06

LIB_DEPENDS=	libbeep.so:${PORTSDIR}/multimedia/beep-media-player

CONFIGURE_ARGS+=	--enable-interface=bmp

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PLIST_FILES=	lib/bmp/Input/libfestalon_bmp.a \
		lib/bmp/Input/libfestalon_bmp.la \
		lib/bmp/Input/libfestalon_bmp.so \
		lib/bmp/Input/libfestalon_bmp.so.0

.include "${MASTERDIR}/Makefile"
