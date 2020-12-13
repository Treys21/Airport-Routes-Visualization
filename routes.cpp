#include "routes.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "readFromFile.hpp"

using namespace std;



Routes::Routes(string airports, string routes) {
	airports_file = airports;
	routes_file = routes;
}

void Routes::createAdjMatrix() {
	parseLocations();
	parseRoutes();

	for (unsigned long i = 0; i < arr.size(); i++) {
		Graph::Edge connection;
		connection.start = arr.at(i).at(0);
		connection.end = arr.at(i).at(1);
		connection.weight = arr.at(i).at(2);
		edges.push_back(connection);
	}
}

void Routes::parseRoutes(){
    std::cout << "The following are vectors for FILE: " << routes_file << " that contain (start_airport, destination_airport, weight):" << std::endl << std::endl;
	std::vector<std::string> vectorRepr = file_to_vector(routes_file);

	vector<int> result;
	//vector<vector<string>> arr;

	for (auto word : vectorRepr) {

		int first_id = -1;
		int second_id = -1;

		stringstream stream(word);
		vector<int> result;
		int counter = 0;

		while(stream.good()){
			string substr;
			getline(stream, substr, ',');
			if(counter == 3 || counter == 5){

				if (substr.at(substr.size() - 1) != 'N') {
					if (counter == 3) {
						first_id = stoi(substr);
					} else {
						second_id = stoi(substr);
						break;
					}
				}
			}
			counter++;
		}


        //call distance function that amish makes
		if (first_id > -1 && second_id > -1) {
			try {
				result.push_back(first_id);
				result.push_back(second_id);
				result.push_back(int(findDistance(locations.at(first_id), locations.at(second_id)))); //update distance as weight in vector
				arr.push_back(result); // push results int arr for reference
			} catch (exception e) { 
				// do nothing continue
			}
		}
	}

}

void Routes::parseLocations(){

	std::vector<std::string> vectorRepr = file_to_vector(airports_file);
	pair<double, double> latlong;

	for (auto word : vectorRepr) {
		stringstream stream(word);
		vector<string> lines;
		lines.clear();

		while(stream.good()){
			string substr;
			getline(stream, substr, ',');
			//cout << substr << endl;
			lines.push_back(substr); 
		}

		try {
            latlong = make_pair(stod(lines.at(6)), stod(lines.at(7)));
        } catch (exception e) {
			latlong = make_pair(stod(lines.at(7)), stod(lines.at(8)));        
        }

		locations[stoi(lines.at(0))] = latlong;

		/*
		//populate dict
		if(lines.at(4).length() != 2){
			if(lines.at(4).length() != 5){
				names[stoi(lines.at(0))] = lines.at(5);
			}
			else{
				names[stoi(lines.at(0))] = lines.at(4);
			}
		}
		else{
			names[stoi(lines.at(0))] = lines.at(1);
		}
		*/		

		names[stoi(lines.at(0))] = lines.at(1);


		max_key = stoi(lines.at(0));
	}
}

void Routes::printRoutes(){
    int count = 0;
	for (const std::vector<int> &entry : arr)
	{
		cout<< "ENTRY " << count << ": " ;
		for ( int route : entry ) std::cout << route << ' ';
		std::cout << std::endl;
		count ++;
	}
}

double Routes::findDistance(pair<double, double> first, pair<double, double> second) {
    
	double radius = 6371;

	double lat_one = get<0>(first) * (M_PI / 180);
	double lon_one = get<1>(first) * (M_PI / 180);
	double lat_two = get<0>(second) * (M_PI / 180);
	double lon_two = get<1>(second) * (M_PI / 180);

	double lon_diff = lon_two - lon_one; 
    double lat_diff = lat_two - lat_one; 
  
    double result = pow(sin(lat_diff / 2), 2) + cos(lat_one) * cos(lat_two) * pow(sin(lon_diff / 2), 2); 
  
    result = 2 * asin(sqrt(result));

    return (result * radius) / 1.609;   // divide by 1.609 to covert km to miles
}
