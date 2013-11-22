/*
 * queue.h
 *
 *  Created on: 2013-11-21
 *      Author: zcs
 */

#include "data_structure_cmmon.h"
#ifndef QUEUE_H_
#define QUEUE_H_

//fixme:modify as needed
/******* modify as needed *********/
#define SEQ_STACK_SIZE 100

typedef int QueueElemType;
typedef int* pQueueElemType;

/***************/

typedef struct{
	pQueueElemType base;
	int head;
	int rear;
	int size;
}SeqQueue,*pSeqQueue;


typedef struct lqueue_node{
	QueueElemType data;
	struct lqueue_node *next;
}LinkQueueNode,*pLinkQueueNode;

typedef struct{
	pLinkQueueNode head;
	pLinkQueueNode rear;
	int size;
}LinkQueue,*pLinkQueue;

pSeqQueue initSeqQueue();
pSeqQueue initSequeueSize(int size);
status destorySeqQueue(pSeqQueue q);
boolean isEmptySeqQueue(pSeqQueue q);
int getLengthSequeue(pSeqQueue q);
pQueueElemType getHeadSeqQueue(pSeqQueue q);
status clearSeqQueue(pSeqQueue q);
status enQueueSeqQueue(pSeqQueue q,QueueElemType elem);
status deQueueSeqQueue(pSeqQueue q,pQueueElemType elem);
status printSeqQueue(pSeqQueue q);
status printSeqQueueElem(pQueueElemType elem);
status copySeqQueueElem(pQueueElemType src,pQueueElemType des);

pLinkQueueNode initLinkQueueNode();
pLinkQueue initLinkQueue();
status destoryLinkQueueNode(pLinkQueueNode n);
status destoryLinkQueue(pLinkQueue q);
boolean isEmptyLinkQueue(pLinkQueue q);
int getLengthLinkQueue(pLinkQueue q);
pLinkQueueNode getHeadLinkQueue(pLinkQueue q);
status clearLinkQueue(pLinkQueue q);
status enQueueLinkQueue(pLinkQueue q,pLinkQueueNode n);
status deQueueLinkQueue(pLinkQueue q,pLinkQueueNode *elem);
status printLinkQueue(pLinkQueue q);
status printLinkQueueNode(pLinkQueueNode p);

status deQueueCirSeqQueue(pSeqQueue q, pQueueElemType elem);
status enQueueCirSeqQueue(pSeqQueue q,QueueElemType elem);
#endif /* QUEUE_H_ */
