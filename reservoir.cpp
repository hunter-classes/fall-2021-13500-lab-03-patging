/* 
reservoir.cpp
Patrick Ging

Professor Zamansky

Lab 3 

*/
#include <iostream>
#include <fstream>

double get_east_storage(std::string date) {
	/* 

	Will look into a tsv file (at the moment Current_Reservoir_Levels.tsv )
	and will use date from MM/DD/YYYY format and will print out the 
	east basin storage of that day.

	std::string argument date

	returns nothing
	*/ 

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

	std::string entry_date, east_basin_storage; // data from csv

	while(input_file >> entry_date >> east_basin_storage) {

		if (date == entry_date) {
			return std::stold(east_basin_storage);
		}

		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	input_file.close(); // closing the stream
	return -1;
}


double get_min_east() {
	// returns smallest capacity of eastern resovior

	std::ifstream input_file("./Current_Reservoir_Levels.tsv"); // file input constructor

	if (input_file.fail()) { // can't open file
		std::cerr << "File cannot be opened for reading." << std::endl;
    	exit(1); // exit if failed to open the file
	}

	//skipping first line
	std::string junk;
	std::getline(input_file, junk);


	//file reading

	double min = INT_MAX; // done so that first value is always less

	std::string date; // not used
	std::string east_basin_storage;

	double current_value; // placeholder for the value in the tsv when converted

	while(input_file >> date >> east_basin_storage) {

		current_value = std::stold(east_basin_storage);

		if (min > current_value) {
			min = current_value;
		}

		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	input_file.close(); // closing the stream

	return min;
}

double get_max_east() {
	// returns greatest capacity of eastern resovior

	std::ifstream input_file("./Current_Reservoir_Levels.tsv"); // file input constructor

	if (input_file.fail()) { // can't open file
		std::cerr << "File cannot be opened for reading." << std::endl;
    	exit(1); // exit if failed to open the file
	}

	//skipping first line
	std::string junk;
	std::getline(input_file, junk);


	//file reading

	double max = INT_MIN; // done so that first value is always less

	std::string date; // not used
	std::string east_basin_storage;

	double current_value; // placeholder for the value in the tsv when converted

	while(input_file >> date >> east_basin_storage) {

		current_value = std::stold(east_basin_storage);

		if (max < current_value) {
			max = current_value;
		}

		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	input_file.close(); // closing the stream

	return max;
}


std::string compare_basins(std::string date) {
	/* 

	Will look into a tsv file (at the moment Current_Reservoir_Levels.tsv )
	and will use date from MM/DD/YYYY format and will print out which of the two
	basins are greater that day (reutning "east" or "west" respectively), or if they're equal, "equal"

	std::string argument date

	returns nothing
	*/ 

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

	std::string entry_date, east_basin_storage, east_elevation, west_basin_storage, west_elevation; // data from csv

	double eBasinStorage, wBasinStorage; // placeholder for values when they get converted

	while(input_file >> entry_date >> east_basin_storage >> east_elevation >> west_basin_storage >> west_elevation ) {

		if (date == entry_date) {
			 eBasinStorage = std::stold(east_basin_storage);
			 wBasinStorage = std::stold(west_basin_storage);

			 if (eBasinStorage > wBasinStorage) {
			 	return "East";
			 } else if (wBasinStorage > eBasinStorage) {
			 	return "West";
			 } else {
			 	return "Equal";
			 }
		}

		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	input_file.close(); // closing the stream
	return "";
}
