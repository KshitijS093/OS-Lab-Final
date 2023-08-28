#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void main()
{
    int tr,n,total=0,curr,dir,min,max;
    printf("Enter the total no of tracks in the disk:\n");
    scanf("%d",&tr);
    printf("Enter the number of requests in the request queue:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the request sequence:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the current head positon of the disk arm:\n");
    scanf("%d",&curr);
    printf("Enter head movement direction(1 for High and 0 for Low):\n");
    scanf("%d",&dir);
    switch(dir)
    { 
        case 1:
        //head first moves to the higher end of disk while the disk fulfills all the higher requests, changes direction to
        //reach the lower end when th disk does not fulill any lower request. After reaching the lower end, the head again
        //changes direction when the disk starts fulfilling lower requests.
        //So we need to find max request less than curr head position

        max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<curr && arr[i]>max)
            {
                max=arr[i];
            }
        }
        total=(tr-1-curr)+(tr-1-0)+(max-0);
        printf("The total head movements using C-SCAN scheduling are:%d\n",total);
        break;

        case 0:
        //reverse of case 1

        min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>50 && arr[i]<min)
            {
                min=arr[i];
            }
        }
        total=(curr-0)+(tr-1-0)+(tr-1-min);
        printf("The total head movements using C-SCAN scheduling are:%d\n",total);
        break;
        
        default:
        printf("Invalid choice!\n");
    }
}