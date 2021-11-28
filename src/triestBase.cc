
#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>

#include "triestBase.h"

TriestBase::TriestBase(const std::string& filepath, int M) {
  Stream stream(filepath);
  std::cout << "Edges in stream: " << stream.count() << std::endl;
  this -> M = M;
  this -> run(stream);
}

void TriestBase::run(Stream stream) {
  for (Edge edge : stream.edges) {
    t++;
    if (sampleEdge(edge)) {
      sample.add(edge);
      updateCounters("+", edge);
    }
  }
}

bool TriestBase::sampleEdge(Edge edge) {
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  double number = distribution(generator);
  if (t <= M) {
    return true;
  }

  else if (number <= (double)M / t) {
    inside++;
    std::uniform_real_distribution<double> distribution(0.0, sample.edges.size());
    int randomNumber = distribution(generator);
    auto it = std::begin(sample.edges);
    std::advance(it, randomNumber);
    Edge randomEdge = (*it);
    sample.remove(randomEdge);
    updateCounters("-", randomEdge);
    return true;
  }

  outside++;
  return false;
}

void TriestBase::updateCounters(const std::string& type, Edge edge) {
  std::unordered_set<int> neighborhoodFrom = sample.neighborhood[edge.from];
  std::unordered_set<int> neighborhoodTo = sample.neighborhood[edge.to];
  std::unordered_set<int> intersect; 

  for (int from : neighborhoodFrom) {
    if (neighborhoodTo.count(from) > 0) {
      intersect.insert(from);
    }
  }

  for (auto node : intersect) {
    if (type == "+") {
      tau += 1;
      taus[node] += 1;
      taus[edge.from] += 1;
      taus[edge.to] += 1;
    }

    else if (type == "-") {
      tau -= 1;
      taus[node] -= 1;
      if (taus[node] <= 0) {
        taus.erase(node);
      }

      taus[edge.from] -= 1;
      if (taus[edge.from] <= 0)  {
        taus.erase(edge.from);
      }

      taus[edge.to] -= 1;
      if (taus[edge.to] <= 0)  {
        taus.erase(edge.to);
      }
    }
  }
}

int TriestBase::triangles() {
  long long unsigned topT = t;
  long long unsigned bottomM = M;
  double xi = std::max(1.0, (double)(topT * (topT - 1) * (topT - 2)) / (bottomM * (bottomM - 1) * (bottomM - 2)));
  return (int) tau * xi;
}