/**
 * Course: CS014 Summer 2020
 *
 * First Name: Shawn
 * Last Name: Long
 * Username: slong024
 * email address: slong024@ucr.edu
 * 
 * 
 * Assignment: e.g. assn5
 * Filename : e.g. Graph.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Vertex.H"

using namespace std;

class Graph {
public:
	Graph(){}
	Graph(ifstream& ifs){ /* implement overloaded constructor */ }
	~Graph(){}
	void build_graph(ifstream& ifs){ /* implement build_graph */ }
	void output_graph(){ /* implement output_graph */ }
	void bfs(){ /* implement bfs */ }
private:
	vector<Vertex> vertices;
};

#endif /* GRAPH_H_ */
