
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate psi(x) for the given parameters
double psi(int n, double a, double x) {
    return sqrt(2.0 / a) * sin(n * PI * x / a);
}

int main() {
    int n = 5;
    double a = 10.0;

    FILE *dataFile = fopen("output.dat", "w");
    if (dataFile == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }

    fprintf(dataFile, "# x  |psi(x)|^2\n");

    for (double x = -10.0; x <= a; x += 0.1) {
        double psi_value = psi(n, a, x);
        double psi_squared = psi_value * psi_value;
        fprintf(dataFile, "%lf %lf\n", x, psi_squared);
    }

    fclose(dataFile);

    // Use gnuplot to plot the data
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        fprintf(stderr, "Error opening pipe to gnuplot.\n");
        return 1;
    }

    fprintf(gnuplotPipe, "set xlabel 'x'\n");
    fprintf(gnuplotPipe, "set ylabel '|\\psi(x)|^2'\n");  // Use LaTeX syntax
    fprintf(gnuplotPipe, "set title 'Probability Density |\\psi(x)|^2 vs. x'\n");
    fprintf(gnuplotPipe, "plot 'output.dat' with lines title '|\\psi(x)|^2'\n");

    fclose(gnuplotPipe);

    return 0;
}