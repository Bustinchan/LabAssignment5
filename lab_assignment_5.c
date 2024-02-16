#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* current = head;
	int length = 0;
	while(current != NULL){
		length++;
		current = current->next;
	}
	return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* current = head;
	int size = length(head);
	int index = 0;

	char* str = (char*)malloc(sizeof(char)*(size+1));
	if (str == NULL) return NULL;

	while (current != NULL){
		str[index] = current->letter;
		index++;
		current=current->next;
	}
	str[size] = '\0';
	return str;
}

// appends character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) return;
	newNode->letter = c;
	newNode->next = NULL;

	if (*pHead == NULL){
		*pHead = newNode;
	}
	else{
		node *current = *pHead;
		while(current->next != NULL && current != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* todelete = *pHead;
	while(*pHead != NULL){
		todelete = *pHead;
		*pHead = (*pHead)->next;
		free(todelete);
	}
	return;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}