#include <stdio.h>
#include <stdlib.h>

int quene[10];
int front=-1,rear=-1;

int max=(sizeof(quene)/sizeof(quene[0]));

int isFull(){
    if (rear==max-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(){
    if (front==-1 || front>rear){
        return 1;
    }else{
        return 0;
    }
}

void Insert(int data){
    if (isFull()==1){
        printf("Quene is full\n");
        return;
    }
    if (isEmpty()==1){
        front=0;
    }
    rear++;
    quene[rear]=data;
    printf("Inserted %d\n",data);
}

void Delete(){
    if (isEmpty()==1){
        printf("Quene is empty\n");
        return;
    }

    printf("Deleted element %d",quene[front]);
    front++;

    if (front>rear){
        front=rear=-1;
    }
}

void peek(){
    if (isEmpty()==1){
        printf("Quene is empty\n");
        return;
    }

    printf("Top element %d",quene[front]);
}

void display(){
    if (isEmpty()==1){
        printf("Quene is empty\n");
        return;
    }
    for (int i=front;i<=rear;i++){
        printf("%d ",quene[i]);
    }
}

int main(){
    int choice,contin=1,value;
    while(contin==1){
        printf("What do you want to do\n1.Insert an element\n2.Delete an element\n3.Peek\n4.Display the quene\n5.Exit\nEnter a choice : ");
        scanf("%d",&choice);
    
        switch (choice)
        {
        case 1:
            printf("Enter element to insert : ");
            scanf("%d",&value);
            Insert(value);        
            break;
        case 2:
            Delete();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);              
        default:
            printf("Enter a valid choice");
            break;
        }
        printf("\nDo you want to continue yes(1)/no(0) : ");
        scanf("%d",&contin);
        if (contin!=1){
            exit(1);
        }
    }    

    return 0;
}

