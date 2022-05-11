#pragma once
#include <iostream>
#include "Sequence.h"
#include "LinkedList.h"

using namespace std;

template <class T> 
class LinkedListSequence : public Sequence<T> {
private:
	LinkedList<T>* list;
public:
	LinkedListSequence() {
		list = new LinkedList<T>();
	}

	LinkedListSequence(T* items, int count) {
		list = new LinkedList<T>(items, count);
	}

	LinkedListSequence(LinkedListSequence<T>& list) {
		this->list = new LinkedList<T>();
		for (int i = 0; i < list.getLength(); i++)
			this->list->append(list.get(i));
	}

	~LinkedListSequence() {
		list->~LinkedList();
	}

	int getLength() {
		return list->getLength();
	}

	void append(T item) {
		list->append(item);
	}

	void prepend(T item) {
		list->prepend(item);
	}

	T getFirst() {
		return list->getFirst();
	}

	T getLast() {
		return list->getLast();
	}

	T get(int index) {
		return list->get(index);
	}

	void output() {
		list->output();
	}

	void insertAt(T item, int index) {
		list->insertAt(item, index);
	}

	LinkedListSequence<T> getSubsequence(int startIndex, int endIndex) {
		LinkedListSequence<T> tmpList;
		LinkedList<T> subList = list->getSubList(startIndex, endIndex);
		for (int i = 0; i < subList.getLength(); i++)
			tmpList.append(subList.get(i));
		return tmpList;
	}

	LinkedListSequence<T> concat(LinkedListSequence<T> list) {
		LinkedList<T> tmpList;
		for (int i = 0; i < list.getLength(); i++)
			tmpList.append(list.get(i));
		LinkedList<T> concatedList = this->list->concat(tmpList);
		LinkedListSequence<T> resList;
		for (int i = 0; i < concatedList.getLength(); i++)
			resList.append(concatedList.get(i));
		return resList;
	}
};
