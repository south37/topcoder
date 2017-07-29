#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <queue>
#include <map>

using namespace std;

#define MAX_ITER 123456

#define DEBUG 0

class EllysBottles {
public:
  double getVolume(vector <int> bottles, int k) {
    int len = bottles.size();
    int k_count = min(k, MAX_ITER);

    priority_queue<double, vector<double>, greater<double>> minq;
    for(auto b : bottles) {
      minq.push(b);
    }
    priority_queue<double> maxq;
    for(auto b : bottles) {
      maxq.push(b);
    }

    map<double, int> usedMin;  // poped value from maxq must be rejected from minq. so is is pushed to here.
    map<double, int> usedMax;  // poped value from minq must be rejected from maxq. so is is pushed to here.
    for (int i = 0; i < k_count; ++i) {
      // fetch minB
      double minB;
      while (true) {
        minB = minq.top(); minq.pop();
        // Check presence in usedMin
        auto it = usedMin.find(minB);
        if ((it != usedMin.end()) && (it->second > 0)) {
          it->second -= 1;
          continue;
        }
        break;
      }


      // fetch maxB
      double maxB;
      while (true) {
        maxB = maxq.top(); maxq.pop();
        // Check presence in usedMax
        auto it = usedMax.find(maxB);
        if ((it != usedMax.end()) && (it->second > 0)) {
          it->second -= 1;
          continue;
        }
        break;
      }


      auto maxIt = usedMax.find(minB);
      if (maxIt != usedMax.end()) {
        maxIt->second += 1;
      } else {
        usedMax[minB] = 1;
      }
      auto minIt = usedMin.find(maxB);
      if (minIt != usedMin.end()) {
        minIt->second += 1;
      } else {
        usedMin[maxB] = 1;
      }

      if (DEBUG) cout << "minB: " << minB << endl;
      if (DEBUG) cout << "maxB: " << maxB << endl;

      double mean = (double)(minB + maxB) / 2.0;
      minq.push(mean);
      minq.push(mean);
      maxq.push(mean);
      maxq.push(mean);

      if (DEBUG) {
        cout << "{";
        priority_queue<double, vector<double>, greater<double>> copyMinq = minq;
        for (int i = 0; i < len; ++i) {
          double b = minq.top(); minq.pop();
          cout << b << ", ";
        }
        cout << "}" << endl;

        minq = copyMinq;
      }
    }

    double result;
    while (true) {
      result = minq.top(); minq.pop();
      // Check presence in usedMin
      auto it = usedMin.find(result);
      if ((it != usedMin.end()) && (it->second > 0)) {
        it->second -= 1;
        continue;
      }
      break;
    }
    return result;
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
