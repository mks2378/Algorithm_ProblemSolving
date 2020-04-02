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
   // 1���� �迭�� �ε��� -> 2���� �迭�� �ε��� ǥ�� ���� 
   // 2�������� ù��° �ε����� y, �ι�° �ε����� x 
   int y = cnt/MAX;
   int x = cnt%MAX;
   
   if(cnt==81){
      Print();
      exit(0);
   }
   
   if(MAP[y][x]==0){
      for(int i=1;i<=9;i++){
         // ����, ����, �ش� ū �簢�� ��𿡵� �������� �ʴ� ���ڶ�� ����  
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
   // 9���� 3���� �������� ������ �ϹǷ� ������ 3�� �̿��Ͽ� �з� 
   // y: (i/3)*3, x: (j/3)
   // �ڵ�� ǥ���� ����  
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
