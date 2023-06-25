#include<stdio.h>
int main()
{
int i,j,n,pages[50],frame[10],nf,k,flag,pfault=0,p_hit=0;
printf("Enter the no.of Pages and frames:\n");
scanf("%d%d",&n,&nf);
printf("Enter the page sequence:\n");
for(i=1;i<=n;i++)
    scanf("%d",&pages[i]);
for(i=0;i<nf;i++)
{
    frame[i]=-1; 
}
j=0;
printf("Pages\t\t");
for(i=1;i<=nf;i++)
    printf("F%d\t",i); 
printf("\n");
for(i=1;i<=n;i++)
{
    printf("%d\t\t",pages[i]);
    flag=0;
    for(k=0;k<nf;k++)
    {
        if(frame[k]==pages[i])
        {
            flag=1;
            p_hit++;
            for(k=0;k<nf;k++)
            {
                if (frame[k]==-1)
                {
                    printf("-\t");
                }
                else{
                printf("%d\t",frame[k]);
                }
            }
            printf("Page Hit");
        }
    }
    if (flag==0)
    {
        frame[j]=pages[i];
        j=(j+1)%nf;
        pfault++;
        for(k=0;k<nf;k++)
        {
            if (frame[k]==-1)
            {
                printf("-\t");
            }
            else{
            printf("%d\t",frame[k]);
            }
        }
        printf("Page Fault");
    }
    printf("\n");
}
    printf("Page Fault=%d\n",pfault);
    printf("Page Hit=%d",p_hit);
    return 0;
}