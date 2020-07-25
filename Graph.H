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

		for (unsigned int i = 0; i < numEdges; i++)
		{
			string token1;
			string token2;

			// input both tokens on lines for edges
			ifs >> token1 >> token2;

			cout << "Token 1: " << token1 << "(" << find(token1) << ")" << 
					", Token 2: " << token2 << "(" << find(token2) << ")" << endl;
			
			// Populate List for each vertex with indices of neighbors
			vertices.at(find(token1)).neighbors.push_back(find(token2));
		}
	}
	void output_graph()
	{
		ofstream ofs("graph.dot");

		ofs << "digraph G {" << endl;
		ofs << "graph [" << endl
			<< "pad = 0.5" << endl
			<< "ranksep = 0.001" << endl
			<< "rankdir = \"LR\"" << endl
			<< "style = radial" << endl
			<< "bgcolor = \"#41C6EA:#4AF2A1\" " << endl
			<< "];" << endl;

		ofs << "node [" << endl
			<< "style = filled" << endl
			<< "fillcolor = white" << endl
			<< "penwidth = 0" << endl
			<< "];" << endl;

		// Output Vertices
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			ofs << vertices.at(i).label	<< ";" << endl;
		}
		ofs << endl;

		// Output Edges
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			for (list<int>::iterator it = vertices.at(i).neighbors.begin(); it!=vertices.at(i).neighbors.end(); it++)
			{
				ofs << vertices.at(i).label << "->" << vertices.at(*it).label << ";" << endl;
			}
		}
		ofs << "}" << endl;
	}
	void bfs(){ /* implement bfs */ }
private:
	vector<Vertex> vertices;
	int find(const string& label)
	{
		for (int i = 0; i<vertices.size(); i++)
		{
			if (vertices.at(i).label == label)
				return i;
		}
		return -1;
	}
};

#endif /* GRAPH_H_ */
