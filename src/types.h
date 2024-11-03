#ifndef types_h_INCLUDED
#define types_h_INCLUDED

#include <stdint.h>

#define String char*

enum exit_value {
    NO_ERROR,
    NO_PROGRAM,
    INVALID_PROGRAM_PATH,
    HOW
};

#if UINTPTR_MAX == UINT64_MAX

    typedef uint64_t Word;
    typedef int64_t S_Word;
    #define WordSize sizeof(Word)

    typedef struct { Word high; Word low; } DWord;
    typedef struct { S_Word high; Word low; } S_DWord;
    #define DWordSize sizeof(DWord)

    typedef uint32_t HWord;
    typedef int32_t S_HWord;
    #define HWordSize sizeof(HWord)

#elif UINTPTR_MAX == UINT32_MAX

    typedef uint64_t DWord;
    typedef int64_t S_DWord;
    #define DWordSize sizeof(DWord)

    typedef uint32_t Word;
    typedef int32_t S_Word;
    #define WordSize sizeof(Word)

    typedef uint16_t HWord;
    typedef int16_t S_HWord;
    #define HWordSize sizeof(HWord)

#elif UINTPTR_MAX == UINT16_MAX

    typedef uint32_t DWord;
    typedef int32_t S_DWord;
    #define DWordSize sizeof(DWord)

    typedef uint16_t Word;
    typedef int16_t S_Word;
    #define WordSize sizeof(Word)

    typedef uint8_t HWord;
    typedef int8_t S_HWord;
    #define HWordSize sizeof(HWord)

#else
    #error "Unsupported architecture, ptr size isn't 16/32/64 bits"
#endif

typedef uint8_t Byte;
typedef int8_t S_Byte;
#define ByteSize sizeof(Byte)

#endif // types_h_INCLUDED
