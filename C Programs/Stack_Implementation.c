#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int size;
    int top;
    int *arr;
};

int IsEmpty(struct Stack *s){

    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }

}
int main(){

        struct Stack *s;
        s->size=80;
        s->top=-1;
        s->arr=(int*) malloc (s->size*sizeof(int));

        if(IsEmpty(s)==1){
            printf("Stack is emplty \n");
        }else {
            printf("Stack is not empty\n");
        }

        


    return 0;
}
