#include <stdio.h>

void main(){
    int num;
    do{
        printf("Enter a number greater than 5 : ");
        scanf("%d",&num);
        if(num<5){
            printf("Invalid input.You entered a number less than 5\n");
        }else if(num==5){
            printf("Invalid input.You entered 5\n");
        }
    }while(num<=5);
    printf("Input accepted");
}