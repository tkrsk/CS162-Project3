#include "node.h"

using namespace std;

//Constructor
Node::Node(){
	next = nullptr;
}



//Destructor
Node::~Node(){
	next = nullptr;	
}



//Book.data wiping function
void Node::destroy(){
	book.clearData();
}



//Accessor
Node* Node::getNext(){
	return next;
}



char* Node::getTopic(){
	return book.getTopic();
}



char* Node::getWebsite(){
	return book.getWebsite();
}



int Node::getRating(){
	return book.getRating();
}



//Mutators
void Node::setNext(Node* parm){
	next = parm;
}



void Node::setReview(char* addReview){
	book.newReview(addReview);
}



void Node::setRating(int addRating){
	book.setRating(addRating);
}



void Node::bookInit(char* addTopic, char* addWebsite, char* addSummary, char* addReview, int addRating){
	book.setTopic(addTopic);
	
	book.setWebsite(addWebsite);
	
	book.setSummary(addSummary);
	
	book.setReview(addReview);
	
	book.setRating(addRating);
}



//Print
void Node::print(){
	cout << "---" << endl;
	cout << "Topic: " <<  book.getTopic() << endl;
	cout << "Wesbite: " << book.getWebsite() << endl;
	cout << "Summary: " << book.getSummary() << endl;
	cout << "Review: " << book.getReview() << endl;
	cout << "Rating: " << book.getRating() << endl;
	cout << endl;
}
