#include<stdio.h>
void main()
{
    int n,m,i,j;
    printf("Enter the number of processes and number of blocks:\n");
    scanf("%d %d",&n,&m);
    int all[n],blockSize[m],processSize[n];
    printf("Enter %d process sizes:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&processSize[i]);
        all[i]=-1;
    }
    printf("Enter %d block sizes:\n",m);
    for(j=0;j<m;j++)
    {
        scanf("%d",&blockSize[j]);
    }

    /*Since this is best fit, the smallest partition which is adequate is allocated to the processes. So we can sort the blockSizes
    in ascending order. */ 
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<m-i-1;j++)
        {
            if(blockSize[j]>blockSize[j+1])
            {
                int temp=blockSize[j];
                blockSize[j]=blockSize[j+1];
                blockSize[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                all[i]=blockSize[j];
                blockSize[j]=-1;
                break;
            }
        }
    }
    printf("****Best fit memory allocation****\n");
    printf("ProcessID\tProcess_Size\tBlock_size_allocated\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t",(i+1));
        printf("%d\t\t",processSize[i]);
        if(all[i]==-1)
        printf("Not allocated\n");
        else
        printf("%d\n",all[i]);
    }
}
