#include <iostream>
#include <vector>
#include <queue>
#include "graph.h"
#include <map> 
using namespace std;

Graph::Graph(vector<Graph::Edge> edges, int num_edges, int vertices)  {
    
    head = nullptr;
    this->vertices = vertices;
    head = new Node*[vertices]();

    for (int i = 0; i < num_edges; i++)  {

        bool hasRoute = false;
        Node* current = head[edges[i].start];

        while (current != nullptr) {
            if (current->dest == edges[i].end) {
                hasRoute = true;
                break;
            }
            current = current -> next;
        } 

        if (hasRoute) {
            continue;
        } 

        Node* node = new Node;
        node -> dest = edges[i].end;
        node -> dist = edges[i].weight;
        node -> next = head[edges[i].start];

        head[edges[i].start] = node;

    }
}

// print adjacent vertices
void Graph::displayAdjListNode(Graph::Node* ptr, int index)
{
	while (ptr != nullptr) {
		cout << "(" << index << ", " << ptr -> dest << ", " << ptr -> dist << ") ";
		ptr = ptr->next;
	}
	cout << endl;
}

map<int, int> Graph::BFS(Graph::Node** node, int vertices){

    vector<int> level; //keep track of num of connections per level
    map<int, int> levelMap;
    //mymap.insert ( std::pair<char,int>('a',100) );
    //each level is a different airport, so this tracks counts the total num of connections per airport 
    for(int i = 0; i < vertices; i++){
        //vector<Graph::Node *> queue; //queue of node pointers
        Graph::Node* curr = NULL;
        int connections = 0;

        if(node[i] != NULL){
            //queue.push_back(node[i]);       //insert node ptr into queue
            curr = node[i];
        }
        else{
            continue;
        }

        //Iterate through entire level here (BFS part)
        while(curr){
            connections++;
            curr = curr->next;
        }
        //level.push_back(connections);
        levelMap.insert(std::pair<int,int>(i, connections));

        
        /*
        //vector<bool> isVisit(vertices, false); //set all verticies to false rn
        //isVisit[node->val] = true;
        Graph::Node* curr;  //store curr node ptr
        while(!queue.empty()){
            int length = queue.size(); //len of level elements also the num of connections
            int numOfConnections = 0;
            //print curr node for visualization if needed here:
            //iterate through all adjacent edges
            for(int i = 0; i < length; i++){
                curr = queue[0];
                queue.erase(queue.begin());  //pop
                numOfConnections++;

                //if(curr == NULL){
                //    break;
                //}

                if (curr->next){
                    queue.push_back(curr->next);
                }
            }
            level.push_back(numOfConnections);
        } */
    }
    return levelMap;
}

vector<int> Graph::Djikstra(int source){
    
    vector<int> distance(vertices, INT_MAX);
    priority_queue<pair<int, int>> queue;

    queue.push(make_pair(0, source));
    distance[source] = 0;


    while (!queue.empty()) {
        int index = queue.top().second;
        queue.pop();

        Node* current = head[index];
        while(current != nullptr) {
            int weight = current->dist;
            int destination = current->dest;

            if (distance[destination] > distance[index] + weight) {
                distance[destination] = distance[index] + weight;
                queue.push(make_pair(distance[destination], destination));
            }
            current = current -> next;
        }
    }

    return distance;
}

int Graph::landmarkPath(int start, int middle, int end) {
    vector<int> shortest_distance = Djikstra(middle);
    int shortest = shortest_distance.at(start) + shortest_distance.at(end);
    return shortest; 
}

vector<pair<int, int>> Graph::findBusiest() {

    vector<pair<int, int>> mostPopular;
    map<int, int> connections = BFS(head, vertices);

    int prev_max = INT_MAX;
    for (int i = 0; i < 10; i++) {
        int max_value = 0;
        int max_index = 0;

        for (auto it = connections.begin(); it != connections.end(); ++it) {
            if (it->second > max_value && it->second < prev_max) {
                max_value = it->second;
                max_index = it->first;
            }
        }

        prev_max = max_value;
        mostPopular.push_back(make_pair(max_index, max_value));

    }
    
    return mostPopular;
}


