/*
 * linear_list.c
 *
 *  Created on: 2013-11-19
 *      Author: zcs
 *      线性表方法
 */
#include <stdlib.h>
#include <stdio.h>
#include "linear_list.h"

pSeqList initSeqList();
int destorySeqList(pSeqList p);
status insertSeqList(pSeqList l, int index, LinearType elem);
status deleteSeqList(pSeqList l, int index);
void printSeqList(pSeqList l);

LinkList initLinkedNode(LinearType data);
int destoryLinedNode(LinkList p);
LinkList findLinkList(LinkList l, int index);
status insertLinkList(LinkList l, int index, LinkList elem);
status deleteLinkList(LinkList l, int index);
void printLinkList(LinkList l);

void printListNode(pLinearType elem);

/**
 * 	初始化顺序表
 */
pSeqList initSeqList() {
	pSeqList p = NULL;

	p = (pSeqList) malloc(sizeof(SeqList));
	if (p == NULL) {
		printf("[%s]malloc failed\n",__func__);
	}
	p->n = 0;
	return p;
}
/**
 * 	销毁顺序表
 */
status destorySeqList(pSeqList p) {
	if (p == NULL) {
		return OK;
	}
	//fixme:modify as needed
	free(p);
	return OK;
}

/**
 * 	查找第i个元素
 */
pLinearType findSeqList(pSeqList l, int index) {
	pLinearType p = NULL;

	if (index < 1 || index > SEQ_LIST_SIZE) {
		printf("ERROR[%s]:Index is out of range\n",__func__);
		return NULL;
	}

	p = l->data + index - 1;
	return p;
}

/**
 * 	插入元素至index位置
 */
status insertSeqList(pSeqList l, int index, LinearType elem) {

	int i, j;
	if (index < 1 || index > SEQ_LIST_SIZE) {
		printf("ERROR[%s]:Index is out of range\n",__func__);
		return ERROR;
	}

	if (l->n == SEQ_LIST_SIZE) {
		printf("ERROR[%s]:List is full\n",__func__);
		return ERROR;
	}

	i = index - 1;
	j = l->n - 1;
	while(i <= j){
		l->data[j+1] = l->data[j];
		j--;
	}

	l->data[i] = elem;
	l->n++;
	return OK;
}

/**
 * 	删除第i个元素
 */
status deleteSeqList(pSeqList l, int index) {
	int i;
	if (index < 1 || index > l->n) {
		printf("ERROR[%s]:Index is out of range\n",__func__);
		return ERROR;
	}

	if (l->n == 0) {
		printf("ERROR[%s]:List is empty\n",__func__);
		return ERROR;
	}

	i = index;
	while (i < l->n) {
		l->data[i-1] = l->data[i];
		i++;
	}

	l->n--;
	return OK;
}

/**
 * 	输出顺序元素
 */
void printSeqList(pSeqList l) {
	int i = 0;
	for (i = 0; i < l->n; i++) {
		printListNode(&(l->data[i]));
	}
}

/**
 * 	初始化链表节点
 */
LinkList initLinkedNode(LinearType data) {
	LinkList node = NULL;
	node = (LinkList) malloc(sizeof(LinkedNode));
	if (node == NULL) {
		printf("ERROR[%s]:malloc failed\n",__func__);
	}
	node->link = NULL;
	//fixme:modify as needed
	node->data = data;
	return node;
}

/**
 * 	销毁链表节点
 */
status destoryLinedNode(LinkList p) {
	if (p == NULL) {
		return OK;
	}
	//fixme:modify as needed
	free(p);
	return OK;
}

/**
 * 	查找第i个元素
 */
LinkList findLinkList(LinkList l, int index) {
	LinkList p;
	int i;
	i = 1;
	p = l->link;
	while (p != NULL && i < index) {
		p = p->link;
		i++;
	}
	if (p != NULL && i == index) {
		return p;
	}
	return NULL;
}

/**
 * 	插入元素至 index位置
 */
status insertLinkList(LinkList l, int index, LinkList elem) {
	LinkList p;

	if (index < 1 || elem == NULL) {
		return ERROR;
	}

	if (index == 1) {
		p = l;
	} else {
		p = findLinkList(l, index - 1);
	}

	if (p == NULL) {
		return ERROR;
	}

	elem->link = p->link;
	p->link = elem;

	return OK;
}

/**
 * 	删除第i个元素
 */
status deleteLinkList(LinkList l, int index) {
	LinkList p, q;

	if (index == 1) {
		p = l;
	} else {
		p = findLinkList(l, index - 1);
	}

	if (p == NULL) {
		return ERROR;
	}

	q = p->link;
	p->link = q->link;
	//fixme:modify as needed
	destoryLinedNode(q);
	return OK;
}

/**
 * 	打印链表
 */
void printLinkList(LinkList l) {
	LinkList p;

	if (l != NULL) {
		p = l->link;
		while (p != NULL) {
			printListNode(&(p->data));
			p = p->link;
		}
	}

}

/**
 * 	打印链表节点
 */
//fixme:modify as needed
void printListNode(pLinearType elem) {
	printf("%c ", *elem);
}
