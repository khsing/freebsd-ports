# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	10
CATEGORIES=	devel
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/${PORTVERSION}/${LINUX_RPM_ARCH}/ \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/${PORTVERSION}/Fedora/${LINUX_RPM_ARCH}/os/Packages/
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	binutils-2.18.50.0.9-8.fc10.${LINUX_RPM_ARCH}.rpm \
		binutils-devel-2.18.50.0.9-8.fc10.${LINUX_RPM_ARCH}.rpm \
		glibc-devel-2.9-3.${LINUX_RPM_ARCH}.rpm \
		glibc-headers-2.9-3.${LINUX_RPM_ARCH}.rpm \
		gmp-4.2.2-8.fc10.${LINUX_RPM_ARCH}.rpm \
		kernel-headers-2.6.27.41-170.2.117.fc10.${LINUX_RPM_ARCH}.rpm \
		mpfr-2.3.2-1.fc10.${LINUX_RPM_ARCH}.rpm \
		cpp-4.3.2-7.${LINUX_RPM_ARCH}.rpm \
		gcc-4.3.2-7.${LINUX_RPM_ARCH}.rpm \
		gcc-c++-4.3.2-7.${LINUX_RPM_ARCH}.rpm \
		gcc-gfortran-4.3.2-7.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)
MASTER_SITES+=	http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/${PORTVERSION}/SRPMS/ \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/${PORTVERSION}/Fedora/source/SRPMS/
SRC_DISTFILES=	binutils-2.18.50.0.9-8.fc10.src.rpm \
		glibc-2.9-3.src.rpm \
		gmp-4.2.2-8.fc10.src.rpm \
		kernel-2.6.27.5-117.fc10.src.rpm \
		mpfr-2.3.2-1.fc10.src.rpm \
		gcc-4.3.2-7.src.rpm
.endif

MAINTAINER=	jwbacon@tds.net
COMMENT=	Linux compilers and base libraries

# LICENSE=	Various GNU

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
USE_LDCONFIG=	yes

PLIST_SUB+=	NLS=""

.include <bsd.port.mk>
