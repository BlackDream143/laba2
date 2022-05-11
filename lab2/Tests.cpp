#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
using namespace std;

void arraySequenceTest();
void linkedListSequenceTest();

void startAllTests() {
	cout << "ArraySequence:\n";
	arraySequenceTest();
	cout << "LinkedListSequence:\n";
	linkedListSequenceTest();
}

void check(int flag, string msg) {
	if (flag)
		cout << "\t" << msg << " OK\n";
	else
		cout << "\t" << msg << " NO\n";
}

void arraySequenceTest() {
	int arr[3] = {1,2,3};
	ArraySequence<int> arraySequence(arr, 3);
	check(arraySequence.getFirst() == 1, "getFirst");
	check(arraySequence.getLast() == 3, "getLast");
	check(arraySequence.get(1) == 2, "get");
	arraySequence.append(4);
	arraySequence.prepend(0);
	check(arraySequence.getFirst() == 0, "prepend");
	check(arraySequence.getLast() == 4, "append");
	arraySequence.insertAt(125, 2);
	check(arraySequence.get(2) == 125, "insertAt");
}

void linkedListSequenceTest() {
	int arr[3] = { 1,2,3 };
	LinkedListSequence<int> linkedListSequence(arr, 3);
	check(linkedListSequence.getFirst() == 1, "getFirst");
	check(linkedListSequence.getLast() == 3, "getLast");
	check(linkedListSequence.get(1) == 2, "get");
	linkedListSequence.append(4);
	linkedListSequence.prepend(0);
	check(linkedListSequence.getFirst() == 0, "prepend");
	check(linkedListSequence.getLast() == 4, "append");
	linkedListSequence.insertAt(125, 2);
	check(linkedListSequence.get(2) == 125, "insertAt");
	check(linkedListSequence.getLast() == 4, "concat");
	check(linkedListSequence.getSubsequence(1, 3).get(0) == 1 && linkedListSequence.getSubsequence(1, 3).get(1) == 125 && linkedListSequence.getSubsequence(1, 3).get(2) == 2, "getSubsequence");
}