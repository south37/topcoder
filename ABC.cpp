#include <iostream>
#include <map>
#include <queue>

typedef std::tuple<int, int, int> tpl;

class ABC {
public:
    std::string createString(int N, int K) {
        tpl result;
        int max = -1;
        if (exists(N, K, &result, &max)) {
            std::string s;
            s += std::to_string(std::get<0>(result));
            s += ", ";
            s += std::to_string(std::get<1>(result));
            s += ", ";
            s += std::to_string(std::get<2>(result));
            s += ": ";
            s += std::to_string(max);
            return s;
        } else {
            return "";
        }
    }
    bool exists(int N, int K, tpl* result, int* max) {
        tpl f = std::make_tuple(0, 0, 0);
        dp[f] = 0;
        std::queue<tpl> que;
        que.push(f);

        while(!que.empty()) {
            tpl t = que.front();
            que.pop();

            auto it = dp.find(t);
            if (it == dp.end()) { exit(-1); }  // Must not occur!
            int prev = it->second;

            if (std::get<0>(t) + std::get<1>(t) + std::get<2>(t) == N) {
                if (prev > *max) {
                    *max = prev;
                    *result = t;
                }
                continue;
            }

            int i0 = std::get<0>(t);
            int i1 = std::get<1>(t);
            int i2 = std::get<2>(t);
            tpl t0 = std::make_tuple(i0 + 1, i1, i2);
            if (insertIfLarge(t0, prev)) {
                que.push(t0);
            }
            tpl t1 = std::make_tuple(i0, i1 + 1, i2);
            if (insertIfLarge(t1, prev + i0)) {
                que.push(t1);
            }
            tpl t2 = std::make_tuple(i0, i1, i2 + 1);
            if (insertIfLarge(t2, prev + i0 + i1)) {
                que.push(t2);
            }
        }

        return (*max >= K);
    }
    // return true if prev is empty and insertion is done
    bool insertIfLarge(const tpl& t, int v) {
        auto it = dp.find(t);
        if (it == dp.end()) {
            dp[t] = v;
            return true;
        }
        if (v > it->second) {
            dp[t] = v;
        }
        return false;
    }
    std::map<tpl, int> dp;
};

int main(int argc, char** argv) {
    ABC a0;
    // std::cout << "Input is (3, 3), expected is \"ABC\" and got \"" << a0.createString(3, 3) << "\"" << std::endl;
    std::cout << "Input is (3, 3), expected is true and got " << a0.createString(3, 3) << std::endl;

    ABC a1;
    std::cout << "Input is (3, 0), expected is true and got " << a1.createString(3, 0) << std::endl;

    ABC a2;
    std::cout << "Input is (5, 10), expected is \"\" and got " << a2.createString(5, 10) << std::endl;

    ABC a3;
    std::cout << "Input is (15, 36), expected is true and got " << a3.createString(15, 36) << std::endl;

    ABC a4;
    std::cout << "Input is (14, 36), expected is ? and got " << a4.createString(14, 36) << std::endl;

    ABC a5;
    std::cout << "Input is (13, 36), expected is ? and got " << a5.createString(13, 36) << std::endl;

    ABC a6;
    std::cout << "Input is (12, 36), expected is ? and got " << a6.createString(12, 36) << std::endl;
}
