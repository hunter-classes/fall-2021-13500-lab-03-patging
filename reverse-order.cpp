/* 
reverse-order.cpp
Patrick Ging

Professor Zamansky

Lab 3 

*/
#include <iostream>
#include <fstream>


void reverse_order(std::string date1, std::string date2) {

	/* 
	Takes two dates, strings, in MM/DD/YYYY format and 
	prints the west basin volumes from them in reverse order via string concatentation

	assumes date1 was after date

	returns nothing
	*/


	//initializing the file stream
	std::ifstream input_file("./Current_Reservoir_Levels.tsv"); // file input constructor

	if (input_file.fail()) { // can't open file
		std::cerr << "File cannot be opened for reading." << std::endl;
    	exit(1); // exit if failed to open the file
	}

	//skipping first line
	std::string junk;
	std::getline(input_file, junk);


	// reading in the file 

	std::string current_date, east_basin_storage, east_elevation, west_basin_storage, west_elevation; // data from csv

	std::string resp = "\n";

	bool inRange = false;

	while(input_file >> current_date >> east_basin_storage >> east_elevation >> west_basin_storage >> west_elevation) {

		if (current_date == date1) {
			inRange = true;
		}

		if (inRange) {
			resp = current_date + " " + west_elevation + " ft\n" + resp;
		}

		if (current_date == date2) {
			break;
		}
		
		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	std::cout << resp; // printing this reverse string
}
