#include<stdio.h>
#include<stdlib.h>
void main()
{
  int n_p,n_b,p[10],bsort[10],b[10],rem_b[10],b_alloc[10],i,j;
  int  flag=0;
  int ch,temp;
  printf("enter the no: of memory blocks:");
  scanf("%d",&n_b);
  printf("enter the memory block sizes:");
  for(i=0;i<n_b;i++)
    {
      scanf("%d",&b[i];
      bsort[i]=i;
      rem_b[i]=b[i];
      b_alloc[i]=-1;
    }
  printf("enter the no: of process:");
  scanf("%d",&n_p);
  printf("enter the process sizes:");
  for(i=0;i<n_p;i++)
    {
      scanf("%d",&p[i]);
    }
}
//Display
printf("BLOCK\tSIZE\n");
for(i=0;i<n_b;i++)
