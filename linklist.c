#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* temp;

void Insert(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if (head==NULL){
        head=newNode;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void Display(){
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Delete(int data){
    struct node *prev = NULL;
    temp=head;
    while(temp->data!=data){
        prev=temp;
        temp=temp->next;
        if(data==temp->data)
        break;
        if(temp->next==NULL){
            printf("Element not found\n");
            return;
        }
    }
    prev->next=temp->next;
    printf("%d has been deleted\n",temp->data);
    free(temp);
}

int main(){
    int choice,k=1,data,data1;
    while(k==1){
        printf("1.Insert\n2.Display\n3.Delete\n4.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d",&data);
            Insert(data);
            break;
        case 2:
            Display();
            break;
        case 3:
            printf("Enter data to be deleted: ");
            scanf("%d",&data1);
            Delete(data1);
            break;
        case 4:
            k=0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}