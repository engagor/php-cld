#include "php_cld.h"

PHP_MINIT_FUNCTION(cld) {
    return SUCCESS;
}

zend_module_entry cld_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_CLD_EXTNAME,
    NULL,                  /* Functions */
    PHP_MINIT(cld),
    NULL,                  /* MSHUTDOWN */
    NULL,                  /* RINIT */
    NULL,                  /* RSHUTDOWN */
    NULL,                  /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_CLD_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
 
#ifdef COMPILE_DL_CLD
extern "C" {
ZEND_GET_MODULE(cld)
}
#endif
