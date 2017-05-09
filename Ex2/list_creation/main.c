//Program by :- Pritesh A Taral

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<conio.h>
//#include<alloc.h>
//-------------------------------------------------
struct node{
    int data;
    struct node *next;
}*start=NULL;
//------------------------------------------------------------

void create(){
    char ch;
    do{
        struct node *new_node,*current;

        new_node=(struct node *)malloc(sizeof(struct node));

        printf("\nEnter the data : ");

        //scanf("%d",&new_node->data);
        int *p, n;

        scanf("%d", &n);

        p = &n;

        new_node->data  = *p;

        new_node->next=NULL;

        if(start==NULL){
            start=new_node;
            current=new_node;
        }
        else{
            current->next=new_node;
            current=new_node;
        }

        printf("\nDo you want to create another : ");
        ch=getche();
    }
    while(ch!='n');
}
//------------------------------------------------------------------

void display(){
    struct node *new_node;
    printf("The Linked List : \n");
    new_node=start;
    while(new_node!=NULL){
        printf("%d--->",new_node->data);
        new_node=new_node->next;
    }
    printf("NULL");
}
//----------------------------------------------------
void main(){
    create();
    display();
}
