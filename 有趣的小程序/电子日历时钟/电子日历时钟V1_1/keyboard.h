#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_


typedef struct
{
    unsigned char Value;
    unsigned char State;
    unsigned char lastValue;
} KeyStruct;
enum KeyState {CheckKey,DelayKey,KeyFallEdge,KeyDown,KeyRisEdge};

//°´¼ü¼ì²â
unsigned char key_scan(KeyStruct* KeyNum);
#endif