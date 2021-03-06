# Created by: Pedro Giffuni S.
# $FreeBSD$

PORTNAME=	bihar
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	NL
DISTFILES=	dbihar.f dbipl.f  dbiplr.f dbisld.f dbislf.f dbmult.f dbplrm.f	\
	dcfftb.f dcfftf.f dcffti.f dcftb1.f dcftf1.f dcfti1.f dcmult.f	\
	dconju.f dcosqb.f dcosqf.f dcosqi.f dcost.f  dcosti.f dcsqb1.f	\
	dcsqf1.f defft1.f defftb.f defftf.f deffti.f dftrnx.f dftrny.f	\
	dhzeri.f dhzero.f dlmult.f dlplrm.f dmatge.f dpentf.f dpmult.f	\
	dpplrm.f dpreco.f dpssb.f  dpssb2.f dpssb3.f dpssb4.f dpssb5.f	\
	dpssf.f  dpssf2.f dpssf3.f dpssf4.f dpssf5.f dradb2.f dradb3.f	\
	dradb4.f dradb5.f dradbg.f dradf2.f dradf3.f dradf4.f dradf5.f	\
	dradfg.f drfftb.f drfftf.f drffti.f drftb1.f drftf1.f drfti1.f	\
	dsinqb.f dsinqf.f dsinqi.f dsint.f  dsinti.f dstart.f dtrigi.f	\
	dupdat.f sbihar.f sbipl.f  sbiplr.f sbisld.f sbislf.f sbmult.f	\
	sbplrm.f scfftb.f scfftf.f scffti.f scftb1.f scftf1.f scfti1.f	\
	scmult.f sconju.f scosqb.f scosqf.f scosqi.f scost.f  scosti.f 	\
	scsqb1.f scsqf1.f sefft1.f sefftb.f sefftf.f seffti.f sftrnx.f	\
	sftrny.f shzeri.f shzero.f slmult.f slplrm.f smatge.f spentf.f	\
	spmult.f spplrm.f spreco.f spssb.f  spssb2.f spssb3.f spssb4.f	\
	spssb5.f spssf.f  spssf2.f spssf3.f spssf4.f spssf5.f sradb2.f	\
	sradb3.f sradb4.f sradb5.f sradbg.f sradf2.f sradf3.f sradf4.f	\
	sradf5.f sradfg.f srfftb.f srfftf.f srffti.f srftb1.f srftf1.f	\
	srfti1.f ssinqb.f ssinqf.f ssinqi.f ssint.f  ssinti.f sstart.f	\
	strigi.f supdat.f
.if !defined(NOPORTDOCS)
DISTFILES+=	fft.doc
.endif
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Biharmonic equation in rectangular geometry and polar coordinates

LIB_DEPENDS=	linpack.3:${PORTSDIR}/math/linpack

NO_STAGE=	yes
NO_WRKSUBDIR=	yes
USE_LDCONFIG=	yes
USES=		fortran

.if !defined(NOPORTDOCS)
PORTDOCS=	fft.doc

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/fft.doc ${DOCSDIR}

.endif

post-extract:
	@(cd ${_DISTDIR}; ${CP} ${DISTFILES} ${WRKSRC})

pre-build:
	@${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

.include <bsd.port.mk>
