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

pSeqList initSeqList() {
	pSeqList p = NULL;

	p = (pSeqList) malloc(sizeof(SeqList));
	if (p == NULL) {
		printf("malloc failed\n");
	}
	p->n = 0;
	return p;
}

status destorySeqList(pSeqList p) {
	if (p == NULL) {
		return OK;
	}
	//fixme:modify as needed
	free(p);
	return OK;
}

pLinearType findSeqList(pSeqList l, int index) {
	pLinearType p = NULL;

	if (index < 1 || index > SEQ_LIST_SIZE) {
		printf("ERROR:Index is out of range\n");
		return NULL;
	}

	p = l->data + index - 1;
	return p;
}

status insertSeqList(pSeqList l, int index, LinearType elem) {

	int i, j;
	if (index < 1 || index > SEQ_LIST_SIZE) {
		printf("ERROR:Index is out of range\n");
		return ERROR;
	}

	if (l->n == SEQ_LIST_SIZE) {
		printf("ERROR:List is full\n");
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

status deleteSeqList(pSeqList l, int index) {
	int i;
	if (index < 1 || index > l->n) {
		printf("ERROR:Index is out of range\n");
		return ERROR;
	}

	if (l->n == 0) {
		printf("ERROR:List is empty\n");
		return ERROR;
	}

	i = index;
//	j = index;
	while (i < l->n) {
		l->data[i-1] = l->data[i];
		i++;
//		j++;
	}

	l->n--;
	return OK;
}

void printSeqList(pSeqList l) {
	int i = 0;
	for (i = 0; i < l->n; i++) {
		printListNode(&(l->data[i]));
	}
}

LinkList initLinkedNode(LinearType data) {
	LinkList node = NULL;
	node = (LinkList) malloc(sizeof(LinkedNode));
	if (node == NULL) {
		printf("malloc failed\n");
	}
	node->link = NULL;
	//fixme:modify as needed
	node->data = data;
	return node;
}

status destoryLinedNode(LinkList p) {
	if (p == NULL) {
		return OK;
	}
	//fixme:modify as needed
	free(p);
	return OK;
}

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

//fixme:modify as needed
void printListNode(pLinearType elem) {
	printf("%c ", *elem);
}
