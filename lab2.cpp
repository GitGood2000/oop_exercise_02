#include <iostream>

#include "angle.h"

int main(){
  Angle a;
  Angle b;
  //std::cout << "Enter numbers:\n[degrees] and [minutes] (-59...59)" << std::endl;
  a.read(std::cin);
  b.read(std::cin);
  std::cout << "RADS:\n";
  std::cout << a.deg_to_rad() << std::endl;
  std::cout << "0-360 DEG:\n";
  std::cout << a.to360() << " " << a.mntsonly() << std::endl;
  std::cout << "SUM:\n";
  (a + b).awrite(std::cout);
  std::cout << "SUB:\n";
  (a - b).awrite(std::cout);
  std::cout << "DIVIDE:\n";
  std::cout << (a / b) << std::endl;
  std::cout << "SIN:\n";
  std::cout << a.asin() << std::endl;
  std::cout << "COS:\n";
  std::cout << a.acos() << std::endl;
  std::cout << "TAN:\n";
  std::cout << a.atan() << std::endl;

  switch (a > b) {
  case 0:
    std::cout << "A = B" << std::endl;
    break;

  case 1:
    std::cout << "A > B" << std::endl;
    break;

  case -1:
    std::cout << "A < B" << std::endl;
    break;
  }

  return 0;
}
