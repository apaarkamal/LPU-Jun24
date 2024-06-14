#include<bits/stdc++.h>
using namespace std;

struct Point {
	double x, y;
	void print() {
		cout << "Point x-> " << x << " | Point y-> " << y << '\n';
	}
};

Point mid1(Point first, Point second) {
	Point res;
	res.x = (second.x + 2 * first.x) / 3;
	res.y = (second.y + 2 * first.y) / 3;
	return res;
}

Point mid2(Point first, Point second) {
	Point res;
	res.x = (first.x + 2 * second.x) / 3;
	res.y = (first.y + 2 * second.y) / 3;
	return res;
}

double distance(Point first, Point second) {
	double dis;
	dis = ((first.x - second.x) * (first.x - second.x))
	      + ((first.y - second.y) * (first.y - second.y));
	return sqrt(dis);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		Point p[4];
		for (int i = 0; i < 4; i++) {
			cin >> p[i].x >> p[i].y;
		}

		// Ax, Ay, Bx, By, Cx, Cy, Dx, Dy.
		// A -> p[0]
		// B -> p[1]
		// C -> p[2]
		// D -> p[3]

		while (abs(distance(p[0], p[2]) - distance(p[1], p[3]))
		        > 1e-8) {
			Point mid1ab = mid1(p[0], p[1]);
			Point mid1cd = mid1(p[2], p[3]);
			Point mid2ab = mid2(p[0], p[1]);
			Point mid2cd = mid2(p[2], p[3]);

			// mid1ab.print();
			// mid1cd.print();
			// mid2ab.print();
			// mid2cd.print();

			if (distance(mid1ab, mid1cd) < distance(mid2ab, mid2cd)) {
				// p1 -> midab2
				p[1].x = mid2ab.x;
				p[1].y = mid2ab.y;

				// p3 -> mid2cd
				p[3].x = mid2cd.x;
				p[3].y = mid2cd.y;
			}
			else {
				// p[0] -> mid1ab
				p[0].x = mid1ab.x;
				p[0].y = mid1ab.y;

				// p[2] -> mid1cd
				p[2].x = mid1cd.x;
				p[2].y = mid1cd.y;
			}
			// p[0].print();
			// p[1].print();
			// p[2].print();
			// p[3].print();
			// break;

		}

		// 1.4142135624

		cout << setprecision(7) << fixed;

		cout << distance(p[0], p[2]) << '\n';

	}

}