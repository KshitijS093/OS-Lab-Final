#include <stdio.h>
void main()
{
   int n,pid[10],bt[10],at[10],pr[10],swap,tat[10],wt[10],comp=0,min,j,count=0,k;
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
   printf("Enter the priority of processes:\n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &pr[i]);
   }
   
   // sorting based on priority, higher number means higher priority, so sorting in descending order
   for(int i=0;i<n-1;i++)
   {
      for(int j=0;j<n-i-1;j++)
      {
         if(pr[j]<=pr[j+1])
         {
            swap = pr[j];
            pr[j] = pr[j+1];
            pr[j+1] = swap;

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
   //to find which process has arrived first because we have sorted the array based on priority
   min=at[0];
   j=0;
   for(int i=1;i<n;i++)
   {
      if(at[i]<min)
      {
         min=at[i];
         j=i;
      }
      else if(at[i]==min) //if arrival time is the same, check which has higher priority
      {
         if(pr[i]>pr[j])
         {
            j=i;
         }
         else if(pr[i]==pr[j]) //if priorities are also same, check whcih one has lesser burst time.
         {
            if(bt[i]<bt[j])
            {
               j=i;
            }
         }
      }
   }
   printf("Min:%d\n",min);
   printf("j:%d\n",j);
   //j is the index/process which has arrived first, so compute tat for that first
   comp+=at[j]+bt[j];
   tat[j]=comp-at[j];
   wt[j]=tat[j]-bt[j];
   
   count++; //keeps track of number of processes computed for tat
   k=0;
   while(count!=n)
   {
      if(tat[k]==-1 && at[k]<=comp) //if tat is not yet computed and arrival time is less than completion time, then only we can compute tat
      {
         comp+=bt[k]; //update completion time
         tat[k]=comp-at[k];
         wt[k]=tat[k]-bt[k];
         k=(k+1)%n;// if the process has not arrrived, we are not computing for this process rn, so we need to come back to check for those not computed
         count++;
      }
      else if(tat[k]!=-1 || at[k]>comp)
      {
         k=(k+1)%n; // if tat already computed or the process has not yet arrived, just circularly increment
      }
   }
   for(int i=0;i<n;i++)
   {
      t_tat+=tat[i];
      t_wt+=wt[i];
   }
   printf("Pid\tArrivalTime\tBurstTime\tPriority\tTAT\tWaitingTime\n");
   for(int m=0;m<n;m++)
   {
      printf("%d\t\t%d\t\t%d\t\t%d\t%d\t\t%d\n", pid[m],at[m], bt[m],pr[m],tat[m], wt[m]);
   }
   printf("Average turn around time:%0.1f\n", (t_tat) / n);
   printf("Average waiting time:%0.1f\n", (t_wt) / n);
}