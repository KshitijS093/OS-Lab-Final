#include<stdio.h>
int isHit(int fr[], int pg, int m)
{
    int hit=0;
    for(int i=0;i<m;i++)
    {
        if(fr[i]==pg)
        {
            hit=1;
            break;
        }
    }
    return hit;
}
void main()
{
    int n,m,k=0,pagefault=0;
    printf("Enter the length of refernce sequence:\n");
    scanf("%d",&n);
    int ref[n];
    printf("Enter the page refernce sequence:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ref[i]);
    }
    printf("Enter the number of frames:\n");
    scanf("%d",&m);
    int fr[m];
    for(int i=0;i<m;i++)
    {
        fr[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        //if it is not a hit
        
        if(isHit(fr,ref[i],m)==0)
        {
            fr[k]=ref[i];
            k=(k+1)%m; //since this is first come first serve. 
            pagefault++;
            printf("%d:Page Fault\n",ref[i]);
        }
        else
        printf("%d:No page fault\n",ref[i]);
    }
    printf("Total number of page faults:%d\n",pagefault);
}