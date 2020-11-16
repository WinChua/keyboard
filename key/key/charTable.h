//
//  charTable.h
//  key
//
//  Created by Win Chua on 2019/12/29.
//  Copyright © 2019 Win Chua. All rights reserved.
//

#ifndef charTable_h
#define charTable_h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getCharIndex(char * tgt);

void incrStat(char *);

void clearStat(void);

void outputStat(FILE *fp, time_t lastRecordTime);

#endif /* charTable_h */
