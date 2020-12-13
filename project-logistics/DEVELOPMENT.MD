# Development Updates

# Week 1 (11/18 - 11/22)
We brainstormed different applications for our fantasy football dataset and decided that it was best to use a different one . We changed our dataset to the airport database because it was easier to parse and more applicable to a graph. We then decided to use the dataset to create a graph that outlines the busiest airports based off of how many connecting edges it has. 


# Week 2 (11/22 - 11/29)
We started the week by creating an appropriate make file that allows us to run our main.cpp - we encountered some segmentation faults on the way but fixed them. We then created functions to open our airport file and convert this data into a vector and graph.


# Week 3 (11/29 - 12/6)
This week, we implemented a Routes and Graph class. To begin, we created edges and connected them together using an adjacency matrix in our Graph class. The edges were determined by data from the start and end points given in airports.dat. Then, in the Routes class, we parsed through routes.dat to find the distance between two airports. We now have an adequate data set to perform algorithms and traversals on.

# Week 4 (12/6 - 12/13)
Since our graph is fully functional and we have extracted all the important data needed in the previous week, we were able to thoroughly analyze our data this week. We have successfully integrated BFS and Dijkstra's algorithm. BFS on the graph has allowed us to find the amount of connections each airport has, thus helping us determine the busiest airport. Additionally, Dijkstra's algorithm will allow us to determine the shortest path from one airport to another. We are currently in the process of researching an uncovered algorithm to implement before finishing the project.

