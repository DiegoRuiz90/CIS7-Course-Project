# CIS7 Course Project

Date Published: 12/13/2025

Author: Diego Ruiz

General Description:

This project applies discrete structures concepts to analyze travel routes for a solar marketing specialist operating in the Inland Empire region. The specialist begins the trip in Riverside and travels to Moreno Valley, Perris, and Hemet to market solar packages to homeowners. The goal of the project is to identify possible travel routes and determine the shortest and lowest-cost paths based on distance. The problem is modeled using graph theory, allowing a real-world routing scenario to be solved using mathematical and algorithmic techniques.


Programming Approach:

The program models each city as a vertex in a weighted graph, with travel routes represented as edges weighted by distance. An adjacency matrix is used to store the distances between cities, and an adjacency list is generated to provide an alternative graph representation. Dijkstra’s shortest path algorithm is implemented to calculate the minimum travel distance from Riverside to each of the other cities. The program makes use of decision-making logic, iteration, and comparisons to evaluate routes efficiently, demonstrating core discrete structures concepts through C++ programming.


How To Use:

To run the program, compile the C++ source file using a standard compiler, then execute the generated executable. When the program runs, it automatically displays the adjacency matrix, adjacency list, and the shortest and lowest-cost travel paths from Riverside to the remaining cities. No user input is required, as all city routes and distances are defined according to the project specifications.
