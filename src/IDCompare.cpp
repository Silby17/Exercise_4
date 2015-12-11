/****************************************
 * Yossi Silberhaft						*
 * Exercise 3							*
 * File: IDCompare.cpp					*
 ****************************************/
#include "IDCompare.h"
#include "Professionals.h"

bool IDCompare::operator ()(const Professionals* first,
		const Professionals* second){

	return (first->getID() < second->getID());
}
