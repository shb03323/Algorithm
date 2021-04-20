#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int m, n;
int cnt;
int cnt_ing = 0;
int day;
int tomato;
int maps[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue <pair <pair<int, int>, int>> q;

int bfs(){
  while(!q.empty()){
    int x = q.front().first.first;
    int y = q.front().first.second;
    day = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny] != 0)
        continue;
      maps[nx][ny] = 1;
      q.push(make_pair(make_pair(nx, ny), day + 1));
      cnt_ing += 1;

      if(cnt_ing == tomato){
        return day + 1;
        break;
      }
    }
  }

  if(cnt_ing < tomato)
    return -1;
    
  if(day == 0)
    return 0;
}

int main() {
  cin >> m >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> maps[i][j];
      if(maps[i][j] == -1)
        cnt += 1;
      if(maps[i][j] == 1) {
        q.push(make_pair(make_pair(i, j), 0));
        cnt_ing += 1;
      }
    }
  }
  
  tomato = m * n - cnt;

  cout << bfs();
}
