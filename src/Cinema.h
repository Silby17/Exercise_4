/****************************************
 * Yossi Silberhaft						*
 * Exercise 3							*
 * FIle: Cinema.h						*
 ****************************************/
#ifndef CINEMA_H
#define CINEMA_H
#include <string>
#include <list>
#include "Movie.h"
#include "Inputs.h"
#include <vector>
#include "Professionals.h"
#include "UDPServer.h"
#include "TCPServer.h"
#define IP_ADDRESS "127.0.0.1"

class Cinema{

protected:
	std::vector<Movie> movies;
	//std::vector<Professionals> proList;
	std::vector<Professionals*> proPtrList;
	std::vector<std::string> usrInput;
	Inputs myInputs;
	UDPServer* udpServer;
	TCPServer* tcpServer;


public:
	/************************************************************************
	 * This is the constructor method for the Cinema class					*
	 ************************************************************************/
	Cinema();

	UDPServer* makeUDP(int port);

	TCPServer* makeTCP(int port);

	/************************************************************************
	 * This function will start the running of the Program					*
	 ************************************************************************/
	void runCinema(std::string type, int port);


	/************************************************************************
	 * This function will create a new movie by receiving all the			*
	 * necessary parameters of a movie										*
	 ************************************************************************/
	void addMovie(std::vector<std::string> input);


	/************************************************************************
	 * This function will add a Professional to a certain movie by his ID   *
	 * and the movie code 													*
	 ************************************************************************/
	void  addProToMovie(std::string code, int id);


	/************************************************************************
	 * This function adds a new Professional my receiving all the			*
	 * necessary attributes													*
	 ************************************************************************/
	void addPro(std::vector<std::string> input);


	/************************************************************************
	 *This function adds Genre to a certain Movie							*
	 ************************************************************************/
	void addGenreToMovie(std::vector<std::string>);


	/************************************************************************
	 * Sorts the Professionals												*
	 * Sort Options:														*
	 * 1) By ascending														*
	 * 2) By age from Oldest to youngest									*
	 * 3) By the number of movies he appears in from the highest			*
	 * to the lowest														*
	 ************************************************************************/
	void sortPros(std::string code, int sortOption);


	/************************************************************************
	 * Prints all the Professionals in the List								*
	 ************************************************************************/
	void printAllPros();


	/************************************************************************
	 * Join multiple movies together given by their codes					*
	 ************************************************************************/
	void joinMovies(std::vector<std::string>);


	/************************************************************************
	 * Prints the movies by the professional using his ID					*
	 ************************************************************************/
	void printMoviesByPro(int id);


	/************************************************************************
	 * Prints all movies that have a certain Genre							*
	 ************************************************************************/
	void printMovieByGenre(std::string genre);


	/************************************************************************
	 * Remove a movie by the movie code										*
	 ************************************************************************/
	void removeMovie(std::string code);

	/************************************************************************
	 * Removes a professional from a movie by the Movie code				*
	 * and the Professionals ID number										*
	 ************************************************************************/
	void removeProFromMovie(std::string code, int id);


	/************************************************************************
	 * Removes a Professional from the List by their ID number				*
	 ************************************************************************/
	void removeProfessional(int id);


	/************************************************************************
	 * Prints all the Movies in the List									*
	 ************************************************************************/
	void printAllMovies();


	/************************************************************************
	 * Prints the movie from the list using its code						*
	 ************************************************************************/
	void printMovie(std::string code);


	/************************************************************************
	 * Prints the professionals of a certain movie given by the Movie Code	*
	 ************************************************************************/
	void printProsOfMovie(std::string code);


	/************************************************************************
	 * Returns the List of movies											*
	 ************************************************************************/
	std::vector<Movie> getMovieList();


	/************************************************************************
	 * Returns the list of Professionals									*
	 ************************************************************************/
	std::vector<Professionals*> getProList();


	/************************************************************************
	 * Given a movie code, this function will find the index of that Movie	*
	 * in the Movie List													*
	 ************************************************************************/
	int getMovieIndex(std::string code);


	/************************************************************************
	 * Given a Professional ID, this function will find the index of that	*
	 * Professional in the professional List								*
	 ************************************************************************/
	int getProIndex(int id);


	/************************************************************************
	 * This is a destructor of a the cinema Class							*
	 ************************************************************************/
	virtual ~Cinema();

};

#endif /*CINEMA_H*/
