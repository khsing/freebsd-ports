# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	cowpatty
PORTVERSION=	4.6
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.willhackforsushi.com/code/cowpatty/${PORTVERSION}/ \
		http://mcx2.org/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Brute-force dictionary attack against WPA-PSK

PORTDOCS=	FAQ README
SUB_FILES=	pkg-message
MAKE_JOBS_UNSAFE=	yes

USE_OPENSSL=	yes

PLIST_FILES=	bin/cowpatty bin/genpmk

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
