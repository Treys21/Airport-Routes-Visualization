#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include "readFromFile.hpp"
#include "graph.h"

using namespace std;

class Routes{
    public:

        Routes(string aiports, string routes);
        //perhaps create constructor if needed?

        map<int, string> names;

        string airports_file;
        string routes_file;
        int max_key;

	    vector<vector<int>> arr; //contains (start, end, weight) for all enteries in routes
        map<int, pair<double, double>> locations;
        vector<string> codes; 


        vector<Graph::Edge> edges;

        void createAdjMatrix();

        void parseRoutes();
        void printRoutes();

        //void parseAirports();
        //void printAirports();

        void parseLocations();
        //void printLocations();

        double findDistance(pair<double, double> first, pair<double, double> second);
};