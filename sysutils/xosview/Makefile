# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	xosview
PORTVERSION=	1.8.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A graphical performance meter

USE_XORG=	xpm
GNU_CONFIGURE=	yes
MAN1=		xosview.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,iostream.h,iostream,' \
		${WRKSRC}/xwin.h \
		${WRKSRC}/Host.h \
		${WRKSRC}/Xrm.cc \
		${WRKSRC}/llist.cc \
		${WRKSRC}/timeval.h \
		${WRKSRC}/xosview.cc
	@${REINPLACE_CMD} -e 's,string.h,string,' \
		${WRKSRC}/xwin.h \
		${WRKSRC}/Host.cc \
		${WRKSRC}/Xrm.cc \
		${WRKSRC}/llist.cc \
		${WRKSRC}/timeval.h \
		${WRKSRC}/xosview.cc
	@${REINPLACE_CMD} -e 's,fstream.h,fstream,' \
		${WRKSRC}/bitfieldmeter.cc \
		${WRKSRC}/fieldmeter.cc \
		${WRKSRC}/fieldmeterdecay.cc \
		${WRKSRC}/fieldmetergraph.cc
	@${REINPLACE_CMD} -e 's,-O4,,' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/share/man,/man,' \
		${WRKSRC}/config/Makefile.top.in

.include <bsd.port.post.mk>
