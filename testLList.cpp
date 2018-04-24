#include <iostream>
#include "LList.h"
#include <assert.h>


int main() {


	//test constructor
	LList list;
	std::cout << "This is a new empty list: [ ] == ";
	list.print();
	//test copy constructor
	LList copyList(list);
	std::cout << "This is a new empty list copy: [ ] == ";
	copyList.print();
	// test assignment overload and destructor
	if (true) {
		LList aList1;
		aList1 = list;
		LList aList2 = list;
		std::cout << "This is a new empty list assignment v1: [ ] == ";
		aList1.print();
		std::cout << "This is a new empty list assignment v2: [ ] == ";
		aList2.print();
		std::cout << "destructor should be called twice\n";
	}

	// test isEmpty on empty list
	assert(true == list.isEmpty());
	// test length on empty list
	assert(0 == list.length());
	// test found on empty list
	assert(false == list.found('b'));
	// test getFirst on empty list
	bool hasFirst;
	assert('\0' == list.getFirst(hasFirst));
	assert(false == hasFirst);
	// test remove on empty list
	assert(false == list.remove('a'));

	// test cons
	list.cons('a');
	// test length on list of length = 1
	assert(1 == list.length());

	//test found on item in list of length = 1
	assert(true == list.found('a'));
	//test found on item not in list of length = 1
	assert(false == list.found('b'));
	//test print on list of length = 1
	std::cout << "testing print on a list of length 1: [ a ] == ";
	list.print();
	// test isEmpty on list of length = 1
	assert(false == list.isEmpty());
	// test getFirst on list of length = 1
	assert('a' == list.getFirst(hasFirst));
	assert(true == hasFirst);
	// test failed remove on list of length = 1
	assert(false == list.remove('f'));
	// test passed remove on list of length = 1
	assert(true == list.remove('a'));
	//restore list after remove
	list.cons('a');

	// test append
	list.append('b');
	// test length on list of length > 1
	assert(2 == list.length());
	//test found on item in list of length > 1
	assert(true == list.found('a'));
	//test found on item not in list of length > 1
	assert(false == list.found('c'));
	//test print on list of length > 1
	std::cout << "testing print on a list of length 2: [ a b ] == ";
	list.print();
	// test isEmpty on list of length > 1;
	assert(false == list.isEmpty());
	// test getFirst on list of length > 1;
	assert('a' == list.getFirst(hasFirst));
	assert(true == hasFirst);
	// test failed remove on list of length > 1
	assert(false == list.remove('f'));
	// test passed remove on list of length > 1
	assert(true == list.remove('b'));
	//restore list after remove
	list.append('b');

	//test reverse:
	//empty list
	std::cout << "printing empty list: [ ] == ";
	copyList.print();
	copyList.reverse();
	std::cout << "printing reverse of empty list: [ ] == ";
	copyList.print();
	// list length = 1
	copyList.cons('a');
	std::cout << "printing list len 1: [ a ] == ";
	copyList.print();
	copyList.reverse();
	std::cout << "printing reverse of list: [ a ] == ";
	copyList.print();
	//list length = 2
	copyList.append('b');
	std::cout << "printing list len 2: [ a b ] == ";
	copyList.print();
	copyList.reverse();
	std::cout << "printing reverse of list: [ b a ] == ";
	copyList.print();
	//list length = 3
	copyList.append('c');
	std::cout << "printing list: [ b a c ] == ";
	copyList.print();
	copyList.reverse();
	std::cout << "printing reverse of list: [ c a b ] == ";
	copyList.print();

	//test increase of array
	LList grow;
	for (int i = 0; i < 10; i++) {
		grow.cons('T');
	}
	std::cout << "The array should be full\n";
	grow.print();

	grow.append('N');
	std::cout << "appending 'N' to the list\n";
	std::cout << "array should now have a size of 20 and 19 free nodes\n";
	std::cout << "[ T T T T T T T T T T N ] == ";
	grow.print();

	int x;
	std::cout << "type anything then press enter to exit\n";
	std::cin >> x;

	return 0;
}
