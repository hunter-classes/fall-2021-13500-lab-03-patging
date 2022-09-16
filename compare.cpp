
#include <iostream>
#include <fstream>


void compare_using_date() {

	// getting dates
	std::string start_date, end_date;

	std::cout << "Enter starting date: ";
	std::cin >> start_date;

	std::cout << "Enter ending date: ";
	std::cin >> end_date;


	//interfacing w file

	std::ifstream input_file("./Current_Reservoir_Levels.tsv"); // file input constructor

	if (input_file.fail()) { // can't open file
		std::cerr << "File cannot be opened for reading." << std::endl;
    	exit(1); // exit if failed to open the file
	}

	//skipping first line
	std::string junk;
	std::getline(input_file, junk);


	// finding the starting point

	double east, west;

	std::string date, east_basin_storage, west_basin_storage, west_elevation, east_elevation;

	bool inRange = false; // a variable for helping us index the start

	// going through the file
	while(input_file >> date >> east_basin_storage >> east_elevation >> west_basin_storage >> west_elevation) {

		if (date == start_date) {
			inRange = true; // letting us know to start comparing
		}

		if (inRange) {

			if (east_basin_storage > west_basin_storage) {
				//east
				std::cout << date << " East" << "\n";
 
			} else if( east_basin_storage < west_basin_storage) {
				// west
				std::cout << date << " West" << "\n";

			} else { // equal
				std::cout << date << " Equal" << "\n";
			}

			if (date == end_date) { // we have reached the end_date
				break;
			}

		}

		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	input_file.close(); // closing the stream

}


int main() {
	compare_using_date();
	return 0;
}