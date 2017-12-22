#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * * argv)
{
	node_t * head = NULL;
	head = Push(head,5);
	head = Push(head,6);
	printlist(head);
	head = Pop(head);
	printlist(head);
	return EXIT_SUCCESS;
		







}
