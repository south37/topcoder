#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define DEBUG 0

class AroundTheWall {
public:
  double minDistance(int r, int x1, int y1, int x2, int y2) {
    // Judge by distance of line and (0, 0)
    double a = (double)(y2 - y1) / (x2 - x1); // slope
    if (DEBUG) std::cout << "slope: " << a << std::endl;
    double b = (double)y2 - (x2 * a);     // segment
    if (DEBUG) std::cout << "segment: " << b << std::endl;

    double newX = - a * b / (a * a + 1);
    double newY = - a * a * b / (a * a + 1) + b;
    if (DEBUG) std::cout << "newP: (" << newX << ", " << newY << ")" << std::endl;

    double disForJudge = sqrt(newX * newX + newY * newY);
    if (DEBUG) std::cout << "disForJudge: " << disForJudge << std::endl;

    if (disForJudge > r) { // Wall is not preventing
      double diffX = x2 - x1;
      double diffY = y2 - y1;
      return sqrt(diffX * diffX + diffY * diffY);

    } else { // Wall is not preventing
      // point 1
      double d1 = sqrt((double)(x1 * x1 + y1 * y1));
      double diffD1 = sqrt((double)(x1 * x1 + y1 * y1 - r * r));
      if (DEBUG) std::cout << "diffD1: " << diffD1 << std::endl;
      double sinDiff1 = diffD1 / d1;
      double angleDiff1 = asin(sinDiff1);
      if (DEBUG) std::cout << "angleDiff1: " << angleDiff1 << std::endl;

      // point 2
      double d2 = sqrt((double)(x2 * x2 + y2 * y2));
      double diffD2 = sqrt((double)(x2 * x2 + y2 * y2 - r * r));
      if (DEBUG) std::cout << "diffD2: " << diffD2 << std::endl;
      double sinDiff2 = diffD2 / d2;
      double angleDiff2 = asin(sinDiff2);
      if (DEBUG) std::cout << "angleDiff2: " << angleDiff2 << std::endl;

      double dot = x1 * x2 + y1 * y2;    // |p1| |p2| cos(0)
      double cross = x1 * y2 - y1 * x2;  // |p1| |p2| sin(0)
      double totalAngle = abs(atan2(cross, dot));
      if (DEBUG) std::cout << "totalAngle: " << setprecision(10) << totalAngle << std::endl;
      double diffAngle = totalAngle - angleDiff1 - angleDiff2;

      return diffD1 + diffD2 + (r * diffAngle);
    }
  }
};

int main(int argc, char** argv) {
    AroundTheWall a0;
    std::cout << "a0: Expected 3.605551275463989, Got \"" << setprecision(10) << a0.minDistance(1, 1, 2, -2, 0) << "\"" << std::endl;

    AroundTheWall a1;
    std::cout << "a1: Expected 11.41897054604164, Got \"" << setprecision(10) << a1.minDistance(5, -7, -1, 1, 7) << "\"" << std::endl;

    AroundTheWall a2;
    std::cout << "a2: Expected 17.853981633974485, Got \"" << setprecision(10) << a2.minDistance(5, 1, 7, -1, -7) << "\"" << std::endl;

    AroundTheWall a3;
    std::cout << "a3: Expected 55.35743588970452, Got \"" << setprecision(10) << a3.minDistance(25, -7, 24, -15, -20) << "\"" << std::endl;
}
