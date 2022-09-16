
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

	std::string date;
	std::string east_basin_storage;
	std::string west_basin_storage;


	while(input_file >> date >> east_basin_storage >> west_basin_storage) {

		if (current_value > max) {
			max = current_value;
			continue;
		} else if (min > current_value) {
			min = current_value;
			continue;
		}

		input_file.ignore(INT_MAX, '\n'); //skips to the end of line, 
	}

	input_file.close(); // closing the stream

}


int main() {
	return 0;
}