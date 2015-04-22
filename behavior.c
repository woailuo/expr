#include <stdio.h>
#include <assert.h>
int Num = 2;
void M()
{
  Num = Num - 1;
  assert(Num >= 0);
}
void F()
{
  Num = Num + 1 ;
}
void original()
{
 l:
  M();
  M();
  goto l;
}
void rw()
{
 l:
  M();
  M();
  F();
  F();
  goto l;
}
int main()
{
  rw();
}
