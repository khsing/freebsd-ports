# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-finespectrum
PORTVERSION=	1.0.1.a
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/finespectrum/finespectrum/1.0.1alpha
DISTNAME=	finespectrum-1.0.1alpha

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fine grain Spectrum analyzers for XMMS

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-23

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libfinespectrum.so
USES=		gmake
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/finespectrum-1.0.1alpha

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
