#include <assert.h>

#include "norcow.h"

bool res;

int main()
{
    res = norcow_init();
    assert(res == true);

    res = norcow_wipe();
    assert(res == true);

    return 0;
}
