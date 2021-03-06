# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	k3b
PORTVERSION=	2.0.2
PORTREVISION=	15
CATEGORIES=	sysutils multimedia kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE CD/DVD writing suite

LIB_DEPENDS=	libcdda_paranoia.so:${PORTSDIR}/audio/cdparanoia \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools
BUILD_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools

USE_BZIP2=	yes
USES=		cmake shared-mime-info
CMAKE_ARGS=	-DK3B_BUILD_K3BSETUP:BOOL=OFF \
		-DK3B_ENABLE_MUSICBRAINZ:BOOL=OFF
USE_KDE4=	automoc4 kdeprefix kdelibs libkcddb
USE_QT4=	gui phonon qt3support webkit \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	CDRDAO DVDPLUSRW EMOVIX VCDIMAGER FFMPEG FLAC MAD \
		MUSEPACK SNDFILE VORBIS_DEC LAME SOX VORBIS_ENC \
		LIBDVDREAD NORMALIZE TAGLIB TRANSCODE
OPTIONS_DEFAULT=CDRDAO DVDPLUSRW FFMPEG FLAC MAD SNDFILE \
		VORBIS_DEC VORBIS_ENC LIBDVDREAD TAGLIB
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes # FFMPEG FLAC MAD MUSEPACK SNDFILE VORBIS_ENC VORBIS_DEC LIBDVDREAD TAGLIB

CDRDAO_DESC=		Burning: cdrdao
CDRDAO_RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

DVDPLUSRW_DESC=		Burning: DVD+RW Tools (DVD+/-R(W))
DVDPLUSRW_RUN_DEPENDS=	dvd+rw-format:${PORTSDIR}/sysutils/dvd+rw-tools

EMOVIX_DESC=		Burning: eMovix (bootable video CDs)
EMOVIX_RUN_DEPENDS=	mkmovixiso:${PORTSDIR}/multimedia/emovix

VCDIMAGER_DESC=		Burning: VCDImager (video CDs)
VCDIMAGER_RUN_DEPENDS=	vcdxrip:${PORTSDIR}/multimedia/vcdimager

FFMPEG_DESC=		Decoder: various (multimedia/ffmpeg)
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CMAKE_OFF=	-DK3B_BUILD_FFMPEG_DECODER_PLUGIN:BOOL=OFF

FLAC_DESC=		Decoder: FLAC (audio/flac)
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CMAKE_OFF=		-DK3B_BUILD_FLAC_DECODER_PLUGIN:BOOL=OFF

MAD_DESC=		Decoder: MP3 (audio/libmad)
MAD_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad
MAD_CMAKE_OFF=		-DK3B_BUILD_MAD_DECODER_PLUGIN:BOOL=OFF

MUSEPACK_DESC=		Decoder: Musepack (audio/musepack)
MUSEPACK_LIB_DEPENDS=	libmpcdec.so:${PORTSDIR}/audio/musepack
MUSEPACK_CMAKE_ON=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
MUSEPACK_CMAKE_OFF=	-DK3B_BUILD_MUSE_DECODER_PLUGIN:BOOL=OFF

SNDFILE_DESC=		Decoder: various (audio/libsndfile)
SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile
SNDFILE_CMAKE_ARGS=	-DK3B_BUILD_SNDFILE_DECODER_PLUGIN:BOOL=OFF

VORBIS_DEC_DESC=	Decoder: Ogg Vorbis
VORBIS_DEC_LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg
VORBIS_DEC_CMAKE_OFF=	-DK3B_BUILD_OGGVORBIS_DECODER_PLUGIN:BOOL=OFF

LAME_DESC=		Encoder: MP3 (audio/lame)
LAME_LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame
LAME_CMAKE_OFF=		-DK3B_BUILD_LAME_ENCODER_PLUGIN:BOOL=OFF

SOX_DESC=		Encoder: various (audio/sox)
SOX_RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox
SOX_CMAKE_OFF=		-DK3B_BUILD_SOX_ENCODER_PLUGIN:BOOL=OFF

VORBIS_ENC_DESC=	Encoder: Ogg Vorbis
VORBIS_ENC_LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg
VORBIS_ENC_CMAKE_OFF=	-DK3B_BUILD_OGGVORBIS_ENCODER_PLUGIN:BOOL=OFF

LIBDVDREAD_DESC=	Misc: libdvdread (video DVD ripping)
LIBDVDREAD_LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread
LIBDVDREAD_CMAKE_OFF=	-DK3B_ENABLE_DVD_RIPPING:BOOL=OFF

NORMALIZE_DESC=		Misc: normalize (adjust audio to a std. level)
NORMALIZE_RUN_DEPENDS=	normalize:${PORTSDIR}/audio/normalize

TAGLIB_DESC=		Misc: TagLib (reading/writing audio metadata)
TAGLIB_LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
TAGLIB_CMAKE_OFF=	-DK3B_ENABLE_TAGLIB:BOOL=OFF

TRANSCODE_DESC=		Misc: Transcode (DVD ripping)
TRANSCODE_RUN_DEPENDS=	transcode:${PORTSDIR}/multimedia/transcode

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMUSEPACK}
BROKEN=		fails to detect Musepack libraries
.endif

.include <bsd.port.mk>
