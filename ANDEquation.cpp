#include <iostream>
#include <vector>

class ANDEquation {
public:
    int restoreY(std::vector<int> input) {
        for(auto it = input.begin(); it != input.end(); ++it) {
            int left = -1;
            for(auto it2 = input.begin(); it2 != input.end(); ++it2) {
                if (it2 != it) {
                    left &= *it2;
                }
            }
            if (left == *it) {
                return *it;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    ANDEquation a0;
    std::vector<int> i0 = {1, 3, 5};
    std::cout << "Input is 1, 3, 5, expected result is 1 and got " << a0.restoreY(i0) << std::endl;

    ANDEquation a1;
    std::vector<int> i1 = {31, 7};
    std::cout << "Input is 31, 7 expected result is -1 and got " << a1.restoreY(i1) << std::endl;

    ANDEquation a2;
    std::vector<int> i2 = {31, 7, 7};
    std::cout << "Input is 31, 7, 7 expected result is 7 and got " << a2.restoreY(i2) << std::endl;

    ANDEquation a3;
    std::vector<int> i3 = {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0, 0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
    std::cout << "Input is {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0, 0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1}, expected result is 0 and got " << a3.restoreY(i3) << std::endl;

    ANDEquation a4;
    std::vector<int> i4 = {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411, 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411, 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947, 191411,191411,191411};
    std::cout << "Input is {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411, 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411, 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947, 191411,191411,191411}, expected result is 191411 and got " << a4.restoreY(i4) << std::endl;

    ANDEquation a5;
    std::vector<int> i5 = {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211};
    std::cout << "Input is {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211}, expected result is -1 and got " << a5.restoreY(i5) << std::endl;

    ANDEquation a6;
    std::vector<int> i6 = {2, 3, 7, 19};
    std::cout << "Input is {2, 3, 7, 19}, expected result is -1 and got " << a6.restoreY(i6) << std::endl;
}
