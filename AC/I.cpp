#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

struct Quadtree {
    int xMin, xMax, yMin, yMax;
    vector<Point> points;
    bool split = false;
    Quadtree *nw = nullptr, *ne = nullptr, *sw = nullptr, *se = nullptr;
};

bool insert(Quadtree *qt, Point p) {
    if (p.x < qt->xMin || p.x > qt->xMax || p.y < qt->yMin || p.y > qt->yMax) 
        return false;

    if (qt->points.size() < 1 && !qt->split) {
        qt->points.push_back(p);
        return true;
    }

    if (!qt->split) {
        int xMid = (qt->xMin + qt->xMax) / 2;
        int yMid = (qt->yMin + qt->yMax) / 2;

        qt->nw = new Quadtree{qt->xMin, xMid, yMid + 1, qt->yMax};
        qt->ne = new Quadtree{xMid + 1, qt->xMax, yMid + 1, qt->yMax};
        qt->sw = new Quadtree{qt->xMin, xMid, qt->yMin, yMid};
        qt->se = new Quadtree{xMid + 1, qt->xMax, qt->yMin, yMid};

        qt->split = true;
        
        for (Point old : qt->points){
            if (!insert(qt->nw, old))
            if (!insert(qt->ne, old))
            if (!insert(qt->sw, old))
            insert(qt->se, old);
        }
            
        qt->points.clear();
    }

    return insert(qt->nw, p) || insert(qt->ne, p) || insert(qt->sw, p) || insert(qt->se, p);
}

int count(Quadtree *qt) {
    if (!qt->split) return 1;
    return count(qt->nw) + count(qt->ne) + count(qt->sw) + count(qt->se);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);

    for (int i = 0; i < n; ++i){
        cin >> points[i].x >> points[i].y;
    }

    Quadtree *qt = new Quadtree{-100, 100, -100, 100};

    for (Point p : points){
        insert(qt, p);
    }

    cout << count(qt) << endl;

    return 0;
}
