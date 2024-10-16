#include "Graph.h"
#include <queue>
#include <unordered_map>

Graph::~Graph() {
    for (Node* node : nodes) {
        delete node;
    }
    nodes.clear();
}

Node* Graph::findNode(const std::string& name) {
    for (Node* node : nodes) {
        if (node->nameIs(name) == true) {
            return node;
        }
    }
    return nullptr; // No node found with the given name
}


void Graph::addNode(const std::string& name) {
    if (findNode(name) == nullptr) {
        nodes.push_back(new Node(name));
    }
    else
        std::cout << "Name already exist" << std::endl;
}

void Graph::addEdge(const std::string& first, const std::string& second) {
    Node* node1 = findNode(first);
    Node* node2 = findNode(second);

    if (node1 == nullptr || node2 == nullptr) {
        std::cout << "User/s not found." << std::endl;
        return;
    }

    if (node1 == node2) {
        std::cout << "Adam karov etzel atzmo." << std::endl;
        return;
    }

    if (std::find(node1->getNeighbors().begin(), node1->getNeighbors().end(), node2) != node1->getNeighbors().end()) {
        std::cout << "Already friends." << std::endl;
        return;
    }

    node1->addNeighbor(node2);
    node2->addNeighbor(node1);
}

void Graph::printPath(const std::string& src, const std::string& dest) {
    if (src == dest) {
        std::cout << "Adam karov etzel atzmo." << std::endl;
        return;
    }

    Node* node1 = findNode(src);
    Node* node2 = findNode(dest);

    if (!node1 || !node2) {
        std::cout << "User/s not found." << std::endl;
        return;
    }

    std::vector<Node*> current_path;
    std::vector<Node*> min_path;

    if (areConnected(node1, node2, current_path, min_path)) {
        for (Node* node : min_path) {
            node->print(); // Assuming getName() returns the name of the node
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No path." << std::endl;
    }
}



bool Graph::areConnected(Node* p_src, Node* p_dest, std::vector<Node*>& current_path, std::vector<Node*>& min_path) {
    current_path.push_back(p_src);

    // Check if we have reached the destination node
    if (p_src == p_dest) {
        // If min_path is empty or current_path is shorter than min_path, update min_path
        if (min_path.empty() || current_path.size() < min_path.size()) {
            min_path = current_path;
        }
        current_path.pop_back(); // Remove the last node from current_path
        return true;
    }

    bool found = false; // Flag to track if a path to destination is found

    // Iterate over neighbors of p_src
    for (Node* neighbor : p_src->getNeighbors()) {
        // Check if neighbor is not already in current_path to avoid cycles
        if (std::find(current_path.begin(), current_path.end(), neighbor) == current_path.end()) {
            // Recursively call areConnected for the neighbor
            if (areConnected(neighbor, p_dest, current_path, min_path)) {
                found = true; // Update flag if a path to destination is found via this neighbor
            }
        }
    }

    current_path.pop_back(); // Remove the last node from current_path

    // Return true if a path to destination is found, otherwise false
    return found;
}

