#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
 int count,i,j,m=0,n,y=0,time,remaining=0,minimum,flag=0;
 int waiting_time=0,turn_around_time=0,arrival_time[10],burst_time[10],p[10],z[10];
 float k=0,x=0;
 printf("Enter number of Process:\t ");
 scanf("%d",&n);
 printf("\n\tArrival time should be greater than 2 as CPU remains idle for first 3 secs.\n");
 printf("\n\tBurst time should be less tha 10\n");
 for(count=0;count<n;count++)
 {
 printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
 scanf("%d",&arrival_time[count]);
 scanf("%d",&burst_time[count]);
 }
for(i=0;i<n;i++)
{
if(arrival_time[i]==0)
{
printf("\nS INVALID ARRIVAL TIME\n");
getch();
exit(1);
}
}
for(i=0;i<n;i++)
{
if(arrival_time[i]<3)
{
printf("\nS INVALID Arrival Time it should be greater than 3\n");
getch();
exit(1);
}
}
 printf("\n\n\tProcess\t|Turnaround Time|Waiting Time\n\n");
 printf("\t===========================================\n");
for(i=0;i<n;i++)
{
m=m+burst_time[i];
}
minimum=m;
time=m;
for(i=0;i<n;i++)
{
if(arrival_time[i]<time)
{
time=arrival_time[i];
}
}
for(i=time;i<=m;i=i+burst_time[j])
{
minimum=m;
remaining=0;
flag=0;
for(count=0;count<n;count++)
{
if(arrival_time[count]<=i)
{
if(burst_time[count]<minimum)
{
minimum = burst_time[count];
j=count;
flag=1;
}
remaining=1;
}
}
if(flag==1&&remaining==1)
{
waiting_time=i-arrival_time[j];
turn_around_time=waiting_time+burst_time[j];
printf("\tP[%d]\t|\t%d\t|\t%d\n",j+1,turn_around_time,waiting_time);
k=k+waiting_time;
x=x+turn_around_time;
arrival_time[j]=m+1;
p[y]=j+1;
z[y]=i;
y++;
}
}
printf("\n\nAverage Waiting Time= %.2f\n",k/n);
printf("Avg Turnaround Time = %.2f",x/n);
printf("\n\n\nTotal time taken by processor to complete all the jobs : %d",m);
printf("\n\nQueue for order of execution:\n");
printf("\n\nProcess ");
for(i=0;i<n;i++)
{
printf(" P[%d] ",p[i]);
if(i==(n-1))
{
printf("End");
}
}
 return 0;
}