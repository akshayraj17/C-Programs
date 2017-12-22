#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) {


	// read token
	// check if token is a number literal
	// 		return a leaf node with literal as value
	// if token is lparen
	// 		build an expression for left child
	// 		read operator, save as value for current node
	// 		build an expression for right child
	// 		read right rparen

	Token tx = nextToken(s);
	 if(tx.type == T_VAL)
	{
		TreeNode * val1 = buildTreeNode(tx);
		return val1;
	} 

	if(tx.type == T_LPAREN)
	{
		TreeNode * tree1  = buildExpressionTree(s);	
		tx  = nextToken(s);
		TreeNode * op = buildTreeNode(tx);
		TreeNode * tree2 = buildExpressionTree(s);
		op->left = tree1;
		op -> right = tree2;
	    tx = nextToken(s); 
		if(tx.type != T_RPAREN)
		{
			 exit(1);
		}

	return op;
	
	}
	return NULL;	
}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {

	if(!t)
	{
		return;	
	}
	makePostFix(t -> left,fptr);
	makePostFix(t -> right,fptr);
	if(t -> t.type == T_VAL)
		fprintf(fptr,"%f ",t->t.value);

	if(t -> t.type == T_ADD)
		fprintf(fptr,"%c ",T_ADD);

	if(t -> t.type == T_SUB)
		fprintf(fptr,"%c ",T_SUB);

	if(t -> t.type == T_MUL)
		fprintf(fptr,"%c ",T_MUL);

	if(t -> t.type == T_DIV)
		fprintf(fptr, "%c ",T_DIV);
}
/* t = nextToken(s);
   second = buildExpressionTree(s);
   op4 -> left = first;
   op4 -> right = second;*/		 

#endif
