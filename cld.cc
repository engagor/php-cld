#include "php_cld.h"

#include "encodings/compact_lang_det/compact_lang_det.h"
#include "encodings/compact_lang_det/ext_lang_enc.h"
#include "encodings/compact_lang_det/unittest_data.h"
#include "encodings/proto/encodings.pb.h"

PHP_MINIT_FUNCTION(cld) {
    return SUCCESS;
}

static PHP_FUNCTION(compact_language_detect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_compact_language_detect, 0, 0, 1)
    ZEND_ARG_INFO(0, text)
    ZEND_ARG_INFO(0, is_plain_text)
    ZEND_ARG_INFO(0, tld_hint)
ZEND_END_ARG_INFO()

static const zend_function_entry cld_functions[] = {
    PHP_FE(compact_language_detect, arginfo_compact_language_detect)
    PHP_FE_END
};

zend_module_entry cld_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_CLD_EXTNAME,
    cld_functions,         /* Functions */
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

static PHP_FUNCTION(compact_language_detect) {
    bool do_allow_extended_languages = true;
    bool do_pick_summary_language = false;
    bool do_remove_weak_matches = false;
    bool is_reliable;
    int encoding_hint = UNKNOWN_ENCODING;
    Language language_hint = UNKNOWN_LANGUAGE;

    double normalized_score3[3];
    Language language3[3];
    int percent3[3];
    int text_bytes;

    zend_bool is_plain_text = 0;
    char *str;
    size_t str_len;
    char* tld_hint = NULL;
    size_t tld_hint_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|bs", &str, &str_len, &is_plain_text, &tld_hint, &tld_hint_len) == FAILURE) {
        return;
    }

    if (!str_len) {
        RETURN_NULL();
    }

    Language lang;
    lang = CompactLangDet::DetectLanguage(0,
                                          str, str_len,
                                          is_plain_text,
                                          do_allow_extended_languages,
                                          do_pick_summary_language,
                                          do_remove_weak_matches,
                                          tld_hint,
                                          encoding_hint,
                                          language_hint,
                                          language3,
                                          percent3,
                                          normalized_score3,
                                          &text_bytes,
                                          &is_reliable);

    RETURN_STRING(LanguageName(lang), 1)
}
