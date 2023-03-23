#include<stdio.h>
#define m 99
#define V 5
int graph[V][V],key[V],pre[V],seq[V],visit[V]={0},n;

int minkey(){
    int min=m,in;
    for(int i=0;i<n;i++)
        if(visit[i]==0 && key[i]<min){
            min=key[i];
            in=i;
        }
    return in;
}

void findmst(){
    int a,i,j;
    printf("\nEnter source node:");
    scanf("%d",&a);
    a--;
    key[a]=0;
    pre[a]=-1;
    for(i=0;i<n;i++){
        int min=minkey();
        visit[min]=1;
        seq[i]=min;
        for(j=0;j<n;j++)
            if(visit[j]==0 && graph[min][j]<key[j]){
                key[j]=graph[min][j];
                pre[j]=min;
            }
    }
    for(i=0;i<n;i++)
        if(pre[seq[i]]!=-1)
            printf("%c-%c:   %d\n",pre[seq[i]]+65,seq[i]+65,key[seq[i]]);
}

int main(){
    int i,j;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Row%d:",i+1);
            for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
        key[i]=m;
    }
    findmst();
    return 0;
}