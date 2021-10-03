
#include <stdio.h>
#include<stdlib.H>

struct Node {
    int data;
    struct Node*next;  // self referencing structures
};

void list(struct Node*ptr){
    while(ptr!=NULL){
        printf("The element is :%d\n",ptr->data);
        ptr=ptr->next;
    }
}


struct Node* insertInBetween(struct Node *head,int index,int data){
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node*));
    int i=0;
    struct Node*p =head;

    while(i!=index-1){
        p=p->next;
        i++;
    }

    ptr->next=p->next;
    p->next=ptr;
    ptr->data =data;
    return head;


}



struct Node *insertAtBegin(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data =data;
    ptr->next=head;
    return ptr;
}



struct Node* InsertAtEnd(struct Node *head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p =head;
    while(p->next!=NULL){
        p=p->next;
    }

    p->next =ptr;
    ptr->next=NULL;
    ptr->data =data;
    return head;
    

}
int main(){
    struct Node *head;    
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=23;
    second->next=third;

    third->data=24;
    third->next=fourth;

    fourth->data=231;
    fourth->next=NULL;

    list(head);
    printf("\n");
    //head = insertAtBegin(head,98);
    //head =insertInBetween(head,1,84);
    head =InsertAtEnd(head,184);
    list(head);
    return 0;
}
