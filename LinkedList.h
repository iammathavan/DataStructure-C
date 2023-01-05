#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
	int number;
	struct LinkedList* next;
}LinkedList;

int lenLL(LinkedList* head);

LinkedList* appendLL(int data, LinkedList* head);

LinkedList* insertLL(int data, int place, LinkedList* head);

LinkedList* removeLL(int value, LinkedList* head);

int indexLL(int value, LinkedList* head);

int countLL(int value, LinkedList* head);

LinkedList* insertion_sortLL(LinkedList* head);

void printLL(LinkedList* head);

LinkedList* clearLL(LinkedList* head);
#endif
