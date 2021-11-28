
#ifndef SAMPLE_H 
#define SAMPLE_H 

#include <unordered_set>
#include <set>
#include <map>

#include "stream.h"

class Sample {
  public:
    Sample();
    void add(Edge edge);
    void remove(Edge edge);
    std::unordered_set<Edge, Edge::Hash> edges;
    std::map<int, std::unordered_set<int> > neighborhood;
};

#endif