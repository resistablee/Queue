#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node 
{
	int data;
	node* next;
};

node* root = NULL;
node* end = NULL;

void endqueue(int val)
{
	if(root == NULL)
	{
		root = new node;
		root->data = val;
		root->next = NULL;
		end = root;
		return;
	}
	
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	end->next = temp;
	end = temp;
	
}

int dequeue()
{
	if (root == NULL)
	{
		printf("Liste bos");
		return -1;
	}
	
	if (root->next == NULL)
	{
		int rvalue = root->data;
		free(root);
		return rvalue;
	}
	
	int rvalue = root->data;
	node* temp = root;
	
	root = root->next;
	free(temp);
	return rvalue;
}

void QueueList(node* list)
{
	node* iter = list;
	
	while (iter->next != NULL)
	{
		printf("Deger: %d\n", iter->data);
		iter = iter->next;
	}
	printf("Deger: %d\n", iter->data);
}

int main()
{
	endqueue(10);
	endqueue(20);
	endqueue(30);
	endqueue(40);
	endqueue(50);
	endqueue(60);
	
	QueueList(root);
	
	printf("\nCikarildi: %d\n", dequeue());
	QueueList(root);
}














