#include <stdio.h>

#define MATRIX_HEIGHT 2
#define MATRIX_WIDTH 5

int main(void)
{
    double matrix[MATRIX_HEIGHT][MATRIX_WIDTH] = {
        { 2, 3, 1, 1, -1 },
        { 1, 1, 4, 1, 3 },
    };
    int pivot_x = 0; // For non-square matrix.
    for (int pivot_y = 0; pivot_y < MATRIX_HEIGHT; pivot_y++) {
        // Divide each coefficients of a line by the coefficients of leftmost column.
        double divisor = 0;
        while (!divisor) {
            // Avoid dividing by 0.
            divisor = matrix[pivot_y][pivot_x];
            if (divisor == 0) {
                pivot_x++;
            }
        }
        for (int xi = pivot_x; xi < MATRIX_WIDTH; xi++) {
            matrix[pivot_y][xi] /= divisor;
        }
        // Subtract each lines from topmost line.
        for (int yi = 0; yi < MATRIX_HEIGHT; yi++) {
            if (pivot_y != yi) {
                double multiplier = matrix[yi][pivot_x];
                for (int xi = pivot_x; xi < MATRIX_WIDTH; xi++) {
                    matrix[yi][xi] -= multiplier * matrix[pivot_y][xi];
                }
            }
        }
        // Switch to the next column.
        pivot_x++;
        // Print the reduced matrix.
        for (int yi = 0; yi < MATRIX_HEIGHT; yi++) {
            for (int xi = 0; xi < MATRIX_WIDTH; xi++) {
                printf("%5.1lf ", matrix[yi][xi]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    // Print the reduced matrix.
    for (int yi = 0; yi < MATRIX_HEIGHT; yi++) {
        for (int xi = 0; xi < MATRIX_WIDTH; xi++) {
            printf("%5.1lf ", matrix[yi][xi]);
        }
        putchar('\n');
    }
    return 0;
}
