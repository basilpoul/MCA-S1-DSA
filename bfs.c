#include <stdio.h>
#include <stdlib.h>

int queue[100];
int front = -1, rear = -1, n;

void enque(int value);
int deque();

void bfs(int a[][100], int n, int s_node, int v[]){
    enque(s_node);
    v[s_node]=1;
    printf("%d ",s_node);
    while(front!=-1 && rear!=-1){
        int node = deque();
        for(int i=0;i<n;i++){
            if(a[node][i]==1 && v[i]==0){
                enque(i);
                v[i]=1;
                printf("%d ",i);
            }    
        }
    }
}

int main()
{
    printf("Enter the size of graph : ");
    scanf("%d", &n);
    int a[100][100], s_node, v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d][%d] ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the source node : ");
    scanf("%d", &s_node);
    bfs(a, n, s_node, v);
}

void enque(int data)
{
    if (rear == n - 1)
    {
        return;
    }
    if (front == -1 )
    {
        front = 0; 
    }
    rear++;
    queue[rear]=data;
}

int deque()
{
    if(front==-1){
        return -1;

    }
    int value=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    return value;
}
