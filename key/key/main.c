// alterkeys.c
// http://osxbook.com
//
// Complile using the following command line:
//     gcc -Wall -o alterkeys alterkeys.c -framework ApplicationServices
//
// You need superuser privileges to create the event tap, unless accessibility
// is enabled. To do so, select the "Enable access for assistive devices"
// checkbox in the Universal Access system preference pane.

#include <ApplicationServices/ApplicationServices.h>
#include <Events.h>
#include "transform.h"
#include "charTable.h"


// This callback will be invoked every time there is a keystroke.
//
char * getCharOfFlag(CGEventFlags f) {
    if ( f == kCGEventFlagMaskAlphaShift ) { return "kCGEventFlagMaskAlphaShift";}
    else if ( f == kCGEventFlagMaskShift ) { return "kCGEventFlagMaskShift";}
    else if ( f == kCGEventFlagMaskControl ) { return "kCGEventFlagMaskControl";}
    else if ( f == kCGEventFlagMaskAlternate ) { return "kCGEventFlagMaskAlternate";}
    else if ( f == kCGEventFlagMaskCommand ) { return "kCGEventFlagMaskCommand";}
    else if ( f == kCGEventFlagMaskHelp ) { return "kCGEventFlagMaskHelp";}
    else if ( f == kCGEventFlagMaskSecondaryFn ) { return "kCGEventFlagMaskSecondaryFn";}
    else if ( f == kCGEventFlagMaskNumericPad ) { return "kCGEventFlagMaskNumericPad";}
    else if ( f == kCGEventFlagMaskNonCoalesced ) { return "kCGEventFlagMaskNonCoalesced";}
    return "unkown flag";
}

void showTheFlag(CGEventFlags flag) {
    static CGEventFlags allFlags[] = {
        kCGEventFlagMaskAlphaShift,
        kCGEventFlagMaskShift,
        kCGEventFlagMaskControl,
        kCGEventFlagMaskAlternate,
        kCGEventFlagMaskCommand,
        kCGEventFlagMaskHelp,
        kCGEventFlagMaskSecondaryFn,
        kCGEventFlagMaskNumericPad,
        kCGEventFlagMaskNonCoalesced
    };
    int flagsSize = sizeof(allFlags) / sizeof(CGEventFlags);
    for(int i=0; i < flagsSize ; ++i) {
        if ( flag & allFlags[i] ) {
            printf("i:(%d), %s is in.\n", i, getCharOfFlag(allFlags[i]));
        }
    }
}

void allKeyCode() {
    //CGKeyCode a = kVK_ANSI_A;
    
}

CGEventRef
myCGEventCallback(CGEventTapProxy proxy, CGEventType type,
                  CGEventRef event, void *refcon)
{
    int period = 60;
    // Paranoid sanity check.
    //if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp))
    //    return event;
    time_t now = time(NULL);
    static time_t lastRecordTime = 0;
    if (lastRecordTime == 0) {
        lastRecordTime = now - now % period;
    }
    if (type != kCGEventKeyDown)
        return event;
    // The incoming keycode.
    CGKeyCode keycode = (CGKeyCode)CGEventGetIntegerValueField(
                                                               event, kCGKeyboardEventKeycode);
    
    CGEventFlags flags = CGEventGetFlags(event);

    char * charOfKeyCode = getCharByCodeAndFlag(flags, keycode);
//    incrStat(charOfKeyCode);
//    outputStat();
//    clearStat();
    printf("one loop\n");
    if (now - lastRecordTime >= period) {
        printf("data is record. timestamp is %ld\n", lastRecordTime);
        outputStat(stdout, lastRecordTime);
        clearStat();
        lastRecordTime = now - now % period;
    }
    incrStat(charOfKeyCode);
    
    //showTheFlag(flags);
    // Swap 'a' (keycode=0) and 'z' (keycode=6).
//    if (keycode == (CGKeyCode)0)
//        keycode = (CGKeyCode)6;
//    else if (keycode == (CGKeyCode)6)
//        keycode = (CGKeyCode)0;
    //printf("the code is %d\n", keycode);
    // Set the modified keycode field in the event.
    //CGEventSetIntegerValueField(
    //                            event, kCGKeyboardEventKeycode, (int64_t)keycode);
    //printf("trans is %s ok \n", getCharByCodeAndFlag(flags, keycode));
    // We must return the event for it to be useful.
    return event;
}

int
main(void)
{
    CFMachPortRef      eventTap;
    CGEventMask        eventMask;
    CFRunLoopSourceRef runLoopSource;
    printf("Start\n");
    // Create an event tap. We are interested in key presses.
    eventMask = ((1 << kCGEventKeyDown) | (1 << kCGEventKeyUp));
    eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0,
                                eventMask, myCGEventCallback, NULL);
    if (!eventTap) {
        perror("Couldn't open event:");
        fprintf(stderr, "failed to create event tap\n");
        exit(1);
    }
    printf("Create Loop\n");
    // Create a run loop source.
    runLoopSource = CFMachPortCreateRunLoopSource(
                                                  kCFAllocatorDefault, eventTap, 0);

    // Add to the current run loop.
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource,
                       kCFRunLoopCommonModes);

    // Enable the event tap.
    CGEventTapEnable(eventTap, true);

    // Set it all running.
    CFRunLoopRun();

    // In a real program, one would have arranged for cleaning up.

    exit(0);
}
