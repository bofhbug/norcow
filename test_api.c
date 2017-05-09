#include "norcow.h"

#define VALLEN 128

uint8_t val[128];
uint16_t vallen;
bool res;

int main()
{
    res = norcow_init();
    res = norcow_wipe();
    res = norcow_set(0x1234, val, VALLEN);
    res = norcow_get(0x1234, (const void **)&val, &vallen);
    return 0;
}
