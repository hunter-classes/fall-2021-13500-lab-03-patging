
#include <iostream>
#include <fstream>


void min_max() {

	std::ifstream input_file("./Current_Reservoir_Levels.tsv"); // file input constructor

	if (input_file.fail()) { // can't open file
		std::cerr << "File cannot be opened for reading." << std::endl;
    	exit(1); // exit if failed to open the file
	}

	//skipping first line
	std::string junk;
	std::getline(input_file, junk);


	//file reading

	double min = INT_MAX ;
	double max = INT_MIN; // data from csv

	std::string dummy_val;
	std::string east_basin_storage;

	double current_value; // placeholder for the value in the tsv

	while(input_file >> dummy_val >> east_basin_storage) {

		current_value = std::stold(east_basin_storage);

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

	std::cout << "The minimum storage in East basin: " <<  min  << " billion gallons" << std::endl;
	std::cout << "MAXimum storage in East basin: " <<  max << " billion gallons" << std::endl;

}




int main() {
	min_max();
	/* code */
	return 0;
}
