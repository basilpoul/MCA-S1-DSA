#include <stdio.h>
#include <stdlib.h>

int main(){
    int stack[10],top=-1,choice,max,i;
    int c=1;
    max=sizeof(stack)/sizeof(stack[0]);
    
    int isEmpty(){
        if (top==-1){
            return 1;
        }else{
            return 0;
        }
    }

    int isFull(){
        if (top==max-1){
            return 1;
        }else{
            return 0;
        }
    }

    void push(){
        int value;
        printf("Enter value to be inserted ");
        scanf("%d",&value);

        if (isFull()==1){
            printf("\nCant insert stack is full");
        }else{
            top+=1;
            stack[top]=value;
            printf("Value inserted\n");
        }
            }

    void pop(){
        if (isEmpty()==1){
            printf("Stack is empty\n");
        }else{
            top-=1;
            printf("Value deleted\n");
        }
    }

    void peek(){
        if (isEmpty()==1){
            printf("Stack is Empty\n");
        }else{
            printf("Top element is %d\n",stack[top]);
        }
    }

    void display(){
        if (isEmpty()==1){
            printf("Stack is Empty\n");
        }else{
            for(i=top;i>=0;i--){
                printf("%d ",stack[i]);
            }
        }
    }

    

    while (c!=0){
        printf("What do you want to do\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY ");
        scanf("%d",&choice);


        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;            
            
            default:
                printf("Enter a valid choice");
                break;
        }

        printf("\nDo you want to continue ? YES(1)/NO(0) ");
        scanf("%d",&c);
    }    
    

    
}

