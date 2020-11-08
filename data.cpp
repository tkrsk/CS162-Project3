//Taka Masagatani
//CS260
//Fall 2020
//Project 3
//cpp file for data module
//data.cpp

#include "data.h"

using namespace std;

//Constructor
Data::Data(){
	topic = nullptr;
	website = nullptr;
	summary = nullptr;
	review = nullptr;
	rating = 0;
}



//Destructor
Data::~Data(){
	clearData();
}



//Accessors
char* Data::getTopic(){
	return topic;
}



char* Data::getWebsite(){
	return website;
}



char* Data::getSummary(){
	return summary;
}



char* Data::getReview(){
	return review;
}



int Data::getRating(){
	return rating;
}



//Mutators
void Data::setTopic(char* addTopic){
	topic = new char[strlen(addTopic) + 1];
	strcpy(topic, addTopic);
}



void Data::setWebsite(char* addWebsite){
	website = new char[strlen(addWebsite) + 1];
	strcpy(website, addWebsite);
}



void Data::setSummary(char* addSummary){
	summary = new char[strlen(addSummary) + 1];
	strcpy(summary, addSummary);
}



void Data::setReview(char* addReview){
	review = new char[strlen(addReview) + 1];
	strcpy(review, addReview);
}



void Data::newReview(char* addReview){
	if(review != nullptr){
		delete [] review;
		review = nullptr;
	}
	review = new char[strlen(addReview) + 1];
	strcpy(review, addReview);
}



void Data::setRating(int addRating){
	rating = addRating;
}



//Wipe data function
void Data::clearData(){
	if(topic != nullptr){
		delete [] topic;
		topic = nullptr;
	}

	if(website != nullptr){
		delete [] website;
		website = nullptr;
	}

	if(summary != nullptr){
		delete [] summary;
		summary = nullptr;
	}

	if(review != nullptr){
		delete [] review;
		review = nullptr;
	}

	rating = 0;
}
