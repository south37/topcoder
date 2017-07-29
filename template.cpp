#include <iostream>

using namespace std;

#define DEBUG 0

class Class {
public:
  int method() {
  }
};

int main(int argc, char** argv) {
  Class a0;
  std::cout << "a0: Expected ~, Got \"" << setprecision(10) << a0.method() << "\"" << std::endl;
  // std::cout << "a0: Expected ~, Got \"" << setprecision(10) << a0.method() << "\"" << std::endl;
}
