#include <iostream>
#include <algorithm>
using namespace std;

int R,C;
int max_cnt;
bool visited[26];
char MAP[20][20];

void dfs(int cnt, int y, int x){
   max_cnt = max(max_cnt, cnt);
   
   if(!visited[MAP[y][x+1]-'A']&&(x+1<C)){
      visited[MAP[y][x+1]-'A'] = true;
      dfs(cnt+1,y,x+1);
      visited[MAP[y][x+1]-'A'] = false;
   }
   
   if(!visited[MAP[y][x-1]-'A']&&(x-1>=0)){
      visited[MAP[y][x-1]-'A'] = true;
      dfs(cnt+1,y,x-1);
      visited[MAP[y][x-1]-'A'] = false;
   }
   
   if(!visited[MAP[y+1][x]-'A']&&(y+1<R)){
      visited[MAP[y+1][x]-'A'] = true;
      dfs(cnt+1,y+1,x);
      visited[MAP[y+1][x]-'A'] = false;
   }
   
   if(!visited[MAP[y-1][x]-'A']&&(y-1>=0)){
      visited[MAP[y-1][x]-'A'] = true;
      dfs(cnt+1,y-1,x);
      visited[MAP[y-1][x]-'A'] = false;
   }
}

int main(){
   cin>>R>>C;
   
   for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
         cin>>MAP[i][j];
   
   visited[MAP[0][0]-'A'] = true;
   dfs(1,0,0);
   cout<<max_cnt;
   return 0;
}
