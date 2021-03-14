#include <iostream> // cout
#include <cmath>    // sqrt

using namespace std;

struct Point {
    double x;
    double y;
};

void swap(Point& a, Point& b) {
	Point tmp = a;
	a = b;
	b = tmp;
}

// Подаваме аргументите по константна референция, защото 
// (константна) - функцията няма смисъл да променя подадените аргументи
// (референция) - добра практика е да не се правят излишни копия
double dist(const Point& a, const Point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point add(const Point& a, const Point& b) {
	Point result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;

	return result;
}

void printPoint(const Point& p) {
    cout << "p.x = " << p.x << ", p.y = " << p.y << '\n';
}


int main()
{
	Point a;
	a.x = 5;
	a.y = 7;
	Point p = add(a, a);
	
    printPoint(p);
    
    cout << "Dist: " << dist(p, a);

    return 0;
}
