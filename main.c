#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structs
typedef struct Node{
    int data;
    struct Node *next;
}Node;


typedef struct List{
    Node *head;
    int length;
}List;


// List methods
void list_add(List *list,int val){
    Node *new_n =(Node *) malloc(sizeof(Node));

    new_n -> data = val;
    new_n -> next = NULL;

    if(list -> head == NULL){
        list -> head = new_n;
        list -> length = 1;
    }else{
        Node *head = list -> head;

        if (head -> data >= val ){ 
            new_n -> next = head; 
            list -> head = new_n;
        }else if(head -> data < val ){

            Node *node = head;

            while( node -> next != NULL){
                // FINISH THIS
                if(node -> next -> data > val){
                    break;
                }
                printf("%d -> ", node -> data); 
                node = node -> next; 
            }
            if(node -> next == NULL){    
                node -> next = new_n;
            }else{
                new_n -> next = node -> next;
                node -> next = new_n;
            }
        }

        list -> length += 1; 
        printf("\nAdded %d to list \n", val);
    }

}


void print_list(List *list){
    printf("\n\nprint_list() =================================================================================================\n\n");  
    Node *node = list -> head;

    while(node != NULL){
        printf("{ val: %d } -> ", node -> data);
        node = node -> next;
    }
    if(node == NULL){
        printf(" NULL; \n length = %d\n", list -> length);
    }
    printf("\nendof printlist() ==============================================================================================\n\n");
}

void delete_item(List *list, int val){

    printf("{%d} is the item to delete", val);
    Node *node = list -> head;
    Node *prev;
    if (node -> data == val){
        list -> head = node -> next;
        free(node);
        printf("\nDeleted item %d\n", val);
        list -> length -= 1;
        return;
    }else{

        prev = node;
        printf("{%d} ->", prev -> data);
        node = node -> next;
        if (node == NULL){
            printf("\nNo item to delete\n");
        }
        while(node != NULL){
            if (node -> data == val){
                printf("Hit %d", node->data);
                prev -> next = node -> next;
                free(node);
                list -> length -= 1;
                printf("\nDeleted item %d\n", val);
                return;
            }else{
                prev = node;
                node = node -> next;
                printf("{%d} ->", prev -> data);
            }
        }
    }
    printf("\nendof delete_item() ==============================================================================================\n\n");
}

void EXIT(List *list){
    printf("\n\n EXIT() =================================================================================================\n\n");  
    Node *node = list -> head;

    while(node != NULL){
        printf("{ val: %d } -> ", node -> data);
        Node *to_free = node;
        node = to_free -> next;
        free(to_free);
    }
    printf("\nendof EXIT() ==============================================================================================\n\n");

}

int main(){
    List list= {NULL, 0}; //List initialization
    bool t = true;
    while(t){
        int option;

        //Printing the menu
        printf("\n\nPlease select an option below:\n");
        printf("1. Add\n");
        printf("2. Print.\n");
        printf("3. Delete item \n");
        printf("4. EXIT \n");
        printf("Enter choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\n\nlist_add() ============================================================================================\n\n");
                printf("Enter data to add: ");
                int val; 
                scanf("%d", &val);
                list_add(&list, val);
                printf("\nendof list_add() ========================================================================================\n\n");
                break;

            case 2:
                print_list(&list);
                break;
            case 3:
                printf("\n\ndelete_item() =================================================================================================\n\n");  
                printf("Enter data to delete: ");
                int val_del; 
                scanf("%d", &val_del);
                delete_item(&list, val_del);
                break;
            case 4:
                EXIT(&list);
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("PLEASE ENTER CORRECT CHOICE FROM ABOVE");

        }
    }

}

