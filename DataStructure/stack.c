/*
 * stack.c
 *
 *  Created on: 2013-11-20
 *      Author: zcs
 */

#include <stdlib.h>
#include <stdio.h>
#include "data_structure_cmmon.h"
#include "stack.h"

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

/**
 * 初始化顺序栈
 */
pSeqStack initSeqStack(){
		pSeqStack s = NULL;
		s = (pSeqStack)malloc(sizeof(SeqStack));
		if(s == NULL){
				printf("ERROR[%s]:malloc failed!\n",__func__);
				return NULL;
		}

		s->base = NULL;
		s->top = NULL;
		s->stack_size = 0;
		return s;
}

/**
 *  根据元素大小初始化顺序栈
 */
pSeqStack initSeqStackSize(int size){
		pSeqStack s = NULL;
		s = initSeqStack();
		if(s == NULL){
				printf("ERROR[%s]:malloc failed!\n",__func__);
				return NULL;
		}

		s->base = (pStackElemType)malloc(sizeof(stackElemType)*(size+1));
		if(s->base == NULL){
				printf("ERROR[%s]:malloc stack elements failed!\n",__func__);
				return NULL;
		}
		s->top = s->base;
		s->stack_size = size;
		return s;
}

/**
 * 	销毁栈空间
 */
status destorySeqStack(pSeqStack s){
		if(s == NULL){
				return OK;
		}
		if(s->base != NULL){
				free(s->base);
		}
		s->base = NULL;
		s->top = NULL;
		free(s);
		return OK;
}

/**
 * 	获取顺序栈长度
 */
int getLengthSeqStack(pSeqStack s){
		int length = -1;
		if(s == NULL){
				printf("[%s]stack not exist!\n",__func__);
				return length;
		}
		length = s->top - s->base;
		return length;
}

/**
 * 	判断顺序栈是否为空
 */
boolean isEmptySeqStatck(pSeqStack s){
		if(s == NULL){
				return TRUE;
		}

		if(s->base == s->top){
				return TRUE;
		}else{
				return FALSE;
		}
}

/**
 * 	清空顺序栈
 */
status clearSeqStack(pSeqStack s){
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return ERROR;
	}

	s->top = s->base;
	return OK;
}

/**
 * 	获得栈顶元素
 */
pStackElemType getTopSeqStack(pSeqStack s){
	pStackElemType elem = NULL;

	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return NULL;
	}

	if(isEmptySeqStatck(s)){
		printf("[%s]stack is empty!\n",__func__);
		return NULL;
	}

	elem = s->top - 1;
	return elem;
}

/**
 * 	顺序栈压栈
 */
status pushSeqStack(pSeqStack s,stackElemType elem){
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return ERROR;
	}
	if(getLengthSeqStack(s) == s->stack_size){
		printf("[%s]stack is full!\n",__func__);
		return ERROR;
	}
	copySeqStack(&elem,s->top);
	s->top++;
	return OK;
}

/**
 * 	顺序栈出栈
 */
status popSeqStack(pSeqStack s,pStackElemType elem){
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		elem = NULL;
		return ERROR;
	}
	if(isEmptySeqStatck(s)){
		printf("[%s]stack is empty",__func__);
		elem = NULL;
		return ERROR;
	}
	s->top--;
	copySeqStack(s->top,elem);
	return OK;
}

/**
 * 	输出顺序栈
 */
status printSeqStack(pSeqStack s){
	pStackElemType p = NULL;
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return ERROR;
	}
	p = s->top;
	while(p>s->base){
		p--;
		printSeqStackElem(p);
	}
	return OK;
}

/**
 * 	复制顺序栈元素
 */
status copySeqStack(pStackElemType src,pStackElemType des){
	//fixme:modify as needed
	*des = *src;
	return OK;
}

/**
 * 	打印顺序栈元素
 */
status printSeqStackElem(pStackElemType elem){
	//fixme:modify as needed
	printf("%d ",*elem);
	return OK;
}


/**
 * 	初始化链栈节点
 */
pLinkStackNode initLinkStackNode(){
	pLinkStackNode node = NULL;
	node = (pLinkStackNode)malloc(sizeof(LinkStackNode));
	if(node == NULL){
		printf("ERROR[%s]:malloc link stack node failed!\n",__func__);
		return NULL;
	}
	node->next = NULL;
	return node;
}

/**
 * 	初始化链栈
 */
pLinkStack initLinkStack(){
	pLinkStack s = NULL;
	s = (pLinkStack)malloc(sizeof(LinkStack));
	if(s == NULL){
		printf("ERROR[%s]:malloc link stack failed!\n",__func__);
		return NULL;
	}
	s->base = NULL;
	s->top = NULL;
	s->stack_size = 0;
	return s;
}

/**
 * 	销毁链栈节点
 */
status destoryLinkStackNode(pLinkStackNode n){
	if(n == NULL){
		printf("[%s]node not exist!\n",__func__);
		return OK;
	}
	n->next = NULL;
	free(n);
	return OK;
}

/**
 * 	销毁链栈
 */
status destoryLinkStack(pLinkStack s){
	pLinkStackNode n = NULL;
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return OK;
	}
	n = s->base;
	while(n != s->top){
		s->base = n->next;
		destoryLinkStackNode(n);
		n = s->base;
	}
	destoryLinkStackNode(s->top);
	s->base = NULL;
	s->top = NULL;
	free(s);
	return OK;
}

/**
 * 	获取链栈长度
 */
int getLengthLinkStack(pLinkStack s){
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return -1;
	}
	return s->stack_size;
}

/**
 * 	判断链栈是否为空
 */
boolean isEmptyLinkStack(pLinkStack s){
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return -1;
	}
	if(s->stack_size == 0 ||(s->base == NULL && s->top == NULL)){
		return TRUE;
	}else{
		return FALSE;
	}
}

/**
 * 	清空链栈
 */
status clearLinkStack(pLinkStack s){
	pLinkStackNode n = NULL;
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return OK;
	}
	n = s->base;
	while(n != s->top){
		s->base = n->next;
		destoryLinkStackNode(n);
		n = s->base;
	}
	destoryLinkStackNode(s->top);
	return OK;
}

/**
 * 	获取链栈栈顶元素
 */
pLinkStackNode getTopLinkStack(pLinkStack s){
	pLinkStackNode top = NULL;
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return NULL;
	}
	if(isEmptyLinkStack(s)){
		printf("[%s]stack is empty!\n",__func__);
		return NULL;
	}
	top = s->top;
	return top;
}

/**
 * 	链栈压栈
 */
status pushLinkStack(pLinkStack s,pLinkStackNode node){
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return ERROR;
	}
	node->next = NULL;
	if(isEmptyLinkStack(s)){
		s->base = node;
		s->top = node;
	}else{
		s->top->next = node;
		s->top = node;
	}
	s->stack_size++;
	return OK;
}

/**
 * 	链栈出栈
 */
status popLinkStack(pLinkStack s,pLinkStackNode *elem){
	pLinkStackNode p = NULL,n = NULL;
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		*elem = NULL;
		return ERROR;
	}
	if(isEmptyLinkStack(s)){
		printf("[%s]stack is empty!\n",__func__);
		*elem = NULL;
		return ERROR;
	}
	n = s->base;
	while(n != s->top){
		p = n;
		n = n->next;
	}
	s->top = p;
	if(p != NULL){
		p->next = NULL;
	}
	*elem = p;
	s->stack_size--;
	return OK;
}

/**
 * 	输出链栈信息
 */
status printLinkStack(pLinkStack s){
	pLinkStackNode p = NULL;
	if(s == NULL){
		printf("[%s]stack not exist!\n",__func__);
		return ERROR;
	}
	if(isEmptyLinkStack(s)){
		return OK;
	}
	p = s->base;
	while(p != s->top){
		printLinkStackElem(p);
		p = p->next;
	}
	printLinkStackElem(p);
	return OK;
}

/**
 * 	输出链栈节点信息
 */
status printLinkStackElem(pLinkStackNode p){
	//fixme:modify as needed
	printf("%d ",p->data);
	return OK;
}
