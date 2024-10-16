#ifndef GRAPH_H
#define GRAPH_H


#include "node.h"
#include <vector>
#include <string>
#include <algorithm>

class Graph {
private:
	std::vector<Node*> nodes;
	Node* findNode(const std::string& name);
	bool areConnected(Node* p_src, Node* p_dest, std::vector<Node*>& current_path,
		std::vector<Node*>& min_path);
public:
	~Graph();
	void addNode(const std::string& name);
	void addEdge(const std::string& first, const std::string& second);
	void printPath(const std::string& src, const std::string& dest);
};
#endif //GRAPH_H
