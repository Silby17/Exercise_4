/****************************************
* Yossi Silberhaft & Nava Shemoul						*
* Exercise 3							*
* File: Screenwriter.cpp				*
****************************************/
#include <iostream>
#include "Screenwriter.h"
using namespace std;


/************************************************************************
 * This is the Screenwriter class constructor which is a Professional		*
 ************************************************************************/
Screenwriter::Screenwriter(int type, int id, int age, std::string desc,
		std::string gender, std::string name)
:Professionals(type, id, age, desc, gender, name){

}


/************************************************************************
 * This function prints the Screenwriter in its correct Format			*
 ************************************************************************/
void Screenwriter::printInfo(){
	cout << this->getName() << this->getJobDescription()<< endl;
}


/************************************************************************
 * This is the Screenwriter Destructor									*
 ************************************************************************/
Screenwriter::~Screenwriter(){}

