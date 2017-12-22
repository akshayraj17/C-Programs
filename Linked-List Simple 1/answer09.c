#include "answer09.h"

bool isCircular(const node_t * head)
{
 node_t * slower; 
 node_t * faster; 
 slower = get(head,0);
 faster = get(head,0);
 
 while(faster != NULL)
 {
   faster = faster -> next;
   if(faster != NULL)
   {
    slower = slower -> next;
	faster = faster ->next;
   }
   if(faster == slower)
   return true;
 
 }
 return false;
}
