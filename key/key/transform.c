//
//  transform.c
//  hello
//
//  Created by Win Chua on 2019/12/29.
//  Copyright © 2019 Win Chua. All rights reserved.
//

#include "transform.h"

int transformFlagToIndex(CGEventFlags flags) {
    if (flags & kCGEventFlagMaskControl) return 2;   // <C-?>
    if (flags & kCGEventFlagMaskAlternate) return 3; // <O-?>
    if (flags & kCGEventFlagMaskCommand) {
        if(flags & kCGEventFlagMaskShift) return 7;
        else return 4;   // <
    }
    if (flags & kCGEventFlagMaskShift) {
        if (flags & kCGEventFlagMaskAlphaShift) return 5;
        return 1;
    }
    if (flags & kCGEventFlagMaskAlphaShift) return 6;
    
    return 0;
}
//  每一个keyCode在不同的flag的控制下有不同的表现, 首先将flag转成为表现数组的index
char * getCharByCodeAndFlag(CGEventFlags flags, CGKeyCode keyCode) {
    return charTable[keyCode][transformFlagToIndex(flags)];
    return "unknow now";
}
