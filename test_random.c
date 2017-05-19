#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "norcow.h"

#define MAXVALLEN 1024

uint8_t val[MAXVALLEN], *v;
uint16_t key, vallen, vlen;
bool res;

int main()
{
    srand(time(0));

    norcow_init();

    for (int i = 0; i < 10000; i++) {

        vallen = rand() % (MAXVALLEN + 1);
        for (uint32_t j = 0; j < vallen; j++) {
            val[j] = rand() & 0xFF;
        }

        key = 0x1234 + (rand() % 32);

        printf("#%d key=0x%04x size=%d\n", i, key, vallen);

        res = norcow_set(key, val, vallen);
        if (!res) {
            printf("Write failed (full storage)\n");
            continue;
        }

        res = norcow_get(key, (const void **)&v, &vlen);
        assert(res == 1);

        assert(vlen == vallen);
        assert(0 == memcmp(val, v, vallen));
    }

    return 0;
}
