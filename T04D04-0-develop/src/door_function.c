#include <math.h>
#include <stdio.h>
int main() {
  FILE *file;
  file = fopen("door_data.txt", "wt");
  double del = (M_PI * 2) / 41.0;
  for (int i = 1; i <= 42; ++i) {
    if ((-M_PI + del * (i - 1) >= 1.412) || (-M_PI + del * (i - 1) <= -1.412))
      fprintf(file, "%.7f|%.7f|-|%.7f\n", (-M_PI + del * (i - 1)),
              (pow(1, 3) / (pow(1, 2) + pow(-M_PI + del * (i - 1), 2))),
              (1 / pow(-M_PI + del * (i - 1), 2)));
    else if (-M_PI + del * (i - 1) == 0)
      fprintf(file, "%.7f|%.7f|%.7f|-\n", (-M_PI + del * (i - 1)),
              (pow(1, 3) / (pow(1, 2) + pow(-M_PI + del * (i - 1), 2))),
              (sqrt(sqrt(1 + 4 * pow(-M_PI + del * (i - 1), 2)) -
                    pow(-M_PI + del * (i - 1), 2) - 1)));
    else
      fprintf(file, "%.7f|%.7f|%.7f|%.7f\n", (-M_PI + del * (i - 1)),
              (pow(1, 3) / (pow(1, 2) + pow(-M_PI + del * (i - 1), 2))),
              (sqrt(sqrt(1 + 4 * pow(-M_PI + del * (i - 1), 2)) -
                    pow(-M_PI + del * (i - 1), 2) - 1)),
              (1 / pow(-M_PI + del * (i - 1), 2)));
  }
  fclose(file);
}
