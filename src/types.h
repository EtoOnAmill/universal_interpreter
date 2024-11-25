#ifndef types_h_INCLUDED
#define types_h_INCLUDED

#include <stdint.h>

#if UINTPTR_MAX == UINT64_MAX

    typedef uint64_t Ptr;
    typedef int64_t S_Ptr;
    #define PtrSize sizeof(Ptr)

    typedef struct { Ptr high; Ptr low; } DPtr;
    typedef struct { S_Ptr high; Ptr low; } S_DPtr;
    #define DPtrSize sizeof(DPtr)

    typedef uint32_t HPtr;
    typedef int32_t S_HPtr;
    #define HPtrSize sizeof(HPtr)

#elif UINTPTR_MAX == UINT32_MAX

    typedef uint64_t DPtr;
    typedef int64_t S_DPtr;
    #define DPtrSize sizeof(DPtr)

    typedef uint32_t Ptr;
    typedef int32_t S_Ptr;
    #define PtrSize sizeof(Ptr)

    typedef uint16_t HPtr;
    typedef int16_t S_HPtr;
    #define HPtrSize sizeof(HPtr)

#elif UINTPTR_MAX == UINT16_MAX

    typedef uint32_t DPtr;
    typedef int32_t S_DPtr;
    #define DPtrSize sizeof(DPtr)

    typedef uint16_t Ptr;
    typedef int16_t S_Ptr;
    #define PtrSize sizeof(Ptr)

    typedef uint8_t HPtr;
    typedef int8_t S_HPtr;
    #define HPtrSize sizeof(HPtr)

#else
    #error "Unsupported architecture, ptr size isn't 16/32/64 bits"
#endif

typedef uint8_t Byte;
typedef int8_t S_Byte;
#define ByteSize sizeof(Byte)
typedef uint16_t HWord;
typedef int16_t S_HWord;
#define HWordSize sizeof(HWord)
typedef uint32_t Word;
typedef int32_t S_Word;
#define WordSize sizeof(Word)
typedef uint64_t DWord;
typedef int64_t S_DWord;
#define DWordSize sizeof(DWord)

#endif // types_h_INCLUDED
