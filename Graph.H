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
	Graph()
	{
		// Set Color Settings
		bgIn = "#2D2732";
		bgOut = "#0D0B0E";
		node0 = "#D14C5A";
		node1 = "#7E364E";
		node2 = "#4C2844";
		node3 = "#2E1F3D";
		node4 = "#2E1F3D";
		edgeLong = "#504755";
		edgeShort = "#FFFFFF";
		fontColor = "#FFFFFF";
	}
	Graph(ifstream& ifs){ /* implement overloaded constructor */ }
	~Graph(){}
	void build_graph(ifstream& ifs)
	{
		unsigned int numVertices;
		unsigned int numEdges;
		ifs >> numVertices >> numEdges;
		
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
			
			// Populate List for each vertex with indices of neighbors
			vertices.at(find(token1)).neighbors.push_back(find(token2));
		}
	}
	void output_graph() // FIXME
	{
		// Declare Variables
		string nodeColor;
		ofstream ofs("graph.dot");

		// ## Set Defaults for Graph, edge and nodes		
		ofs << "strict digraph G {" << endl << endl;
		ofs << "layout = circo" << endl;
		ofs << "tooltip = \"Breadth First Search\"" << endl << endl;

		ofs << "graph [" << endl
			<< "concentrate = true" << endl
			<< "pad = 0.5" << endl
			<< "ranksep = 0.4" << endl
			<< "nodesep = 0.7" << endl
			<< "style = radial" << endl
			<< "labelloc = t" << endl
			<< "label = \"Shortest Path via Breadth First Search\"" << endl
			<< "fontcolor = \"" << fontColor << "\"" << endl
			<< "fontname = Georgia" << endl
			<< "fontsize = 18" << endl
			<< "bgcolor = \"" << bgIn << ":" << bgOut << "\"];" << endl << endl;

		ofs << "node [" << endl
			<< "fontcolor = \"" << fontColor << "\"" << endl
			<< "fontname = Georgia" << endl
			<< "style = filled" << endl
			<< "fixedsize = true" << endl
			<< "width = 1.2" << endl
			<< "shape = circle" << endl
			<< "penwidth = 0];" << endl << endl; 

			ofs << "edge [" << endl
				<< "arrowhead = vee" << endl
				<< "len = 0.6" << endl
				<< "arrowsize = 0.7];" << endl << endl; 

		// ## Output Vertices

		// Just Source Node
		ofs << vertices.at(0).label	
				<< " [" << endl
				<< "label = \"" << vertices.at(0).label 
				<< " (" << vertices.at(0).distance << ")\"" << endl
				<< "fillcolor = \""<< node0 << "\"" << endl
				<< "peripheries = 2, penwidth = 1" << endl
				<< "tooltip = \"" << vertices.at(0).label << ", ORIGIN \"" << endl
				<< "color = \"" << node0 << "\" ];" << endl << endl;
		// Remaining Vertices
		for (unsigned int i = 1; i < vertices.size(); i++)
		{
			string nodeColor ="";

			switch (vertices.at(i).distance) 
			{
				case 0 : { nodeColor = node0; break; }
				case 1 : { nodeColor = node1; break; }
				case 2 : { nodeColor = node2; break; }
				case 3 : { nodeColor = node3; break; }
				case 4 : { nodeColor = node4; break; }
			}

			ofs << vertices.at(i).label	
				<< " [label = \"" << vertices.at(i).label 
				<< " (" << vertices.at(i).distance << ")\""
				<< "tooltip = \"" << vertices.at(i).label << ", Distance from Origin: "
				<< vertices.at(i).distance << "\"" << endl
				<< ", fillcolor = \""<< nodeColor << "\"];" << endl;
		}
		ofs << endl;

		// ## Output Edges
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			for (list<int>::iterator it = vertices.at(i).neighbors.begin(); it!=vertices.at(i).neighbors.end(); it++)
			{
				ofs << vertices.at(i).label << "->" << vertices.at(*it).label;

				if (vertices.at(*it).parent == i)
				{
					if (bidirectional(vertices.at(*it),vertices.at(i)))
					{
						ofs << " [" << endl
							<< "color = \"" << edgeShort << "\""
							<< ", tooltip = \"" << vertices.at(i).label << " <-> " << vertices.at(*it).label 
							<< " (part of shortest path)\""
							<< ", dir = both"
							<< ", style = bold ];" << endl;
					}
					else
					{
						ofs << " [" << endl
							<< "color = \"" << edgeShort << "\""
							<< ", tooltip = \"" << vertices.at(i).label << " -> " << vertices.at(*it).label 
							<< " (part of shortest path)\""
							<< ", style = bold ];" << endl;
					}
					

				}
				else
				{
					if (bidirectional(vertices.at(*it),vertices.at(i)))
					{
						ofs << " [" << endl
							<< "color = \"" << edgeLong << "\""
							<< ", tooltip = \"" << vertices.at(i).label << " <-> " << vertices.at(*it).label 
							<< " (not part of shortest path)\""
							<< ", dir = both"
							<< ", style = line ];" << endl;
					}
					else
					{
						ofs << " [" << endl
							<< "color = \"" << edgeLong << "\""
							<< ", tooltip = \"" << vertices.at(i).label << " -> " << vertices.at(*it).label 
							<< " (not part of shortest path)\""
							<< ", style = line ];" << endl;
						
					}
				}
				
			}
		}
		ofs << "}" << endl;
	}
	void bfs()
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
	// Colors
	string bgIn;
	string bgOut;
	string node0;
	string node1;
	string node2;
	string node3;
	string node4;
	string fontColor;
	string edgeLong;
	string edgeShort;

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
	bool bidirectional(Vertex& v1, Vertex& v2)
	{
		int numDirections = 0;

		// Check if v2 is neighbor of v1
		for (list<int>::iterator it = v1.neighbors.begin(); it!=v1.neighbors.end(); it++)
		{
			if (vertices.at(*it).label == v2.label)
				numDirections++;
		}

		// Check if v1 is neighbor of v2
		for (list<int>::iterator it = v2.neighbors.begin(); it!=v2.neighbors.end(); it++)
		{
			if (vertices.at(*it).label == v1.label)
				numDirections++;
		}

		if (numDirections==2)
			return true;
		else
			return false;
	}
};

#endif /* GRAPH_H_ */
