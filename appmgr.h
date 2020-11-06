//Taka Masagatani
//CS260
//Fall 2020
//Project 3
//Header file for main app manager
//appmgr.h

#include <iostream>
#include <cstring>

#include "table.h"

using namespace std;

class AppMgr{
public:
//Constructor
	AppMgr();

//Destructor
	~AppMgr();

//Main user sided function
	void start(); 
	
//Hash Table functions
	void add();
	void retrieve();
	void edit();
	void remove();
	void displayTopic();
	void displayAll();

private:
	Table* resources;

//Go-to string builder
	char* strbuild();
};

