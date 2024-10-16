#include "Node.h"
#include <string>
#include <vector>
#include <iostream>

Node::Node(const std::string& input) {
	name = input;
}
void Node::addNeighbor(Node* p_neighbor) {
	neighbors.push_back(p_neighbor);
}
const std::vector<Node*>& Node::getNeighbors() const {
	return neighbors;
}


bool Node::nameIs(const std::string& input) const {
	return name == input;
}
void Node::print() const {
	std::cout << name << " ";
}