#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void main()
{
    int tr,n,total=0,curr,min,count=0,d,ind,i,j=0;
    printf("Enter the total no of tracks in the disk:\n");
    scanf("%d",&tr);
    printf("Enter the number of requests in the request queue:\n");
    scanf("%d",&n);
    int arr[n],seek[n];
    printf("Enter the request sequence:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the current head positon of the disk arm:\n");
    scanf("%d",&curr);
    while(count!=n)
    {
        min=1000;
        for(i=0;i<n;i++)
        {
            if(abs(arr[i]-curr)<min)
            {
                min=abs(arr[i]-curr);
                ind=i;
            }
        }
        seek[j]=arr[ind];
        total+=min;
        curr=arr[ind];
        arr[ind]=1000;
        count++;
        j++;
    }
    printf("Safe sequence is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",seek[i]);
    }
    printf("\n");
    printf("Total number of movements using SSTF scheduling are:%d\n",total);
}