/*
 * queue.c
 *
 *  Created on: 2013-11-21
 *      Author: zcs
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "data_structure_cmmon.h"

pSeqQueue initSeqQueue();
pSeqQueue initSequeueSize(int size);
status destorySeqQueue(pSeqQueue q);
boolean isEmptySeqQueue(pSeqQueue q);
int getLengthSequeue(pSeqQueue q);
pQueueElemType getHeadSeqQueue(pSeqQueue q);
status clearSeqQueue(pSeqQueue q);
status enQueueSeqQueue(pSeqQueue q, QueueElemType elem);
status deQueueSeqQueue(pSeqQueue q, pQueueElemType elem);
status printSeqQueue(pSeqQueue q);
status printSeqQueueElem(pQueueElemType elem);
status copySeqQueueElem(pQueueElemType src, pQueueElemType des);

pLinkQueueNode initLinkQueueNode();
pLinkQueue initLinkQueue();
status destoryLinkQueueNode(pLinkQueueNode n);
status destoryLinkQueue(pLinkQueue q);
boolean isEmptyLinkQueue(pLinkQueue q);
int getLengthLinkQueue(pLinkQueue q);
pLinkQueueNode getHeadLinkQueue(pLinkQueue q);
status clearLinkQueue(pLinkQueue q);
status enQueueLinkQueue(pLinkQueue q, pLinkQueueNode n);
status deQueueLinkQueue(pLinkQueue q, pLinkQueueNode *elem);
status printLinkQueue(pLinkQueue q);
status printLinkQueueNode(pLinkQueueNode p);

status deQueueCirSeqQueue(pSeqQueue q, pQueueElemType elem);
status enQueueCirSeqQueue(pSeqQueue q,QueueElemType elem);

/**
 *	初始化顺序队列
 **/
pSeqQueue initSeqQueue() {
	pSeqQueue q = NULL;
	q = (pSeqQueue) malloc(sizeof(SeqQueue));
	if (q == NULL) {
		printf("ERROR[%s]malloc queue failed\n", __func__);
		return NULL;
	}
	q->base = NULL;
	q->head = -1;
	q->size = 0;
	q->rear = -1;
	return q;
}

/**
 * 根据大小初始化顺序队列
 */
pSeqQueue initSequeueSize(int size) {
	pSeqQueue q = NULL;
	q = initSeqQueue();
	if (q == NULL) {
		printf("[%s]malloc queue failed\n", __func__);
		return NULL;
	}
	q->base = (pQueueElemType) malloc((size + 1) * sizeof(QueueElemType));
	if (q->base == NULL) {
		printf("ERROR[%s]malloc queue elements failed\n", __func__);
		return NULL;
	}
	q->head = 0;
	q->size = size;
	q->rear = 0;
	return q;
}

/**
 * 销毁顺序队列
 */
status destorySeqQueue(pSeqQueue q) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return OK;
	}
	if (q->base != NULL) {
		free(q->base);
	}
	q->base = NULL;
	free(q);
	return OK;
}

/**
 * 顺序队列是否为空
 */
boolean isEmptySeqQueue(pSeqQueue q) {
	if (q == NULL) {
		return TRUE;
	}
	if (q->rear == q->head) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
 * 获得顺序队列长度
 */
int getLengthSequeue(pSeqQueue q) {
	int length = -1;
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return -1;
	}
	length = q->rear - q->head;
	return length;
}

/**
 * 获取队头元素
 */
pQueueElemType getHeadSeqQueue(pSeqQueue q) {
	pQueueElemType head = NULL;
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return NULL;
	}
	if (isEmptySeqQueue(q)) {
		printf("[%s]queue is empty!\n", __func__);
		return NULL;
	}
	head = q->base + q->head;
	return head;
}

/**
 * 清空顺序队列
 */
status clearSeqQueue(pSeqQueue q) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	q->head = 0;
	q->rear = 0;
	return OK;
}

/**
 * 顺序队列入队
 */
status enQueueSeqQueue(pSeqQueue q, QueueElemType elem) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	if (q->rear == q->size) {
		printf("[%s]queue is full\n", __func__);
		return ERROR;
	}
	copySeqQueueElem(&elem, &(q->base[q->rear]));
	q->rear++;
	return OK;
}

/**
 * 顺序队列出队
 */
status deQueueSeqQueue(pSeqQueue q, pQueueElemType elem) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	if (isEmptySeqQueue(q)) {
		printf("[%s]queue is empty\n", __func__);
		return ERROR;
	}
	copySeqQueueElem(&(q->base[q->head]), elem);
	q->head++;
	return OK;
}

/**
 * 打印顺序队列
 */
status printSeqQueue(pSeqQueue q) {
	int i;
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	if (isEmptySeqQueue(q)) {
		printf("[%s]queue is empty\n", __func__);
		return OK;
	}
	i = q->head;
	while (i < q->rear) {
		printSeqQueueElem(q->base + i);
		i++;
	}
	return OK;
}

/**
 * 复制顺序队列元素
 */
status copySeqQueueElem(pQueueElemType src, pQueueElemType des) {
	//fixme:modify as needed
	*des = *src;
	return OK;
}

/**
 * 打印顺序队列元素
 */
status printSeqQueueElem(pQueueElemType elem) {
	//fixme:modify as needed
	printf("%d ", *elem);
	return OK;
}

/**
 * 初始化链队列节点
 */
pLinkQueueNode initLinkQueueNode() {
	pLinkQueueNode p = NULL;
	p = (pLinkQueueNode) malloc(sizeof(LinkQueueNode));
	if (p == NULL) {
		printf("ERROR[%s]:malloc link queue node failed!\n", __func__);
		return NULL;
	}
	p->next = NULL;
	return p;
}

/**
 * 初始化链队列
 */
pLinkQueue initLinkQueue() {
	pLinkQueue p = NULL;
	p = (pLinkQueue) malloc(sizeof(LinkQueue));
	if (p == NULL) {
		printf("ERROR[%s]:malloc link queue failed!\n", __func__);
		return NULL;
	}
	p->head = NULL;
	p->rear = NULL;
	p->size = 0;
	return p;
}

/**
 * 销毁链队列节点
 */
status destoryLinkQueueNode(pLinkQueueNode n) {
	if (n == NULL) {
		return OK;
	}
	n->next = NULL;
	free(n);
	return OK;
}

/**
 * 销毁链队列
 */
status destoryLinkQueue(pLinkQueue q) {
	pLinkQueueNode p;
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	p = q->head;
	while (p != NULL) {
		q->head = p->next;
		destoryLinkQueueNode(p);
		p = q->head;
	}
	q->head = NULL;
	q->rear = NULL;
	q->size = 0;
	free(q);
	return OK;
}

/**
 * 判断链队列是否为空
 */
boolean isEmptyLinkQueue(pLinkQueue q) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return -1;
	}
	if (q->size == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
 * 获取队列长度
 */
int getLengthLinkQueue(pLinkQueue q) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return -1;
	}
	return q->size;
}

/**
 * 获取链队列头节点
 */
pLinkQueueNode getHeadLinkQueue(pLinkQueue q) {
	pLinkQueueNode head;
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return NULL;
	}
	if (isEmptyLinkQueue(q)) {
		printf("[%s]queue is empty!\n", __func__);
		return NULL;
	}
	head = q->head;
	return head;
}

/**
 * 清空链队列
 */
status clearLinkQueue(pLinkQueue q) {
	pLinkQueueNode p;
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	p = q->head;
	while (p != NULL) {
		q->head = p->next;
		destoryLinkQueueNode(p);
		p = q->head;
	}
	q->head = NULL;
	q->rear = NULL;
	q->size = 0;
	return OK;
}

/**
 * 链队列入队
 */
status enQueueLinkQueue(pLinkQueue q, pLinkQueueNode n) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	if (isEmptyLinkQueue(q)) {
		n->next = NULL;
		q->head = n;
		q->rear = n;
	} else {
		n->next = q->rear->next;
		q->rear->next = n;
		q->rear = n;
	}
	q->size++;
	return OK;
}

/**
 * 	链队列出队
 */
status deQueueLinkQueue(pLinkQueue q, pLinkQueueNode *elem) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		*elem = NULL;
		return ERROR;
	}
	if (isEmptyLinkQueue(q)) {
		printf("[%s]queue is empty!\n", __func__);
		*elem = NULL;
		return ERROR;
	}
	*elem = q->head;
	q->head = q->head->next;
	(*elem)->next = NULL;
	q->size--;
	return OK;
}

/**
 *	输出链队列
 */
status printLinkQueue(pLinkQueue q) {
	pLinkQueueNode p;
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	if (isEmptyLinkQueue(q)) {
		printf("[%s]queue is empty!\n", __func__);
		return OK;
	}
	p = q->head;
	while (p != q->rear) {
		printLinkQueueNode(p);
		p = p->next;
	}
	printLinkQueueNode(q->rear);
	return OK;
}

/**
 *	打印链队列节点
 */
status printLinkQueueNode(pLinkQueueNode p) {
	//fixme:modify as needed
	printf("%d ", p->data);
	return OK;
}

/**
 * 循环队列入队
 */
status enQueueCirSeqQueue(pSeqQueue q,QueueElemType elem){
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	if (q->rear == q->size) {
		printf("[%s]queue is full\n", __func__);
		return ERROR;
	}
	copySeqQueueElem(&elem, &(q->base[q->rear]));
	q->rear = (q->rear + 1) % q->size;
	return OK;
}

/**
 * 循环队列出队
 */
status deQueueCirSeqQueue(pSeqQueue q, pQueueElemType elem) {
	if (q == NULL) {
		printf("[%s]queue not exist!\n", __func__);
		return ERROR;
	}
	if (isEmptySeqQueue(q)) {
		printf("[%s]queue is empty\n", __func__);
		return ERROR;
	}
	copySeqQueueElem(&(q->base[q->head]), elem);
	q->head = (q->head + 1) % q->size;
	return OK;
}
