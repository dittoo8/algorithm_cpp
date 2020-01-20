#include <iostream>
#include <string>
#include <queue>
#include <cstring> //memset
#include <utility>
using namespace std;
 
const int MAX = 30;
 
typedef struct
{
        int z, y, x;
}Dir;
 
Dir moveDir[6] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
 
int L, R, C;
pair<pair<int, int >, int > start, finish;
int cube[MAX][MAX][MAX];
 
int BFS(pair<pair<int, int >, int > start)
{
        queue < pair<pair<int, int>, pair<int, int> > > q; //z, y, x, cnt
        bool visited[MAX][MAX][MAX];
        q.push( make_pair(make_pair(start.first.first, start.first.second), make_pair(start.second, 0 )));
        memset(visited, false, sizeof(visited));
        visited[start.first.first][start.first.second][start.second] = true;
 
        while (!q.empty())
        {
                 int z = q.front().first.first;
                 int y = q.front().first.second;
                 int x = q.front().second.first;
                 int cnt = q.front().second.second;
                 q.pop();
 
                 //도착했을 경우
                 if (z == finish.first.first && y == finish.first.second && x == finish.second)
                         return cnt;
 
                 for (int i = 0; i < 6; i++)
                 {
                         int nextZ = z + moveDir[i].z;
                         int nextY = y + moveDir[i].y;
                         int nextX = x + moveDir[i].x;
 
                         //범위 내에 있고 방문하지 않았으며 벽이 아닌 공간일 떄만 큐에 넣는다
                         if (0 <= nextZ && nextZ < L && 0 <= nextY && nextY < R && 0 <= nextX && nextX < C)
                                 if (visited[nextZ][nextY][nextX] == false && cube[nextZ][nextY][nextX] == 0)
                                 {
                                          visited[nextZ][nextY][nextX] = true;
                                          q.push(make_pair(make_pair(nextZ, nextY), make_pair(nextX, cnt + 1)));
                                 }
                 }
        }
        return -1; //도착하지 못할 경우
}
 
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 속도 향상
 
        while (1)
        {
                 memset(cube, 0, sizeof(cube));
                 cin >> L >> R >> C;
                 if (!L && !R && !C)
                         break;
 
                 //맵 정보 입력
                 for(int z=0; z<L; z++)
                         for (int y = 0; y < R; y++)
                         {
                                 string temp;
                                 cin >> temp;
 
                                 for (int i = 0; i < temp.length(); i++)
                                          if (temp[i] == 'S') //시작점
                                          {
                                                  start.first.first = z;
                                                  start.first.second = y;
                                                  start.second = i;
                                          }
                                          else if (temp[i] == '#') //벽
                                                  cube[z][y][i] = 1;
                                          else if (temp[i] == 'E') //도착점
                                          {
                                                  finish.first.first = z;
                                                  finish.first.second = y;
                                                  finish.second = i;
                                          }
                         }
 
                 int result = BFS(start);
                 if (result == -1)
                         cout << "Trapped!" << "\n";
                 else
                         cout << "Escaped in " << result << " minute(s).\n";
        }
        return 0;
}