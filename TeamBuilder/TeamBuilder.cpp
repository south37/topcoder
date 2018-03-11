#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX_N 50
// NOTE: MAX_D must be larger than MAX_N
#define MAX_D 100

class TeamBuilder {
private:
  int d[MAX_N][MAX_N];
public:
  std::vector<int> specialLocations(const std::vector<std::string>& paths) {
    int len = paths.size();
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        // NOTE: set 0 when i == j
        if (i == j) {
          d[i][j] = 0;
          continue;
        }

        if (paths[i][j] == '1') {
          // NOTE: can move
          d[i][j] = 0;
        } else {
          // NOTE: can not move
          d[i][j] = MAX_D;
        }
      }
    }

    for (int k = 0; k < len; ++k) {
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }

    int r1 = 0;
    for (int i = 0; i < len; ++i) {
      int success = true;
      for (int j = 0; j < len; ++j) {
        if (d[i][j] != 0) success = false;
      }
      if (success) r1++;
    }
    int r2 = 0;
    for (int i = 0; i < len; ++i) {
      int success = true;
      for (int j = 0; j < len; ++j) {
        if (d[j][i] != 0) success = false;
      }
      if (success) r2++;
    }
    return { r1, r2 };
  }
};

int main(int argc, char** argv) {
  TeamBuilder a0;
  std::vector<std::string> s0 = {"010","000","110"};
  std::vector<int> r0 = a0.specialLocations(s0);
  std::cout << "a0: Expected { 1, 1 }, Got " << "{ " << r0[0] << ", " << r0[1] << " }" << std::endl;

  TeamBuilder a1;
  std::vector<std::string> s1 = {"0010","1000","1100","1000"};
  std::vector<int> r1 = a1.specialLocations(s1);
  std::cout << "a1: Expected { 1, 3 }, Got " << "{ " << r1[0] << ", " << r1[1] << " }" << std::endl;

  TeamBuilder a2;
  std::vector<std::string> s2 = {"01000","00100","00010","00001","10000"};
  std::vector<int> r2 = a2.specialLocations(s2);
  std::cout << "a2: Expected { 5, 5 }, Got " << "{ " << r2[0] << ", " << r2[1] << " }" << std::endl;

  TeamBuilder a3;
  std::vector<std::string> s3 = {"0110000","1000100","0000001","0010000","0110000","1000010","0001000"};
  std::vector<int> r3 = a3.specialLocations(s3);
  std::cout << "a2: Expected { 1, 3 }, Got " << "{ " << r3[0] << ", " << r3[1] << " }" << std::endl;

  return 0;
}
