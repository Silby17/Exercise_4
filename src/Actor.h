/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 3							*
 * FIle: Actor.h							*
 ****************************************/
#ifndef ACTOR_H_
#define ACTOR_H_
#include "Professionals.h"

class Actor: public Professionals{
public:

	/************************************************************************
	 * This is the Actor Constructor										*
	 ************************************************************************/
	Actor(int type, int id, int age, std::string desc,
			std::string gender, std::string name);


	/************************************************************************
	 * This function will print all the information of the Actor			*
	 ************************************************************************/
	void printInfo();

	/************************************************************************
	 * This is the Actor Destructor										*
	 ************************************************************************/
	~Actor();
};
#endif
