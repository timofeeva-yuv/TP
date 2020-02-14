#include <iostream>
#include <vector>
#include <queue>
#include "lib.h"

ListGraph::ListGraph(int vertexCount) : adjacencyList(vertexCount) {}

ListGraph::ListGraph(const IGraph* graph) : ListGraph(graph->VerticesCount())
{
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        std::vector <int> next;
        graph->GetNextVertices(i, next);
        adjacencyList.push_back(next);
    }
}

void ListGraph::AddEdge(int from, int to) {
    adjacencyList[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacencyList.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    vertices = adjacencyList[vertex];
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < adjacencyList.size(); ++i) {
        for (int second : adjacencyList[i]) {
            if (second == vertex) {
                vertices.push_back(i);
            }
        }
    }
}

bool BFS(IGraph* graph, int start) {
    std::queue<int> tops;
    std::vector<int> color(graph->VerticesCount());
    std::vector<int> set(graph->VerticesCount());
    color[start] = 1;
    set[start] = 1;
    tops.push(start);
    while ((!tops.empty())) {
        int vertex = tops.front();
        tops.pop();
        std::vector<int> next_vertices;
        graph->GetNextVertices(vertex, next_vertices);
        for (int i = 0; i < next_vertices.size(); ++i) {
            if (set[next_vertices[i]] == set[vertex]) {
                return false;
            }
            set[next_vertices[i]] = set[vertex] % 2 + 1;
            if (color[next_vertices[i]] == 0) {
                tops.push(next_vertices[i]);
                color[next_vertices[i]] = 1;
            }
        }
        color[vertex] = 2;
    }
    return true;
}

