#ifndef INCLUDE_MNEMON_H
#define INCLUDE_MNEMON_H

#include <stddef.h>
#include <stdint.h>

#define MNEMON_BAADF00D_NAME "Bad food"
#define MNEMON_CAFEBABE_NAME "Cafe babe"
#define MNEMON_CAFED00D_NAME "Cafe dude"
#define MNEMON_DEADBEEF_NAME "Dead beef"
#define MNEMON_BADC0FFEE0DDF00D_NAME "Bad coffee odd food"

struct mnemon_desc_32 {
    uint32_t value;
    const char *name;
};

struct mnemon_desc_64 {
    uint64_t value;
    const char *name;
};

// Require capitalised hexadecimal value
#define MNEMON_NAME(value) MNEMON_ ## value ## _NAME

#define MNEMON_32(value) UINT32_C(0x ## value)
#define MNEMON_DESC_32(value) ((struct mnemon_desc_32) { MNEMON_32(value), MNEMON_NAME(value) })
#define MNEMON_DESC_32_NULL ((struct mnemon_desc_32) { 0, NULL })

#define MNEMON_64(value) UINT64_C(0x ## value)
#define MNEMON_DESC_64(value) ((struct mnemon_desc_64) { MNEMON_64(value), MNEMON_NAME(value) })
#define MNEMON_DESC_64_NULL ((struct mnemon_desc_64) { 0, NULL })

extern struct mnemon_desc_32 mnemon_tab_32[];
extern struct mnemon_desc_64 mnemon_tab_64[];

const char *mnemon_lookup_32(uint32_t value);
const char *mnemon_lookup_64(uint64_t value);

#endif
