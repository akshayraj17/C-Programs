#include "linkedlist.h"


node_t * Push(node_t * head, float value)
{

 	node_t * obj_add = malloc(sizeof(*obj_add));
	obj_add -> data = value;
	obj_add -> next = NULL;

  if (head == NULL)
  {
    head = obj_add;
	    return obj_add;
  }

  if (head != NULL)
  {
    node_t * old_head = head;
    head = obj_add;
    head -> next = old_head;
    return obj_add;
  }
  return obj_add;

}

float * Pop(node_t * head)
{
	if(head == NULL)
	{
		printf("Empty Stack");
		return NULL;
	}
	node_t * temp = head;
	//node_t * tempNode = temp;
	float *x = (&head ->data);
	temp = temp -> next;
	//free (tempNode);
	return x;
}


void printlist(const node_t * head)
{
  while (head != NULL)
  {
    printf(" data = %f", head->data);
    head = head->next;
  }
}
