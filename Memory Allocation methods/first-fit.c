#include<stdio.h>
void main()
{
    int np,nb,i,j,alloc[20],used[20],avail[20],psize[20],bsize[20];
    printf("No.of Process and blocks:\n");
    scanf("%d%d",&np,&nb);
    for(i=0;i<np;i++)
        alloc[i]=-1;
    for(i=0;i<nb;i++)
        used[i]=-1;
    printf("Enter the process Sizes:\n");
    for(i=0;i<np;i++)
    {
        scanf("%d",&psize[i]);
    }
    printf("Enter the Block Sizes:\n");
    for(i=0;i<nb;i++)
    {
        scanf("%d",&bsize[i]);
        avail[i]=bsize[i];
    }    
    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(avail[j]>=psize[i] && used[j]==-1)
            {
                alloc[i]=j;
                avail[j]-=psize[i];
                used[j]=0;break;
            }
        }
    }
    printf("ProcessNo\tProcessSize\tBlockNo.\tBlockSize\tWastage\n");
    for(i=0;i<np;i++)
    {
        printf("%d\t%d\t",i+1,psize[i]);
        if(alloc[i]!=-1)
            printf("%d\t%d\t%d\n",alloc[i]+1,bsize[alloc[i]],avail[alloc[i]]);
        else
            printf("Not Allocated!");
    }
}