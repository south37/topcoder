#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

#define MAX_D 50
#define MAX_B 101
// NOTE: MAX_RESULT must be larger than 50 x 50 = 2,500
#define MAX_RESULT 10000

typedef std::pair<int, int> position;

struct state {
  int y, x, b, t;
};
bool operator < (const state &a, const state &b) {
  // NOTE: priority_queue's top() returns minimum.
  return a.t > b.t;
}

// NOTE: (dx[i], dy[i]) means next position offset.
int dy[4] = { 0, 0,  1, -1 };
int dx[4] = { 1, -1, 0, 0 };

class BombMan {
private:
  int seen[MAX_D][MAX_D][MAX_B] = { 0 };
public:
  int shortestPath(const std::vector<std::string>& maze, int bombs) {
    // NOTE: i (0..h-1) is height dir, j (0..w-1) is width dir.
    int h = maze.size();
    int w = maze[0].size();

    // NOTE: initialize b and e
    position b;
    position e;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (maze[i][j] == 'B') {
          b.first = i;
          b.second = j;
        }
        if (maze[i][j] == 'E') {
          e.first = i;
          e.second = j;
        }
      }
    }

    std::priority_queue<state> q;
    state bs = { b.first, b.second, bombs, 0 };
    q.push(bs);

    while (!q.empty()) {
      state s = q.top();
      q.pop();

      // Find
      if (s.y == e.first && s.x == e.second) return s.t;

      if (seen[s.y][s.x][s.b]) continue;
      seen[s.y][s.x][s.b] = 1;

      // Check top, left, right, bottom
      for (int i = 0; i < 4; ++i) {
        int ty = s.y + dy[i];
        int tx = s.x + dx[i];
        if ((ty >= 0) && (ty <= h - 1) && (tx >= 0) && (tx <= w - 1)) {
          state n = s;
          n.y = ty;
          n.x = tx;
          if (maze[ty][tx] == '#') {
            // NOTE: b is necessary for proceed
            if (n.b == 0) continue;
            n.b--;
            n.t += 3;
            q.push(n);
          } else {
            n.t++;
            q.push(n);
          }
        }
      }
    }
    return -1;
  }
};

int main(int argc, char** argv) {
  BombMan a0;
  std::vector<std::string> maze0 = {
    ".....B.",
    ".#####.",
    ".#...#.",
    ".#E#.#.",
    ".###.#.",
    "......."
  };
  int bombs0 = 1;
  std::cout << "a0: Expected 8, Got " << a0.shortestPath(maze0, bombs0) << std::endl;

  BombMan a1;
  std::vector<std::string> maze1 = {"B.#.#.#...E"};
  int bombs1 = 2;
  std::cout << "a0: Expected -1, Got " << a1.shortestPath(maze1, bombs1) << std::endl;

  BombMan a2;
  std::vector<std::string> maze2 = {
    "..#####",
    "B.#####",
    "..#####",
    "#######",
    "####...",
    "####.E."
  };
  int bombs2 = 4;
  std::cout << "a0: Expected 17, Got " << a2.shortestPath(maze2, bombs2) << std::endl;

  return 0;
}
