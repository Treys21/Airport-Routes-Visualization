# adara2-anikp2-rohani2-abhijit3

# What our progam does:
Our program implements 3 algorithms to analyze our airport data set:
    1) BFS: This traversal reveals the total number of connections each airport has. 
    2) Dijkstra's: This algorithm will display all possible routes that one airport has to every other aiport.
    3) Landmark: This algorithm will find a path from one airport to a destination airport through some middle airport.
       (A path from a to c through b)

# How to run the program:
Disclaimer: make sure you have navigated to the "src" folder and before running any commands
Step 1: run "make"
Step 2: choose your algorithm and follow the prompts:
    BFS: "./finalproj data/airports.dat data/routes.dat bfs"
    Dijkstra: "./finalproj data/airports.dat data/routes.dat djikstra"
    Landmark: "./finalproj data/airports.dat data/routes.dat landmark"
    Top 10 Busisest Airports: "./finalproj data/airports.dat data/routes.dat busiest"

Outputs will be displayed if valid airport credentials are given!