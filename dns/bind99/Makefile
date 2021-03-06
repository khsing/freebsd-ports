# $FreeBSD$

PORTNAME=	bind
PORTVERSION=	9.9.5
PORTREVISION=	1
CATEGORIES=	dns net ipv6
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
PKGNAMESUFFIX?=	99
DISTNAME=	${PORTNAME}-${ISCVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64

LICENSE=	ISCL

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.9.5

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--disable-symtable \
		--with-randomdev=/dev/random \
		--without-python
ETCDIR=		${PREFIX}/etc/namedb

CONFLICTS=	bind9*-9.[45678].* bind9*-sdb-9.[45678].* bind-tools-9.*

OPTIONS_DEFAULT=	IPV6 SSL XML THREADS GSSAPI
OPTIONS_DEFINE=		SSL IDN REPLACE_BASE LARGE_FILE \
			FIXED_RRSET SIGCHASE IPV6 THREADS GSSAPI FILTER_AAAA
.if !defined(BIND_TOOLS_SLAVE)
OPTIONS_DEFINE+=	LINKS XML RPZ_NSIP RPZ_NSDNAME RRL DOCS RPZ_PATCH
OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB
.endif	# BIND_TOOLS_SLAVE

SSL_DESC=		Build with OpenSSL (Required for DNSSEC)
REPLACE_BASE_DESC=	Replace base BIND (FreeBSD 9.x and earlier)
LARGE_FILE_DESC=	64-bit file support
FIXED_RRSET_DESC=	Enable fixed rrset ordering
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
FILTER_AAAA_DESC=	Enable filtering of AAAA records

LINKS_DESC=		Create conf file symlinks in ${PREFIX}
XML_DESC=		Support for xml statistics output
RPZ_NSIP_DESC=		Enable RPZ NSIP trigger rules
RPZ_NSDNAME_DESC=	Enable RPZ NSDNAME policy records
RPZ_PATCH_DESC=		RPZ improvements
RRL_DESC=		Response Rate Limiting
DLZ_DESC=		Dynamically Loadable Zones
DLZ_POSTGRESQL_DESC=	DLZ Postgres driver
DLZ_MYSQL_DESC=		DLZ MySQL driver (no threading)
DLZ_BDB_DESC=		DLZ BDB driver
DLZ_LDAP_DESC=		DLZ LDAP driver
DLZ_FILESYSTEM_DESC=	DLZ filesystem driver
DLZ_STUB_DESC=		DLZ stub driver

.if !defined(BIND_TOOLS_SLAVE)
CONFLICTS+=		bind-tools-9.*
.endif	# BIND_TOOLS_SLAVE

SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_USE=		openssl=yes
SSL_CONFIGURE_OFF=	--disable-openssl-version-check --without-openssl

XML_CONFIGURE_ON=	--with-libxml2=${LOCALBASE}
XML_LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
XML_CONFIGURE_OFF=	--without-libxml2

IDN_USES=		iconv
IDN_CONFIGURE_ON=	--with-idn=${LOCALBASE} ${ICONV_CONFIGURE_BASE}
IDN_LIB_DEPENDS=	libidnkit.so:${PORTSDIR}/dns/idnkit
IDN_CONFIGURE_OFF=	--without-idn

LARGE_FILE_CONFIGURE_ENABLE=	largefile

SIGCHASE_CONFIGURE_ON=	STD_CDEFINES="-DDIG_SIGCHASE=1"

IPV6_CONFIGURE_ENABLE=	ipv6

FILTER_AAAA_CONFIGURE_ENABLE=	filter-aaaa

DLZ_POSTGRESQL_CONFIGURE_ON=	--with-dlz-postgres=yes
DLZ_POSTGRESQL_USE=		pgsql=yes

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

RPZ_NSIP_CONFIGURE_ENABLE=	rpz-nsip

RPZ_NSDNAME_CONFIGURE_ENABLE=	rpz-nsdname

RPZ_PATCH_PATCHFILES=	9.9.5-rpz2+rl.14038.05.patch:vix
RPZ_PATCH_PATCH_SITES=	http://ss.vix.su/~vjs/:vix

RRL_CONFIGURE_ENABLE=	rrl

DLZ_MYSQL_CONFIGURE_ON=	--with-dlz-mysql=yes
DLZ_MYSQL_USE=		mysql=yes

DLZ_BDB_CONFIGURE_ON=	--with-dlz-bdb=yes
DLZ_BDB_USE=		bdb=yes

DLZ_LDAP_CONFIGURE_ON=	--with-dlz-ldap=yes
DLZ_LDAP_USE=		openldap=yes

DLZ_FILESYSTEM_CONFIGURE_ON=	--with-dlz-filesystem=yes

DLZ_STUB_CONFIGURE_ON=	--with-dlz-stub=yes

GSSAPI_CONFIGURE_WITH=	gssapi

.include <bsd.port.options.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

.if !${PORT_OPTIONS:MLINKS} || ${PORT_OPTIONS:MREPLACE_BASE}
PKGINSTALL=${NONEXISTENT}
.endif

.if ${PORT_OPTIONS:MTHREADS} && !${PORT_OPTIONS:MDLZ_MYSQL}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if ${PORT_OPTIONS:MGSSAPI}
.if defined(HEIMDAL_HOME)
LDFLAGS+=		-L${LIBDIR} -lgssapi -lkrb5
.else
LDFLAGS+=		-L${LIBDIR} -lgssapi_krb5
.endif
.endif

.if ${PORT_OPTIONS:MREPLACE_BASE}
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
IGNORE=		REPLACE_BASE option is not supported on this release
.endif
PKGNAMESUFFIX=	-base
PREFIX=		/usr
PLIST_SUB+=	SHARE_MAN="share/"
NO_MTREE=	yes
BIND_DESTETC=	/etc/namedb
.else
PLIST_SUB+=	SHARE_MAN=""
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
BIND_DESTETC=	${PREFIX}/etc/namedb
PKGINSTALL=	${NONEXISTENT}
.else
BIND_DESTETC=	${PREFIX}/etc
.endif
.endif

PKGDEINSTALL=	${PKGINSTALL}

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--sysconfdir=${BIND_DESTETC}
PLIST_SUB+=	BIND_DESTETC="${BIND_DESTETC}"

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
PLIST_SUB+=	NOBASE="" BASE="@comment "
.else
PLIST_SUB+=	NOBASE="@comment " BASE=""
.endif

.if !defined(BIND_TOOLS_SLAVE)
post-patch:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${MV} ${WRKSRC}/bin/${FILE} ${WRKSRC}/bin/${FILE}.Dist
	@${SED} -e 's#/etc/named.conf#${BIND_DESTETC}/named.conf#g' \
		-e 's#/etc/rndc.conf#${BIND_DESTETC}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}.Dist > ${WRKSRC}/bin/${FILE}
.endfor
	@${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.Dist
	@${SED} -e 's#.*bind\.keys.*##' ${WRKSRC}/Makefile.in.Dist > \
		${WRKSRC}/Makefile.in
	@${MV} ${WRKSRC}/bin/named/Makefile.in ${WRKSRC}/bin/named/Makefile.in.Dist
	@${SED} -e 's/$${PERL}/#/' -e 's/bind.keys.h/#/g' -e 's/bind9.xsl.h/#/g' \
		${WRKSRC}/bin/named/Makefile.in.Dist > \
		${WRKSRC}/bin/named/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif
post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm ${STAGEDIR}${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* ${STAGEDIR}${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/HISTORY ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
.for FILE in named named.conf
	${SED} -e 's#%%PREFIX%%#${PREFIX}#g' \
		-e 's#%%BIND_DESTETC%%#${BIND_DESTETC}#g' \
		${FILESDIR}/${FILE} > ${WRKDIR}/${FILE}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/named ${STAGEDIR}${PREFIX}/etc/rc.d
	${MKDIR} ${STAGEDIR}${BIND_DESTETC}
.for i in dynamic master slave working
	@${MKDIR} ${STAGEDIR}${BIND_DESTETC}/$i
.endfor
	${INSTALL_DATA} ${WRKDIR}/named.conf ${STAGEDIR}${BIND_DESTETC}/named.conf.sample
	${INSTALL_DATA} ${FILESDIR}/named.root ${STAGEDIR}${BIND_DESTETC}
	${INSTALL_DATA} ${FILESDIR}/empty.db ${STAGEDIR}${BIND_DESTETC}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-forward.db ${STAGEDIR}${BIND_DESTETC}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-reverse.db ${STAGEDIR}${BIND_DESTETC}/master
.endif
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${STAGEDIR}${BIND_DESTETC}/rndc.conf.sample

.endif	# BIND_TOOLS_SLAVE

.include <bsd.port.mk>
