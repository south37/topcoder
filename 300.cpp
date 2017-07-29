#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define DEBUG 0

class ILike5 {
public:
  // odd number.
  // bug if odd number is 0, 5 must be exists. if not, result is 1.
  int transformTheSequence(vector <int> X) {
    int result = 0;
    bool fiveExists = false;
    for (auto num : X) {
      if ((num % 2) == 0) {
        result += 1;
      }

      if ((num % 10) == 5) {
        fiveExists = true;
      }
    }

    if (result > 0) {
      return result;
    } else {
      if (fiveExists) {
        return 0;
      } else {
        return 1;
      }
    }
  }
};

int main(int argc, char** argv) {
  ILike5 a0;
  vector<int> bottles0 = {5, 2, 8, 12};
  std::cout << "a0: Expected 20.0625, Got \"" << setprecision(10) << a0.transformTheSequence(bottles0) << "\"" << std::endl;

  ILike5 a1;
  vector<int> bottles1 = {1555};
  std::cout << "a1: Expected 42.0, Got \"" << setprecision(10) << a1.transformTheSequence(bottles1) << "\"" << std::endl;

  ILike5 a2;
  vector<int> bottles2 = {0, 10, 100, 1000, 10000};
  std::cout << "a2: Expected 5555555.0, Got \"" << setprecision(10) << a2.transformTheSequence(bottles2) << "\"" << std::endl;

  ILike5 a3;
  vector<int> bottles3 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  std::cout << "a3: Expected 5.08428837725E8, Got \"" << setprecision(10) << a3.transformTheSequence(bottles3) << "\"" << std::endl;

  ILike5 a4;
  vector<int> bottles4 = {7890, 4861, 65773, 3769, 4638, 46000, 548254, 36185, 115};
  std::cout << "a4: Expected 0.5, Got \"" << setprecision(10) << a4.transformTheSequence(bottles4) << "\"" << std::endl;
}
