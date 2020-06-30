#include "mnemon.h"

struct mnemon_desc_32 mnemon_tab_32[] = {
    MNEMON_DESC_32(BAADF00D),
    MNEMON_DESC_32(CAFEBABE),
    MNEMON_DESC_32(CAFED00D),
    MNEMON_DESC_32(DEADBEEF),
    MNEMON_DESC_32_NULL
};

struct mnemon_desc_64 mnemon_tab_64[] = {
    MNEMON_DESC_64(BADC0FFEE0DDF00D),
    MNEMON_DESC_64_NULL
};

const char *mnemon_lookup_32(uint32_t value) {
    for (struct mnemon_desc_32 *it = mnemon_tab_32;
         it->name;
         it += 1) {
        if (it->value == value) {
            return it->name;
        }
    }

    return NULL;
}

const char *mnemon_lookup_64(uint64_t value) {
    for (struct mnemon_desc_64 *it = mnemon_tab_64;
         it->name;
         it += 1) {
        if (it->value == value) {
            return it->name;
        }
    }

    return NULL;
}

const char *mnemon_lookup_ptr(void *value) {
    uintptr_t value_uint = (uintptr_t) value;
    const char *result;

    if (sizeof(uintptr_t) >= sizeof(uint64_t)) {
        result = mnemon_lookup_64((uint64_t) value_uint);
        if (result) return result;
    }

    if (sizeof(uintptr_t) >= sizeof(uint32_t)) {
        result = mnemon_lookup_32((uint32_t) value_uint);
        if (result) return result;
    }

    return NULL;
}
