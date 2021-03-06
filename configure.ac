
dnl  Copyright 2005 Red Hat, Inc.
dnl 
dnl  Permission to use, copy, modify, distribute, and sell this software and its
dnl  documentation for any purpose is hereby granted without fee, provided that
dnl  the above copyright notice appear in all copies and that both that
dnl  copyright notice and this permission notice appear in supporting
dnl  documentation, and that the name of Red Hat not be used in
dnl  advertising or publicity pertaining to distribution of the software without
dnl  specific, written prior permission.  Red Hat makes no
dnl  representations about the suitability of this software for any purpose.  It
dnl  is provided "as is" without express or implied warranty.
dnl 
dnl  RED HAT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
dnl  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
dnl  EVENT SHALL RED HAT BE LIABLE FOR ANY SPECIAL, INDIRECT OR
dnl  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
dnl  DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
dnl  TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
dnl  PERFORMANCE OF THIS SOFTWARE.
dnl
dnl Process this file with autoconf to create configure.

# Initialize Autoconf
AC_PREREQ([2.60])
AC_INIT([lbxproxy], [1.0.3],
        [https://bugs.freedesktop.org/enter_bug.cgi?product=xorg], [lbxproxy])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS([config.h])
AC_CANONICAL_HOST

# Initialize Automake
AM_INIT_AUTOMAKE([foreign dist-bzip2])

# Set common system defines for POSIX extensions, such as _GNU_SOURCE
# Must be called before any macros that run the compiler (like
# XORG_DEFAULT_OPTIONS) to avoid autoconf errors.
AC_USE_SYSTEM_EXTENSIONS

# Require X.Org macros 1.8 or later for MAN_SUBSTS set by XORG_MANPAGE_SECTIONS
m4_ifndef([XORG_MACROS_VERSION],
	  [m4_fatal([must install xorg-macros 1.8 or later before running autoconf/autogen])])
XORG_MACROS_VERSION(1.8)
XORG_DEFAULT_OPTIONS

case $host_os in
    linux*|gnu*|*-gnu)
        OS_CFLAGS="-D_XOPEN_SOURCE"
        ;;
    *)
        OS_CFLAGS=
        ;;
esac
AC_SUBST(OS_CFLAGS)

# Checks for pkg-config packages
PKG_CHECK_MODULES(LBXPROXY, xtrans xext lbxutil x11 ice xproxymngproto bigreqsproto)

# Check which version of extension headers are installed
save_CFLAGS="${CFLAGS}"
CFLAGS="${CFLAGS} ${LBXPROXY_CFLAGS}"
AC_CHECK_HEADERS([X11/extensions/lbxproto.h X11/extensions/bigreqsproto.h],
[],[],[
#include <X11/X.h>
#include <X11/Xproto.h>
])
CFLAGS="${save_CFLAGS}"

# Transport selection macro from xtrans.m4
XTRANS_CONNECTION_FLAGS

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
