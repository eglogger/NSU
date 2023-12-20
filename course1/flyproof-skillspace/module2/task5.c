#include <stdio.h>
#include <math.h>

float dist(float x1, float y1, float x2, float y2) {                      // Counting the distance between two points according to the formula of the distance between two points.
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

float triangS(float a, float b, float c) {                                // Counting the square of a triangle according to Heron 's formula.
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

float polyS(float x[], float y[], int n) {                                // Counting the square of a polygon
    float totalS = 0;
    float a, b, c, tempS;

    for (int i = 0; i < n - 2; i++) {                                     // n - Number of vertices.
        a = dist(x[i], y[i], x[i+1], y[i+1]);
        b = dist(x[i+1], y[i+1], x[i+2], y[i+2]);
        c = dist(x[i+2], y[i+2], x[i], y[i]);
        tempS = triangS(a, b, c);
        totalS += tempS;
    }

    return totalS;
}

int main() {

    int n;

    scanf("%d", &n);

    float x[n], y[n];

    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i+1);
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("%f\n", polyS(x, y, n));

    return 0;
}