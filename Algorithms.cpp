#include <iostream>
#include "Algorithms.hpp"
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <limits>
namespace ariel
{
    // DFS helper
    void traverseGraph(const Graph &g, unsigned int u, bool visited[])
    {
        visited[u] = true;
        for (unsigned int v = 0; v < (unsigned int)g.getNumVertices(); v++)
        {
            if (g.containsEdge(u, v))
            {
                if (!visited[v])
                    traverseGraph(g, v, visited);
            }
        }
    }

    bool Algorithms::isConnected(const Graph &g)
    {
        // using DFS algorithm over all vertices
        bool *vis = new bool[g.getNumVertices()];
        for (unsigned int u = 0; u < (unsigned int)g.getNumVertices(); u++)
        {
            for (int i = 0; i < g.getNumVertices(); i++)
                vis[i] = false;
            traverseGraph(g, u, vis);
            for (int i = 0; i < g.getNumVertices(); i++)
            {
                if (!vis[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    std::string Algorithms::shortestPath(const Graph &g, int start, int end)
    {
        unsigned int n = (unsigned int)g.getNumVertices();
        std::queue<int> q;
        std::vector<bool> visited(n, false);
        std::vector<int> parent(n, -1);
        q.push(start);
        visited[(unsigned int)start] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor = 0; neighbor < g.getNumVertices(); ++neighbor)
            {
                if (g.containsEdge((unsigned int)current, (unsigned int)neighbor) && !visited[(unsigned int)neighbor])
                {
                    q.push(neighbor);
                    visited[(unsigned int)neighbor] = true;
                    parent[(unsigned int)neighbor] = current;

                    if (neighbor == end)
                    {
                        std::string path;
                        int node = end;
                        while (node != start)
                        {
                            if (node != end)
                                path = std::to_string(node) + "->" + path;
                            else
                            {
                                path = std::to_string(node) + path;
                            }
                            node = parent[(unsigned int)node];
                        }
                        return std::to_string(start) + "->" + path;
                    }
                }
            }
        }

        return "-1";
    }

    bool Algorithms::isContainsCycle(const Graph &g)
    {
        std::vector<bool> visited((unsigned int)g.getNumVertices(), false);
        std::vector<int> parent((unsigned int)g.getNumVertices(), -1);

        for (int i = 0; i < g.getNumVertices(); ++i)
        {
            if (!visited[(unsigned int)i])
            {
                parent[(unsigned int)i] = -1;
                if (isContainsCycleUtil(g, i, visited, parent))
                    return true;
            }
        }
        return false;
    }
    bool Algorithms::isContainsCycleUtil(const Graph &g, int v, std::vector<bool> &visited, std::vector<int> &parent)
    {
        visited[(unsigned int)v] = true;

        int size;
        int *neighbors = g.getNeighbors((unsigned int)v, size);
        for (int i = 0; i < size; i++)
        {
            int u = neighbors[i];
            if (!visited[(unsigned int)u])
            {
                parent[(unsigned int)u] = v;
                if (isContainsCycleUtil(g, u, visited, parent))
                    return true;
            }
            else if (u != parent[(unsigned int)v])
            {
                // Print the cycle
                std::cout << "Cycle found: ";
                std::stack<int> cycle;
                cycle.push(u);
                for (int x = v; x != u; x = parent[(unsigned int)x])
                {
                    cycle.push(x);
                }
                cycle.push(u);

                while (!cycle.empty())
                {
                    std::cout << cycle.top() << " ";
                    cycle.pop();
                }
                std::cout << std::endl;

                return true;
            }
        }
        return false;
    }

    std::string Algorithms::isBipartite(const Graph &g)
    {
        unsigned int src = 0;
        int colorArr[(unsigned int)g.getNumVertices()];
        for (int i = 0; i < g.getNumVertices(); ++i)
            colorArr[i] = -1;
        colorArr[src] = 1;
        std::queue<unsigned int> q;
        q.push(src);

        while (!q.empty())
        {
            unsigned int u = q.front();
            q.pop();

            for (unsigned int v = 0; (int)v < g.getNumVertices(); ++v)
            {
                if (g.containsEdge(u, v) && colorArr[v] == -1)
                {
                    colorArr[v] = 1 - colorArr[u];
                    q.push(v);
                }
                else if (g.containsEdge(u, v) && colorArr[v] == colorArr[u])
                {
                    return "0";
                }
            }
        }

        std::string partitionA = "{";
        std::string partitionB = "{";
        for (int i = 0; i < g.getNumVertices(); ++i)
        {
            if (colorArr[(unsigned int)i] == 1)
            {
                partitionA += std::to_string(i) + ", ";
            }
            else
            {
                partitionB += std::to_string(i) + ", ";
            }
        }
        partitionA.pop_back(); // space
        partitionA.pop_back(); //,
        partitionA += "}";
        partitionB.pop_back();
        partitionB.pop_back();
        partitionB += "}";

        return "The graph is bipartite: A=" + partitionA + ", B=" + partitionB;
    }
    // bellman ford algorithm
    bool Algorithms::negativeCycle(const Graph &g)
    {
        std::vector<int> dist((unsigned int)g.getNumVertices(), std::numeric_limits<int>::max());
        dist[0] = 0;

        for (int i = 0; i < g.getNumVertices() - 1; ++i)
        {
            for (int u = 0; u < g.getNumVertices(); ++u)
            {
                for (int v = 0; v < g.getNumVertices(); ++v)
                {
                    if (g.containsEdge((unsigned int)u, (unsigned int)v) && dist[(unsigned int)u] != std::numeric_limits<int>::max() && dist[(unsigned int)u] + g.getWeight((unsigned int)u, (unsigned int)v) < dist[(unsigned int)v])
                    {
                        dist[(unsigned int)v] = dist[(unsigned int)u] + g.getWeight((unsigned int)u, (unsigned int)v);
                    }
                }
            }
        }

        // Check for negative cycles
        for (int u = 0; u < g.getNumVertices(); ++u)
        {
            for (int v = 0; v < g.getNumVertices(); ++v)
            {
                if (g.containsEdge((unsigned int)u, (unsigned int)v) && dist[(unsigned int)u] != std::numeric_limits<int>::max() && dist[(unsigned int)u] + g.getWeight((unsigned int)u, (unsigned int)v) < dist[(unsigned int)v])
                {
                    std::cout << "Negative cycle found!" << std::endl;
                    return true;
                }
            }
        }

        std::cout << "No negative cycle found." << std::endl;
        return false;
    }

} // namespace ariel
