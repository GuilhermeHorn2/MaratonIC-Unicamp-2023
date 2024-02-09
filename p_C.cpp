#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

std::vector<int> prep_vec(std::vector<int> &v);

int find_max_idx(std::vector<int> &s, std::vector<int> &v, int k);

int find_min_idx(std::vector<int> &s, std::vector<int> &v, int k);

void print_vec(std::vector<int> &v);

int main()
{
 /* ?\n;||(or) e &&(and)*/

 /*std::vector<int> v = {1000, 1, 2, 3, 4, 100};
 int k = 4;

 std::vector<int> s = prep_vec(v);
 int min = find_min_idx(s, v, k);
 int max = find_max_idx(s, v, k);
 std::cout << min + 1 << ' ' << max + 1;*/

 int n = 0;
 int k = 0;

 std::cin >> n >> k;
 std::vector<int> v;

 for (int i = 0; i < n; i++)
 {
  int tmp = 0;
  std::cin >> tmp;
  v.push_back(tmp);
 }
 std::vector<int> s = prep_vec(v);
 int min = find_min_idx(s, v, k);
 int max = find_max_idx(s, v, k);
 std::cout << min + 1 << ' ' << max + 1;

 return 0;
}

std::vector<int> prep_vec(std::vector<int> &v)
{
 std::vector<int> s;
 for (int i = 0; i < v.size(); i++)
 {
  s.push_back(0);
 }

 s[0] = v[0];
 for (int i = 1; i < v.size(); i++)
 {
  s[i] = s[i - 1] + v[i];
 }
 return s;
}

void print_vec(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i] << ' ';
 }
 std::cout << (char)10;
}

int find_min_idx(std::vector<int> &s, std::vector<int> &v, int k)
{
 int val = -1;
 int idx = 0;
 for (int i = 0; i <= s.size() - k; i++)
 {
  int tmp = s[i + k - 1] - s[i] + v[i];
  if (val == -1)
  {
   val = tmp;
  }
  else
  {
   if (tmp < val)
   {
    val = tmp;
    idx = i;
   }
  }
 }
 return idx;
}

int find_max_idx(std::vector<int> &s, std::vector<int> &v, int k)
{
 int val = -1;
 int idx = 0;
 for (int i = 0; i <= s.size() - k; i++)
 {
  int tmp = s[i + k - 1] - s[i] + v[i];
  if (val == -1)
  {
   val = tmp;
  }
  else
  {
   if (tmp > val)
   {
    val = tmp;
    idx = i;
   }
  }
 }
 return idx;
}
