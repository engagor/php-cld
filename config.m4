dnl $Id$
dnl config.m4 for extension cld

PHP_ARG_WITH(cld, for cld support,
[  --with-cld             Include cld support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(cld, whether to enable cld support,
dnl Make sure that the comment is aligned:
dnl [  --enable-cld           Enable cld support])

if test "$PHP_CLD" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-cld -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/cld.h"  # you most likely want to change this
  dnl if test -r $PHP_CLD/$SEARCH_FOR; then # path given as parameter
  dnl   CLD_DIR=$PHP_CLD
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for cld files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       CLD_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$CLD_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the cld distribution])
  dnl fi

  PHP_ADD_INCLUDE($CLD_DIR/include)

  LIBNAME=cld # you may want to change this
  LIBSYMBOL=cld # you most likely want to change this 

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $CLD_DIR/$PHP_LIBDIR, CLD_SHARED_LIBADD)
    AC_DEFINE(HAVE_CLDLIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong cld lib version or lib not found])
  ],[
    -L$CLD_DIR/$PHP_LIBDIR -lm
  ])
  
  PHP_SUBST(CLD_SHARED_LIBADD)

  PHP_NEW_EXTENSION(cld, cld.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
