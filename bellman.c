#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int arr[50][50], n;
int d[10];
int p[10];
void readgraph()
{
    int i, j;
    FILE *fp;
    fp=fopen("graph", "r");
    if(fp==NULL)
    {
        printf("File does not exist");
        exit(0);
    }
    else
    {
        fscanf(fp, "%d", &n);
        for(i=0; i<n; i++)
        {
            for(j=0;j<n;j++)
            {
                fscanf(fp, "%d", &arr[i][j]);
            }
        }
    }
}
void showgraph()
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}
void BellmanFord(int s)
{
    int i, j;
    d[s]=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(arr[j][i]!=0)
            {
                if(d[i]>(d[j]+arr[j][i]))
                {
                    d[i]=d[j]+arr[j][i];
                    p[i]=j;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t", d[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%c\t", p[i]+'A');
    }
    printf("\n");
}
int main()
{
    int i, s;
    readgraph();
    showgraph();
    for(i=0;i<n;i++)
    {
        d[i]=INT_MAX;
        p[i]=-1;
    }
    printf("\nEnter source vertex: ");
    scanf("%d", &s);
    BellmanFord(s);
    return 0;
}
