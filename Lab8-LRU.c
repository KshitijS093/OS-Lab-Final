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
    int i,n,m,k,j,pagefault=0,min=999,x,y,count=0,u=0;
    printf("Enter the length of reference sequence:\n");
    scanf("%d",&n);
    int ref[n];
    printf("Enter the page reference sequence:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ref[i]);
    }
    printf("Enter the number of frames:\n");
    scanf("%d",&m);
    int fr[m];
    for(i=0;i<m;i++)
    {
        fr[i]=-1;
    }
    y=0;
    u=0;
    while(count<m)
    {
        if(isHit(fr,ref[u],m)==0)
        {
            fr[y]=ref[u];
            printf("%d:Page Fault\n",ref[u]);
            y++;
            u++;
            pagefault++;
            count++;
            
        }
        else
        {
            printf("%d:No page fault\n",ref[u]);
            u++;
        }
    }
    for(i=u;i<n;i++)
    {
        if(isHit(fr,ref[i],m)==0)
        {
            for(j=0;j<m;j++)//for every element in the frames, check which index is the least.
            {
                for(k=i-1;k>=0;k--)//to check which index is the least, for each number in the frame, we need to start checking from i-1 only.
                {
                    if(fr[j]==ref[k])
                    {
                        break;
                    }
                }
                if(k<min) /*agar pg no ki index min se kam ho, iska matlab ye hai ki uski demand sabse pehele hua tha, 
                sirf tabhi min ko update karna*/
                {
                    x=j;
                    min=k;
                }
            }
            min=999; //reset min for other iterations
            fr[x]=ref[i];
            pagefault++;
            printf("%d:Page fault\n",ref[i]);
        }
        else
        {
            printf("%d:No page fault\n",ref[i]);
        }
    }
    printf("Total number page faults:%d\n",pagefault);
}