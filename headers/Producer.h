/****************************************
 * Yossi Silberhaft						*
 * Exercise 1							*
 * File: Producer.h						*
 ****************************************/
#ifndef PRODUCER_H
#define PRODUCER_H
#include "Professionals.h"


class Producer: public Professionals{
public:

	Producer(int type, int id, int age, std::string desc,
			std::string gender, std::string name);
	/************************************************************************
	 * This function will print all the information of the Producer	*
	 ************************************************************************/
	void printInfo();


	~Producer();
};

#endif
