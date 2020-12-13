#include <iostream>
#include <vector>
#include <map>

#pragma once

using namespace std;

class Graph{

    public:

        struct Node {
            int dest, dist;
            Node* next;
        };

        struct Edge {
            int start, end, weight;
        };

        Node **head;
                
        Graph(vector<Graph::Edge> edges, int num_edges, int vertices);

        void displayAdjListNode(Node* ptr, int index);
        map<int, int> BFS(Graph::Node** node, int vertices);
        vector<int> Djikstra(int source);
        int landmarkPath(int start, int middle, int end);
        vector<pair<int, int>> findBusiest();

    private:
	    int vertices;
};