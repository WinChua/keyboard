#include "charTable.h"

static int stat[308] = {};
static char * cTable[] = {"Cmd-7","y","o",".","Cmd-\\","Cmd-;","O-/","C-F","C-<>","q","O-.","C-C","C","0","Cmd-)","Cmd-S-Enter","8","Cmd-[","C-T","C-V","O-;","O-Y","C->-","C-\\","Cmd-A","Cmd-4","O-`","Cmd-_","_","Cmd-G","O-T","C-Z","Cmd-H","b","{","Cmd-Z","Cmd-N","Cmd-Y","s","C-1","Cmd->-","E","Cmd--","k","a","7","Z","C-tab","G","C-Del","S->-","+","O-4","Space","Cmd-<-","C-S","\\","O-2","Cmd-}","S","O-D","-^","O-^","O-Enter","-","Cmd-S-Esc","Esc","O-M","Cmd-\"","Cmd-V","Cmd-`","C-K","Cmd-:","m","Cmd-~","O-R","Cmd-5","C-H","H","p","O-V","#","O-6","(","O-Esc","Cmd-E","C-M","Cmd-=","O-C","Cmd-2","S-Enter","O-\\","Cmd->","Q","]","O-[","Cmd-*","O-7","Cmd-/","|","C-^","Cmd-L","^","S-tab","O-Space","O-3","Cmd-I","O-S","Cmd-.","C-9","S-^","S-Esc","C-=","Cmd-9","O-]","C-O","x","C-`","e","Cmd-S-<-","Cmd-!","Y","Cmd-1","Cmd-(","C-E","w","Del","C-0","'","f","z",")","[","S-<>","Cmd-P","O-0","=","O-B","Cmd-F","Cmd-J","r","Cmd-3","2","j","Cmd-Del","*","O-=","Cmd-S","9","Cmd-tab","S-Space","Cmd-6","O-U","O-tab","h","Cmd-+","}","V","/","O-H","I","Cmd-|","5","C-J","\"","C-P","<-","Enter","O-5",">-","C-A","C-W","u","C-N","A","$","C-/","!","O-E","v","Cmd-W","O-Del","Cmd-{","C-5","O-X","Cmd-Enter","C-]","O-P","C-Esc","Cmd-%","C-.","C-X",";","Cmd-S-Space","Cmd-0","X","Cmd-K","Cmd-Space","C-6","Cmd-S->-","C-8","C-I","Cmd-U","Cmd-Esc","O-<-","O-A","O","C-,","g","O-N","C-D","4","?","Cmd-?","Cmd-X","C-3","C-;","@","Cmd-B","R","3","6","O->-","D","O-O","O-K","M","C-Y","Cmd-'",",","F","`","Cmd-S-^","d",":","Cmd-C","C-B","C-G","L",">","W","U","C-R","K","O-G","O-Z","S-Del","Cmd-S-tab","O-1","<>","tab","O-<>","<","Cmd-&","Cmd-#","C-'","Cmd-,","Cmd-Q","O-9","N","Cmd-D","O--","P","Cmd-O","Cmd-8","O-L","~","C-Q","Cmd-R","C-Enter","B","n","Cmd-S-Del","O-,","O-Q","&","c","O-'","Cmd-@","t","Cmd-^","Cmd-<>","J","C-4","T","Cmd-$","O-W","O-J","Cmd-M","O-F","%","S-<-","C-7","C-Space","C-<-","C-[","Cmd-]","i","C-L","O-8","Cmd-T","C--","1","C-U","Cmd-S-<>","l","C-2","O-I"};

int getCharIndex(char * tgt) {
    int size = sizeof(cTable) / sizeof(char *);
    for(int i=0; i < size; ++i) {
        if(strcmp(tgt, cTable[i]) == 0) return i;
    }
    return -1;
}

void clearStat() {
    for(int i=0; i<sizeof(stat)/sizeof(int); ++i) {
        stat[i] = 0;
    }
}

int cInStr(char c, char *s) {
    for(int i=0; i< 20; i++) {
        if(s[i] == '\0') return -1;
        if(s[i] == c) return i;
    }
    return -1;
}

void incrStat(char * c) {
    int i = getCharIndex(c);
    if(i == -1) {
        return;
    }
    stat[i] += 1;
}

void insertBSlash(char * src, char * dst, int index) {
    int i=0;
    int j=0;
    while (src[i]!= '\0') {
        if(index == i) {
            dst[j++] = '\\';
        }
        dst[j++] = src[i++];
    }
    dst[j] = '\0';
    return;
}

void outputStat(FILE *fp, time_t lastRecordTime) {
    if(fp == NULL) {
        //printf("Stdout:\n");
        for(int i=0; i<sizeof(stat)/sizeof(int); ++i) {
            if(stat[i] == 0) continue;
            printf("%s hit %d times\n", cTable[i], stat[i]);
        }
        //printf("Stdout:end\n");
    } else {
        //printf("Debug\n");
        char out[4096] = {};
        int bufUsed = 1;
        out[0] = '{';
        for (int i = 0; i < sizeof(stat)/ sizeof(int); ++i) {
            if(stat[i] == 0) continue;
            //printf("%c in %s?: %d\n", '"', cTable[i], cInStr('"', cTable[i]));
            //printf("%c in %s?: %d\n", '\\', cTable[i], cInStr('\\', cTable[i]));
            int indexOfQuote = cInStr('"', cTable[i]);
            int indexOfBSlash = cInStr('\\', cTable[i]);
            if(indexOfQuote != -1) {
                char * key = (char*)malloc(sizeof(cTable[i]) + 2);
                insertBSlash(cTable[i], key, indexOfQuote);
                bufUsed += snprintf(out + bufUsed, sizeof(out) - bufUsed, "\"%s\":%d,", key, stat[i]);
                free(key);
            } else if(indexOfBSlash != -1 ) {
                char * key = (char*)malloc(sizeof(cTable[i]) + 2);
                insertBSlash(cTable[i], key, indexOfBSlash);
                bufUsed += snprintf(out + bufUsed, sizeof(out) - bufUsed, "\"%s\":%d,", key, stat[i]);
                free(key);
            } else {
                bufUsed += snprintf(out + bufUsed, sizeof(out) - bufUsed, "\"%s\":%d,", cTable[i], stat[i]);
            }
        }
        bufUsed += snprintf(out+bufUsed, sizeof(out) - bufUsed, "\"tt\":%ld}", lastRecordTime);
        //out[bufUsed-1] = '}';
        FILE * outFile = fopen("/Users/winchua/.static/result.json", "a");
        if(outFile == NULL) {
            printf("Open File Error:");
            return;
        }
        //printf("%s\n", out);
        fprintf(outFile, "%s\n", out);
        fflush(outFile);
        fclose(outFile);
       
        //printf("DebugEnd\n");
    }
}
