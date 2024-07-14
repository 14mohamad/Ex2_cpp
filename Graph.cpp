#include <iostream>
#include <sstream>
#include "Graph.hpp"

namespace ariel
{
    Graph::Graph()
    {
        // Constructor
    }

    Graph::~Graph()
    {
        // Destructor
    }

    void Graph::loadGraph(const std::vector<std::vector<int>> &adjacencyMatrix)
    {
        // Load the graph from the adjacency matrix
        for (unsigned int i = 0; i < adjacencyMatrix.size(); i++)
        {
            if (adjacencyMatrix.size() != adjacencyMatrix[i].size())
            {
                throw std::invalid_argument("Not square");
            }
            for (unsigned int j = 0; j < adjacencyMatrix.size(); j++)
            {
                if (j == i && adjacencyMatrix[i][j] != 0)
                {
                    throw std::invalid_argument("Invalid values");
                }
            }
        }
        this->adjacencyMatrix = adjacencyMatrix;
    }

    void Graph::printGraph() const
    {
        // Print the graph (for debugging purposes)
        std::cout << "Graph with " << adjacencyMatrix.size() << " vertices and " << getNumEdges() << " edges." << std::endl;
        for (unsigned int i = 0; i < (unsigned int)getNumVertices(); i++)
        {
            std::cout << i;
            for (unsigned int j = 0; j < (unsigned int)getNumVertices(); j++)
            {
                if ((i != j) && (adjacencyMatrix[i][j] != 0))
                {
                    std::cout << " -> " << j;
                }
            }
            std::cout << std::endl;
        }
    }

    int Graph::getNumVertices() const
    {
        // Get the number of vertices in the graph
        return adjacencyMatrix.size();
    }

    int Graph::getNumEdges() const
    {
        // Get the number of edges in the graph
        int count = 0;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (unsigned int j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool Graph::containsEdge(unsigned int u, unsigned int v) const
    {
        return adjacencyMatrix[u][v] != 0;
    }

    int *Graph::getNeighbors(unsigned int u, int &size) const
    {
        int neighborsCount = 0;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); i++)
        {
            if (containsEdge(u, i))
            {
                neighborsCount++;
            }
        }

        int *neighbors = new int[neighborsCount];
        neighborsCount = 0;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); i++)
        {
            if (containsEdge(u, i))
            {
                neighbors[neighborsCount] = (int)i;
                neighborsCount++;
            }
        }
        size = neighborsCount;
        return neighbors;
    }

    int Graph::getWeight(unsigned int u, unsigned int v) const
    {
        return adjacencyMatrix[u][v];
    }

    std::string Graph::toString() const
    {
        std::ostringstream os;
        os << "[";
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            os << "[";
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                os << adjacencyMatrix[i][j];
                if (j < adjacencyMatrix[i].size() - 1)
                {
                    os << ", ";
                }
            }
            os << "]";
            if (i < adjacencyMatrix.size() - 1)
            {
                os << ", ";
            }
        }
        os << "]"; // Ensure it ends without a newline character
        return os.str();
    }

    //  מטלה 2

    // Arithmetic operators
    Graph Graph::operator+(const Graph &other) const
    {
        if (getNumVertices() != other.getNumVertices())
        {
            throw std::invalid_argument("Graphs must be of the same size.");
        }
        Graph result = *this;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (unsigned int j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                result.adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    Graph &Graph::operator+=(const Graph &other)
    {
        if (getNumVertices() != other.getNumVertices())
        {
            throw std::invalid_argument("Graphs must be of the same size.");
        }
        for (unsigned int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (unsigned int j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator-(const Graph &other) const
    {
        if (getNumVertices() != other.getNumVertices())
        {
            throw std::invalid_argument("Graphs must be of the same size.");
        }
        Graph result = *this;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (unsigned int j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                result.adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    Graph &Graph::operator-=(const Graph &other)
    {
        if (getNumVertices() != other.getNumVertices())
        {
            throw std::invalid_argument("Graphs must be of the same size.");
        }
        for (unsigned int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (unsigned int j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator+() const
    {
        return *this;
    }

    Graph Graph::operator-() const
    {
        Graph result = *this;
        for (auto &row : result.adjacencyMatrix)
        {
            for (auto &val : row)
            {
                val = -val;
            }
        }
        return result;
    }

    // Comparison operators

    bool Graph::operator==(const Graph &other) const
    {
        return adjacencyMatrix == other.adjacencyMatrix;
    }

    bool Graph::operator!=(const Graph &other) const
    {
        return !(*this == other);
    }

    bool Graph::operator<(const Graph &other) const
    {
        if (adjacencyMatrix == other.adjacencyMatrix)
        {
            return false;
        }
        int thisEdges = getNumEdges();
        int otherEdges = other.getNumEdges();
        return (thisEdges < otherEdges) || (thisEdges == otherEdges && getNumVertices() < other.getNumVertices());
    }

    bool Graph::operator<=(const Graph &other) const
    {
        return *this < other || *this == other;
    }

    bool Graph::operator>(const Graph &other) const
    {
        return !(*this <= other);
    }

    bool Graph::operator>=(const Graph &other) const
    {
        return !(*this < other);
    }

    // Increment and decrement operators

    Graph& Graph::operator++()
    {
        for (auto& row : adjacencyMatrix)
        {
            for (auto& val : row)
            {
                ++val;
            }
        }
        return *this;
    }

    Graph Graph::operator++(int)
    {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    Graph& Graph::operator--()
    {
        for (auto& row : adjacencyMatrix)
        {
            for (auto& val : row)
            {
                --val;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int)
    {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    // Scalar multiplication

    Graph Graph::operator*(int scalar) const
    {
        Graph result = *this;
        for (auto &row : result.adjacencyMatrix)
        {
            for (auto &val : row)
            {
                val *= scalar;
            }
        }
        return result;
    }

    Graph &Graph::operator*=(int scalar)
    {
        for (auto &row : adjacencyMatrix)
        {
            for (auto &val : row)
            {
                val *= scalar;
            }
        }
        return *this;
    }

    // Graph multiplication

    Graph Graph::operator*(const Graph &other) const
    {

        if (getNumVertices() != other.getNumVertices())
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        // Get the size type
        using size_type = typename std::vector<int>::size_type;

        // Initialize the resulting graph
        Graph result;
        result.loadGraph(std::vector<std::vector<int>>(static_cast<size_type>(getNumVertices()), std::vector<int>(static_cast<size_type>(getNumVertices()), 0)));

        // Perform matrix multiplication
        for (size_type i = 0; i < static_cast<size_type>(getNumVertices()); ++i)
        {
            for (size_type j = 0; j < static_cast<size_type>(getNumVertices()); ++j)
            {
                for (size_type k = 0; k < static_cast<size_type>(getNumVertices()); ++k)
                {
                    result.adjacencyMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                }
            }
        }
        return result;
    }

    // Scalar division

    Graph Graph::operator/(int scalar) const
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        Graph result = *this;
        for (auto &row : result.adjacencyMatrix)
        {
            for (auto &val : row)
            {
                val /= scalar;
            }
        }
        return result;
    }

    Graph &Graph::operator/=(int scalar)
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        for (auto &row : adjacencyMatrix)
        {
            for (auto &val : row)
            {
                val /= scalar;
            }
        }
        return *this;
    }

    // Output operator

    std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        os << "[";
        for (size_t i = 0; i < graph.adjacencyMatrix.size(); ++i)
        {
            os << "[";
            for (size_t j = 0; j < graph.adjacencyMatrix[i].size(); ++j)
            {
                os << graph.adjacencyMatrix[i][j];
                if (j < graph.adjacencyMatrix[i].size() - 1)
                {
                    os << ", ";
                }
            }
            os << "]";
            if (i < graph.adjacencyMatrix.size() - 1)
            {
                os << ", ";
            }
        }
        os << "]\n"; // Ensure it ends with a newline character
        return os;
    }

} // namespace ariel
