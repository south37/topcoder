#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

class ATaleOfThreeCities {
public:
    double connect(std::vector <int> ax, std::vector <int> ay, std::vector <int> bx, std::vector <int> by, std::vector <int> cx, std::vector <int> cy) {
        int minAB = calcMin(ax, ay, bx, by);
        int minBC = calcMin(bx, by, cx, cy);
        int minCA = calcMin(cx, cy, ax, ay);
        std::vector<int> v = {minAB, minBC, minCA};
        std::sort(v.begin(), v.end());

        long double v0 = std::sqrt(v[0]);
        long double v1 = std::sqrt(v[1]);

        return (v0 + v1);
    }

    int calcMin(std::vector <int> ax, std::vector <int> ay, std::vector <int> bx, std::vector <int> by) {
        int minAB = 100000; // larger than (200 * 200) * 2 = 80,000
        int sizeA = ax.size();
        int sizeB = bx.size();
        for(int i = 0; i < sizeA; ++i) {
            for(int j = 0; j < sizeB; ++j) {
                int d = ((ax[i] - bx[j]) * (ax[i] - bx[j])) + ((ay[i] - by[j]) * (ay[i] - by[j]));
                if (d < minAB) {
                    minAB = d;
                }
            }
        }
        return minAB;
    }
};

int main(int argc, char**argv) {
    ATaleOfThreeCities t0;
    std::vector<int> ax0 = {0,0,0};
    std::vector<int> ay0 = {0,1,2};
    std::vector<int> bx0 = {2,3};
    std::vector<int> by0 = {1,1};
    std::vector<int> cx0 = {1,5};
    std::vector<int> cy0 = {3,28};
    std::cout << "expected is 3.414213562373095, and got " << t0.connect(ax0, ay0, bx0, by0, cx0, cy0) << std::endl;
}
