# $NetBSD$

DISTNAME=	pkg-2.6.2
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeBSD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.freebsd.org/pkg
COMMENT=	Package management tool for FreeBSD
LICENSE=	2-clause-bsd

#USE_CWRAPPERS=	no
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

HAS_CONFIGURE=	yes
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure
CONFIGURE_ARGS+=	--with-libarchive.pc
CONFIGURE_ARGS+=	--with-libcurl
CONFIGURE_ARGS+=	--with-openssl.pc

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
