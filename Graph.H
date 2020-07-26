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
	void build_graph(ifstream& ifs)
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
	void output_graph() // FIXME
	{
		// Declare Variables
		string nodeColor;
		ofstream ofs("graph.dot");

		// Set Defaults for Graph, edge and nodes		
		ofs << "strict digraph G {" << endl << endl;
		ofs << "graph [" << endl
			<< "concentrate = true" << endl
			// << "rankdir = \"LR\"" << endl
			<< "pad = 0.5" << endl
			<< "ranksep = 0.4" << endl
			// << "ratio = \"6,9\""
			<< "nodesep = 0.7" << endl
			<< "style = radial" << endl
			<< "bgcolor = \"#EEEEEE:#6EDCC5\"];" << endl << endl;

		ofs << "node [" << endl
			<< "style = filled" << endl
			<< "fillcolor = \"#F2ECC6\"" << endl
			<< "penwidth = 0];" << endl << endl; 

			ofs << "edge [" << endl
				<< "arrowhead = vee" << endl
				<< "len = 0.6" << endl
				<< "arrowsize = 0.7" << endl
				<< "color = \"#3A3E45\"];" << endl << endl; 

		// Output Vertices
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			string nodeColor ="";

			switch (vertices.at(i).distance) 
			{
				case 0 : { nodeColor = "#F8E6D6"; break; }
				case 1 : { nodeColor = "#F6CC92"; break; }
				case 2 : { nodeColor = "#F2AB4D"; break; }
			}

			ofs << vertices.at(i).label	
				<< " [label = \"" << vertices.at(i).label 
				<< " (" << vertices.at(i).distance << ")\""
				<< ", fillcolor = \""<< nodeColor << "\"];" << endl;
		}
		ofs << endl;

		// Output Edges
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			for (list<int>::iterator it = vertices.at(i).neighbors.begin(); it!=vertices.at(i).neighbors.end(); it++)
			{
				ofs << vertices.at(i).label << "->" << vertices.at(*it).label;

				if (vertices.at(*it).parent == i)
				{
					ofs << " [color = \"#D75B5F\", style = bold ];" << endl;
				}
				else
				{
					ofs << " [color = \"#3A3E45\", style = dotted ];" << endl;
				}
				
			}
		}
		ofs << "}" << endl;
	}
	void bfs() // FIXME
	{
		// Declare Variables
		queue<Vertex> Q;
		Vertex v;

		// Set all Vertices except source to infinity
		for (unsigned int i = 1; i<vertices.size(); i++)
			vertices.at(i).distance = INT_MAX;

		// Set Source to 0
		vertices.at(0).distance = 0;

		// Enqueue Source
		Q.push(vertices.at(0));
		// While Q not empty
		while (!Q.empty())
		{
			// v <- dequeue Q
			v = Q.front();
			Q.pop();

			// for each adjacent Vertex (u)
			for (list<int>::iterator it = v.neighbors.begin(); it!=v.neighbors.end(); it++)
			{
				// if u.d = infinity
				if (vertices.at(*it).distance==INT_MAX)
				{
					// u.d = v.d + 1
					vertices.at(*it).distance = v.distance+1;
					vertices.at(*it).parent = find(v.label);

					// enqueue u
					Q.push(vertices.at(*it));

				}


			}


		}

	}
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
