# Created by: erikhb@bgnett.no
# $FreeBSD$

PORTNAME=	libiodbc
PORTVERSION=	3.52.8
CATEGORIES=	databases
MASTER_SITES=	SF/iodbc/iodbc/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	ODBC 3.x driver manager, for universal data source access

LICENSE=		BSD3CLAUSE LGPL20
LICENSE_COMB=		dual
LICENSE_FILE_BSD=	${WRKSRC}/LICENSE.BSD
LICENSE_FILE_LGPL20=	${WRKSRC}/LICENSE.LGPL

CONFLICTS=	unixODBC-[0-9]*

USES=		libtool:oldver pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-iodbc-inidir=${ETCDIR}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GTK2 DOCS EXAMPLES
OPTIONS_SUB=	yes

GTK2_USE=	GNOME=gtk20
GTK2_CONFIGURE_ENABLE=	gui

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|samples||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl||g' ${WRKSRC}/admin/libiodbc.pc.in

post-install:
	@${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/odbc*.ini.sample ${STAGEDIR}/${ETCDIR}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in Makefile.sample iodbctest.c
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
