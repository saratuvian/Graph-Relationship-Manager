#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <iostream>

class Node {
private:
	std::string name;
	std::vector<Node*> neighbors;
public:
	Node(const std::string& input);
	void addNeighbor(Node* p_neighbor);
	const std::vector<Node*>& getNeighbors()const;
	bool nameIs(const std::string& input)const;
	void print() const;
};
#endif //NODE_H