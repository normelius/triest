
#include <iostream>
#include "sample.h"

Sample::Sample() {

}

void Sample::add(Edge edge) {
  edges.insert(edge);
  neighborhood[edge.from].insert(edge.to);
  neighborhood[edge.to].insert(edge.from);
}

void Sample::remove(Edge edge) {
  edges.erase(edge);
  neighborhood[edge.from].erase(edge.to);
  if (neighborhood[edge.from].size() == 0) {
    neighborhood.erase(edge.from);
  }

  neighborhood[edge.to].erase(edge.from);
  if (neighborhood[edge.to].size() == 0) {
    neighborhood.erase(edge.to);
  }
}