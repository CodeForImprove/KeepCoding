/*
 * stack.h
 *
 *  Created on: 2013-11-20
 *      Author: zcs
 */

#include "data_structure_cmmon.h"
#ifndef STACK_H_
#define STACK_H_

//fixme:modify as needed
/******* modify as needed *********/
#define SEQ_STACK_SIZE 100

typedef int stackElemType;
typedef int* pStackElemType;

/***************/

typedef struct{
	pStackElemType top;
	pStackElemType base;
	int stack_size;
}SeqStack,*pSeqStack;


typedef struct lstack_node{
	stackElemType data;
	struct lstack_node *next;
}LinkStackNode,*pLinkStackNode;

typedef struct{
	pLinkStackNode top;
	pLinkStackNode base;
	int stack_size;
}LinkStack,*pLinkStack;

pSeqStack initSeqStack();
pSeqStack initSeqStackSize(int size);
status destorySeqStack(pSeqStack s);
int getLengthSeqStack(pSeqStack s);
boolean isEmptySeqStatck(pSeqStack s);
status clearSeqStack(pSeqStack s);
pStackElemType getTopSeqStack(pSeqStack s);
status pushSeqStack(pSeqStack s,stackElemType elem);
status popSeqStack(pSeqStack s,pStackElemType elem);
status printSeqStack(pSeqStack s);
status copySeqStack(pStackElemType src,pStackElemType des);
status printSeqStackElem(pStackElemType elem);


pLinkStackNode initLinkStackNode();
pLinkStack initLinkStack();
status destoryLinkStackNode(pLinkStackNode n);
status destoryLinkStack(pLinkStack s);
int getLengthLinkStack(pLinkStack s);
boolean isEmptyLinkStack(pLinkStack s);
status clearLinkStack(pLinkStack s);
pLinkStackNode getTopLinkStack(pLinkStack s);
status pushLinkStack(pLinkStack s,pLinkStackNode node);
status popLinkStack(pLinkStack s,pLinkStackNode *elem);
status printLinkStack(pLinkStack s);
status printLinkStackElem(pLinkStackNode p);

#endif /* STACK_H_ */
