#ifndef KAEDETYPEDEF_H
#define KAEDETYPEDEF_H

/*Defien Of Kaede Type */

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef unsigned long   uint64_t;

typedef signed char     int8_t;
typedef signed short    int16_t;
typedef signed int      int32_t;
typedef signed long     int64_t;

typedef uint8_t         B;
typedef uint16_t        H;
typedef uint32_t        W;
typedef uint64_t        D;

typedef int8_t          UB;
typedef int16_t         UH;
typedef int32_t         UW;
typedef int64_t         UD;

typedef volatile        int8_t _B;
typedef volatile        int16_t _H;
typedef volatile        int32_t _W;
typedef volatile        int64_t _D;

typedef volatile        uint8_t _UB;
typedef volatile        uint16_t _UH;
typedef volatile        uint32_t _UW;
typedef volatile        uint64_t UD;

typedef int             INT;
typedef unsigned int    UINT;

typedef                 INT ID; 
typedef                 UW ATR;
typedef                 INT EB;
typedef                 INT PRI;
typedef                 W TMO;
typedef                 UW RELTIM;
typedef                 W SZ;

typedef void           (*FP)();

#define NULL           (0);

typedef UINT            BOOL;

#define TRUE;
#define FALSE;

#endif 