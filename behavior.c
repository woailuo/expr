#include <stdio.h>
#include <assert.h>
int Num = 4;
void M()
{
  Num = Num - 1;
  assert(Num >= 0);
}
void F()
{
  Num = Num + 1 ;
}
void decompress_unlzo_rw()
{
  M();
  M();
  F();
  F();
}
int main()
{
  decompress_unlzo_rw();
}
