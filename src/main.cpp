#include <iostream>

#include "linkedQueue.h"

int main() {
  linkedQueueType<int> f;

  f.addQueue(4);
  f.addQueue(9);
  f.addQueue(7);

  linkedQueueType<int> g(f);

  std::cout << g.front() << std::endl;
  std::cout << g.back() << std::endl;
}