#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;

struct node* CreateNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Insert(int data){
    struct node* newNode = CreateNode(data);
    struct node* parent =NULL;
    struct node* current=root;

    if(root==NULL){
        root=newNode;
        return;
    }

    while(current!=NULL){
        parent=current;
        if (data>current->data){
            current=current->right;
        }else if(data==current->data){
            printf("Duplicate value not allowed\n");
            return;
        }else{
            current=current->left;
        }
    }
    if (data>parent->data){
        parent->right=newNode;
    }else{
        parent->left=newNode;
    }
}

void Inorder(struct node* node){
    if (node == NULL) {
        return;
    }
    Inorder(node->left);
    printf("%d ",node->data);
    Inorder(node->right);
}

void Preorder(struct node* node){
    if (node == NULL) {
        return;
    }
    printf("%d ",node->data);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct node* node){
    if (node == NULL) {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ",node->data);
}

void delete(struct node* node,int val){
    if (node == NULL) {
        printf("Tree is empty");
        return;
    }

    struct node* parent=NULL;    
    struct node* current=root;

    while(current->data!=val){
        parent=current;
        if (val>current->data){
            current=current->right;
        }else{
            current=current->left;
        }    
    }

    if (current->left==NULL && current->right==NULL){
        if (parent->left==current){
            parent->left=NULL;
        }else{
            parent->right=NULL;
        }
        free(current);    
    }else if(current->left==NULL){
        if (parent->left==current){
            parent->left=current->right;
        }else{
            parent->right=current->right;
        }
        free(current);    
    }else if(current->right==NULL){
        if (parent->left==current){
            parent->left=current->left;
        }else{
            parent->right=current->left;
        }
        free(current); 
    } 
    else{
        struct node* minNode = current->right;
        struct node* minParent = current;
        while (minNode->left != NULL) {
            minParent = minNode;
            minNode = minNode->left;    

        }
        current->data=minNode->data;
        if (minParent->left == minNode) {
            minParent->left = NULL;
        } else {
            minParent->right = NULL;
        }
        free(minNode);
    }   }

int main(){
    int choice=0,data;
    while(choice!=4){
        printf("1.Insert\n2.Display\n3.Delete\n4.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted :");
            scanf("%d",&data);
            Insert(data);
            break;
        case 2:
            Inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter value to be deleted : ");
            scanf("%d",&data);
            delete(root,data);
            break;    
        case 4:
            printf("Exited successfully");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }

}