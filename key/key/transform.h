//
//  transform.h
//  hello
//
//  Created by Win Chua on 2019/12/29.
//  Copyright © 2019 Win Chua. All rights reserved.
//

#ifndef transform_h
#define transform_h

#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>
#include <Events.h>
char * getCharByCodeAndFlag(CGEventFlags flags, CGKeyCode keyCode);
static char* charTable[][8] = {
    {"a","A","C-A","O-A","Cmd-A","A","A","Cmd-A"},
    {"s","S","C-S","O-S","Cmd-S","S","S","Cmd-S"},
    {"d","D","C-D","O-D","Cmd-D","D","D","Cmd-D"},
    {"f","F","C-F","O-F","Cmd-F","F","F","Cmd-F"},
    {"h","H","C-H","O-H","Cmd-H","H","H","Cmd-H"},
    {"g","G","C-G","O-G","Cmd-G","G","G","Cmd-G"},
    {"z","Z","C-Z","O-Z","Cmd-Z","Z","Z","Cmd-Z"},
    {"x","X","C-X","O-X","Cmd-X","X","X","Cmd-X"},
    {"c","C","C-C","O-C","Cmd-C","C","C","Cmd-C"},
    {"v","V","C-V","O-V","Cmd-V","V","V","Cmd-V"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"b","B","C-B","O-B","Cmd-B","B","B","Cmd-B"},
    {"q","Q","C-Q","O-Q","Cmd-Q","Q","Q","Cmd-Q"},
    {"w","W","C-W","O-W","Cmd-W","W","W","Cmd-W"},
    {"e","E","C-E","O-E","Cmd-E","E","E","Cmd-E"},
    {"r","R","C-R","O-R","Cmd-R","R","R","Cmd-R"},
    {"y","Y","C-Y","O-Y","Cmd-Y","Y","Y","Cmd-Y"},
    {"t","T","C-T","O-T","Cmd-T","T","T","Cmd-T"},
    {"1","!","C-1","O-1","Cmd-1","!","1","Cmd-!"},
    {"2","@","C-2","O-2","Cmd-2","@","2","Cmd-@"},
    {"3","#","C-3","O-3","Cmd-3","#","3","Cmd-#"},
    {"4","$","C-4","O-4","Cmd-4","$","4","Cmd-$"},
    {"6","^","C-6","O-6","Cmd-6","^","6","Cmd-^"},
    {"5","%","C-5","O-5","Cmd-5","%","5","Cmd-%"},
    {"=","+","C-=","O-=","Cmd-=","+","=","Cmd-+"},
    {"9","(","C-9","O-9","Cmd-9","(","9","Cmd-("},
    {"7","&","C-7","O-7","Cmd-7","&","7","Cmd-&"},
    {"-","_","C--","O--","Cmd--","_","-","Cmd-_"},
    {"8","*","C-8","O-8","Cmd-8","*","8","Cmd-*"},
    {"0",")","C-0","O-0","Cmd-0",")","0","Cmd-)"},
    {"]","}","C-]","O-]","Cmd-]","}","]","Cmd-}"},
    {"o","O","C-O","O-O","Cmd-O","O","O","Cmd-O"},
    {"u","U","C-U","O-U","Cmd-U","U","U","Cmd-U"},
    {"[","{","C-[","O-[","Cmd-[","{","[","Cmd-{"},
    {"i","I","C-I","O-I","Cmd-I","I","I","Cmd-I"},
    {"p","P","C-P","O-P","Cmd-P","P","P","Cmd-P"},
    {"Enter","S-Enter","C-Enter","O-Enter","Cmd-Enter","Enter","Enter","Cmd-S-Enter"},
    {"l","L","C-L","O-L","Cmd-L","L","L","Cmd-L"},
    {"j","J","C-J","O-J","Cmd-J","J","J","Cmd-J"},
    {"'","\"","C-'","O-'","Cmd-'","\"","'","Cmd-\""},
    {"k","K","C-K","O-K","Cmd-K","K","K","Cmd-K"},
    {";",":","C-;","O-;","Cmd-;",":",";","Cmd-:"},
    {"\\","|","C-\\","O-\\","Cmd-\\","|","\\","Cmd-|"},
    {",","<","C-,","O-,","Cmd-,","<",",","Cmd-,"},
    {"/","?","C-/","O-/","Cmd-/","?","/","Cmd-?"},
    {"n","N","C-N","O-N","Cmd-N","N","N","Cmd-N"},
    {"m","M","C-M","O-M","Cmd-M","M","M","Cmd-M"},
    {".",">","C-.","O-.","Cmd-.",">",".","Cmd->"},
    {"tab","S-tab","C-tab","O-tab","Cmd-tab","tab","tab","Cmd-S-tab"},
    {"Space","S-Space","C-Space","O-Space","Cmd-Space","Space","Space","Cmd-S-Space"},
    {"`","~","C-`","O-`","Cmd-`","~","`","Cmd-~"},
    {"Del","S-Del","C-Del","O-Del","Cmd-Del","Del","Del","Cmd-S-Del"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"Esc","S-Esc","C-Esc","O-Esc","Cmd-Esc","Esc","Esc","Cmd-S-Esc"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"unkown","unkown","unkown","unkown","unkown","unkown","unkown","unkown"},
    {"<-","S-<-","C-<-","O-<-","Cmd-<-","<-","<-","Cmd-S-<-"},
    {">-","S->-","C->-","O->-","Cmd->-",">-",">-","Cmd-S->-"},
    {"<>","S-<>","C-<>","O-<>","Cmd-<>","<>","<>","Cmd-S-<>"},
    {"-^","S-^","C-^","O-^","Cmd-^","-^","-^","Cmd-S-^"},
    
};


#endif /* transform_h */
