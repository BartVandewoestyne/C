/*
 * Program to test regular expressions for slrn, based on slang2 library.
 *
 * Compile with:
 *   cc -std=c99 -o slmatch slmatch.c -lslang
 *
 * Run with:
 *   ./slmatch "mypattern" "mystring"
 */

#include <string.h>
#include <stdlib.h>
#include <slang.h>

int main(int argc, char *argv[])
{
  unsigned int flags = SLREGEXP_CASELESS;
  char *pattern;
  char *mystring;
  char *match;
  SLRegexp_Type *re;

  if ( argc != 3 ) {
    fprintf(stderr, "slmatch: Usage: slmatch pattern string\n");
    exit(EXIT_SUCCESS);
  }

  printf("Your regular expression: %s\n", argv[1]);
  printf("Your string to test    : %s\n", argv[2]);

  pattern = argv[1];
  mystring = argv[2];

  if (NULL == (re = SLregexp_compile(pattern, flags))) {
    printf("ERROR: could not compile pattern!");
    exit(EXIT_SUCCESS);
  }

  match = SLregexp_match(re, mystring, strlen(mystring));

  if ( match == NULL ) {
    printf("String does NOT match pattern.\n");
    exit(EXIT_SUCCESS);
  }

  printf("String matches pattern!\n");

  return 0;
}
