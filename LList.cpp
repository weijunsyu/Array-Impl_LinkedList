
#include <iostream>
#include "LList.h"



//constructor
LList::LList() {
	//create new list
	list = new Node[DEFAULT_SIZE];
	//initialize list
	list[DEFAULT_SIZE - 1] = cons('\0', NULLPTR);
	for (int i = 0; i < DEFAULT_SIZE - 1; i++) {
		list[i] = cons('\0', i + 1);
	}
	size = DEFAULT_SIZE;
	free = 0;
	head = NULLPTR;

}

//copy constructor
LList::LList(const LList& list) {
	this->list = new Node[list.size];
	for (int i = 0; i < list.size; i++) {
		this->list[i] = cons(list.list[i].item, list.list[i].next);
	}
	size = list.size;
	head = list.head;
	free = list.free;
}

//destructor
LList::~LList() {
#ifndef NDEBUG
	std::cerr << "the destructor is being called\n";
#endif
	delete[] list;
}

//assignment overload
LList& LList::operator = (const LList& rtSide) {
	if (this != &rtSide) {
		delete[] list;
		list = new Node[rtSide.size];
		for (int i = 0; i < rtSide.size; i++) {
			list[i] = cons(rtSide.list[i].item, rtSide.list[i].next);
		}
		size = rtSide.size;
		head = rtSide.head;
		free = rtSide.free;
	}
	return *this;
}

bool LList::isEmpty() const {
	if (head == NULLPTR) {
		return true;
	}
	return false;
}

int LList::length() const {
	return length(head);
}

bool LList::cons(char ch) {
	try {
		//list is empty
		if (head == NULLPTR) {
			head = free;
			free = list[free].next;
			list[head].item = ch;
			list[head].next = NULLPTR;
			return true;
		}
		//if array is full increase size
		else if (free == NULLPTR) {
			increaseSize();
		}
		int temp = free;
		free = list[free].next;
		list[temp].item = ch;
		list[temp].next = head;
		head = temp;
		return true;
	}
	catch (const std::bad_alloc&) {
		return false;
	}
}

bool LList::append(char ch) {
	try {
		//list is empty
		if (head == NULLPTR) {
			head = free;
			free = list[free].next;
			list[head].item = ch;
			list[head].next = NULLPTR;
			return true;
		}
		//if array is full increase size
		else if (free == NULLPTR) {
			increaseSize();
		}
		int temp = free;
		free = list[free].next;
		list[temp].item = ch;
		list[temp].next = NULLPTR;
		int last = head;
		while(list[last].next != NULLPTR) {
			last = list[last].next;
		}
		list[last].next = temp;
		return true;
	}
	catch (const std::bad_alloc&) {
		return false;
	}
}

bool LList::remove(char ch) {
	if (head == NULLPTR) {
		return false;
	}
	int prev = NULLPTR;
	int current = head;
	while (current != NULLPTR) {
		if (list[current].item == ch) {
			//if element is at head
			if (prev == NULLPTR) {
				prev = current;
				head = list[current].next;
				list[prev].next = free;
				free = prev;
			}
			else {
				list[prev].next = list[current].next;
				list[current].next = free;
				free = current;
			}
			return true;
		}
		prev = current;
		current = list[current].next;
	}
	return false;
}

bool LList::found(char ch) const {
	if (head == NULLPTR) {
		return false;
	}
	for (int i = head; i != NULLPTR; i = list[i].next) {
		if (list[i].item == ch) {
			return true;
		}
	}
	return false;
}

char LList::getFirst(bool& hasFirst) const {
	if (head == NULLPTR) {
		hasFirst = false;
		return '\0';
	}
	hasFirst = true;
	return list[head].item;
}

void LList::reverse() {
	int current = head;
	int next = NULLPTR;
	int previous = NULLPTR;
	while (current != NULLPTR) {
		next = list[current].next;
		list[current].next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}

void LList::print() const {
	std::cout << "[ ";
	if (head == NULLPTR) {
		std::cout << " ";
	}
	else {
		for (int i = head; i != NULLPTR; i = list[i].next) {
			std::cout << list[i].item << " ";
		}
	}
	std::cout << "]\n";

	#ifndef NDEBUG
	dumpNodesArray();
	#endif
}

int LList::length(int p) const {
	if (p == NULLPTR) {
		return 0;
	}
	int counter = 0;
	for (int i = p; i != NULLPTR; i = list[i].next) {
		counter++;
	}
	return counter;
}
#ifndef NDEBUG
void LList::dumpNodesArray() const {
	std::cout << "=====================\n";
	std::cout << "Head = " << getHead() << " Free = " << getFree();
	std::cout << " Size = " << getSize() << "\n";
	std::cout << "---------------------\n";
	std::cout << "Index :: Item :: Next\n";
	std::cout << "---------------------\n";
	for (int i = 0; i < size; i++) {
		std::cout << i << " :: " << list[i].item << " :: " << list[i].next << "\n";
	}
	std::cout << "=====================\n";
}
#endif

LList::Node LList::cons(char ch, int p) {
	return Node{ ch, p };
}
//precondition: free == NULLPTR; array is full.
bool LList::increaseSize() {
	try {
		Node *temp = new Node[size * 2];
		for (int i = 0; i < size; i++) {
			temp[i] = list[i];
		}
		delete[] list;
		list = temp;

		free = size;
		size *= 2;
		//initialize the rest of the list
		list[size - 1] = cons('\0', NULLPTR);
		for (int j = free; j < size - 1; j++) {
			list[j] = cons('\0', j + 1);
		}

		return true;
	}
	catch (std::bad_alloc&) {
		return false;
	}
}
#ifndef NDEBUG
int LList::getHead() const {
	return head;
}

int LList::getFree() const {
	return free;
}

int LList::getSize() const {
	return size;
}
#endif
