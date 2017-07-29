#include <iostream>
#include <cmath>

using namespace std;

class AroundTheWall {
public:
  double minDistance(int r, int x1, int y1, int x2, int y2) {
    // Judge by distance of line and (0, 0)
    double a = (double)(y2 - y1) / (x2 - x1); // slope
    std::cout << "slope: " << a << std::endl;
    double b = (double)y2 - (x2 * a);     // segment
    std::cout << "segment: " << b << std::endl;

    double newX = - a * b / (a * a + 1);
    double newY = - a * a * b / (a * a + 1) + b;
    std::cout << "newP: (" << newX << ", " << newY << ")" << std::endl;

    double disForJudge = sqrt(newX * newX + newY * newY);
    std::cout << "disForJudge: " << disForJudge << std::endl;

    if (disForJudge > r) { // Wall is not preventing
      double diffX = x2 - x1;
      double diffY = y2 - y1;
      return sqrt(diffX * diffX + diffY * diffY);

    } else { // Wall is not preventing
      // point 1
      double d1 = sqrt(x1 * x1 + y1 * y1);
      // double cos1 = (double)x1 / d1;  // Must be corrected for all position.
      // double angle1;
      // if (y1 > 0) {
      //   angle1 = acos(cos1);
      // } else {
      //   angle1 = M_PI * 2 - acos(cos1);
      // }
      // std::cout << "angle1: " << angle1 << std::endl;
      // std::cout << "tan(angle1): " << tan(angle1) << std::endl;

      double diffD1 = sqrt(x1 * x1 + y1 * y1 - r * r);
      double cosDiff1 = diffD1 / d1;
      double angleDiff1 = acos(cosDiff1);

      // point 2
      double d2 = sqrt(x2 * x2 + y2 * y2);
      // double cos2 = abs((double)x2 / d2); // Must be corrected for all position.
      // double angle2;
      // if (y2 > 0) {
      //   angle2 = acos(cos2);
      // } else {
      //   angle2 = M_PI * 2 - acos(cos2);
      // }
      // std::cout << "angle2: " << angle2 << std::endl;
      // std::cout << "tan(angle2): " << tan(angle2) << std::endl;

      double diffD2 = sqrt(x2 * x2 + y2 * y2 - r * r);
      double cosDiff2 = diffD2 / d2;
      double angleDiff2 = acos(cosDiff2);

      // double totalAngle = abs(angle1 - angle2);  // Must be fixed!!(accuracy is necessary)
      double cosTotalAngle = (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
      std::cout << "cosTotalAngle: " << cosTotalAngle << std::endl;
      double totalAngle = acos(cosTotalAngle);
      std::cout << "totalAngle: " << totalAngle << std::endl;
      double diffAngle = totalAngle - angleDiff1 - angleDiff2;

      return diffD1 + diffD2 + (r * diffAngle);
    }
  }

  // Used by rightBottom point.
  // void leftBottomVector(int x, int y, int r) {
  //   double len = sqrt(r) / sqrt(x * x + y * y);
  //   double newX = -y / (x * x + ;
  //   double newY = x;
  // }

  // Used by leftBottom point.
  void leftUpVector(int x, int y, int r) {
    double forLen = sqrt(r) / sqrt(x * x + y * y);
    double newX = y * forLen;
    double newY = - x * forLen;
  }
};

int main(int argc, char** argv) {
    AroundTheWall a0;
    std::cout << "a0: Got \"" << a0.minDistance(1, 1, 2, -2, 0) << "\"" << std::endl;

    AroundTheWall a1;
    std::cout << "a1: Got \"" << a1.minDistance(5, -7, -1, 1, 7) << "\"" << std::endl;

    AroundTheWall a2;
    std::cout << "a1: Got \"" << a2.minDistance(5, 1, 7, -1, -7) << "\"" << std::endl;
}
