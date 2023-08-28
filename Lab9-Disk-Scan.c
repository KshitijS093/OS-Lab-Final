#include<stdio.h>
#include<stdlib.h>
void sortAsc(int arr[], int s,int e)
{
    int temp;
    for(int i=s;i<e-1;i++)
    {
        for(int j=s;j<e-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void sortDesc(int arr[], int s,int e)
{
    int temp;
    for(int i=s;i<e-1;i++)
    {
        for(int j=s;j<e-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void main()
{
    int tr,n,total=0,curr,dir,min,max,i,j,k;
    printf("Enter the total no of tracks in the disk:\n");
    scanf("%d",&tr);
    printf("Enter the number of requests in the request queue:\n");
    scanf("%d",&n);
    int arr[n],seek[n+1];
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
        //disk fulfills all the higher requests first, so the head reaches the higher end of disk and then changes direction.
        //That is why, we need to find the lower most request track.
        min=arr[0];
        for(i=1;i<n;i++)
        {
            if(arr[i]<min)
            min=arr[i];
        }
        for(i=0;i<=n;i++)
        {
            seek[i]=arr[i];
        }
        seek[n]=curr;
        printf("Seek sequence:\n");
        sortDesc(seek,0,n+1); //sort in descending order
        for(i=0;i<=n;i++)
        {
            if(seek[i]==curr)
            k=i;
        }
        sortAsc(seek,0,k);

        for(i=0;i<=n;i++)
        {
            printf("%d ",seek[i]);
        }
        printf("\n");
        total=(tr-1-curr)+(tr-1-min);
        printf("Total head movements using SCAN scheduling are:%d\n",total);
        break;

        case 0:
        //disk fulfills all the lower requests first, so the head reaches the lower end of disk and then changes direction.
        //That is why, we need to find the max request track.
        max=arr[0];
        for(i=1;i<n;i++)
        {
            if(arr[i]>max)
            max=arr[i];
        }
        total=(curr-0)+(max-0);//0 is the lower most track
        printf("Total head movements:%d\n",total);
        break;

        default:
        printf("Invalid choice:\n");
    }
}