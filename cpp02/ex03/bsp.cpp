#include "Point.hpp"

static Fixed cross(const Point& a, const Point& b, const Point& c) {
	return (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed c1 = cross(a, b, point);
	Fixed c2 = cross(b, c, point);
	Fixed c3 = cross(c, a, point);

	if (c1 == Fixed(0) || c2 == Fixed(0) || c3 == Fixed(0))
		return false;
	bool hasNeg = (c1 < Fixed(0)) || (c2 < Fixed(0)) || (c3 < Fixed(0));
	bool hasPos = (c1 > Fixed(0)) || (c2 > Fixed(0)) || (c3 > Fixed(0));

	return !(hasNeg && hasPos);
}
