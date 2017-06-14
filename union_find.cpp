#include <cstring>
#include <iostream>
#include <vector>

class union_find {
public:
    union_find(int size) : data(size, -1) {}
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    void unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return;
        if (x < y) {
          data[y] = x;
        } else {
          data[x] = y;
        }
    }
    int root(int x) {
        return (data[x] < 0) ? x : (data[x] = root(data[x]));
    }
private:
    std::vector<int> data;
};

int main(int argc, char** argv) {
    union_find u(1000);
    u.unionSet(2, 3);
    std::cout << "0 is expected, got " << u.findSet(1, 2) << std::endl;
    std::cout << "1 is expected, got " << u.findSet(2, 3) << std::endl;
    u.unionSet(4, 5);
    std::cout << "0 is expected, got " << u.findSet(2, 4) << std::endl;
    u.unionSet(2, 4);
    std::cout << "1 is expected, got " << u.findSet(3, 5) << std::endl;
    std::cout << "2 is expected, got " << u.root(4) << std::endl;
}
