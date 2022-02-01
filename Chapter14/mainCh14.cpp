#include <iostream>
#include <string>

using std::cout;
using std::string;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

class SimpleRational
{
	int numerator;
	int denominator;
public:
	SimpleRational(int n, int d) : numerator(n), denominator(d)
	{
		if (d == 0)
		{
			cout << "Zero denominator error\n";
			exit(1);
		}
	}

	SimpleRational() : numerator(0), denominator(1) {}

	void set_numerator(int n)
	{
		numerator = n;
	}

	void set_denominator(int d)
	{
		if (d != 0)
			denominator = d;
		else
		{
			cout << "Zero denominator error\n";
			exit(1);
		}
	}

	int get_numerator() { return numerator; }
	int get_denominator() { return denominator; }

	string print()
	{
		return { std::to_string(numerator) + '/' + std::to_string(denominator) };
	}

	// Exercise 14.7.5
	SimpleRational reduce()
	{
		int divisor = gcd(numerator, denominator);
		return SimpleRational(numerator / divisor, denominator / divisor);
	}
};

class Point
{
	double x;
	double y;
public:
	Point(double x, double y) : x(x), y(y) {}
	double get_x() const { return x; }
	double get_y() const { return y; }
	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }

	// Exercise 14.7.7
	double distance(Point p)
	{
		return sqrt((p.get_x() - x) * (p.get_x() - x) + (p.get_y() - y) * (p.get_y() - y));
	}
};

class IntPoint
{
public:
	int x;
	int y;
	IntPoint(int x, int y) : x(x), y(y) {}
	string print()
	{
		return { '(' + std::to_string(x) + ',' + std::to_string(y) + ')' };
	}
};

// Exercise 14.7.1
SimpleRational add(SimpleRational r1, SimpleRational r2)
{
	return SimpleRational(r1.get_numerator() * r2.get_denominator() + r2.get_numerator() * r1.get_denominator(), r1.get_denominator() * r2.get_denominator());
}

// Exercise 14.7.2
double distance(Point r1, Point r2)
{
	return sqrt((r2.get_x() - r1.get_x()) * (r2.get_x() - r1.get_x()) + (r2.get_y() - r1.get_y()) * (r2.get_y() - r1.get_y()));
}

// Exercise 14.7.6
SimpleRational reduce(SimpleRational f)
{
	int divisor = gcd(f.get_numerator(), f.get_denominator());
	return SimpleRational(f.get_numerator() / divisor, f.get_denominator() / divisor);
}

// Exercise 14.7.8
class Rectangle {
	IntPoint corner; // Location of the rectangle's lower-left corner
	int width; // The rectangle's width
	int height; // The rectangle's height
public:
	Rectangle(IntPoint pt, int w, int h) :
		corner((pt.x < -100) ? -100 : (pt.x > 100 ? 100 : pt.x),
			(pt.y < -100) ? -100 : (pt.y > 100 ? 100 : pt.y)),
		width((w < 0) ? 0 : w), height((h < 0) ? 0 : h) {}
	int perimeter() {
		return 2 * width + 2 * height;
	}
	int area() {
		return width * height;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}

	// Returns the length of a diagonal rounded to the nearest integer.
	int diagonal() {
		return static_cast<int>(sqrt(pow(width, 2) + pow(height, 2)));
	}

	// Returns the geometric center of the rectangle with the (x,y) coordinates rounded to the nearest integer.
	IntPoint center() {
		return IntPoint(corner.x + width / 2, corner.y + height / 2);
	}

	// Returns true is point pt is inside this rectangle object.
	bool is_inside(IntPoint pt) {
		if (pt.x >= corner.x && pt.y >= corner.y && pt.x <= corner.x + width && pt.y <= corner.y + height)
			return true;
		return false;
	}

	// Returns true if rectangle r overlaps this rectangle object.
	bool intersect(Rectangle r) {
		return is_inside(r.corner) || r.is_inside(corner);
	}
};

// Exercise 14.7.8.j)
IntPoint corner(Rectangle r)
{
	return IntPoint(r.center().x - r.get_width() / 2, r.center().y - r.get_height() / 2);
}

// Exercise 14.7.9
class Circle
{
	IntPoint center;
	int radius;
public:
	Circle(IntPoint pt, int n) : center(pt), radius(n) {}
	int perimeter() {
		return static_cast<int>(6.28 * radius);
	}
	int area() {
		return static_cast<int>(3.14 * radius * radius);
	}
};

// Exercise 14.7.10
bool encloses(Rectangle r, Circle c)
{
	int circleRadius = 2 * c.area() / c.perimeter();
	int largestRadiusInsideRectangle = 0;
	if (r.get_width() > r.get_height())
		largestRadiusInsideRectangle = r.get_height() / 2;
	else
		largestRadiusInsideRectangle = r.get_width() / 2;
	return largestRadiusInsideRectangle >= circleRadius;
}

int main()
{
	cout << " Exercise 14.7.1\n";
	{
		cout << "See code above main.\n";
		SimpleRational r1(1, 2);
		SimpleRational r2(2, 3);
		SimpleRational r3(1, 4);
		cout << "Test result for add on " << r1.print() << " and " << r2.print() << " is: " << add(r1, r2).print() << '\n';
		cout << "Test result for add on " << r1.print() << " and " << r3.print() << " is: " << add(r1, r3).print() << '\n';
		cout << "Test result for add on " << r2.print() << " and " << r3.print() << " is: " << add(r2, r3).print() << '\n';
	}
	cout << '\n';

	cout << " Exercise 14.7.2\n";
	{
		cout << "See code above main.\n";
		Point r1(1, 2);
		Point r2(2, 3);
		Point r3(1, 4);
		cout << "Test result for distance on (1, 2) and (2, 3) is: " << distance(r1, r2) << '\n';
		cout << "Test result for distance on (1, 2) and (1, 4) is: " << distance(r1, r3) << '\n';
		cout << "Test result for distance on (2, 3) and (1, 4) is: " << distance(r2, r3) << '\n';
	}
	cout << '\n';

	cout << " Exercise 14.7.5\n";
	{
		cout << "See code above main.\n";
		SimpleRational r1(2, 4);
		SimpleRational r2(3, 18);
		SimpleRational r3(6, 10);
		cout << "Test result for reduce on " << r1.print() << " is: " << r1.reduce().print() << '\n';
		cout << "Test result for reduce on " << r2.print() << " is: " << r2.reduce().print() << '\n';
		cout << "Test result for reduce on " << r3.print() << " is: " << r3.reduce().print() << '\n';
	}
	cout << '\n';

	cout << " Exercise 14.7.6\n";
	{
		cout << "See code above main.\n";
		SimpleRational r1(2, 4);
		SimpleRational r2(3, 18);
		SimpleRational r3(6, 10);
		cout << "Test result for reduce on " << r1.print() << " is: " << reduce(r1).print() << '\n';
		cout << "Test result for reduce on " << r2.print() << " is: " << reduce(r2).print() << '\n';
		cout << "Test result for reduce on " << r3.print() << " is: " << reduce(r3).print() << '\n';
	}
	cout << '\n';

	cout << " Exercise 14.7.7\n";
	{
		cout << "See code above main.\n";
		Point r1(1, 2);
		Point r2(2, 3);
		Point r3(1, 4);
		cout << "Test result for (1, 2).distance(2, 3) is: " << r1.distance(r2) << '\n';
		cout << "Test result for (1, 2).distance(1, 4) is: " << r1.distance(r3) << '\n';
		cout << "Test result for (2, 3).distance(1, 4) is: " << r2.distance(r3) << '\n';
	}
	cout << '\n';

	cout << " Exercise 14.7.8\n";
	{
		Rectangle rect1(IntPoint(2, 3), 5, 7);
		Rectangle rect2(IntPoint(2, 3), 1, 3);
		Rectangle rect3(IntPoint(2, 3), 15, 3);
		Rectangle rect4(IntPoint(2, 3), 5, 3);
		cout << "Width rect1: " << rect1.get_width() << '\n';
		cout << "Height rect1: " << rect1.get_height() << '\n';
		cout << "Perimeter rect1: " << rect1.perimeter() << '\n';
		cout << "Area rect1: " << rect1.area() << '\n';
		cout << "Diagonal rect1: " << rect1.diagonal() << '\n';
		cout << "Center rect1: " << rect1.center().print() << '\n';
		cout << "Position of lower-left corner of rect1: " << corner(rect1).print() << '\n';
		cout << '\n';
		cout << "Width rect2: " << rect2.get_width() << '\n';
		cout << "Height rect2: " << rect2.get_height() << '\n';
		cout << "Perimeter rect2: " << rect2.perimeter() << '\n';
		cout << "Area rect2: " << rect2.area() << '\n';
		cout << "Diagonal rect2: " << rect2.diagonal() << '\n';
		cout << "Center rect2: " << rect2.center().print() << '\n';
		cout << "Position of lower-left corner of rect2: " << corner(rect2).print() << '\n';
		cout << '\n';
		cout << "Width rect3: " << rect3.get_width() << '\n';
		cout << "Height rect3: " << rect3.get_height() << '\n';
		cout << "Perimeter rect3: " << rect3.perimeter() << '\n';
		cout << "Area rect3: " << rect3.area() << '\n';
		cout << "Diagonal rect3: " << rect3.diagonal() << '\n';
		cout << "Center rect3: " << rect3.center().print() << '\n';
		cout << "Position of lower-left corner of rect3: " << corner(rect3).print() << '\n';
		cout << '\n';
		cout << "Width rect4: " << rect4.get_width() << '\n';
		cout << "Height rect4: " << rect4.get_height() << '\n';
		cout << "Perimeter rect4: " << rect4.perimeter() << '\n';
		cout << "Area rect4: " << rect4.area() << '\n';
		cout << "Diagonal rect4: " << rect4.diagonal() << '\n';
		cout << "Center rect4: " << rect4.center().print() << '\n';
		cout << "Position of lower-left corner of rect4: " << corner(rect4).print() << '\n';
		cout << '\n';

		IntPoint p1(2, 3);
		IntPoint p2(1, 1);
		cout << "Is " << p1.print() << " in rect1: " << rect1.is_inside(p1) << '\n';
		cout << "Is " << p2.print() << " in rect1: " << rect1.is_inside(p2) << '\n';

		Rectangle rect5(IntPoint(3, 4), 3, 4);
		Rectangle rect6(IntPoint(1, 1), 1, 1);
		cout << "Do rect1 and rect5 intersect: " << rect1.intersect(rect5) << '\n';
		cout << "Do rect1 and rect6 intersect: " << rect1.intersect(rect6) << '\n';
		cout << "Do rect2 and rect6 intersect: " << rect2.intersect(rect6) << '\n';
	}
	cout << '\n';

	cout << " Exercise 14.7.9\n";
	{
		cout << "See code above main.\n";
		Circle c1(IntPoint(1, 2), 2);
		Circle c2(IntPoint(3, 3), 3);
		Circle c3(IntPoint(0, 0), 10);
		cout << "Area of c1 is: " << c1.area() << '\n';
		cout << "Perimeter of c1 is: " << c1.perimeter() << '\n';
		cout << "Area of c2 is: " << c2.area() << '\n';
		cout << "Perimeter of c2 is: " << c2.perimeter() << '\n';
		cout << "Area of c3 is: " << c3.area() << '\n';
		cout << "Perimeter of c3 is: " << c3.perimeter() << '\n';
	}
	cout << '\n';

	cout << " Exercise 14.7.10\n";
	{
		cout << "See code above main.\n";
		Circle c1(IntPoint(5, 6), 2);
		cout << "Area of c1 is: " << c1.area() << '\n';
		Circle c2(IntPoint(1, 2), 5);
		cout << "Area of c2 is: " << c2.area() << '\n';
		Rectangle r1(IntPoint(2, 3), 5, 7);
		cout << "Area of r1 is: " << r1.area() << '\n';
		cout << "Does c1 fit in r1: " << encloses(r1, c1) << '\n';
		cout << "Does c2 fit in r1: " << encloses(r1, c2) << '\n';
	}
	cout << '\n';

	return 0;
}