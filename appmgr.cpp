//Taka Masagatani
//CS260
//Fall 2020
//Project 3
//cpp file for main app manager
//appmgr.cpp

#include "appmgr.h"

using namespace std;

//Constructor
AppMgr::AppMgr(){
	resources = new Table;
	resources->loadFile();
}



//Destructor
AppMgr::~AppMgr(){
	delete resources;
}



//App Management function
void AppMgr::start(){
	retrieve();
}



//Hash Table Functions
//Add New Resource Function
void AppMgr::add(){
	resources->insert();
}



//Retrieval function
void AppMgr::retrieve(){
	cout << "Please enter topic to retrieve all sites: " << endl;
	char* search = strbuild(); //Char array for topic to use for search

	int found = 0; //Int to keep array index size

	char** foundList = new char*[found]; //String array to store retrieved websites

	bool check = resources->retrieve(search, foundList, found);
	
	if(check == true){	
		cout << "Websites found for topic: " << search << endl;
		for(int i = 0; i < found; i++){
			cout << i+1 << ": " << foundList[i] << endl;
		}
	}
	else cout << "Nothing under that topic was found!" << endl;

	delete [] search;

	for(int i = 0; i < found; i++){
		delete [] foundList[i];
	}
	if(foundList != nullptr) delete [] foundList;
}



//My go-to cstring building function to save lines of code in other functions
char* AppMgr::strbuild(){
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
