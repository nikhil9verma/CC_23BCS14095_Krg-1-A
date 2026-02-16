#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;

    bool operator<(const Point &other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

// Cross product of OA x OB
long long cross(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - 
           (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> &points) {
    int n = points.size();
    if (n <= 1) return points;

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    vector<Point> lower, upper;

    // Lower hull
    for (auto &p : points) {
        while (lower.size() >= 2 &&
               cross(lower[lower.size()-2],
                     lower[lower.size()-1],
                     p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    // Upper hull
    for (int i = points.size() - 1; i >= 0; i--) {
        while (upper.size() >= 2 &&
               cross(upper[upper.size()-2],
                     upper[upper.size()-1],
                     points[i]) <= 0) {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }

    // Remove last element of each (duplicate endpoints)
    lower.pop_back();
    upper.pop_back();

    // Combine
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    cout << hull.size() << "\n";
    for (auto &p : hull) {
        cout << p.x << " " << p.y << "\n";
    }

    return 0;
}
