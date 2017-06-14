#include <cstring>
#include <iostream>
#include <vector>

#define N 1000

class union_find {
public:
    union_find(void) { std::memset(data, 0, sizeof(data)); }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    void unionSet(int x, int y) {
        if (root(x) == root(y)) return;
        if (x < y) {
          data[root(y)] = root(x);
        } else {
          data[root(x)] = root(y);
        }
    }
    int root(int x) {
        if (data[x] == 0) {
            data[x] = x;
            return x;
        }
        if (x == data[x]) {
            return x;
        } else {
            int r = root(data[x]);
            data[x] = r;
            return r;
        }
    }
private:
    int data[N];
};

int main(int argc, char** argv) {
    union_find u;
    u.unionSet(2, 3);
    std::cout << "0 is expected, got " << u.findSet(1, 2) << std::endl;
    std::cout << "1 is expected, got " << u.findSet(2, 3) << std::endl;
    u.unionSet(4, 5);
    std::cout << "0 is expected, got " << u.findSet(2, 4) << std::endl;
    u.unionSet(2, 4);
    std::cout << "1 is expected, got " << u.findSet(3, 5) << std::endl;
    std::cout << "2 is expected, got " << u.root(4) << std::endl;
}
