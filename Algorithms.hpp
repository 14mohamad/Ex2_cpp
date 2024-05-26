#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace ariel {

    class Algorithms {
    public:
        // Check if the graph is connected
        static bool isConnected(const Graph& g);

        // Find the shortest path between two vertices
        static std::string shortestPath(const Graph& g, int start, int end);

        // Check if the graph contains a cycle
        static bool isContainsCycle(const Graph& g);

        // Check if the graph is bipartite
        static std::string isBipartite(const Graph& g);

        // Check if the graph has a negative cycle
        static bool negativeCycle(const Graph& g);

    private:
        // Helper function for checking cycle
        static bool isContainsCycleUtil(const Graph &g, int v, std::vector<bool> &visited, std::vector<int> &parent);
    };

} // namespace ariel

#endif // ALGORITHMS_HPP
