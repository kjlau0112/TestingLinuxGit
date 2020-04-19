#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void print_list(struct Node * head)
{
    struct Node * current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void create(int A[],int n)
{
	int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    
	for(i=1;i<n;i++)
    {
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		//last = t;
		last=last->next;
    }
	printf("first->next->next>next->next->data = %d\n",first->next->next->next->next->data);
}

void setasFirstNode(int pos)
{
	struct Node *firstNode;
	int i=0;
	if(pos == 0)
	{
		firstNode = (struct Node *)malloc(sizeof(struct Node));
		firstNode->data = 100;
		firstNode->next = first;
		first = firstNode;

	}
	else 
	{
		//secondNode = firstNode;
		for(i=0;i<pos-1;i++)
			first= first->next;
		
		if(first!= NULL)
		{	
			firstNode = (struct Node *)malloc(sizeof(struct Node));
			firstNode->data = 100;
			firstNode->next=first->next;
			first->next =firstNode;
		}
	}

}

void freeList(struct Node* head)
{
   struct Node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

int main(int argc, char **argv)
{
	int A[]={3,5,7,10,25,8,32,2};
        create(A,8); 
	setasFirstNode(1);
	print_list(first);
	freeList(first);
	return 0;
}
