/*********************************************************************
** Program name:Queue
** Author:Trevor Rollins
** Date:11/12/2017
** Description:This is the implementation file for the Queue class.
*********************************************************************/
#include "Queue.hpp"

/*********************************************************************
** Function Purpose:This is the constructor for the QueueNode struct.  It initializes
the fighter, and the prev and next pointers
** Arguments:It takes an int and two QueueNode* to initialize the member data.
The default values for the pointers is nullptr
** Restrictions:None
** Return Value:None
*********************************************************************/
Queue::QueueNode::QueueNode(Character* ftr, QueueNode* nextNode, QueueNode* prevNode)
{
	next = nextNode;
	prev = prevNode;
	doDelete = true;
	fighter = ftr;
}
/*********************************************************************
** Function Purpose:This is the destructor for the QueueNode struct.  It only
deletes the fighter member if the doDelete member is true
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Queue::QueueNode::~QueueNode()
{
	if (doDelete)
	{
		delete fighter;
	}
}

/*********************************************************************
** Function Purpose:This is the default constructor for the Queue class.
It initializes the head to nullptr.
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Queue::Queue()
{
	head = nullptr;
}
/*********************************************************************
** Function Purpose:This creates a new QueueNode at the back of the Queue.
** Arguments:An character* to initialize the value held in the node
** Restrictions:None
** Return Value:None
*********************************************************************/
void Queue::addBack(Character* fighter)
{
	if (isEmpty())
	{
		head = new QueueNode(fighter);
		head->next = head;
		head->prev = head;
	}
	else
	{
		QueueNode* nextNode = head;
		while (nextNode->next != head)
		{
			nextNode = nextNode->next;
		}
		nextNode->next = new QueueNode(fighter, head, nextNode);
		head->prev = nextNode->next;
	}
}
/*********************************************************************
** Function Purpose:This deletes the front QueueNode from the Queue
and returns the character* held in that node.  it also sets doDelete to
false so that the character is not deleted by this node
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Character* Queue::popFront()
{
	Character* tempChar = head->fighter;
	if (isEmpty())
	{
		cout << "The queue is empty." << endl;
	}
	else if (head == head->next)
	{
		head->doDelete = false;
		delete head;
		head = nullptr;
	}
	else
	{
		QueueNode* tail = head;
		while (tail->next != head)
		{
			tail = tail->next;
		}
		QueueNode* tempHead = head->next;
		head->doDelete = false;
		delete head;
		head = tempHead;
		tail->next = head;
		head->prev = tail;
	}
	return tempChar;
}
/*********************************************************************
** Function Purpose:This returns the value of the front Node in the Queue
** Arguments:None
** Restrictions:None
** Return Value:An int representing the value of the front node
*********************************************************************/
Character* Queue::getFront()
{
	if (isEmpty())
	{
		return nullptr;
	}
	else
	{
		return head->fighter;
	}
}
/*********************************************************************
** Function Purpose:This returns the character* of the back node
** Arguments:None
** Restrictions:None
** Return Value:Character*
*********************************************************************/
Character* Queue::getBack()
{
	if (isEmpty())
	{
		return nullptr;
	}
	else
	{
		return head->prev->fighter;
	}
}

/*********************************************************************
** Function Purpose:This moves the front node of the queue to the back 
of the queue
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void Queue::frontToBack()
{
	Character* temp = popFront();
	if (temp != nullptr)
	{
		addBack(temp);
	}
}
/*********************************************************************
** Function Purpose:This checks whether the queue is empty
** Arguments:None
** Restrictions:None
** Return Value:A bool, true if empty, false if not
*********************************************************************/
bool Queue::isEmpty()
{
	return (head == nullptr);
}
/*********************************************************************
** Function Purpose:This prints the Queue front to back
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void Queue::printQueue()
{
	if (isEmpty())
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		QueueNode* nextNode = head;
		do
		{
			cout << nextNode->fighter->getName() << " ";
			nextNode = nextNode->next;
		} while (nextNode != head);
		cout << endl;
	}
}
/*********************************************************************
** Function Purpose:This deleles each node of the queue, clearing its contents
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void Queue::emptyQueue()
{
	if (!isEmpty())
	{
		QueueNode* tail = head->prev;
		while (tail != head)
		{
			QueueNode* newTail = tail->prev;
			delete tail;
			tail = newTail;
		}
		delete head;
		head = nullptr;
	}
}

/*********************************************************************
** Function Purpose:This is the queue destructor.  It deletes all the QueueNodes
inside the Queue.
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Queue::~Queue()
{
	emptyQueue();
}
