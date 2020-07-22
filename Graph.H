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
#include <map>
#include "Vertex.H"

using namespace std;

class Graph {
public:
	Graph(){}
	Graph(ifstream& ifs){ /* implement overloaded constructor */ }
	~Graph(){}
	void build_graph(ifstream& ifs) // TODO
	{
		unsigned int numVertices;
		unsigned int numEdges;
		ifs >> numVertices >> numEdges;
		cout << "Vertices: " << numVertices << ", Edges: " << numEdges << endl;

		for (unsigned int i = 0; i<numVertices; ++i)
		{
			Vertex V;
			ifs >> V.label;
			vertices.push_back(V);
		}
	}
	void output_graph(){ /* implement output_graph */ }
	void bfs(){ /* implement bfs */ }
private:
	vector<Vertex> vertices;
};

#endif /* GRAPH_H_ */
