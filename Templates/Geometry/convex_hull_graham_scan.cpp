/*
- Graham Scan Algorithm
- Reference: https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html

Note use of the isCW, isACW is crucial 
isCW   => True for points which are strictly clockwise.
!isACW => True for points which are clockwise and lie on the line.

Note: 
	- Current Convex Hull Code outputs all the points which lies on a convex hull boundary line.
	- If we want to output just end points of all convex hull's boundary line.
		Then replace isACW() to !isCW  and isCW() to !isACW() in while loop of upper and lower part respectively


*/

struct Point
{
	double x;
	double y;
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};
class ConvexHull {
	int n; 
	vector<Point> points;
	vector<Point> convexHull;
public:
	ConvexHull(vector<Point> &points){
		this->n = points.size();
		this->points = points;
        generateConvexHull();
	}

	bool isCW(Point a, Point b, Point c){ //compares orientation of line bc wrt line ab, 
		// bc is Clock wise w.r.t ab, iff slope(bc) < slope(ab)
		return (c.y - b.y)*(b.x - a.x) < (c.x - b.x)*(b.y - a.y);
	}
	bool isACW(Point a, Point b, Point c){ //compares orientation of line bc wrt line ab, 
		// bc is Anti Clock Wise w.r.t ab, iff slope(bc) > slope(ab)
		return (c.y - b.y)*(b.x - a.x) > (c.x - b.x)*(b.y - a.y);
	}
	void generateConvexHull(){
        if(points.size()==1) {
            convexHull.push_back(points[0]);
            return;
        }
        sort(points.begin(), points.end(),[](const Point &p1, const Point &p2){
			if(p1.x==p2.x) return p1.y < p2.y;
			return p1.x < p2.x;
		});	

		Point p1 = points[0], p2 = points.back();
		vector<Point> up = {p1} , down = {p1};
		for(int i=1; i<n; ++i){
			if(i==n-1 || isCW(p1, points[i], p2)){ //point belongs to upper half
				while(up.size()>=2 && isACW(up[up.size()-2], up[up.size()-1], points[i])) 
					up.pop_back(); 
				up.push_back(points[i]);

			}
			if(i==n-1 || !isCW(p1, points[i], p2)){ //point belongs to lower half or on the line p1p2
				while(down.size()>=2 && isCW(down[down.size()-2], down[down.size()-1], points[i]))
					down.pop_back();
				down.push_back(points[i]);
			}
		}

		//storing in clockwise fashion
		convexHull.clear();
		for(int i=0; i<up.size(); ++i) 		{convexHull.push_back(up[i]);}
		for(int i=down.size()-2; i>0; --i) {convexHull.push_back(down[i]);}
		return;
	}
    
    vector<Point> getConvexHull(){
        return convexHull;
    }
};