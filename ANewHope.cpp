#include <iostream>
#include <vector>

class ANewHope {
public:
    int count(std::vector<int> firstWeek, std::vector<int> lastWeek, int D) {
        int size = firstWeek.size();
        std::vector<int> firstInverted(size);
        for (auto it = firstWeek.begin(); it != firstWeek.end(); ++it) {
            firstInverted[*it-1] = std::distance(firstWeek.begin(), it);
        }
        std::vector<int> lastInverted(size);
        for (auto it = lastWeek.begin(); it != lastWeek.end(); ++it) {
            lastInverted[*it-1] = std::distance(lastWeek.begin(), it);
        }

        int m = 0;
        for (int i = 0; i < size; ++i) {
            int d = firstInverted[i] - lastInverted[i];
            if (d > m) {
                m = d;
            }
        }

        int step = size - D;
        int operationCount = 1;
        operationCount += m / step;
        if ((m % step) > 0) {
            operationCount += 1;
        }
        return operationCount;
    }
};

int main(int argc, char** argv) {
    ANewHope a0;
    std::vector<int> firstWeek0 = {1,2,3,4};
    std::vector<int> lastWeek0 = {4,3,2,1};
    std::cout << "Input is {1,2,3,4} and {4,3,2,1} and 3, 4 is expected and got " << a0.count(firstWeek0, lastWeek0, 3) << std::endl;

    ANewHope a1;
    std::vector<int> firstWeek1 = {8,5,4,1,7,6,3,2};
    std::vector<int> lastWeek1 = {2,4,6,8,1,3,5,7};
    std::cout << "Input is {8,5,4,1,7,6,3,2} and {2,4,6,8,1,3,5,7} and 3, 3 is expected and got " << a1.count(firstWeek1, lastWeek1, 3) << std::endl;

    ANewHope a2;
    std::vector<int> firstWeek2 = {1,2,3,4};
    std::vector<int> lastWeek2 = {1,2,3,4};
    std::cout << "Input is {1,2,3,4} and {1,2,3,4} and 2, 1 is expected and got " << a2.count(firstWeek2, lastWeek2, 2) << std::endl;
}
