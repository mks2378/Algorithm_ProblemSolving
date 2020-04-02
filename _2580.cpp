#include <iostream>
using namespace std;

#define MAX 9
int MAP[MAX][MAX];
bool Row[MAX][MAX+1];
bool Col[MAX][MAX+1];
bool Square[MAX][MAX+1];

void Print(){
   for(int i=0;i<MAX;i++){
      for(int j=0;j<MAX;j++)
         cout<<MAP[i][j]<<' ';   
      cout<<'\n';
   }
}

void dfs(int cnt){
   // 1차원 배열의 인덱스 -> 2차원 배열의 인덱스 표현 공부 
   // 2차원에서 첫번째 인덱스는 y, 두번째 인덱스는 x 
   int y = cnt/MAX;
   int x = cnt%MAX;
   
   if(cnt==81){
      Print();
      exit(0);
   }
   
   if(MAP[y][x]==0){
      for(int i=1;i<=9;i++){
         // 가로, 세로, 해당 큰 사각형 어디에도 존재하지 않는 숫자라면 선택  
         if(Row[y][i]==false && Col[x][i] == false && Square[(y/3)*3 + (x/3)][i] == false){
            Row[y][i] = true;
            Col[x][i] = true;
            Square[(y/3)*3 + (x/3)][i] = true;
            MAP[y][x] = i;
            dfs(cnt+1);
            MAP[y][x] = 0;
            Row[y][i] = false;
            Col[x][i] = false;
            Square[(y/3)*3 + (x/3)][i] = false;
         }
      }      
   }
   else
      dfs(cnt+1);
}

int main(){
   // 9개를 3개의 집단으로 나눠야 하므로 나누기 3을 이용하여 분류 
   // y: (i/3)*3, x: (j/3)
   // 코드로 표현법 공부  
   for(int i=0;i<MAX;i++){
      for(int j=0;j<MAX;j++){
         cin>>MAP[i][j];
         if(MAP[i][j]!=0){
            Row[i][MAP[i][j]] = true;
            Col[j][MAP[i][j]] = true;
            Square[(i/3)*3 + (j/3)][MAP[i][j]] = true;
         }
      }
   }
   
   dfs(0);
   return 0;
}
