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

	int command;

	cout << "(0) To Exit.\n(1) Add new website.\n(2) Retrieve all websites from a certain topic.\n(3) Edit the reviews and rating on a certain website." << endl;
	cout << "(4) Remove all 1-star reviewed websites.\n(5) Show all websites under a certain topic.\n(6) Show all websites." << endl;
	cout << "What would you like to do?" << endl;
	cin >> command;
	while (!cin.good()){ //Checks for valid integer input
    	cin.clear();
	    cin.ignore();
		cout << "Please enter a valid number!" << endl;
		cin >> command;
	}
	cin.ignore();

	while(command > 0 && command <= 6){
		while (!cin.good()){ //Checks for valid integer input
    		cin.clear();
	    	cin.ignore();
			cout << "Please enter a valid number!" << endl;
			cin >> command;
		}
		if(command == 1){
			add();
		}

		else if(command == 2){
			retrieve();
		}

		else if(command == 3){
			edit();
		}

		else if(command == 4){
			remove();
		}

		else if(command == 5){
			displayTopic();
		}
		
		else if(command == 6){
			displayAll();
		}
		
		cout << "(0) To Exit.\n(1) Add new website.\n(2) Retrieve all websites from a certain topic.\n(3) Edit the reviews and rating on a certain website." << endl;
		cout << "(4) Remove all 1-star reviewed websites.\n(5) Show all websites under a certain topic.\n(6) Show all websites." << endl;
		cout << "What would you like to do?" << endl;
		cin >> command;
		cin.ignore();
	}
	cout << "Good Bye!" << endl;
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



void AppMgr::edit(){
	cout << "Please enter the topic you would like to edit a website for: " << endl;
	
	char* search = strbuild();

	while(strlen(search) < 1){
		cout << "You entered a blank item, try again: " << endl;
		search = strbuild();
	}
	
	bool check = resources->edit(search);
	
	if(check == false){
		cout << "Website was not found!" << endl;
	}

	delete [] search;
	search = nullptr;
}



void AppMgr::remove(){
	resources->removeStar();

	cout << "Removed all 1-star reviewed websites!" << endl;
}



void AppMgr::displayTopic(){
	cout << "Please enter the topic you would like to: " << endl;
	char* search = strbuild();

	while(strlen(search) < 1){
		cout << "You entered a blank item, try again: " << endl;
		search = strbuild();
	}

	bool check = resources->displayTopic(search);

	if(check == false){
		cout << "Topic was not found!" << endl;
	}

	delete [] search;
	search = nullptr;

}



void AppMgr::displayAll(){
	resources->displayAll();
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
