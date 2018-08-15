#include <stdbool.h>

#ifndef __CALC_H_
#define __CALC_H_

#define NUMBER '0'
#define STRING '1'

#define VAR_LAST_PRINTED "lp"

char getch();
void ungetch(char c);

void push(double val);
double pop();
double peek();

int getop(char s[]);

bool isset(char var);
double getvar(char var);
void setvar(char var, double val);
void printVal(double val);
double getLastPrintedVal();

#endif
