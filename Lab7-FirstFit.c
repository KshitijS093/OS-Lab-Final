#include<stdio.h>
void main()
{
    int n,m,i,j,c=0;
    printf("Enter the number of processes and number of blocks:\n");
    scanf("%d %d",&n,&m);
    int all[n];
    for(int i=0;i<n;i++)
    {
        all[i]=-1;
    }
    int blockSize[m],processSize[n];
    printf("Enter the %d block sizes:\n",m);
    for(j=0;j<m;j++)
    {
        scanf("%d",&blockSize[j]);
    }
    printf("Enter the %d process sizes:\n",n);
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&processSize[i]);
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
    printf("****First fit memory allocation****\n");
    printf("ProcessId\tProcessSize\tBlock_Size_allocated\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t",(i+1));
        printf("%d\t\t",processSize[i]);
        if(all[i]!=-1)
        printf("%d\n",all[i]);
        else
        printf("Not allocated\n");
    }
}