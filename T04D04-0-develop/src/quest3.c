#include <stdio.h>
int Fib(int n) {
  if ((n == 1) || (n == 2))
    return 1;
  else
    return Fib(n - 1) + Fib(n - 2);
}
int main() {
  int n;
  if ((scanf("%d", &n) != 1) || (n <= 0))
    printf("n/a");
  else
    printf("%d", Fib(n));

  return 0;
}
