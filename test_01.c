#include <stdio.h>
#include "linked_list_int.h"

int main(){
  linked_list_int l1 = lli_create();
  int i,t;
  for (i=0; i < 8 ; ++i)
    lli_push_back(l1,i*3+1);
  t = lli_size(l1);
  printf("Tamanho de l1: %d\n",t);
  printf("l1 = { ");
  for (i=0; i < t ; ++i)
    printf("%d ", lli_get(l1,i));
  printf("}\n");
  /*for (i=0; i < 8 ; ++i)
    lli_pop_back(l1);
  t = lli_size(l1);
  printf("Tamanho de l1: %d\n",t);
  printf("l1 = { ");
  for (i=0; i < t ; ++i)
    printf("%d ", lli_get(l1,i));
  printf("}\n");*/
  lli_destroy(l1);
  t = lli_size(l1);
  printf("Tamanho de l1: %d\n",t);
  printf("l1 = { ");
  for (i=0; i < t ; ++i)
    printf("%d ", lli_get(l1,i));
  printf("}\n");
  return 0;
}
