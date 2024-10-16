#include <stdio.h>
#include <math.h>
#include <time.h>

// Function to evaluate the curve (y = f(x))
float f(float x) {
    return x * x; // Example: y = x^2
}

// Function to compute the area of a trapezoid
float trapezoid_area(float a, float b, float d) {
    float area = 0;
    for (float x = a; x < b; x += d) {
        area += f(x) + f(x + d);
    }
    return area * d / 2.0f;
}

int main() {
    float a = 0.0f, b = 1.0f;  // Limits of integration
    int n;
    float total_area;
    clock_t start, end;

    // Get the number of intervals from the user
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    // Start timing
    start = clock();

    // Calculate the interval size
    float d = (b - a) / n; // delta

    // Calculate the total area (sequentially)
    total_area = trapezoid_area(a, b, d);

    // End timing
    end = clock();

    // Print the result and execution time
    printf("The total area under the curve is: %f\n", total_area);
    printf("Execution time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
