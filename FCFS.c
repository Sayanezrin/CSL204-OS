#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int completion_time;
    int turnaround_time;
}Process;
void print_table(Process p[],int n);
void print_gantt_chart(Process p[],int n);
void avg_TAT_WT(Process p[],int n);
float sum_waiting_time,sum_turnaroud_time;

int main()
{
    Process p[MAX];
    int i,j,n;
    printf("enter total no:of process:");
    scanf("%d",&n);
    printf("enter the arrival time for each process:");
    for(i=0;i<n;i++)
    {
        p[i].pid=i;
        printf("p[%d]:",i);
        scanf("%d",&p[i].arrival_time);
        p[i].waiting_time=p[i].turnaround_time=0;
    }
    printf("enter the burst time for each process:\n");
    for(i=0;i<n;i++)
    {
        p[i].pid=i;
        printf("p[%d]:",i);
        scanf("%d",&p[i].burst_time);
    }
    p[0].turnaround_time=p[0].completion_time=p[0].burst_time;
    for(i=1;i<n;i++)
    {
        int c=0;
        for(int j=i;j>=0;j--)
        {
            c=c+p[j].burst_time;
        }
        p[i].completion_time=c;
        p[i].waiting_time=p[i-1].completion_time-p[i].arrival_time;
        p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
    }
    //print table
    printf("/n");
    print_table(p,n);
    //print gantt chart
    printf("    GANTT CHART   \n");
    printf("     ___    \n");
    print_gantt_chart(p,n);
    avg_TAT_WT(p,n);
    return 0;
}
void print_table(Process p[],int n)
{
    int i;
    printf("+____________________________________________________________________+\n");
    printf(" | PID | ARRIVAL TIME |\t BURST TIME |\t WAITING TIME |\t TURNAROUND TIME |\t\n");
    printf("+____________________________________________________________________+\n");
    for(i=0;i<n;i++)
    {
        printf("| %d\t || %d\t\t | %d\t\t | %d\t\t | %d\t\t |\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
        printf("+____________________________________________________________________+\n");
    }
}
void print_gantt_chart(Process p[],int n)
{
    int i,j;
    //ptint top bar
    printf(" ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p[i].burst_time;j++)printf("--");
        printf(" ");
    }
    printf("\n|");
    //printing process id in the middle
    for(i=0;i<n;i++)
    {
      for(j=0;j<p[i].burst_time-1;j++)printf(" ");
      printf("p%d",p[i].pid);
      for(j=0;j<p[i].burst_time-1;j++)printf(" ");
      printf("|");
      printf("\n");
      //printing bottom bar
      for(i=0;i<n;i++)
      {
          for(j=0;j<p[i].burst_time;j++)printf("--");
          printf(" ");
      }
      printf("\n");
      //printing the line
      printf("0");
      for(i=0;i<n;i++)
      {
          for(j=0;j<p[i].burst_time;j++)printf(" ");
          printf("%d",p[i].completion_time);
      }
      printf("\n");
    }
}

    void avg_TAT_WT(Process p[],int n)
    {
        int i;
        float sum_waiting_time =0,sum_turnaround_time =0;
        for(i=0;i<n;i++)
        {
            sum_waiting_time+=p[i].waiting_time;
            sum_turnaround_time+=p[i].turnaround_time;
        }
    printf("total waiting time :%2f\n",sum_waiting_time);
    printf("average waiting time :%2f\n",(sum_waiting_time/n));
    printf("total turnaround time :%2f\n",sum_turnaround_time);
    printf("average turnaround time :%2f\n",(sum_turnaround_time/n));
    }
