// LP: not sure who originally wrote these cseries files: Bo Lindbergh?
#ifndef _CSERIES_TYPES_
#define _CSERIES_TYPES_

#include <limits.h>

const int NONE = -1;

// Integer types with specific bit size
#if defined(mac)
typedef SInt8 int8;
typedef UInt8 uint8;
typedef SInt16 int16;
typedef UInt16 uint16;
typedef SInt32 int32;
typedef UInt32 uint32;
typedef uint32 TimeType;
#elif defined(__BEOS__)
#include <support/SupportDefs.h>
typedef time_t TimeType;
#elif defined(SDL)
typedef Uint8 uint8;
typedef Sint8 int8;
typedef Uint16 uint16;
typedef Sint16 int16;
typedef Uint32 uint32;
typedef Sint32 int32;
typedef time_t TimeType;
#endif

// Minimum and maximum values for these types
#ifndef INT16_MAX
#define INT16_MAX 32767
#endif
#ifndef INT16_MIN
#define INT16_MIN (-INT16_MAX-1)
#endif
#ifndef INT32_MAX
#define INT32_MAX 2147483647
#endif
#ifndef INT32_MIN
#define INT32_MIN (-INT32_MAX-1)
#endif

// Fixed point (16.16) type
typedef int32 fixed;

#define FIXED_FRACTIONAL_BITS 16
#define INTEGER_TO_FIXED(i) ((fixed)(i)<<FIXED_FRACTIONAL_BITS)
#define FIXED_INTEGERAL_PART(f) ((f)>>FIXED_FRACTIONAL_BITS)

#define FIXED_ONE		(1L<<FIXED_FRACTIONAL_BITS)
#define FIXED_ONE_HALF	(1L<<(FIXED_FRACTIONAL_BITS-1))

// Binary powers
const int MEG = 0x100000;
const int KILO = 0x400L;

// Construct four-character-code
#define FOUR_CHARS_TO_INT(a,b,c,d) (((uint32)(a) << 24) | ((uint32)(b) << 16) | ((uint32)(c) << 8) | (uint32)(d))

// Hmmm, this should be removed one day...
typedef uint8 byte;

// Make it compile on systems without OpenGL
#ifndef HAVE_OPENGL
#define GLfloat float
#endif

#endif
