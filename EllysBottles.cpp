#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

#define MAX_ITER 123456

#define DEBUG 0

class EllysBottles {
public:
  double getVolume(vector <int> bottles, int k) {
    int k_count = min(k, MAX_ITER);

    multiset<double> st;
    for (auto b : bottles) {
      st.insert(b);
    }

    for (int i = 0; i < k_count; ++i) {
      auto beginIt = st.begin();
      double minB = *beginIt;
      if (DEBUG) { cout << "minB: " << minB << endl; }
      st.erase(beginIt);
      auto endIt = prev(st.end());
      double maxB = *endIt;
      if (DEBUG) { cout << "maxB: " << maxB << endl; }
      st.erase(endIt);

      double mean = (double)(minB + maxB) / 2.0;
      st.insert(mean);
      st.insert(mean);

      if (DEBUG) {
        cout << "{";
        for (auto b : st) {
          cout << b << ", ";
        }
        cout << "}" << endl;
      }
    }

    return *st.begin();
  }
};

int main(int argc, char** argv) {
  EllysBottles a0;
  vector<int> bottles0 = { 42, 13, 17, 7, 22 };
  std::cout << "a0: Expected 20.0625, Got \"" << setprecision(10) << a0.getVolume(bottles0, 8) << "\"" << std::endl;

  EllysBottles a1;
  vector<int> bottles1 = { 42, 42, 42 };
  std::cout << "a1: Expected 42.0, Got \"" << setprecision(10) << a1.getVolume(bottles1, 42) << "\"" << std::endl;

  EllysBottles a2;
  vector<int> bottles2 = {1111111, 2222222, 3333333, 4444444, 5555555, 6666666, 7777777, 8888888, 9999999};
  std::cout << "a2: Expected 5555555.0, Got \"" << setprecision(10) << a2.getVolume(bottles2, 4) << "\"" << std::endl;

  EllysBottles a3;
  vector<int> bottles3 = {937831252, 223252363, 706118333, 954711869, 819583497, 520873195, 879422756, 464831418, 156067240, 646868794, 894534170, 23380905, 855234472, 319560027, 305097549, 374217481, 86837363, 718892301, 952809474, 558293585, 91833518, 862607400, 982038771, 942620013, 507984782, 546527456, 615697673, 237645185, 53645793, 780959476, 136257699, 969658933, 959150775, 43875123, 9012, 349823412, 85123543, 349085123, 194357213, 229834565};
  std::cout << "a3: Expected 5.08428837725E8, Got \"" << setprecision(10) << a3.getVolume(bottles3, 1234567) << "\"" << std::endl;

  EllysBottles a4;
  vector<int> bottles4 = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  std::cout << "a4: Expected 0.5, Got \"" << setprecision(10) << a4.getVolume(bottles4, 1000000000) << "\"" << std::endl;
}
