#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include "graph.h"
#include "routes.h"

#include <sstream>
#include <sstream>
#include <iterator> 

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */


using namespace std;



int main(int argc, const char * argv[]) {

	if (argc < 0) { return -1; }

	Routes parser(argv[1], argv[2]);
	parser.createAdjMatrix();

	//cout << parser.edges.size() << endl;
	//cout << parser.max_key << endl;
	Graph graph(parser.edges, parser.edges.size(), parser.max_key);
	parser.parseLocations();

	
	
	if (argc > 3) {
		if (strcmp(argv[3], "bfs") == 0){
			cout << GREEN << "You have selected to perform a BFS on the current graph data set we have" << RESET << endl << endl;
			cout << "Do you want to view a map that contains:  <destination, number of connections>..... ('yes' or 'no')" << endl;
			
			string input;
			std::cin >> input;
			if(input == "yes"){
				map<int, int> res = graph.BFS(graph.head, parser.max_key);
				cout << "MAP contents include <destination, number of connections>:\n";
				for (auto it=res.begin(); it!=res.end(); ++it){
					std::cout << "Airport: " << MAGENTA << parser.names[it->first] << RESET << " => " << "connections: " << GREEN << it->second << RESET << '\n';
				}

				cout << GREEN << "Successful! All airports and their connections have been displayed." << RESET << endl; 
			}
		}
		else if(strcmp(argv[3], "djikstra") == 0){
			cout << GREEN << "You have selected to perform Dijkstra's algorithm." << RESET << endl;
			cout << "This algorithm will find the shortest distance to each reachable airport, given a starting airport." << endl << endl;
			cout << BLUE << "Enter an airport ID (ex: 3484). Enter -1 to quit. Reference the datasheet provided to make sure that you are referencing a real airport." << RESET << endl; 
			string input;
			cin >> input;
			int num = std::stoi(input);

			if(num > 0){
				vector<int> distances = graph.Djikstra(num); 
		
				for (unsigned long i = 0; i < distances.size(); i++) {
					// prints out shortest dist to each reachable aiport
					if (distances[i] < INT_MAX) {
						cout << "Destination Aiport: " << MAGENTA << parser.names[i] << RESET << " => " << "Miles to Destination: " << GREEN << distances[i] << RESET << endl;
					}
				}
				cout << GREEN << "Successful! Shortest distance to each reachable aiport has been calculated." << RESET << endl; 

			}
		}
		else if(strcmp(argv[3], "landmark") == 0){
			int start, end, middle;
			cout << GREEN << "You have selected to perform the Landmark algortihm." << RESET << endl;
			cout << "This algorithm finds the shortest path from a to c through b (assuming a,b,c are airports)" << endl;
			cout << BLUE << "Input starting airport id: " << RESET << endl;
			cin >> start;
			cout << "Input destination airport id: " << RESET << endl;
			cin >> end;
			cout << "Input middle airport id: " << RESET << endl;
			cin >> middle;
			//cout << graph.landmarkPath(3484, 3462, 3469) << endl;
			int shortest = graph.landmarkPath(start, middle, end);
			cout << "Shortest Distance (a to c through b): " << GREEN << shortest << RESET << " miles " << endl;
			cout << GREEN << "Successful! Shortest distance from " << MAGENTA << parser.names[start] << RESET << " to " << MAGENTA << parser.names[end] << RESET << " through " << MAGENTA << parser.names[middle] << RESET << " has been calculated." << endl; 

		}

		else if(strcmp(argv[3], "busiest") == 0){
			cout << GREEN << "You have selected to perform print out top 10 busiest airports." << RESET << endl;
			cout << "This algorithm will find count the top 10 airports by number of connections." << endl << endl;

			vector<pair<int, int>> most = graph.findBusiest();

			for (unsigned long i = 0; i < most.size(); i++) {
				cout << "ID: " << MAGENTA << parser.names[most.at(i).first] << RESET << " Value: " << GREEN << most.at(i).second << RESET << endl;
			}
			
		}

		cout << RED << "Program has been terminated" << RESET << endl;
		return 0;
	} 
	



	
	

	//BFS of graph (level by level)
	//Returns a map that records connections for each airport(level)

	/*
	map<int, int> res = graph.BFS(graph.head, parser.max_key);
	cout << "MAP contents include <destination, connections>:\n";
  	for (auto it=res.begin(); it!=res.end(); ++it){
		std::cout << "dest: " << it->first << " => " << "connections: " << it->second << '\n';
	} 
	*/
	
	

	/*
	vector<int> distances = graph.Djikstra(3484); // Lax Airport
	
	for (unsigned long i = 0; i < distances.size(); i++) {
		// prints out shortest dist to each reachable aiport
		if (distances[i] < INT_MAX) {
			cout << "Aiport ID: " << i << " => " << "Miles: " << distances[i] << endl;
		}
	}
	*/
	
	
	// testing landmarks
	//cout << graph.landmarkPath(3484, 3462, 3469) << endl;
	

	

	
	// Use this to print out all aiports in head (fail means there are no routes for that given airport)
	
	/*
	for (int i = 0; i < parser.max_key; i++) {
		if (graph.head[i] != nullptr) {
			cout << graph.head[i]->dest << " ";
		} else {
			cout <<  "fail" << " ";
		}
	}
	*/
	
	
	
	
}