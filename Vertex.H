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
 * Filename : e.g. Vertex.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <climits>
#include <string>
#include <list>

using namespace std;

class Vertex {
public:
	Vertex()
	{
		distance = INT_MAX;
		label = "";
		parent = -1;
	}

	~Vertex(){}
	string label;
	int distance;
	list<int> neighbors;
	int parent;
};

#endif /* VERTEX_H_ */
