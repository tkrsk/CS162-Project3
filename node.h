//Taka Masagatani
//CS260
//Fall 2020
//Project 3
//Header file for node module
//node.h

#include <iostream>
#include <cstring>

#include "data.h"

using namespace std;

class Node{
public:
//Constructors
	Node();

//Destructor
	~Node();

//Destroy data function
	void destroy();

//Accessors
	Node* getNext();
	char* getTopic();
	char* getWebsite();
	int getRating();
	
//Mutators
	void setNext(Node* parm);
		
	void bookInit(char* addTopic, char* addWebsite, char* addSummary, char* addReview, int addRating);

//Print
	void print();

private:
	Node* next;
	Data book;
};
