#include <stdio.h>

int main(){
    int arr1Size,arr2Size,mergedArraySize,i,j;
    int arr2[50],arr1[50],mergedArray[100];

    printf("Enter size of first array");
    scanf("%d",&arr1Size);
    
    printf("Enter elements of first array");
    for(i=0;i<arr1Size;i++){
        scanf("%d",&arr1[i]);
    }
    
    printf("Enter size of second array");
    scanf("%d",&arr2Size);

    printf("Enter elements of second array");
    for(i=0;i<arr2Size;i++){
        scanf("%d",&arr2[i]);
    }
    
    mergedArraySize=arr1Size+arr2Size;

    for(i=0;i<(arr1Size+arr2Size);i++){
        if (i<arr1Size){
            mergedArray[i]=arr1[i];
        }else{
            mergedArray[i]=arr2[i-arr1Size];
        }
    }
   
   printf("Array 1\n");
   for(i=0;i<arr1Size;i++){
    printf("%d",arr1[i]);
   }

   printf("\nArray 2\n");
   for(i=0;i<arr2Size;i++){
    printf("%d",arr2[i]);
   }
   
   printf("\nMerged Array\n");
   for(i=0;i<mergedArraySize;i++){
    printf("%d",mergedArray[i]);
   }
}