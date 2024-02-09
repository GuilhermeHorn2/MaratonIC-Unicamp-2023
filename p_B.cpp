#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

int main()
{
 /* ?\n;||(or) e &&(and)*/

 int a = 0;
 int b = 0;
 int c = 0;
 int d = 0;
 std::cin >> a >> b >> c >> d;
 if (a > b)
 {
  std::cout << 0;
 }
 if (c > a && d > a)
 {
  std::cout << -1;
 }
 if (c == a && d > a)
 {
  std::cout << -1;
 }
 else
 {
  int r = (c - a) / (b - d);
  std::cout << r + 1;
 }

 return 0;
}
