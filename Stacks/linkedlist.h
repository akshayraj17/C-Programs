#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  float data;
  struct node * next;
} node_t;


node_t * Push(node_t * head, float value);
float * Pop(node_t * head);

//node_t * get(const node_t * head, int index);
//int length(const node_t * head);

void printlist(const node_t * head);
#endif
