// Guard Code + Pre-Processor Directives
#ifndef Header_h
#define Header_h
#define _CRT_SECURE_NO_WARNINGS
#define MaxNumOperators 2 // maximum # of operators for level1 function
#define MaxFileLinesLength 1000 // maximum # lines in file
#define NumOfLines4 106 // amount of level 4 file equations
#define NumOfLines5 98 // amount of level 5 file equations

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structs + Function Decleration (using long long data types for memory reasons, learned this from my step-dad)
typedef struct profile
{
	long long score;
	long long correct;
	long long incorrect;
	char name[4]; // 4 for null char
}Profile;

// Regular Functions
void menu(void);
void how_to_play(void);
void help_examples(void);
void run_intro(Profile* p1);
void stats(Profile* p1);
void save_stats(Profile* p1, const char* infile);
void load_stats(Profile* p1, const char* infile);
void setname(Profile* p1);
void achievements(Profile* p1);

// Level functions
void level1(Profile* p1);
void level2(Profile* p1);
void level3(Profile* p1);
void level4(FILE* outfile, Profile* p1);
void level5(FILE* outfile, Profile* p1);

// End of Guard Code
#endif
