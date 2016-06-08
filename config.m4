PHP_ARG_WITH(cld, for cld support,
[  --with-cld             Include cld support])

if test "$PHP_CLD" != "no"; then
  PHP_REQUIRE_CXX()
  PHP_ADD_INCLUDE(../cld/)
  PHP_ADD_LIBRARY_WITH_PATH(cld, ../cld/.libs, CLD_SHARED_LIBADD)
  PHP_SUBST(CLD_SHARED_LIBADD)
  PHP_NEW_EXTENSION(
    cld,
    cld.cc,
    $ext_shared,,
    -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -DCLD_WINDOWS)
fi
