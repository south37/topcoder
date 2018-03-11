#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <boost/functional/hash.hpp>

using namespace std;

#define DEBUG 0

#define MAX_W 100
#define MAX_L 100

typedef tuple<int, int, int, int> quad;
template<> struct hash<quad> {
  size_t operator()(const quad& q) const noexcept {
    size_t seed = 0;
    boost::hash_combine(seed, get<0>(q));
    boost::hash_combine(seed, get<1>(q));
    boost::hash_combine(seed, get<2>(q));
    boost::hash_combine(seed, get<3>(q));
    return seed;
  }
};

class AvoidRoads {
private:
  long dp[MAX_W+1][MAX_L+1] = { 0 };
  unordered_map<quad, int>bad_m;

public:
  long numWays(int w, int l, vector<string> bad) {
    preparebad(bad);

    dp[0][0] = 1;

    // Initialize bottom row
    for (int i = 1; i < w + 1; ++i) {
      quad p = make_tuple(i - 1, 0, i, 0);
      if (bad_m.find(p) == bad_m.end()) {
        dp[i][0] = dp[i-1][0];
      }
      int j = 0;
      // cout << "i: " << i << ", j: " << j << ", dp[i][j]: " << dp[i][j] << endl;
    }
    // Initialize left column
    for (int j = 1; j < l + 1; ++j) {
      quad p = make_tuple(0, j - 1, 0, j);
      if (bad_m.find(p) == bad_m.end()) {
        dp[0][j] = dp[0][j-1];
      }
      int i = 0;
      // cout << "i: " << i << ", j: " << j << ", dp[i][j]: " << dp[i][j] << endl;
    }
    for (int i = 1; i < w + 1; ++i) {
      for (int j = 1; j < l + 1; ++j) {
        if (bad_m.find(make_tuple(i - 1, j, i, j)) == bad_m.end()) {
          dp[i][j] += dp[i-1][j];
        }
        if (bad_m.find(make_tuple(i, j - 1, i, j)) == bad_m.end()) {
          dp[i][j] += dp[i][j-1];
        }
        // cout << "i: " << i << ", j: " << j << ", dp[i][j]: " << dp[i][j] << endl;
      }
    }

    // Only for debug
    // printf("\n");
    // for (int j = l; j >= 0; --j) {
    //   for (int i = 0; i < w + 1; ++i) {
    //     printf("%5ld", dp[i][j]);
    //   }
    //   printf("\n");
    // }
    return dp[w][l];
  }

  void preparebad(vector<string> bad) {
    for(auto &s : bad) {
      // NOTE: read int from bad string
      int l = s.size();
      vector<int> space;
      for (int i = 0; i < l; ++i) {
        if (s[i] == ' ') {
          space.push_back(i);
        }
      }

      vector<int> pos_list;
      pos_list.push_back(stoi(s));
      for(auto &p : space) {
        pos_list.push_back(stoi(s.substr(p + 1)));
      }

      quad p;
      if (pos_list[0] < pos_list[2] || pos_list[1] < pos_list[3]) {
        p = make_tuple(pos_list[0], pos_list[1], pos_list[2], pos_list[3]);
      } else {
        p = make_tuple(pos_list[2], pos_list[3], pos_list[0], pos_list[1]);
      }
      bad_m[p] = 1;
    }
  }
};

int main(int argc, char** argv) {
  AvoidRoads a0;
  vector<string> bad0 = {"0 0 0 1", "6 6 5 6"};
  std::cout << "a0: Expected 252, Got " << a0.numWays(6, 6, bad0) << "" << std::endl;

  AvoidRoads a1;
  vector<string> bad1 = {};
  std::cout << "a1: Expected 2, Got " << a1.numWays(1, 1, bad1) << "" << std::endl;

  AvoidRoads a2;
  vector<string> bad2 = {};
  std::cout << "a1: Expected 6406484391866534976, Got " << a2.numWays(35, 31, bad2) << "" << std::endl;

  AvoidRoads a3;
  vector<string> bad3 = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
  std::cout << "a1: Expected 0, Got " << a3.numWays(2, 2, bad3) << "" << std::endl;

  return 0;
}
