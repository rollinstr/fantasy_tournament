/*********************************************************************
** Program name:Queue
** Author:Trevor Rollins
** Date:11/12/2017
** Description:This is the header file for the Queue class.  It contains
a struct QueueNode which holds a Character pointer, and two pointer to the next and 
previous nodes.  The Queue class allows for new QueueNodes to be created in
a circular linked list structure.  It allows for a new node to be created on the 
back of the queue, and for the front node to be removed.  Also allows for
the front node to be moved to the back of the queue
*********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include "inputValidation.hpp"
#include <string>
#include "Character.hpp"
using std::string;
using std::cout;
using std::endl;

class Queue
{
public:
	struct QueueNode
	{
		bool doDelete;
		Character* fighter;
		QueueNode* next;
		QueueNode* prev;
		QueueNode(Character* ftr, QueueNode* nextNode=nullptr, QueueNode* prevNode=nullptr);
		~QueueNode();
	};
private:
	QueueNode* head;
public:
	void emptyQueue();
	void frontToBack();
	bool isEmpty();
	void addBack(Character* fighter);
	
	Character* getFront();
	Character* getBack();
	Character* popFront();
	void printQueue();
	
	Queue();
	~Queue();
};
#endif
