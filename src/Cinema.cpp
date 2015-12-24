/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 3							*
 * File: Cinema.cpp						*
 ****************************************/
#include "Inputs.h"
#include "Cinema.h"
#include "Producer.h"
#include "Director.h"
#include "Screenwriter.h"
#include "Actor.h"
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;
#define IP_ADDRESS "127.0.0.1"


/************************************************************************
 * This is the constructor method for the Cinema class					*
 ************************************************************************/
Cinema::Cinema(){}


/************************************************************************
 * This function is responsible for the constant running of the program	*
 * it will receive a Type and port which will be used to create			*
 * the necessary server													*
 ************************************************************************/
void Cinema::runCinema(int type, int port){
	//Sets the Type or server/client we are using
    if(type == 0){
        this->c_Type = "UDP";
    }
    else{
        this->c_Type = "TCP";
    }
	int option;
	int code;
	string usrInput;
	vector<string> inputVec;

    //Checks what server we are using
    //and then creates it
	if(this->c_Type == "TCP"){
		this->tcpServer = makeTCP(port);
	}
	else if(this->c_Type == "UDP"){
		this->udpServer = makeUDP(port);
	}

    //This is where the run loop of the program happens
	while(true){
		if(this->c_Type == "TCP"){
			usrInput = tcpServer->receiveTCP();
		}
		else {
			usrInput = udpServer->receiveFrom();
			this->newPort = udpServer->getPortNumber();
		}

		inputVec = myInputs.getInputVector(usrInput);
		option = atoi(inputVec.at(0).c_str());

		//Switch case for the users entries
		switch(option){
		//Add movie to the movie vector
		case 1:
			addMovie(inputVec);
				break;
			//Adds a Professional to the Pro List
		case 2:
			addPro(inputVec);
			break;

		case 3:
		{
			int proId = atoi(inputVec.at(2).c_str());
			addProToMovie(inputVec.at(1), proId);
			break;
		}
		case 4:
			addGenreToMovie(inputVec);
			break;

		case 5:
			sortPros(inputVec.at(1), atoi(inputVec.at(2).c_str()));
			break;
		case 6:
			printProsOfMovie(inputVec.at(1));
			break;

		case 7:
		{
			printMovie(inputVec.at(1));
			break;
		}
		case 8:
		{
			//joinMovies(inputVec);
            printStringByServer("Faliure");
			break;
		}
		case 9:
			//code = atoi(inputVec.at(1).c_str());
			printMoviesByPro(atoi(inputVec.at(1).c_str()));
			break;
		case 10:
		{
			removeMovie(inputVec.at(1));
			break;
		}
		case 11:
		{
			code = atoi(inputVec.at(1).c_str());
			removeProfessional(code);
			break;
		}
		case 12:{
			int proID =atoi(inputVec.at(2).c_str());
			removeProFromMovie(inputVec.at(1), proID);
			break;
		}

		case 13:
		{
			printAllMovies();
			break;
		}
		case 14:
			printAllPros();
			break;
		case 15:
			printMovieByGenre(inputVec.at(1));
			break;
		case -1:
		{
			exit(1);
		}
		}
	}
}


/************************************************************************
 * This function will create a new TCP server and return it, it will	*
 * receive an IP address and create and new server using that ip		*
 ************************************************************************/
TCPServer* Cinema::makeTCP(int port) {
	TCPServer* tcpServer = new TCPServer;
	tcpServer->newSocket(SOCK_STREAM);
	tcpServer->bindTCP(port);
	tcpServer->listenTCP(2);
	tcpServer->acceptTCP();

	return tcpServer;
}


/************************************************************************
 * This function will create a new UDP server and return it, it will	*
 * receive an IP address and create and new server using that ip		*
 ************************************************************************/
UDPServer* Cinema::makeUDP(int port){
	UDPServer* udpServer = new UDPServer;
	udpServer->newSocket(SOCK_DGRAM);
	udpServer->bindUDP(port);

	return udpServer;
}


/************************************************************************
 * This function sends a string to server and server prints it out.     *
 ************************************************************************/
void Cinema::printStringByServer(string printMe) {
    if(this->c_Type == "UDP"){
        this->udpServer->sendTo(IP_ADDRESS, this->newPort,printMe);
    }
    else{
        //converts string to char*
        char *y1 = new char[printMe.length() + 1];
        strcpy(y1, printMe.c_str());

        this->tcpServer->sendTCP(y1, BUFFER_SIZE);
    }
}


/************************************************************************
 * 1) This function will create a new movie by receiving all the		*
 * necessary parameters of a movie										*
 ************************************************************************/
void Cinema::addMovie(vector<string> inputVector){
	//Deceleration of variables
	string code, name, description;
	int len, year, size;
	double rating;
	code = inputVector.at(1);
	size = inputVector.size();
	string ans;

    len = atoi(inputVector.at(3).c_str());

    //Checks if the movie Exists
	int atIndex = getMovieIndex(code);
	if(atIndex != -1 || len < 0){
		ans = "Failure";
	}
	//If it doesn't exist and it returns -1 then add the Movie
	else {
		//Placing the details into their variables
		name = inputVector.at(2);
		year = atoi(inputVector.at(4).c_str());
		rating = atof(inputVector.at(5).c_str());

		//Pieces together the description
		stringstream ss;
		for(int i = 6; i < size; i++){
			ss << inputVector.at(i);
			if(i < size - 1){
				ss << " ";
			}
		}
		description = ss.str();
		int vectorSize = movies.size();
		//Creates the the movie
		Movie tempMovie(code, name, len, year, rating, description);
		//Add movie to the list
		movies.push_back(tempMovie);
		//Checks that the Movie was added to the list
		if(movies.size() - vectorSize == 1){
			ans ="Success";
		}
	}
	printStringByServer(ans);

}


/************************************************************************
 * 2) This function adds a new Professional my receiving all the		*
 * necessary attributes													*
 ************************************************************************/
void Cinema::addPro(vector<string> inputVec){
	int id, type, age;
	string gender, name, description;
	int listSize = proPtrList.size();
	string ans;

	type = atoi(inputVec.at(1).c_str());
	id = atoi(inputVec.at(2).c_str());
    age = atoi(inputVec.at(3).c_str());
    description = inputVec.at(4);
    gender = inputVec.at(5);

	//Checks that the ID number is a positive Number
	if(id < 0 || age < 0){
		ans= "Failure";
	}
	else{
		int size = inputVec.size();
		stringstream ss;
		for(int i = 6; i != size; i++){
			ss << inputVec.at(i) << " ";
		}
		name = ss.str();
		int atIndex = getProIndex(id);
		if(atIndex != - 1){
			ans = "Failure";
		}
		else {
			//Switch case to make each type of Professional
			switch(type){
			//Director
			case 0:
			{
				Professionals* newDirector =
						new Director(type, id, age, description, gender, name);
				proPtrList.push_back(newDirector);
				break;
			}
			//Actor
			case 1:
			{
				Professionals* newActor =
						new Actor(type, id, age, description, gender, name);
				proPtrList.push_back(newActor);
				break;
			}
			//Screenwriter
			case 2:
			{
				Professionals* newScreen =
						new Screenwriter(type, id, age,
								description, gender, name);
				proPtrList.push_back(newScreen);
				break;
			}
			//Producer
			case 3:
			{
				Professionals* newProducer =
						new Producer(type, id, age, description, gender, name);
				proPtrList.push_back(newProducer);
				break;
			}
			}
			if(proPtrList.size() - listSize == 1){
				ans= "Success";
			}
		}
	}
	printStringByServer(ans);
}


/************************************************************************
 * 3) This function add a Professional to a certain movie by his ID   	*
 * and the movie code 													*
 ************************************************************************/
void Cinema::addProToMovie(string code, int id){
	//Gets the index of the movie and pro in their lists
	int movieIndex = getMovieIndex(code);
	int proIndex = getProIndex(id);
	string ans;

	//Checks that both the movie and the professional exist
	if(movieIndex != -1 && proIndex != -1){
		//Checks that the Professional is not already in that movie
		if(movies.at(movieIndex).getProIndex(id) == -1){
			ans = movies.at(movieIndex).addPro(proPtrList.at(proIndex), 1);
		}
	}
	//If the movie does not exist print error messages
	else {
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * 4) This function a Genre to a certain Movie							*
 ************************************************************************/
void Cinema::addGenreToMovie(vector<string> vecInput){
	string movieCode = vecInput.at(1);
	string genre = vecInput.at(2);
	string ans;

	//Checks if the movie exists
	int atIndex = getMovieIndex(movieCode);
	//If the movie does exist then add the Genre to the Movie
	if(atIndex != -1){
		ans = movies.at(atIndex).addGenre(genre, 1);
	}
	//Else print an error message
	else{
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * 5) This function will sort the Professionals of a given movie		*
 * it will find the index of the movie to be sorted and then			*
 * activate its sort method by passing an number which is the option	*
 * of the different sort method											*
 ************************************************************************/
void Cinema::sortPros(string code, int sortOption){
	string ans;
	//Gets the movie index
	int movieIndex = getMovieIndex(code);
	if(movieIndex != -1){
		ans = movies.at(movieIndex).sortPros(sortOption);
	}
	//If the movie doesn't exist
	else {
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * 6) This function prints the list of Professionals of a certain movie	*
 * given by the movie code												*
 ************************************************************************/
void Cinema::printProsOfMovie(std::string code){
	int movieIndex = getMovieIndex(code);
	string ans;
	//Checks if the movie exists in the movies List
	if(movieIndex != -1){
		ans = movies.at(movieIndex).printAllPros();
	}
	else{
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * 7) Prints the movie from the list using its code						*
 ************************************************************************/
void Cinema::printMovie(string code){
	int index = getMovieIndex(code);
	string ans;
	//Checks if the movie exists
	if(index != -1){
		//If it does then print
		ans = movies.at(index).printMovie();
	}
	//If it doesn't then print error message
	else{
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * This function will find the index of a Professional by iterating		*
 * through the list and looking for a Professional with the given id	*
 * if the Professional doesn't exist it will return -1					*
 ************************************************************************/
int Cinema::getProIndex(int id){
	vector<Professionals*>::iterator it;
	for(it = proPtrList.begin(); it < proPtrList.end(); it++){
		if((*it)->getID() == id){
			return it - proPtrList.begin();
		}
	}
	return -1;
}


/************************************************************************
 * This function will find the index of a movie by iterating through	*
 * the list and looking for a movie with the given code					*
 * if the movie doesn't exist it will return -1							*
 ************************************************************************/
int Cinema::getMovieIndex(string code){
	vector<Movie>::iterator it;

	for(it = movies.begin(); it < movies.end(); it++){
		if(it->getCode() == code){
			return it - movies.begin();
		}
	}
	return -1;
}


/************************************************************************
 * 8) This function will merge a couple of movies given by their codes	*
 * it will break up the codes and check they exist						*
 * then it will create the new code for the movie, It will then find	*
 * which of the movies to join is the longest and save all its details	*
 * for the new Movie. Then the function will merge the Genre lists		*
 * as well as the Professional lists into the new joint movie			*
 ************************************************************************/
void Cinema::joinMovies(vector<string> inputVector){
	int tempIndex;
	bool cont = true;
	vector<int> indecies;
	string newCode;
	vector<string>codesVec;
	int i;
	string ans;

	//Breaks down the string of codes into a vector by the comma separator
	istringstream ss(inputVector.at(1));
	string token;
	while(getline(ss, token, ',')){
		codesVec.push_back(token);
	}
	//Gets the size of the codes vector
	int vectorSize = codesVec.size();

	//First check if all the movies exist in the movie list
	for(i = 0; i != vectorSize; i++){
		//If the movie exists then add the index of the movie
		// into a vector
		tempIndex = getMovieIndex(codesVec.at(i));
		if(tempIndex != -1){
			indecies.push_back(tempIndex);
		}
		else{
			cont = false;
			ans = "Failure";
			break;
		}
	}

	//If the Continue condition above holds
	if(cont){
		//Creates a new Code by stringing together the codes of the movies
		ostringstream oss;
		if(!codesVec.empty()){
			copy(codesVec.begin(), codesVec.end()-1,
					ostream_iterator<string>(oss, "_"));
			oss << codesVec.back();
		}
		//Convert the new code into string
		newCode = oss.str();

		int maxLen = 0;
		int indexOfMax = -1;
		int tempVexSize = indecies.size();

		vector<int>::iterator it;

		for(i = 0; i != tempVexSize; i++){
			if(movies.at(indecies.at(i)).getLength() > maxLen){
				maxLen = movies.at(indecies.at(i)).getLength();
				indexOfMax = indecies.at(i);
			}
		}
		int size = movies.size();
		Movie jointMovie(newCode, movies.at(indexOfMax).getMovieName(),
				movies.at(indexOfMax).getLength(),
				movies.at(indexOfMax).getYear(),
				movies.at(indexOfMax).getRating(),
				movies.at(indexOfMax).getSummary());

		//This will merge the list of all the Genres
		vector<string>::iterator sIT;
		int n;
		for(i = 0; i != tempVexSize; i++){
			vector<string> genreString =
					movies.at(indecies.at(i)).getGenreList();
			int currentGenreSize = genreString.size();
			n = 0;
			//Copies the first set of pros to the new movie
			if(i == 0){
				for(int j = 0; j != currentGenreSize; j++){
					jointMovie.addGenre(genreString.at(j), 0);
				}
			}
			else if(i > 0){
				while(n != currentGenreSize){
					if(jointMovie.checkGenre(genreString.at(n)) == false){
						jointMovie.addGenre(genreString.at(n), 0);
					}
					n++;
				}
			}
		}

		//The following code will merge the list of professionals to the new
		// Joint movie
		for(i = 0; i != tempVexSize; i++){
			//Makes a copy of the current Movie Pro list to be run through
			// Checking if the pros already appear in the new
			//Joint movie Pro list
			vector<Professionals*> proListTemp =
					movies.at(indecies.at(i)).getProList();
			int currentProSize = proListTemp.size();
			n = 0;
			//Copies the first set of pros to the new movie
			if(i == 0){
				for(int j = 0; j != currentProSize; j++){
					jointMovie.addPro(proListTemp.at(j), 0);
				}
			}
			else if(i > 0){
				while(n != currentProSize){
					if(jointMovie.getProIndex(
							proListTemp.at(n)->getID()) == -1){
						jointMovie.addPro(proListTemp.at(n), 0);
					}
					n++;
				}
			}
		}
		movies.push_back(jointMovie);
		//Checks if the new Movie as been added to the Movie List
		if(movies.size() - size == 1){
			ans = "Success";
		}
	}
	printStringByServer(ans);
}


/************************************************************************
 * 9) This function goes through the list of movies and prints the		*
 * movies that have the professionals by their ID						*
 ************************************************************************/
void Cinema::printMoviesByPro(int id){
	vector<Movie>::iterator mIT;
	bool printed = false;
	string ans;

	for(mIT = movies.begin(); mIT != movies.end(); mIT++){
		if(mIT->getProIndex(id) != -1){
			if(mIT ==  movies.begin()){
				ans = ans + mIT->printMovie();
			}
			else{
				ans = ans + "\n" +mIT->printMovie();
			}

			printed = true;
		}
	}
	if(printed == false){
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * 10)This function will remove a movie from the list by its code		*
 ************************************************************************/
void Cinema::removeMovie(string code){
	int index = getMovieIndex(code);
	int size = movies.size();
	string ans;

    //Checks if the movie is in the Movie List
	//if it doesn't then print Failure
	if(index == -1){
		ans = "Failure";
	}
	//if it is then remove the movie
	else {
		movies.erase(movies.begin() + index);
		if(size - movies.size() == 1){
			ans = "Success";
		}
	}
	printStringByServer(ans);
}


/************************************************************************
 * 11)This function will remove a Professional from the list by its code*
 ************************************************************************/
void Cinema::removeProfessional(int id){
	int index = getProIndex(id);
	int size = proPtrList.size();
	string ans;

	//Checks if the Pro exists in the List
	//if it doesn't then print Failure
	if(index == -1){
		ans = "Failure";
	}
	//If it does then remove it
	else {
		if(proPtrList.at(index)->getNumMovies() > 0){
			//Runs through the Movies and removes the Professional from them
			vector<Movie>::iterator it;
			for(it = movies.begin(); it != movies.end(); it++){
				if(it->getProIndex(id) != -1){
					 string result = it->removePro(id, 0);
				}
			}
		}
		delete proPtrList.at(index);
		proPtrList.erase(proPtrList.begin() + index);

		if(size - proPtrList.size() == 1){
			ans = "Success";
		}
	}
	printStringByServer(ans);
}


/************************************************************************
 * 12) Removes a professional from a movie by the Movie code			*
 * and the Professionals ID number										*
 ************************************************************************/
void Cinema::removeProFromMovie(string code, int id){
	int movieIndex = getMovieIndex(code);
	string ans;

	if(movieIndex != -1){
		ans = this->movies.at(movieIndex).removePro(id, 1);
	}
	else {
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * 13) Prints all the Movies in the List								*
 ************************************************************************/
void Cinema::printAllMovies(){
	//Define the iterator
	string ans;
	if(movies.size() != 0){
		vector<Movie>::iterator it;
		for(it = movies.begin(); it != movies.end(); it++){
			if(it == movies.begin()) {
				ans = ans + it->printMovie();
			}
			else{
				ans = ans +"\n" + it->printMovie();
			}
		}
	}
	else{
		ans = "Failure";
	}
	printStringByServer(ans);
}

/************************************************************************
 * 14) Prints all the Professionals of a movie given by the code		*
 ************************************************************************/
void Cinema::printAllPros(){
	string ans;
	if(proPtrList.size() != 0){
		//Define the iterator
		vector<Professionals*>::iterator it;
		for(it = proPtrList.begin(); it != proPtrList.end(); it++){
			if(it == proPtrList.begin()){
				ans = ans + (*it)->printInfo();
			}
			else{
				ans = ans +  "\n" + (*it)->printInfo();
			}

		}
	}
	else {
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * 15) This function will go through the list of movies and check their	*
 * given genres and will print the movie if it has that Genre			*
 ************************************************************************/
void Cinema::printMovieByGenre(string genre){
	bool foundAny = false;
	vector<Movie>::iterator it;
	string ans;

	for(it = movies.begin(); it != movies.end(); it++){
		if(it->checkGenre(genre) == true){
			foundAny = true;
			if(it == movies.begin()){
				ans = ans + it->printMovie();
			}
			else{
				ans = ans +"\n" + it->printMovie();
			}
		}
	}
	if(foundAny == false){
		ans = "Failure";
	}
	printStringByServer(ans);
}


/************************************************************************
 * Returns the List of movies											*
 ************************************************************************/
vector<Movie> Cinema::getMovieList(){
	return movies;
}


/************************************************************************
 * Returns the list of Professionals									*
 ************************************************************************/
vector<Professionals*> Cinema::getProList(){
	return proPtrList;
}


/************************************************************************
 * This is a destructor of a Cinema                                     *
 ************************************************************************/
Cinema::~Cinema(){}