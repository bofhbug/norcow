#include <assert.h>
#include <stdarg.h>
#include <stdint.h>

#include "norcow.h"

void assert_content(const void *data, ...)
{
    va_list va;
    va_start(va, data);
    uint32_t len, pos;
    uint8_t byte;
    for (;;) {
       len = va_arg(va, uint32_t);
       byte = va_arg(va, uint32_t);
       if (!len) {
           break;
       }
       // compare len/byte area
       (void)len;
       (void)byte;
       (void)pos;
    }
    va_end(va);
}

bool res;

int main()
{
    res = norcow_init();
    assert(res == true);

    res = norcow_wipe();
    assert(res == true);

    return 0;
}
