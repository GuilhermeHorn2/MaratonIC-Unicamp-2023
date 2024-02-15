#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <queue>

int sky_wars(std::vector<std::vector<char>> &sky, int x, int y);

int main()
{
 /* ?_n;||(or) e &&(and)*/

 /*std::vector<char> a = {'T', '#', '.', '*'};
 std::vector<char> b = {'.', '.', '#', '.'};
 std::vector<char> c = {'#', '.', '.', '#'};
 std::vector<char> d = {'#', '#', '.', '*'};

 std::vector<std::vector<char>> sky = {a, b, c, d};

 std::cout << sky_wars(sky, 0, 0);*/

 int n = 0;
 int m = 0;
 std::cin >> n >> m;
 int x = 0;
 int y = 0;
 std::vector<std::vector<char>> sky;
 for (int i = 0; i < n; i++)
 {
  std::vector<char> tmp;
  sky.push_back(tmp);
  for (int j = 0; j < m; j++)
  {
   char r = ' ';
   std::cin >> r;
   sky[i].push_back(r);
   if (r == 'T')
   {
    x = i;
    y = j;
   }
  }
 }

 std::cout << sky_wars(sky, x, y);

 return 0;
}

int sky_wars(std::vector<std::vector<char>> &sky, int x, int y)
{

 std::vector<std::vector<int>> blocks;
 for (int i = 0; i < sky.size(); i++)
 {
  std::vector<int> tmp;
  blocks.push_back(tmp);
  for (int j = 0; j < sky[0].size(); j++)
  {
   blocks[i].push_back(0);
  }
 }

 std::queue<int> q_x;
 std::queue<int> q_y;
 q_x.push(x);
 q_y.push(y);
 bool found2 = false;

 while (!q_x.empty())
 {
  int a = q_x.front();
  int b = q_y.front();
  q_x.pop();
  q_y.pop();

  if (sky[a][b] == '*')
  {
   if (!found2)
   {
    found2 = true;
   }
   else
   {
    return blocks[a][b];
   }
  }

  std::vector<int> d_i = {1, -1, 0, 0};
  std::vector<int> d_j = {0, 0, 1, -1};

  for (int q = 0; q < 4; q++)
  {
   int i = a + d_i[q];
   int j = b + d_j[q];

   if (i >= 0 && i < sky.size())
   {
    if (j >= 0 && j < sky[0].size())
    {

     if (sky[i][j] != '1')
     {
      //
      if (sky[i][j] == '*')
      {
       if (found2)
       {
        return blocks[a][b];
       }
       blocks[i][j] = blocks[a][b];
       found2 = true;
      }
      else if (sky[i][j] == '.')
      {
       blocks[i][j] = blocks[a][b] + 1;
      }
      else
      {
       blocks[i][j] = blocks[a][b];
      }
      //
      sky[i][j] = '1';
      q_x.push(i);
      q_y.push(j);
     }
     //
    }
   }
  }
 }
 return -1;
}
