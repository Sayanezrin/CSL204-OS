//bankers algorithm
#include<stdio.h>
int n,r;
int max[100][100],alloc[100][100],need[100][100],avail[10];
void input();
void show();
void calc();
int main()
{
      int i,j;
      printf("\n\t\t\tBanker's Algorithm\n\n");
      input();
      show();
      calc();
      return 0;
}

void input()
{
      int i,j;
      printf("Enter the no of processes: ");
      scanf("%d",&n);
      printf("Enter the no of resource instances :");
      scanf("%d",&r);
      printf("Enter the max matrix :");
      for(i=0;i<n;i++)
        {
            for(j=0;j<r;j++)
              {
                  scanf("%d",&max[i][j]);
              }
        }
      printf("Enter the allocation matrix:");
      for(i=0;i<n;i++)
        {
            for(j=0;j<r;j++)
              {
                  scanf("%d",&alloc[i][j]);
              }
        }
      printf("Enter the available resources :");
      for(i=0;i<r;i++)
        {
          scanf("%d",&avail[i]);
        }
}

void show()
{
    int i,j;
    printf("Process\tAllocation\tMax\t\tAvailable\t");
    for(i=0;i<n;i++)
    {
      printf("\nP%d\t ",i+1);
      for(j=0;j<r;j++)
      {
        printf("%d ",alloc[i][j]);
      }
        printf("\t");
      for(j=0;j<r;j++)
      {
        printf("%d ",max[i][j]);
      }
        printf("\t");
      if(i==0)
      {
        for(j=0;j<r;j++)
        {
          printf("%d ",avail[j]);
        }
      }
    }
}
void calc()
{
    int i,j,k;
    int finish[100],temp,need[100][100],flag=1,c1=0;
    for(i=0;i<n;i++)
    {
      finish[i]=0;
    }
    for(i=0;i<n;i++)
    {
      for(j=0;j<r;j++)
      {
        need[i][j]=max[i][j]-alloc[i][j];
      }
    }
    printf("\n");
while(flag)
{
  flag=0;
  for(i=0;i<n;i++)  
  {
  int c=0;
  for(j=0;j<r;j++)
  {
    if(finish[i]==0&&need[i][j]<=avail[j])
    {
      c++;
      if(c==r)
      {
        for(k=0;k<r;k++)
        {
          avail[k]+=alloc[i][j];
          finish[i]=j;
          flag=1;
        }
    printf("P%d->",i);
    if(finish[i]==1)
      {
          i=n;
      }
      }
  }
  }
  }
}
for(i=0;i<n;i++)
{
  if(finish[i]==1)
  {
    c1++;
  }
  else
  printf("P%d->",i);
}
if(c1==n)
  printf("\nThe system is in safe state");
else
{
  printf("\nProcess are in dead lock.\nSystem is in unsafe state.");
}
}
