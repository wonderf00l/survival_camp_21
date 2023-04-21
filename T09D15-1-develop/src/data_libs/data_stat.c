#include "data_stat.h"

double max(const double *data, int n) {
    double max = data[0];
    for (int i = 0; i != n; ++i) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

double min(const double *data, int n) {
    double min = data[0];
    for (int i = 0; i != n; ++i) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

double mean(const double *a, int n) { return (min(a, n) + max(a, n)) / 2; }

double variance(const double *a, int n) {
    double sq_sum = 0;
    double mean_ = mean(a, n);
    for (int i = 0; i != n; ++i) {
        sq_sum += (a[i] - mean_) * (a[i] - mean_);
    }
    return sq_sum / n;
}