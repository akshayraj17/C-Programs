#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "linkedlist.h"



	node_t * calcs(node_t * head, char c)
	{	
		float *operator1;
		float *operator2;

		if(head == NULL)
		 return head;
		if( head -> next == NULL)
		 return head;
		if(c == 'a')
		{
			operator1 = Pop(head);
			float num1 = *operator1;
			if(operator1 == NULL)
			 return NULL;
			if(head -> next == NULL)
			{
				return head;
			}
			node_t * temp = head;
			head = head -> next;
			free (temp);
			operator2 = Pop(head);
			if(operator2 == NULL)
			{
				head -> next = NULL;
				free(head);
				return NULL;
			}
			head -> data = *operator2 + (num1);
			return head;
		
		}
		 if(c == 's')
		{
			operator1 = Pop(head);
			float num1 = *operator1;
			if(operator1 == NULL)
			 return NULL;
			if(head -> next == NULL)
			{
				return head;
			}
			node_t * temp = head;
			head = head -> next;
			free(temp);
			operator2 = Pop(head);
			if(operator2 == NULL)
			{
				head -> next = NULL;
				free(head);
				return NULL;
			}
			head -> data = *operator2 - (num1);
			return head;
		
		
		}
		 if(c == 'm')
		{
			operator1 = Pop(head);
			float num1 = *operator1;
			if(operator1 == NULL)
			 return NULL;
			if(head -> next == NULL)
			{
				return head;
			}
			node_t * temp = head;
			head = head -> next;
			free (temp);
			operator2 = Pop(head);
			if(operator2 == NULL)
			{
				head -> next = NULL;
				free(head);
				return NULL;
			}
			head -> data = *operator2 * (num1);
			return head;

		
		}
		 if(c == 'd')
		{
			operator1 = Pop(head);
			float num1 = *operator1;
			if(operator1 == NULL)
			 return NULL;
			if(head -> next == NULL)
			{
				return head;
			}
			node_t * temp = head;
			head = head -> next;
			free (temp);
			operator2 = Pop(head);
			if(operator2 == NULL)
			{
				head -> next = NULL;
				free(head);
				return NULL;
			}
			head -> data = *operator2 / (num1);
			return head;
		
		}

return head;	
	
	}

/*
operator1 = head -> data;
			Pop(head);
			if(head -> next == NULL)
			{
				return head;
			}
			head = head -> next;
			operator2 = head -> data;
			Pop(head);
			head -> data = operator1 / operator2;
			return head;





*/












