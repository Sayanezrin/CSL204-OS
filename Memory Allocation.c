#include<stdio.h>
#include<stdlib.h>
void main()
{
int n_p,n_b, p[10], bsort[10], b[10], rem_b[10], b_alloc[10], i,j;
int flag=0;
int ch,temp;
printf("Enter the number of Memory Blocks : ");
scanf("%d",&n_b);
printf("Enter the Memory block sizes :");
for(i=0;i<n_b;i++)
{
scanf("%d",&b[i]);
bsort[i]=i;
rem_b[i]=b[i];
b_alloc[i]=-1;
}
printf("Enter the number of Processes : ");
scanf("%d",&n_p);
printf("Enter the Process sizes :");
for(i=0;i<n_p;i++)
{
scanf("%d",&p[i]);
}
//DISPLAY
printf("BLOCK\tSIZE\n");
for(i=0;i<n_b;i++)
printf("%d\t%d\n",i+1,b[i]);
printf("\n\nPROCESS\tSIZE\n");
for(i=0;i<n_p;i++)
printf("%d\t%d\n",i+1,p[i]);
//sorting the memory blocks
for(i=0;i<n_b-1;i++){
for(j=0;j<n_b-i-1;j++){
if(b[bsort[j]]>b[bsort[j+1]]){
temp=bsort[j];
bsort[j]=bsort[j+1];
bsort[j+1]=temp;
}
}
}
printf("\n\nMENU\n1.FIRST FIT\n2.WORST FIT\n3.BEST FIT\nSELECT CHOICE :");
scanf("%d",&ch);
switch(ch)
{
case 1: //FIRST FIT
for(i=0;i<n_p;i++)
{
flag=1;
for(j=0;j<n_b;j++){
if(p[i]<=rem_b[j]){
rem_b[j]=0;
b_alloc[j]=i+1;
flag=0;
break;
}
}
if(flag==1)
break;
}
break;
case 2 : //WORST FIT
for(i=0;i<n_p;i++){
flag=1;
for(j=n_b-1;j>=0;j--){
if(p[i]<=rem_b[bsort[j]]){
rem_b[bsort[j]]=0;
b_alloc[bsort[j]]=i+1;
flag=0;
break;
}
}
if(flag==1)
break;
}
break;
case 3 : //BEST FIT
for(i=0;i<n_p;i++){
flag=1;
for(j=0;j<n_b;j++){
if(p[i]<=rem_b[bsort[j]]){
rem_b[bsort[j]]=0;
b_alloc[bsort[j]]=i+1;
flag=0;
break;
}
}
if(flag==1)
break;
}
break;
default:
printf("\nINVALID CHOICE\n\n");
exit(0);
};
//DISPLAY
printf("\n\nBLOCK\tSIZE\tALLOCATED PROCESSES\n");
for(i=0;i<n_b;i++){
printf("%d\t%d\t",i+1,b[i]);
if(b_alloc[i]>-1){
printf("%d\n",b_alloc[i]);
}
else
printf("-\n");
}
printf("\nUNALLOCATED PROCESSES NUMBERS = ");
for(i=0;i<n_p;i++){
flag=0;
for(j=0;j<n_b;j++){
if(b_alloc[j]==i+1 ){
flag=1;
break;
}
}
if(flag==0)
printf("%d ",i+1);
}
printf("\n\n");
}
//OUTPUT
