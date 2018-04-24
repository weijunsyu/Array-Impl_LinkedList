#ifndef LLIST_H
#define LLIST_H

//#define NDEBUG


class  LList {
   public:
      // build a list
      LList();
      // determine if the list is empty
      bool isEmpty() const;
      // give length of list
      int length() const;
      // insert ch at the beginning (at the front) of the linked list
      // return true if successful, false otherwise
      bool cons(char ch);
      // append ch to the end of the linked list
      // return true if successful, false otherwise
      bool append(char ch);
      // delete the first occurence of ch in the list
      // if the deletion happens, return true,  false otherwise
      bool remove(char ch);
      // search ch in the list, return true if found, false otherwise
      bool found(char ch) const;
      // if the list is empty,  getFirst is set to false and the character '\0'
      // is returned, otherwise it returns the first character of the list and
      // hasFirst is set to true
      char getFirst(bool& hasFirst) const;
      // reverses the list, the original list is mutated
      void reverse();
      // print the list to standard output started with a  '[' and finished
      // with a ']' followed by an end-of-line
      // dumps the array when NDEBUG is defined
      void print() const;

      // copy constructor
      LList(const LList&);
      // destructor
      ~LList();
      // overloaded assignment operator
      LList& operator = (const LList& rtSide);

   private:
	   struct Node {
		   char item;
		   int next;
	   };
	   Node * list;
	   //size of array
	   int size;

	   int free;
	   int head;

	   static const int NULLPTR = -1;
	   //initial size of array
	   static const int DEFAULT_SIZE = 10;


      // get the length of the list p
      int length(int p) const;

	  // construct a new Node
	  static Node cons(char ch, int p);

	  // double size of list
      //precondition: free == NULLPTR; array is full.
	  bool increaseSize();


      #ifndef NDEBUG
      // dump the array
      void dumpNodesArray() const;
      // possibly other code
	  int getHead() const;
	  int getFree() const;
	  int getSize() const;
      #endif

};
#endif
