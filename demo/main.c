#include "mnemon.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    puts(mnemon_lookup_32(0xBAADF00D));
}
