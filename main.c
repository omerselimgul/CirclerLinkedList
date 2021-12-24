#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertAtBeginning(int);
void insertAtEnd(int);
void display();
void removeBeginning();
void removeEnd();

struct node
{
    struct node *next;
    struct node *previous;
    int data;
};

struct node *head=NULL;
struct node *tail=NULL;

int main()
{
	int choice,value,choice1,loc1;
	while(1)
	{
		printf("\n\n********* MENU ************\n1. Insert\n2. Display\n3. Delete\n4. Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be insert: ");
				scanf("%d",&value);

				printf("Where do you want to insert: \n1. At Beginning\n2. At End\nEnter your choice: ");
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 1:
						insertAtBeginning(value);
						break;
					case 2:
						insertAtEnd(value);
						break;
					default:
						printf("\nWrong Input!! Try again!!!\n\n");
						break;
				}
				break;
			case 2:
				display();
				break;
			case 3:
				printf("How do you want to Delete: \n1. From Beginning\n2. From End\nEnter your choice: ");
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 1:
						removeBeginning();
						break;
					case 2:
						removeEnd(value);
						break;
					default:
						printf("\nWrong Input!! Try again!!!\n\n");
						break;
				}
				break;
			case 4:
				return 0;
			default:
				printf("\nWrong input!!! Try again!!\n\n");
				break;
		}
	}
}

void insertAtBeginning(int value){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        tail=newNode;
        tail->next=head;
        tail->previous=head;
        head->next=tail;
        head->previous=tail;
    }else{
        newNode->next=head;
        newNode->previous=tail;
        head->previous=newNode;
        tail->next=newNode;
        head=newNode;
    }
	printf("\nOne node inserted!!!\n");
}

void insertAtEnd(int value){
	struct node *newNode=malloc(sizeof(struct node));
	newNode->data=value;
		if (head==NULL)
		{
			head=newNode;
			tail=newNode;
			tail->next=newNode;
			tail->previous=newNode;
			head->next=newNode;
			head->previous=newNode;
		}
		else{
			tail->next=newNode;
			newNode->previous=tail;

			newNode->next=head;
			head->previous=newNode;
			
			tail=newNode;
		}
	printf("\nOne node inserted!!!\n");
		
}

void removeBeginning(){
	if(head==NULL){
		printf("\n\nList is Empty!!!");

	}else{

		if (head->next==head)
		{
			head=NULL;
			tail=NULL;
		}
		else{
			head=head->next;
			tail->next=head;
			head->previous=tail;
		}
			
	}

}

void removeEnd(){
	if(head==NULL){
		printf("\n\nList is Empty!!!");

	}else{

		if (head->next==head)
		{
			head=NULL;
			tail=NULL;
		}
		else{
			tail=tail->previous;
			tail->next=head;
			head->previous;
		}
	}
}
void display()
{
	if(head == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		struct node *temp = head;
		printf("\n\nList elements are - \n");
		while(temp->next != head)
		{
			printf("\n prev=%u\t %d\t address=%u \t next=%u\t",temp->previous, temp->data, temp, temp->next);
			temp = temp->next;
		}
		printf("\n prev=%u\t %d\t address=%u \t next=%u\t",temp->previous, temp->data, temp, temp->next);
	}
}
