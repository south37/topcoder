#include <iostream>
#include <vector>

class ZigZag {
public:
  int longestZigZag(std::vector <int> sequence) {
    // NOTE: early return
    if (sequence.size() <= 2) {
      return sequence.size();
    }

    std::vector<int> diff_list(sequence.size() - 1);
    for(int i = 1; i < sequence.size(); ++i) {
      diff_list[i - 1] = sequence[i] - sequence[i - 1];
    }

    // NOTE: check for sequence of 0
    int ii = 0;
    while (ii < diff_list.size() && diff_list[ii] == 0) ++ii;
    if (ii == diff_list.size()) return 1;

    int dir = diff_list[ii];
    int len = 2;
    for (int i = ii + 1; i < diff_list.size(); ++i) {
      if (diff_list[i] * dir < 0) {
        dir *= -1;
        ++len;
      }
    }
    return len;
  }
};

int main(int argc, char** argv) {
  std::vector<int> x1 = { 1, 7, 4, 9, 2, 5 };
  ZigZag(zigzag1);
  std::cout << "6 is expected, got " << zigzag1.longestZigZag(x1) << std::endl;

  std::vector<int> x2 = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
  ZigZag(zigzag2);
  std::cout << "7 is expected, got " << zigzag2.longestZigZag(x2) << std::endl;

  std::vector<int> x3 = {396, 549, 22, 819, 611, 972, 730, 638, 978, 342, 566, 514, 752, 871, 911, 172, 488, 542, 482, 974, 210, 474, 66, 387, 1, 872, 799, 262, 567, 113, 578, 308, 813, 515, 716, 905, 434, 101, 632, 450, 74, 254, 1000, 780, 633, 496, 513, 772, 925, 746};
  ZigZag(zigzag3);
  std::cout << "37 is expected, got " << zigzag3.longestZigZag(x3) << std::endl;
  return 0;
}
