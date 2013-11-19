/*
 * linear_list.h
 *
 *  Created on: 2013-11-19
 *      Author: zcs
 */
#include "data_structure_cmmon.h"


#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_

//fixme:modify as needed
/******* modify as needed *********/
#define SEQ_LIST_SIZE 100

typedef char LinearType;
typedef char* pLinearType;

/***************/

typedef struct {
	LinearType data[SEQ_LIST_SIZE];
	int n;
}SeqList,*pSeqList;

typedef struct node{
	LinearType data;
	struct node *link;
}LinkedNode,*LinkList;


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

#endif /* LINEAR_LIST_H_ */
