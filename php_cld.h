#ifndef PHP_CLD_H
#define PHP_CLD_H

#define PHP_CLD_EXTNAME "cld"
#define PHP_CLD_VERSION "0.1.0"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

extern "C" {
#include "php.h"
}

extern zend_module_entry cld_module_entry;
#define phpext_cld_ptr &cld_module_entry

#endif	/* PHP_CLD_H */
