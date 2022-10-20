//Question: "merge two sorted linked lists" on gfg

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* pull off the front node of the source and put it in dest */
void MoveNode(struct Node** destRef, struct Node** sourceRef);

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node *curr=NULL;
    struct Node *head=NULL;
    
    
    if(a->data < b->data)
    {
        curr=a;
        head=a;
        a=a->next;
        
    }
    else
    {
        curr=b;
        head=b;
        b=b->next;
    }
    
    
    while(1)
    {
        if(a->data>b->data)
        {
            curr->next=b;
            curr=b;
            b=b->next;
        }
        else
        {
            curr->next=a;
            curr=a;
            a=a->next;
        }
        
        
        if(a==NULL)
        {
            curr->next=b;
            break;
        }
        if(b==NULL)
        {
            curr->next=a;
            break;
        }
    }

    return head;
    
}

void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
	/* the front source node */
	struct Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}


/* Function to insert a node at the beginging of the
linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d",&n);
        scanf("%d",&m);

        /* Start with the empty list */
      	struct Node* res = NULL;
	    struct Node* a = NULL;
	    struct Node* b = NULL;
	    int arr[n];
	    for (int i = 0; i < n; ++i)
        {   
            scanf("%d",&arr[i]);
        }
        for (int i = n-1; i >=0; i--)
        {  
            push(&a, arr[i]);
        }
        int arr1[m];
        for(int i = 0; i<m; i++)
        {   
            scanf("%d",&arr1[i]);
            
        }
        for(int i = m-1; i>=0; i--)
        {   
            push(&b, arr1[i]);    
        }
        res = SortedMerge(a, b);
        printList(res);
        printf("\n");
    }
    return 0;
}