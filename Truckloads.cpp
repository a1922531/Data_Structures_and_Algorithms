#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
  if (numCrates <= 0 || loadSize <= 0) return 0;  // Check for correctness
  if (numCrates <= loadSize) return 1;            // return 1 truck when the load fits within truck

  int half = numCrates / 2;
  int otherHalf = numCrates - half;

  return numTrucks(half, loadSize) + numTrucks(otherHalf, loadSize);
}