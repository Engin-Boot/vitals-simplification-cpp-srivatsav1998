#include <assert.h>
#include <iostream>

bool isInsideLimit(float value, float lowerLimit, float upperLimit){
  return ( value >= lowerLimit && value <= upperLimit );
}

void testAbstractFunction(){
  assert(isInsideLimit(10, 30, 40) == false);
  assert(isInsideLimit(35, 30, 40) == true);
  assert(isInsideLimit(45, 30, 40) == false);
  assert(isInsideLimit(30, 30, 40) == true);
  assert(isInsideLimit(40, 30, 40) == true);
}

int main() {
  testAbstractFunction();
  std::cout << "All tests passed!!" << std::endl;
}
