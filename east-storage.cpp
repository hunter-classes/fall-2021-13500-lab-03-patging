
#include <iostream>
#include <fstream>

void get_storage_by_data() {
	/* 

	Will look into a tsv file (at the moment Current_Reservoir_Levels.tsv )
	and will use cin to ask for a date in MM/DD/YYYY format and will print out the 
	east basin storage of that day.

	no arguments, returns nothing
	*/

	// getting query

	std::string query;

	std::cout << "Enter date: ";
	std::cin >> query; 

	//file input

	std::ifstream input_file("./Current_Reservoir_Levels.tsv"); // file input constructor

	if (input_file.fail()) { // can't open file
		std::cerr << "File cannot be opened for reading." << std::endl;
    	exit(1); // exit if failed to open the file
	}

	//skipping first line
	std::string junk;
	std::getline(input_file, junk);


	//file reading

	std::string date, east_basin_storage; // data from csv

	while(input_file >> date >> east_basin_storage) {
		//std::cout << date << std::endl;

		if (query == date) {
			std::cout << "East basin storage: " << east_basin_storage << " billion gallons" << std::endl;
		}

		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	input_file.close(); // closing the stream
}


int main() {

	get_storage_by_data();

	return 0;
}

