#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct {
	double x;
	double y;
} point_t;

typedef point_t* point_ptr_t;

double ccw(point_t p1, point_t p2, point_t p3)
{
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
	/*	double m;
	if (p1.x == p2.x)
	{
	if (p2.y > p1.y)
	{
	if (p3.x >= p2.x)
	return 1;
	else if (p3.x == p2.x)
	return 0;
	else
	return -1;
	}
	else
	{
	if (p3.x < p2.x)
	return 1;
	else if (p3.x == p2.x)
	return 0;
	else
	return -1;
	}

	}
	m = (p2.y - p1.y) / (p2.x - p1.x);
	if (m > 0)
	{

	}*/


}

/* Returns a list of points on the convex hull in counter-clockwise order.
* Note: the last point in the returned list is the same as the first one.
*/
//void convex_hull(point_t* points, int npoints, point_ptr_t** out_hull, int* out_hullsize)
//{
//	point_ptr_t* hull;
//	int i, t, k = 0;
//
//	hull = *out_hull;
//
//	/* lower hull */
//	for (i = 0; i < npoints; ++i) {
//		while (k >= 2 && ccw(hull[k - 2], hull[k - 1], &points[i]) <= 0) --k;
//		hull[k++] = &points[i];
//	}
//
//	/* upper hull */
//	for (i = npoints - 2, t = k + 1; i >= 0; --i) {
//		while (k >= t && ccw(hull[k - 2], hull[k - 1], &points[i]) <= 0) --k;
//		hull[k++] = &points[i];
//	}
//
//	*out_hull = hull;
//	*out_hullsize = k;
//}

void slow_convex_hull(point_t* points, int npoints)
{
	point_ptr_t* hull;
	int i, t, k = 0;
	int *edges;
	edges = (int*)malloc(2 * npoints*(sizeof(int)));
	int**  valid_points;
	valid_points = (int**)malloc(npoints*sizeof(int*));
	for (int i = 0;i < npoints;i++)
	{
		valid_points[i] = (int*)malloc(sizeof(int));
	}
	for (int i = 0;i < npoints;i++)
	{
		for (int j = 0;j < npoints;j++)
		{
			valid_points[i][j] = 1;
		}
	}
	int m = 0;
	for (int i = 0;i < npoints;i++)
		for (int j = 0;j < npoints;j++)
		{
			for (int k = 0;k < npoints;k++)
			{
				if (i != j && k != i && k != j)
					if (ccw(points[i], points[j], points[k])>0)
					{
						valid_points[i][j] = 0;
					}
			}
			if (i != j && valid_points[i][j] == 1)
			{
				edges[m] = i;
				edges[m + 1] = j;
				m += 2;
			}
		}

	for (int h = 0;h < m;h++)
		printf("-%d", edges[h]);
}


int main()
{
	point_t p1, p2, p3, p4;
	p1.x = 1;
	p1.y = 1;
	p2.x = 3;
	p2.y = 3;
	p3.x = 5;
	p3.y = 1;
	p4.x = 3;
	p4.y = 0;

	point_t pts[4];
	pts[0] = p1;
	pts[1] = p2;
	pts[2] = p3;
	pts[3] = p4;

	slow_convex_hull(pts, 4);
	//printf("%lf\n", cw(p1, p2, p3));
}