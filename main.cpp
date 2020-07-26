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
 * Filename : e.g. main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */


#include "Graph.H"

int main(int argc, char* argv[]) {

    if(argc != 2) {
      cerr << "Usage error: expected <executable> <input>" << endl;
      exit(1);
    }

    ifstream ifs(argv[1]);
    if(!ifs) {
      cerr << "Input file not found." << endl;
      exit(1);
    }
    
    Graph g(ifs);
    ifs.close();
    g.bfs();
    g.output_graph();
    cout << "The End." << endl;

    return 0;
}
