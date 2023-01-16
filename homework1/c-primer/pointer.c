// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {  // What is the type of argv?
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172";
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print?

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid? A: The array can decay into a pointer

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c;  // What is the type of pcc2? A: It is also a pointer to char const

  // For each of the following, why is the assignment:
//  *pcc = '7';  // invalid? As the value pointed to is constant
  pcc = *pcp;  // valid? The pointer itself can be reasigned
  pcc = argv[0];  // valid? A: Again this decays into a pointer of the first elem.

  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
//  cp = *pcp;  // invalid? A: The pointer is constant so can't be reassigned
//  cp = *argv;  // invalid? A: Same as above
  *cp = '!';  // valid? A: The value pointed to can be modified

  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
//  cpc = *pcp;  // invalid? A: Pointer cannot be reasigned
//  cpc = argv[0];  // invalid? A: same
//  *cpc = '@';  // invalid? A: Now the value cannot be modified

  return 0;
}
