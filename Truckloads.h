#ifndef TRUCKLOADS_H
#define TRUCKLOADS_H

class Truckloads {
 private:
  int numCrates_;
  int loadSize_;

 public:
  Truckloads(int numCrates, int loadSize) : numCrates_(numCrates), loadSize_(loadSize) {}

  int numTrucks(int numCrates, int loadSize);
};

#endif
