# Shortest Path via Breadth First Search

This C++ program reads an input file detailing vertices and edges in a graph and outputs a neatly organized .dot file illustrating the shortest path from the origin to all other nodes.

<img src="Screenshot.png" width=500></img>

## Key Features

* Descriptive tooltips on vertices **and** edges
* Uniform radial graph Layout
* Coloring to reflect distance from origin
* Hyperlink via Subgraph

## Input File Formatting

Your input.txt file should be formatting as follows:

1. **Line 1**: No. of Vertices (Integer)
2. **Line 2**: No. of Edges (Integer)
3. **Vertices**: One line for each Vertex Name (String)
4. **Edges**: One line for each edge, consisting of a vertex followed by a space, and then the second vertex

## Compiling the Output File

This program utilizes the *circo* layout for GraphViz dot files. Because of this, the output file will **must** be run from a web compiler that supports additional GraphViz layouts. I recommend using [GraphViz Online](https://dreampuf.github.io/GraphvizOnline/).

## Built With

* [GraphViz](https://graphviz.org) - Output Dot File
* [Visual Studio Code](https://code.visualstudio.com) - IDE

## Author

* **Shawn Long** - [ShawnLong636](https://github.com/shawnlong636)

## Acknowledgments

* Professor Rusich, University of California - Riverside
* [GraphViz Documentation](https://graphviz.org/documentation/)

This program was assigned for *CS14: Data Structures and Algorithms* at UCR, instructed by Professor Rusich with teaching assistance from Quazi Mishkatul Alam. All code in this repository is composed of my original work and the files provided by the instructor for the assignment.

Copyright &copy; 2020 ShawnLong636
