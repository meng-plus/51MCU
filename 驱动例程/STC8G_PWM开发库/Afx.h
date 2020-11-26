#ifndef  __AFX_H_
#define  __AFX_H_

#define MCU_ID 0x39
#define FRAME_TIME 0x03 

#ifndef uint16_t
typedef signed char        int8_t;
//typedef short              int16_t;
typedef int                int16_t;
typedef long               int32_t;
typedef unsigned char      uint8_t;
//typedef unsigned short     uint16_t;
typedef unsigned int       uint16_t;
typedef unsigned long      uint32_t;
#endif // !uint16_t

#endif
