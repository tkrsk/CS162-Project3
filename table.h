#include <iostream>
#include <cstring>
#include <fstream>

#include "node.h"

using namespace std;

class Table{
public:
//Constructor
	Table();

//Destructor
	~Table();

//Public Destroy function
	void destroy();

//Add function
	void insert();

//Retrieval function
	bool retrieve(char* keyword, char**& sites, int& found);

//Editor functions
	bool edit(char* search);

//Remove 1star function
	void removeStar();

//Public display Functions
	bool displayTopic(char* search);
	void displayAll();

//Data read and write
	void loadFile();

private:
	Node** hashTable;

	const int INIT_CAP = 397;
	int capacity;
	int size;

//Hashing function
	int hash(char* key);

//Private insert function
	void insert(Node* add, int index);

//Private destory function
	void destroy(Node* curr);

//Private display functions
	void displayTopic(Node*	start);
	void displayAll(Node* start);

//Private retrieve function
	void retrieve(char* keyword, char** &sites, int& found, Node* curr);

//Private Remove 1 Star function
	void removeStar(Node* start);

//Go-to string builder functions
	char* strbuild();
	char* strhelper(ifstream& ifile);
};
