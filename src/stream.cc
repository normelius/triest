
#include <fstream>
#include <iostream>
#include <functional>
#include <tuple>

#include "stream.h"

Edge::Edge(int from, int to) {
  this->from = from;
  this->to = to;
  if (to < from) {
    this->from = to;
    this->to = from;
  }
}

bool Edge::operator==(const Edge& edge) const {
    return this->from == edge.from && this->to == edge.to;
}


// Stream class
Stream::Stream(const std::string &filepath) {
  this -> read_data(filepath);
}

void Stream::read_data(const std::string &filepath) {
  std::ifstream file_lines(filepath);
  initNumEdges = std::count(std::istreambuf_iterator<char>(file_lines), 
    std::istreambuf_iterator<char>(), '\n');
  file_lines.close();

  std::ifstream file(filepath);
  int from, to;

  while (file >> from >> to) {
    if (from != to) {
      Edge edge(from, to);
      edges.insert(edge);
    }
  }

  this -> numEdges = edges.size();
}

int Stream::count() {
  return this -> numEdges;
}