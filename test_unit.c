#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "norcow.h"

extern const void *norcow_start_address;

void assert_data(int lineno, const void *data, uint32_t size, ...)
{
    va_list va;
    va_start(va, size);
    uint32_t index = 0, rep, sublen, pos = 0;
    const void *sub;
    for (;;) {
       rep = va_arg(va, uint32_t);
       sublen = va_arg(va, uint32_t);
       sub = va_arg(va, const void *);
       if (!rep || !sublen || !sub) {
           break;
       }
       if (pos + sublen > size) {
           printf("test_unit.exe: %s:%d: assert_data: Overflow #%d", __FILE__, lineno, index);
           exit(1);
       }
       if (0 != memcmp((const uint8_t *)data + pos, (const uint8_t *)sub, sublen)) {
           printf("test_unit.exe: %s:%d: assert_data: Assertion #%d failed at pos %d.\n", __FILE__, lineno, index, pos);
           exit(1);
       }
       pos += sublen;
       index++;
    }
    va_end(va);
}

int main()
{
    bool res;

    res = norcow_init();
    assert(res == true);

    res = norcow_wipe();
    assert(res == true);

    assert_data(__LINE__, norcow_start_address,
        32768, 1, "\xFF",
        0, 0, 0
    );

    res = norcow_set(0x1234, "ABCDEFGHIJ", 10);
    assert(res == true);

    assert_data(__LINE__, norcow_start_address, 32768,
        // first item
        1, 2, "\x34\x12",
        1, 2, "\x0A\x00",
        1, 10, "ABCDEFGHIJ",
        1, 2, "\xFF\xFF",
        // end
        32768 - 16, 1, "\xFF",
        0, 0, 0
    );

    res = norcow_set(0x5678, "KLMNOPQRSTUVWXYZ!", 17);
    assert(res == true);

    assert_data(__LINE__, norcow_start_address, 32768,
        // first item
        1, 2, "\x34\x12",
        1, 2, "\x0A\x00",
        1, 10, "ABCDEFGHIJ",
        1, 2, "\xFF\xFF",
        // second item
        1, 2, "\x78\x56",
        1, 2, "\x11\x00",
        1, 17, "KLMNOPQRSTUVWXYZ!",
        1, 3, "\xFF\xFF\xFF",
        // end
        32768 - 16 - 24, 1, "\xFF",
        0, 0, 0
    );

    res = norcow_set(0xABCD, "1234", 4);
    assert(res == true);

    assert_data(__LINE__, norcow_start_address, 32768,
        // first item
        1, 2, "\x34\x12",
        1, 2, "\x0A\x00",
        1, 10, "ABCDEFGHIJ",
        1, 2, "\xFF\xFF",
        // second item
        1, 2, "\x78\x56",
        1, 2, "\x11\x00",
        1, 17, "KLMNOPQRSTUVWXYZ!",
        1, 3, "\xFF\xFF\xFF",
        // third item
        1, 2, "\xCD\xAB",
        1, 2, "\x04\x00",
        1, 4, "1234",
        // end
        32768 - 16 - 24 - 8, 1, "\xFF",
        0, 0, 0
    );

    return 0;
}
