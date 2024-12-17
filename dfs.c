#include <stdio.h>
#include <stdlib.h>

int a[100][100],i,j,n,start,v[20];

void dfs(int start);

int main(){
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++){
        v[i]=0;
    }

    printf("Enter the starting node ");
    scanf("%d",&start);
    dfs(start);
}

void dfs(int start){
    v[start]=1;
    printf("%d ",start);
    for(int i=0;i<n;i++){
        if(a[start][i]==1 && v[i]==0){
            dfs(i);
        }
    }
}

