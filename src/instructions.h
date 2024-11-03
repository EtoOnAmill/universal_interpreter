#pragma once
#ifndef instructions_h_INCLUDED
#define instructions_h_INCLUDED

#include <string.h>
#include "types.h"

typedef struct {
    Byte high : 4;
    Byte low : 4;
} Byte_hl;

Byte_hl split(Byte b);

#endif // instructions_h_INCLUDED
