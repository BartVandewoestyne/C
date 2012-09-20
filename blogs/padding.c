/*
 * Some examples that illustrate padding and how rearranging the members of
 * a struct can reduce the number of padding bytes and thus also the size of
 * the struct.
 *
 * References:
 *
 *   [1] http://www.drdobbs.com/cpp/padding-and-rearranging-structure-member/240007649
 */

#include <stdio.h>

typedef struct widget widget;
struct widget
{
    char m1; // 1 byte
             // 3 padding bytes
    int m2;  // 4 bytes
    char m3; // 1 byte
             // 3 padding bytes
};

typedef struct widget_rearranged1 widget_rearranged1;
struct widget_rearranged1
{
    char m1; // 1 byte
    char m3; // 1 byte
             // 2 padding bytes
    int m2;  // 4 bytes
};

typedef struct widget_rearranged2 widget_rearranged2;
struct widget_rearranged2
{
    char m1; // 1 byte
    char m3; // 1 byte
             // 2 padding bytes
    int m2;  // 4 bytes
};

typedef struct gadget gadget;
struct gadget
{
    char m1;
    double m2;
    char m3;
};


int main()
{
  printf("sizeof(char) = %ld\n", sizeof(char));
  printf("sizeof(int) = %ld\n", sizeof(int));
  printf("sizeof(double) = %ld\n", sizeof(double));

  printf("sizeof(widget) = %ld\n", sizeof(widget));
  printf("sizeof(widget_rearranged1) = %ld\n", sizeof(widget_rearranged1));
  printf("sizeof(widget_rearranged2) = %ld\n", sizeof(widget_rearranged2));
  printf("sizeof(gadget) = %ld\n", sizeof(gadget));

  return 0;
}
