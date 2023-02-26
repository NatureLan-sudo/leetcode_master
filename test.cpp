#include "common_include.h"
struct Point2D {
  double x;
  double y;
};
int chacheng(Point2D a, Point2D b) {};
Point2D shiliang (Point2D a, Point2D b) {
  Point2D ab;
  ab.x = b.x - a.x;
  ab.y = b.y - a.y;
  return ab;
}
bool OutsideOfTriangle(const Point2D &a, const Point2D &b, const Point2D &c, const Point2D &m) {
  // write code here
  Point2D ab = shiliang(a, b);
  Point2D ac = shiliang(a, c);
  Point2D bc = shiliang(b, c);
  Point2D am = shiliang(a, m);
  Point2D bm = shiliang(b, m);
  Point2D cm = shiliang(c, m);
  if (chacheng(ab, am)*chacheng(ab, ac) && chacheng(ac, am)*chacheng(ac, ab) && chacheng(bc, bm)*chacheng(bc, ab)) return false;
  return true;
}
