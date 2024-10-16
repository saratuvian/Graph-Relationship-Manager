# Graph Relationship Manager

## Project Overview

The **Graph Relationship Manager** is a C++ implementation of a graph data structure. It models relationships between entities, such as people or objects, using nodes and edges. The project includes features for:
- Adding nodes (representing entities)
- Establishing relationships between nodes (edges)
- Finding and printing the shortest path between two entities using a depth-first search (DFS) algorithm.

## Features

1. **Add Node**: 
   - Allows adding a new entity to the graph.
   - Each node has a unique name.

2. **Add Edge**: 
   - Adds a relationship (edge) between two existing nodes (entities).
   - Ensures no duplicate edges are created between the same nodes.

3. **Find Path**: 
   - Finds the shortest path between two nodes if they are connected.
   - If no path exists, an appropriate message is shown.

4. **Depth-First Search (DFS)**:
   - Implements DFS to traverse the graph and find connections between entities.

## Classes

### 1. **Graph**
   - Manages the collection of nodes and edges.
   - Methods:
     - `addNode`: Adds a new node to the graph.
     - `addEdge`: Establishes a connection between two nodes.
     - `printPath`: Prints the shortest path between two nodes, if one exists.

### 2. **Node**
   - Represents an individual entity within the graph.
   - Stores its neighbors (connected nodes).
   - Methods:
     - `addNeighbor`: Connects this node to another node.
     - `getNeighbors`: Retrieves the neighbors of this node.
     - `nameIs`: Checks if the node's name matches a given string.
     - `print`: Prints the node's name.

## How to Use

1. Clone the repository and compile the project.
2. Run the program and use the following commands:
   - `addNode(name)`: Add a node to the graph.
   - `addEdge(node1, node2)`: Establish a connection between two nodes.
   - `printPath(node1, node2)`: Find and print the shortest path between two nodes.

## Example

```cpp
Graph g;
g.addNode("Alice");
g.addNode("Bob");
g.addEdge("Alice", "Bob");
g.printPath("Alice", "Bob");  // Outputs: Alice Bob
```

## Compilation

To compile the project, use any C++ compiler. Example with `g++`:

```bash
g++ main.cpp Graph.cpp Node.cpp -o graph_manager
```

Run the executable:

```bash
./graph_manager
```

## License

This project is open-source and available for use under the MIT License.
