
#include <iostream>
#include <chrono>

#include "src/stream.h"
#include "src/triestBase.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main() {
  std::cout << std::endl;
  std::string filepath = "../data/p2p-gnutella08.txt";

  auto t1 = high_resolution_clock::now();

  TriestBase tb(filepath, 10000);
  std::cout << "Triangles: " << tb.triangles() << std::endl;

  auto t2 = high_resolution_clock::now();
  auto ms_int = duration_cast<milliseconds>(t2 - t1);
  std::cout << "Execution time: " << ms_int.count() << " ms" << std::endl;

  return 0;
}