
#ifndef TRIESTBASE_H 
#define TRIESTBASE_H 

#include <map>
#include <random>
#include <string>

#include "stream.h"
#include "sample.h"

class TriestBase {
  public:
    TriestBase(const std::string& filepath, int M = 1000);
    int triangles();
    int inside = 0;
    int outside = 0;

  private:
    void run(Stream stream);
    bool sampleEdge(Edge edge);
    void updateCounters(const std::string& type, Edge edge);

    Sample sample;
    int M;
    int tau = 0;
    std::map<int, int> taus;
    int t = 0;
    std::default_random_engine generator;
};

#endif