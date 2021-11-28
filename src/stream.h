#ifndef STREAM_H 
#define STREAM_H 

#include <string>
#include <unordered_set>

class Edge {
  public:
    Edge(int from, int to);
    bool operator==(const Edge& edge) const;
    struct Hash {
      size_t operator()(const Edge& edge) const {
        size_t fromHash = std::hash<int>()(edge.from);
        size_t toHash = std::hash<int>()(edge.to);
        return fromHash ^ (toHash << 1);
      }
    };

    int from;
    int to;
};

class Stream{
  public:
    Stream(const std::string &filepath);
    int count();
    std::unordered_set<Edge, Edge::Hash> edges;

  private:
    int initNumEdges;
    int numEdges;

    void read_data(const std::string &filepath);
};

#endif