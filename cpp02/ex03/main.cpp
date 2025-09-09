#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
	Point A(0.0f, 0.0f);
	Point B(10.0f, 0.0f);
	Point C(5.0f, 10.0f);

	Point P_inside(5.0f, 5.0f);
	Point P_outside(10.0f, 10.0f);
	Point P_edge(5.0f, 0.0f);
	Point P_vertex(0.0f, 0.0f);

	std::cout << "P_inside: " << (bsp(A, B, C, P_inside) ? "inside" : "outside") << std::endl;
	std::cout << "P_outside: " << (bsp(A, B, C, P_outside) ? "inside" : "outside") << std::endl;
	std::cout << "P_edge: " << (bsp(A, B, C, P_edge) ? "inside" : "outside") << std::endl;
	std::cout << "P_vertex: " << (bsp(A, B, C, P_vertex) ? "inside" : "outside") << std::endl;

	return 0;
}