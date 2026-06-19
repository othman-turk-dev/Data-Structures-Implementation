#pragma once
#include "clsDblLinkedList.h"

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _MyList;

	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};

public:

	void Print()
	{
		_MyList.PrintList();
	}

	void push(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int Item)
	{
		return _MyList.GetItem(Item);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index , T ValueToUpdate)
	{
		_MyList.UpdateItem(Index, ValueToUpdate);
	}

	void InsertAfter(int Index , T Value)
	{
		_MyList.InsertAfter(Index, Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}

};

