#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

int main()
{
 /* ?\n;||(or) e &&(and)*/

 int n = 0;
 std::cin >> n;

 long long r = 0;
 if (n % 2 == 0)
 {
  r = pow(n, 2);
 }
 else
 {
  r = pow(n - 1, 2) + ((2 * n) - 1);
 }

 std::cout << r << std::endl;

 return 0;
}
