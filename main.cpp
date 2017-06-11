#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

typedef unsigned long long unsigned int ulong;

class ABBADiv1 {
public:
    std::string canObtain(std::string initial, std::string target) {
        int i_len = initial.length();
        int t_len = target.length();
        int dif = t_len - i_len;
        createFromInitial(initial, i_len + dif / 2);
        if (checkFromTarget(target, i_len + dif / 2)) {
            return "Possible";
        } else {
            return "Impossible";
        }
    }
    void createFromInitial(std::string& initial, int len) {
        ulong i = changeToLong(initial);
        auto f = std::make_pair(i, initial.length());
        std::queue< std::pair<ulong, int> > que;
        que.push(f);
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p.second == len) {
                set.insert(p.first);
                continue;
            }
            que.push(std::make_pair(addA(p.first), p.second + 1));
            que.push(std::make_pair(addBAndRevese(p.first, p.second), p.second + 1));
        }
    }
    bool checkFromTarget(std::string& target, int len) {
        ulong t = changeToLong(target);
        auto f = std::make_pair(t, target.length());
        std::queue< std::pair<ulong, int> > que;
        que.push(f);
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p.second == len) {
                if (set.find(p.first) != set.end()) {
                    return true;
                }
                continue;
            }
            if (canRemoveA(p.first)) {
                que.push(std::make_pair(removeA(p.first), p.second - 1));
            }
            if (canRemoveB(p.first, p.second)) {
                que.push(std::make_pair(removeB(p.first, p.second), p.second - 1));
            }
        }
        return false;
    }
    bool canRemoveA(ulong n) {
        return (n & 0x01) == 0;
    }
    ulong removeA(ulong n) {
        return (n >> 1);
    }
    bool canRemoveB(ulong n, int len) {
        return (n >> (len - 1)) & 0x01;
    }
    ulong removeB(ulong n, int len) {
        return reverseWithLen(n, len) >> 1;
    }
    ulong addA(ulong n) {
        return (n << 1);
    }
    ulong addBAndRevese(ulong n, int len) {
        return reverseWithLen(((n << 1) | 0x01), len + 1);
    }
    ulong changeToLong(const std::string& s) {
        ulong result = 0;
        auto end = s.end();
        for(auto it = s.begin(); it != end; ++it) {
            result <<= 1;
            if (*it == 'B') {  // If 'A', 0 is set
                result += 1;
            }
        }
        return result;
    }
    ulong reverseWithLen(ulong n, int len) {
        return reverse(n) >> (sizeof(long) * CHAR_BIT - len);
    }
    ulong reverse(ulong n) {
        ulong rv = 0;
        std::size_t b = sizeof(ulong) * CHAR_BIT;
        for (std::size_t i = 0; i < b; ++i, n >>= 1) {
            rv = (rv << 1) | (n & 0x01);
        }
        return rv;
    }
    std::set<ulong> set;
};


int main(int argc, char** argv) {
  ABBADiv1 a;
  ulong result = a.changeToLong("BAAB");
  std::cout << std::bitset<sizeof(ulong) * CHAR_BIT>(result) << std::endl;
  std::cout << std::bitset<sizeof(ulong) * CHAR_BIT>(a.addA(result)) << std::endl;
  std::cout << std::bitset<sizeof(ulong) * CHAR_BIT>(a.addBAndRevese(result, 4)) << std::endl;

  std::cout << "start from BAAB" << std::endl;
  std::string s("BAAB");
  a.createFromInitial(s, 6);
  for (auto it = a.set.begin(); it != a.set.end(); ++it) {
      std::cout << std::bitset<sizeof(ulong) * CHAR_BIT>(*it) << std::endl;
  }

  ABBADiv1 b;
  std::cout << "Possible is expected, got " << b.canObtain("A", "BABA") << std::endl;

  ABBADiv1 c;
  std::cout << "Impossible is expected, got " << c.canObtain("A", "ABBA") << std::endl;

  //ABBADiv1 b2;
  //auto start = std::chrono::system_clock::now();
  //std::cout << "Possible is expected, got " << b2.canObtain("A", "BABAAAAAAAAAAAAAAAAAAA") << std::endl;
  //auto end = std::chrono::system_clock::now();
  //std::chrono::duration<double> diff = end-start;
  //std::cout << "Time is " << diff.count() << std::endl;

  ABBADiv1 d;
  std::cout << "Possible is expected, got " << d.canObtain("AAABBAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") << std::endl;

  ABBADiv1 e;
  std::cout << "Impossible is expected, got " << e.canObtain("AAABAAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") << std::endl;
}
