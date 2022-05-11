#pragma once
#include <iostream>
#include "Sequence.h"
#include "DynamicArray.h"

using namespace std;

template <class T> 
class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* items;
public:
	ArraySequence(int size) {
		items = new DynamicArray<T>(size);
	}

	ArraySequence(T* arr, int count) {
		items = new DynamicArray<T>(arr, count);
	}

	ArraySequence(ArraySequence<T>& list) {
		this->items = new DynamicArray<T>(list.getLength());
		for (int i = 0; i < list.getLength(); i++)
			this->items->setData(list.get(i), i);
	}

	~ArraySequence() {
		items->~DynamicArray();
	}

	void output() {
		items->output();
	}

	int getLength() {
		return items->getSize();
	}

	T getFirst() {
		return items->getData(0);
	}

	T getLast() {
		return items->getData(items->getSize() - 1);
	}

	T get(int index) {
		return items->getData(index);
	}

	void append(T item) {
		items->resize(items->getSize() + 1);
		items->setData(item, items->getSize() - 1);
	}

	void prepend(T item) {
		items->resize(items->getSize() + 1);
		for (int i = items->getSize() - 1; i > 0; i--) {
			T tmp = items->getData(i);
			items->setData(items->getData(i - 1), i);
			items->setData(tmp, i-1);
		}
		items->setData(item, 0);
	}

	void insertAt(T item, int index) {
		items->setData(item, index);
	}

	T operator[](int index) {
		return get(index);
	}
};
