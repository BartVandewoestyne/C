/*
 * Compile with:
 *
 *    gcc fun1.c main.c
 *
 * Note that if fun1 is defined static, then it cannot be used here.  If the
 * static keyword in front of fun1 is commented out, it can be accessed.
 */
int main(void)
{
  fun1();
  return 0;
}
