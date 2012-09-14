#include <stdio.h>

int main(int argc, char *argv[]) {

  int i;

  for (i=0; i< 100; i++) {
  
    printf("p_Np = %d -> BSIZE = %d\n", i, 16*((i+15)/16));
  
  }

}
