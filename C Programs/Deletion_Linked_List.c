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


struct Node*DeleteBegin(struct Node* head){
    struct Node *ptr=head;
    head =head->next;
    free(ptr);
    return head;
}

struct Node *DeleteBetween(struct Node *head,int index){
    struct Node*p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    struct Node*q=p->next;
    p->next= q->next;
    free(q);
    return head;
}


struct Node*DeleteLastNode(struct Node *head){

    struct Node *p=head;
    struct Node *q=p->next;

    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    free(q);
    return head;
}


struct Node*DeleteVal(struct Node *head,int val){
    struct Node*p=head;
    struct Node*q=p->next;
    
    while(q->data !=val && q->next!=NULL){
        p=p->next;
        q=q->next;

    }
    if(q->data ==val){
    p->next=q->next;
    free(q);
    }
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

    //head=DeleteBegin(head);
    //head=DeleteBetween(head,1);
    //head=DeleteLastNode(head);
    head =DeleteVal(head,24);
    list(head);
   
    return 0;
}
