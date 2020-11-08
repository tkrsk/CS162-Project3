//Taka Masagatani
//CS260
//Fall 2020
//Project 3
//cpp file for table module
//table.cpp

#include "table.h"

using namespace std;

//Constructor
Table::Table(){
	capacity = INIT_CAP;
	
	hashTable = new Node*[capacity];
	
	for(int i = 0; i < capacity; i++){
		hashTable[i] = nullptr;
	}
}



//Destructor
Table::~Table(){
	destroy();
}



//Destory functions
void Table::destroy(){
	for(int i = 0; i < capacity; i++){
		destroy(hashTable[i]);
	}
	if(hashTable != nullptr){
		delete [] hashTable;
	}
}



void Table::destroy(Node* curr){
	if(curr != nullptr){
		destroy(curr->getNext());
		curr->destroy();
		delete curr;
		curr = nullptr;
	}
}



//Add to data function
void Table::insert(){
	Node* add = new	Node;
	
	char* addTopic = nullptr;
	char* addWebsite = nullptr;
	char* addSummary = nullptr;
	char* addReview = nullptr;
	int addRating = 0;
	
	cout << "Please enter a topic: " << endl;
	addTopic = strbuild();

	cout << "Please enter the website: " << endl;
	addWebsite = strbuild();

	cout << "Please enter a summary: " << endl;
	addSummary = strbuild();

	cout << "Please enter a review: " << endl;
	addReview = strbuild();

	cout << "Please enter a rating(1 - 5): " << endl;
	cin >> addRating;
	cin.ignore();

	add->bookInit(addTopic, addWebsite, addSummary, addReview, addRating);

	int index = hash(addTopic);

	insert(add, index);

	delete [] addTopic;
	delete [] addWebsite;
	delete [] addSummary;
	delete [] addReview;
	addRating = 0;
}



void Table::insert(Node* add, int index){
	if(hashTable[index] == nullptr){
		hashTable[index] = add;
		size++;
	}
	else{
		Node* curr = hashTable[index];
		while(curr->getNext() != nullptr){
			curr = curr->getNext();
		}
		curr->setNext(add);
		size++;
	}
}



//Retrieval function
bool Table::retrieve(char* keyword, char**& sites, int& found){
	int index = hash(keyword);
	Node* curr = hashTable[index];
	retrieve(keyword, sites, found, curr);
	if(found > 0) return true;
	else return false;
}



void Table::retrieve(char* keyword, char**& sites, int& found, Node* curr){
	if(curr != nullptr){
		if(strcmp(curr->getTopic(), keyword) == 0){
			char** temp = new char*[found + 1];
			
			for(int i = 0; i < found; i++){
				temp[i] = sites[i];
			}
			
			char* tempSite = new char[strlen(curr->getWebsite()) + 1];
			strcpy(tempSite, curr->getWebsite());

			temp[found] = tempSite;

			found++;
			
			delete [] sites;
		
			sites = temp;
		}
		retrieve(keyword, sites, found, curr->getNext());
	}
}


//Editor function
bool Table::edit(char* search){
	int index = hash(search);
	bool found = false;

	if(hashTable[index] != nullptr){
		Node* curr = hashTable[index];
		
		cout << "Please enter the website for the topic you would like to edit: " << endl;
		
		char* editSite = strbuild();
		
		while(curr != nullptr){
			if(strcmp(curr->getWebsite(), editSite) == 0){
				cout << "Please enter a new review for the website: " << endl;
				char* newReview = strbuild();

				cout << "Please enter a new rating for the website: " << endl;
				int newRating = 0;
				cin >> newRating;
				while (!cin.good()){ //Checks for valid integer input
    				cin.clear();
	    			cin.ignore();
					cout << "Please enter a valid number!" << endl;
					cin >> newRating;
	}
				cin.ignore();

				curr->setReview(newReview);
				curr->setRating(newRating);

				found = true;

				delete [] newReview;
			}
			curr = curr->getNext();
		}
		delete [] editSite;
	}
	return found;
}



//Remove 1star functions
void Table::removeStar(){
	for(int i = 0; i < capacity; i++){
		Node* curr = nullptr;
		
		if(hashTable[i] != nullptr){
			curr = hashTable[i];
	
			Node* temp = curr->getNext();
			
			while(temp != nullptr){
				if(curr->getRating() == 1){
					delete curr;
					
					hashTable[i] = temp;
					
					curr = hashTable[i];
					
					temp = curr->getNext();
				}
				else if(temp->getRating() == 1){
					curr->setNext(temp->getNext());
					
					delete temp;
					
					temp = curr->getNext();
				}
				else{
					curr = curr->getNext();
					
					temp = temp->getNext();
				}
			}
			if(hashTable[i]->getRating() == 1){
				if(hashTable[i]->getNext() != nullptr){
					Node* temp = hashTable[i]->getNext();
					
					delete hashTable[i];
					
					hashTable[i] = temp;
				}
				else{
					delete hashTable[i];
					
					hashTable[i] = nullptr;
				}
			}
		}
	}
}



//Display functions
bool Table::displayTopic(char* search){
	int index = hash(search);
	if(hashTable[index] != nullptr){
		displayTopic(hashTable[index]);
		return true;
	}
	else{
		return false;
	}
}



void Table::displayTopic(Node* start){
	if(start != nullptr){
		start->print();
		displayTopic(start->getNext());
	}
}

void Table::displayAll(){
	for(int i = 0; i < capacity; i++){
		if(hashTable[i] != nullptr){
			displayTopic(hashTable[i]);
		}
	}
}



//Data read and write functions
void Table::loadFile(){
	ifstream infile;

	infile.open("randomdata.txt");
	
	while(infile.peek() != '~'){
		Node* add = new Node;
		
		char* addTopic = strhelper(infile);
		char* addWebsite = strhelper(infile);
		char* addSummary = strhelper(infile);
		char* addReview = strhelper(infile);
		int addRating = 0;
		
		infile >> addRating;
		
		if(infile.peek() == '\n') infile.get();

		add->bookInit(addTopic, addWebsite, addSummary, addReview, addRating);
		
		int index = hash(addTopic);

		insert(add, index);

		delete [] addTopic;
		delete [] addWebsite;
		delete [] addSummary;
		delete [] addReview;

		addRating = 0;
		//infile.ignore();
	}
}



void writeFile(char* outFile){
}



//Hashing function
int Table::hash(char* key){
	int index = 0;
	int size = strlen(key);
	for(int i = 0; i <= size; i++){
		int asci = key[i];
		index += asci * i;
	}
	index = index % capacity;
	return index;
}



//My go-to cstring building function to save lines of code in other functions
char* Table::strbuild(){
	char buffer = '\0'; //Buffer char to append to end of cstring
	char * string = nullptr; //Buffer cstring to return to where function was called

	while(cin.peek() != '\n'){
		buffer = cin.get();
		
		if(string == nullptr){
			
			string = new char[2];
			
			string[0] = buffer;
			
			string[1] = '\0';
		}
		else{
			char * temp = new char[strlen(string) + 2]; //Temporary cstring to change output string to right size CArray
			
			strcpy(temp, string);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(string) + 1] = '\0';
			
			delete [] string;
			
			string = temp;
		}
	}
	cin.ignore(); //clear buffer stream
	
	return string;
}



char* Table::strhelper(ifstream& ifile){
	char buffer = '\0'; //Buffer char to append to end of cstring
	char * string = nullptr; //Buffer cstring to return to where function was called

	while(ifile.peek() != ';'){
		buffer = ifile.get();
		
		if(string == nullptr){
			string = new char[2];
			
			string[0] = buffer;
			
			string[1] = '\0';
		}
		else{
			char * temp = new char[strlen(string) + 2]; //Temporary cstring to change output string to right size CArray
			
			strcpy(temp, string);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(string) + 1] = '\0';
			
			delete [] string;
			
			string = temp;
		}
	}
	ifile.ignore(); //clear buffer stream
	
	return string;
}
