#pragma once

template<class E>
struct node
{
	E data;
	node<E> *next;
};
template<class E>
class LinkedList 
{
private:
	

	node<E> *head, *tail;
	size_t count;
public:
	
	LinkedList():count(0)
	{
	}

	~LinkedList()
	{
		if (head == 0)
			return;
		node<E> *tmp ;
		node<E> *next = head;
		do {

			tmp = next->next;
			delete next;
			next = tmp;
		} while (next != head);
	}

	void addEnd(E e);

	E get(node<E>*);
	
	bool isEmpty();
	void removeEnd();
	void removeStart();
	size_t size();
	void clear();
	node<E>* getStart()
	{
		return head;
	}
	node<E>* getEnd()
	{
		return tail;
	}
	node<E>* getNext(node<E>*);
	bool isEnd(node<E>* tmp)
	{
		if (tmp->next == head || tmp->next == 0)
			return true;
		return false;
	}
	//*/

};

template<class E>
void LinkedList<E>::addEnd(E e)
{
	node<E> *tmp = new node<E>;
	tmp->data = e;
	if (head == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tmp;
	}
	tmp->next = head;
	++count;
}

template<class E>
E LinkedList<E>::get(node<E>* tmp)
{
	if (tmp == nullptr)
		throw 1;
	return tmp->data;
}


template<class E>
inline bool LinkedList<E>::isEmpty()
{
	return count == 0;
}

template<class E>
inline void LinkedList<E>::removeEnd()
{
	if (count == 0)
		return;
	if (count == 1)
	{
		delete head;
		head = tail = 0;
		count = 0;
		return;
	}

	node<E> *prev = head;
	while (prev->next != tail)//идём до предпоследнего элеметы
		prev = prev->next;
	
	tail = prev;//меняем что конец является предпоследним элементом
	delete tail->next;//удаляем указатель на последний элемент
	tail->next = head;//зацикливаем на начало
	--count;
}
template<class E>
inline void LinkedList<E>::removeStart()
{
	if (count == 1)
	{
		delete head;
		head = tail = 0;
		count = 0;
		return;
	}
	
	head = head->next;
	delete tail->next;
	tail->next = head;

	--count;
}


template<class E>
inline size_t LinkedList<E>::size()
{
	return count;
}

template<class E>
inline void LinkedList<E>::clear()
{
	node<E> *tmp;
	node<E> *next = head;
	do
	{
		tmp = next->next;
		delete next;
		next = tmp;

	} while (next != head);
	head = tail = 0;
	count = 0;
}

template<class E>
inline node<E>* LinkedList<E>::getNext(node<E>* tmp)
{
	return tmp->next;
}
