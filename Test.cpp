#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test graph addition") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);
    
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);
    
    Graph g3 = g1 + g2;
    CHECK(g3.toString() == "[[0, 2, 1], [2, 0, 3], [1, 3, 0]]");
}

TEST_CASE("Test graph multiplication") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);
    
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);
    
    Graph g4 = g1 * g2;
    CHECK(g4.toString() == "[[1, 0, 2], [1, 3, 1], [1, 0, 2]]");
}

TEST_CASE("Invalid operations") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);
    
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {1, 1, 1, 0}
    };
    g2.loadGraph(weightedGraph);
    
    Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g5.loadGraph(graph2);
    
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g6.loadGraph(graph3);
    
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Test graph unary plus and minus") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    Graph g2 = +g1;
    CHECK(g1 == g2);

    Graph g3 = -g1;
    CHECK(g1 != g3);
}

TEST_CASE("Test graph comparison operators") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);

    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g3.loadGraph(graph3);

    CHECK(g1 == g2);
    CHECK(g1 != g3);
    CHECK(g1 < g3);
    CHECK(g1 <= g2);
    CHECK(g3 > g1);
    CHECK(g3 >= g2);
}

TEST_CASE("Test graph increment and decrement operators") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    Graph g2 = g1;
    ++g1;
    CHECK(g1 != g2);
    CHECK(g1.toString() == "[[1, 2, 1], [2, 1, 2], [1, 2, 1]]");

    Graph g3 = g1;
    g1++;
    CHECK(g1 != g3);
    CHECK(g1.toString() == "[[2, 3, 2], [3, 2, 3], [2, 3, 2]]");

    Graph g4 = g1;
    --g1;
    CHECK(g1 != g4);
    CHECK(g1.toString() == "[[1, 2, 1], [2, 1, 2], [1, 2, 1]]");

    Graph g5 = g1;
    g1--;
    CHECK(g1 == g2); // Compare with the initial state
}

TEST_CASE("Test scalar multiplication and division operators") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    Graph g2 = g1 * 2;
    CHECK(g2.toString() == "[[0, 2, 0], [2, 0, 2], [0, 2, 0]]");

    Graph g3 = g1 / 2;
    CHECK(g3.toString() == "[[0, 0, 0], [0, 0, 0], [0, 0, 0]]");
}
