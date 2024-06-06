#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x;
    int y;
};
int compare(const void *a, const void *b) {
    struct Point *pointA = (struct Point *)a;
    struct Point *pointB = (struct Point *)b;
    int distA = pointA->x * pointA->x + pointA->y * pointA->y;
    int distB = pointB->x * pointB->x + pointB->y * pointB->y;
    return distA - distB;
}
struct Point* kClosest(struct Point* points, int pointsSize, int k) {
    qsort(points, pointsSize, sizeof(struct Point), compare);
    return points;
}
int main() {
    struct Point points[] = {{1, 3}, {-2, 2}};
    int k = 1;
    int pointsSize = sizeof(points) / sizeof(points[0]);
    struct Point* closestPoints = kClosest(points, pointsSize, k);
    for (int i = 0; i < k; i++) {
        printf("[%d, %d] ", closestPoints[i].x, closestPoints[i].y);
    }
    return 0;
