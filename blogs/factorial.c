/* This is a program I used for learning gdb.  See
   http://www.thegeekstuff.com/2010/03/debug-c-program-using-gdb/ */

#include <stdio.h>

int main()
{
	int i, num, j;
        j = 1;
	printf ("Enter the number: ");
	scanf ("%d", &num );

	for (i=1; i<num; i++)
		j=j*i;    

	printf("The factorial of %d is %d\n",num,j);
}
