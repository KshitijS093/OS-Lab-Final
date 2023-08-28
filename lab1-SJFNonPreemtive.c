#include <stdio.h>
void main()
{
   int n,pid[10],bt[10],at[10],swap,tat[10],wt[10],comp=0,min,j,count=0,k;
   float t_tat=0,t_wt=0;
   printf("Enter the number of processes:\n");
   scanf("%d",&n);
   printf("Enter the process id:\n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &pid[i]);
   }
   printf("Enter the arrival time of the processes:\n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &at[i]);
   }
   printf("Enter the burst time of the processes:\n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &bt[i]);
   }
   //sort based on burst time
   for(int i=0;i<n-1;i++)
   {
      for(int j=0;j<n-i-1;j++)
      {
         if(bt[j]>bt[j+1])
         {
            swap = pid[j];
            pid[j] = pid[j+1];
            pid[j+1] = swap;

            swap= bt[j];
            bt[j] = bt[j+1];
            bt[j+1] = swap;

            swap = at[j];
            at[j] = at[j+1];
            at[j+1] = swap;
         }
      }
   }
   for(int i=0;i<n;i++)
   {
      tat[i]=-1;
   }
   //find the process which has minimum arrival time because the arrays are sorted
   min=at[0];
   for(int i=1;i<n;i++)
   {
      if(at[i]<min)
      {
         min=at[i];
         j=i;
      }
   }
   tat[j]=at[j]+bt[j];
   wt[j]=tat[j]-bt[j];
   comp+=tat[j];
   count++;
   k=0;
   while(count!=n)
   {
      if(tat[k]==-1 && at[k]<=comp)
      {
         comp+=bt[k];
         tat[k]=comp-at[k];
         wt[k]=tat[k]-bt[k];
         count++;
         k=(k+1)%n;
      }
      else if(tat[k]!=-1 || at[k]>comp)
      {
         k=(k+1)%n;
      }
   }
   for(int i=0;i<n;i++)
   {
      t_tat+=tat[i];
      t_wt+=wt[i];
   }
   printf("Pid\tArrivalTime\tBurstTime\tTAT\tWaitingTime\n");
   for(int m=0;m<n;m++)
   {
      printf("%d\t\t%d\t\t%d\t%d\t%d\n", pid[m],at[m], bt[m],tat[m], wt[m]);
   }
   printf("Average turn around time:%0.2f\n", (t_tat) / n);
   printf("Average waiting time:%0.2f\n", (t_wt) / n);
}