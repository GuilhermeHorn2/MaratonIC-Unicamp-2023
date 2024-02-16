#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <queue>

int potato(std::vector<int> &b, int B, int t, int idx);
int potato(std::vector<int> &b, int B, int t);
int main()
{
 /* ?_n;||(or) e &&(and)*/

 /*std::vector<int> b = {1};
 std::cout << potato(b, 10, 9);*/

 /*std::vector<int> b = {1, 1};
 std::cout << potato(b, 3, 1000);*/

 /*std::vector<int> b = {1, 1};
 std::cout << potato(b, 3, 0);*/

 /*std::vector<int> b = {1, 2, 3};
 std::cout << potato(b, 10, 100);*/

 std::vector<int> b = {1, 2, 3};
 std::cout << potato(b, 1000000000, 1000000000);

 return 0;
}

int potato(std::vector<int> &b, int B, int t)
{
 /*std::vector<std::vector<int>> memo;
 for (long long i = 0; i < 100000; i++)
 {
  std::vector<int> tmp;
  memo.push_back(tmp);
  for (int j = 0; j < 100; j++)
  {
   memo[i].push_back(-2);
  }
 }*/
 return potato(b, B, t, b.size() - 1);
}

int potato(std::vector<int> &b, int B, int t, int idx)
{
 if (B == 0)
 {
  // std::cout << "----" << (char)10;
  return 1;
 }
 if (idx < 0)
 {
  return 0;
 }
 if (b[idx] == 0)
 {
  // q pora
  return 0;
 }
 /*if (memo[B][idx] != -2)
 {
  return memo[B][idx];
 }*/

 int n = B / b[idx];
 // restriction
 if (idx == 0 && n > t)
 {
  n = t;
 }
 //
 int c = 0;
 for (int i = 0; i <= n; i++)
 {
  int tmp = potato(b, B - (b[idx] * i), t, idx - 1);
  if (tmp > 0)
  {
   c += tmp;
  }
 }
 // memo[B][idx] = c;
 return c;
}
