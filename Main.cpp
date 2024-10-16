//JE
#include <iostream>
#include <string>
#include <sstream>
#include "graph.h"

void runTest(const std::string& testName, const std::string& expected, void (*func)(Graph&, const std::string&, const std::string&), Graph& graph, const std::string& arg1, const std::string& arg2) {
    // Redirect std::cout to a stringstream
    std::stringstream ss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Run the function
    func(graph, arg1, arg2);

    // Restore std::cout
    std::cout.rdbuf(oldCoutStreamBuf);

    // Compare the output with the expected output
    std::string actual = ss.str();
    if (expected == actual) {
        std::cout << testName << ": Passed\n";
    }
    else {
        std::cout << testName << ": Failed\n";
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Actual: " << actual << "\n";
    }
}

void testPrintPath(Graph& graph, const std::string& src, const std::string& dest) {
    graph.printPath(src, dest);
}

void testAddEdge(Graph& graph, const std::string& first, const std::string& second) {
    graph.addEdge(first, second);
}
void testAddNode(Graph& graph, const std::string& name, const std::string&) {
    graph.addNode(name);
}

int main() {
    // Create a new graph
    Graph network;

    // Add some users to the network
    network.addNode("Alice");
    network.addNode("Bob");
    network.addNode("Charlie");
    network.addNode("David");
    network.addNode("Eve");
    network.addNode("Frank");
    network.addNode("George");
    network.addNode("Hannah");
    network.addNode("Anastasia");

    // Add some friendships to the network
    network.addEdge("Alice", "Bob");
    network.addEdge("Bob", "Charlie");
    network.addEdge("Charlie", "David");
    network.addEdge("Eve", "Frank");
    network.addEdge("Alice", "Eve");
    network.addEdge("George", "Hannah");
    network.addEdge("Hannah", "Alice");

    // Run tests
    runTest("Test 1", "Alice Bob Charlie David\n", testPrintPath, network, "Alice", "David");  
    runTest("Test 2", "Alice Bob Charlie\n", testPrintPath, network, "Alice", "Charlie");
    runTest("Test 3", "Bob Charlie David\n", testPrintPath, network, "Bob", "David");
    runTest("Test 4", "Eve Frank\n", testPrintPath, network, "Eve", "Frank");
    runTest("Test 5", "Alice Eve Frank\n", testPrintPath, network, "Alice", "Frank");
    runTest("Test 6", "Adam karov etzel atzmo.\n", testPrintPath, network, "Alice", "Alice");
    runTest("Test 7", "User/s not found.\n", testPrintPath, network, "Alice", "Zoe");
    runTest("Test 8", "User/s not found.\n", testPrintPath, network, "Zoe", "Alice");
    runTest("Test 9", "Adam karov etzel atzmo.\n", testPrintPath, network, "Zoe", "Zoe");
    runTest("Test 10", "George Hannah Alice Bob Charlie David\n", testPrintPath, network, "George", "David");
    runTest("Test 11", "Hannah Alice Eve Frank\n", testPrintPath, network, "Hannah", "Frank");
    runTest("Test 12", "Adam karov etzel atzmo.\n", testPrintPath, network, "George", "George");
    runTest("Test 13", "User/s not found.\n", testPrintPath, network, "George", "Zoe");
    runTest("Test 14", "User/s not found.\n", testPrintPath, network, "Zoe", "George");
    runTest("Test 15", "Name already exists.\n", testAddNode, network, "Alice", "");
    runTest("Test 16", "Already friends.\n", testAddEdge, network, "Alice", "Bob");
    runTest("Test 17", "User/s not found.\n", testAddEdge, network, "Alice", "Zoe");
    runTest("Test 18", "User/s not found.\n", testAddEdge, network, "Zoe", "Alice");
    runTest("Test 19", "User/s not found.\n", testAddEdge, network, "Zoe", "Zoe");
    runTest("Test 22", "User/s not found.\n", testPrintPath, network, "Alice", "Iris");
    runTest("Test 23", "Name already exists.\n", testAddNode, network, "Alice", "");
    runTest("Test 24", "Already friends.\n", testAddEdge, network, "Alice", "Bob");
    runTest("Test 25", "User/s not found.\n", testAddEdge, network, "Alice", "Zoe");
    runTest("Test 26", "User/s not found.\n", testPrintPath, network, "Alice", "Zoe");
    runTest("Test 27", "Adam karov etzel atzmo.\n", testPrintPath, network, "Alice", "Alice");
    runTest("Test 28", "Alice Hannah George\n", testPrintPath, network, "Alice", "George");
    runTest("Test 29", "No path.\n", testPrintPath, network, "Alice", "Anastasia");
    return 0;
}

//JE