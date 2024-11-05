#include <stdio.h>

int main(){
    int arr[100],array_size,choice,c=1;
    printf("Enter size of array");
    scanf("%d",&array_size);
    printf("Enter elements of array");
    for(int i=0;i<array_size;i++){
        scanf("%d",&arr[i]);
    }
    
    void insertElement() {
        int element,position;
        printf("Enter element to insert");
        scanf("%d",&element);
        printf("Enter position to insert");
        scanf("%d",&position);

        for (int i = array_size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;  
        array_size++;  
    }

    void deleteElement() {
        int position;
        printf("Enter position of element to delete");
        scanf("%d",&position);    
        for (int i = position; i < array_size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        array_size--; 
    }

    void search(){
        int element;
        printf("Enter element to search");
        scanf("%d",element);
        for (int i=0;i<array_size;i++){
            if(arr[i]==element){
                printf("Element found at position %d",i+1);
            }
        }
    }

    void Sort() {
        for (int i = 0; i < array_size - 1; i++) {
            for (int j = 0; j < array_size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("Sorted array\n");
        for (int i=0;i<array_size;i++){
            printf("%d",arr[i]);
        }
    }

    while (c==1){
        printf("What do you want to do\n1.INSERT\n2.DELETE\n3.SEARCH\n4.SORT ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                insertElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                search();
                break;
            case 4:
                Sort();
                break;
            default:
                printf("Enter a valid choice");            
        }
        
        printf("Do you want to continue YES(1)/NO(0)");
        scanf("%d",&c);
    }

}