#include <iostream>
#include <vector>
#include "A/index.h"

class ListGraph : public IGraph {
public:
    ListGraph(int);
    ListGraph(const IGraph*);
    void AddEdge(int, int);
    int VerticesCount() const;
    void GetNextVertices(int, std::vector<int>&) const;
    void GetPrevVertices(int, std::vector<int>&) const;
private:
    std::vector< std::vector<int> > adjacencyList;
};


