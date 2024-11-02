#ifndef types_h_INCLUDED
#define types_h_INCLUDED

#include <stdint.h>

#define String char*

#if UINTPTR_MAX == UINT64_MAX

    #define Word uint64_t
    #define S_Word int64_t
    #define WordSize sizeof(Word)

    #define DWord struct { Word high; Word low; }
    #define S_DWord struct { S_Word high; Word low; }
    #define DWordSize sizeof(DWord)

    #define HWord uint32_t
    #define S_HWord int32_t
    #define HWordSize sizeof(HWord)

#elif UINTPTR_MAX == UINT32_MAX

    #define DWord uint64_t
    #define S_DWord int64_t
    #define DWordSize sizeof(DWord)

    #define Word uint32_t
    #define S_Word int32_t
    #define WordSize sizeof(Word)

    #define HWord uint16_t
    #define S_HWord int16_t
    #define HWordSize sizeof(HWord)

#elif UINTPTR_MAX == UINT16_MAX

    #define DWord uint32_t
    #define S_DWord int32_t
    #define DWordSize sizeof(DWord)

    #define Word uint16_t
    #define S_Word int16_t
    #define WordSize sizeof(Word)

    #define HWord uint8_t
    #define S_HWord int8_t
    #define HWordSize sizeof(HWord)

#else
    #error "Unsupported architecture, ptr size isn't 16/32/64 bits"
#endif

#define Byte uint8_t
#define S_Byte int8_t
#define ByteSize sizeof(Byte)

#endif // types_h_INCLUDED
