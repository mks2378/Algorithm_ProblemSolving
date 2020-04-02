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

/*
<처음 나의 접근>
- 2차원 배열에서 각 위치마다 세로, 가로, 사각형(9개 요소)에 대하여 for문으로 1~9 값이 1개씩 있는지 확인 
- 특히, Square_check() 함수에서 사각형(9개 요소)에 대한 모든 경우의 수를 계산하여 코드가 길어졌다. 
- 스도쿠가 완성되었는지 판단 위해 Check_Completion()도 시간을 증가시켰다.

<해결 방법>
- 각각의 row, column, square를 2차원 배열로 생성하여 첫 번째 인덱스는 몇 번째인지를 가르키고, 두 번째 인덱스는
  인덱스 자체가 값을 의미하게 하여, 해당 값이 존재하는지 여부를 표현하였다.
- 아이디어: 81개 각각의 위치에 대하여 값이 0일 때, 해당 위치에 대한 row, column, square에서 중복되지 않는 값(1~9)로 선택하여 dfs 진행 
- 각각의 위치가 어느 square에 해당하는지 인덱스로 표현하는 아이디어  
- void dfs(int cnt) 에서 cnt==81에서 종료, cnt 0~80을 2차원 배열의 인덱스(y,x)로 표현하는 아이디어  

#include <iostream>
using namespace std;

int MAP[9][9];
bool Completed;

void Row_check(int x){
	int idx, cnt=0;
	int sum=45;
	for(int i=0;i<9;i++){
		if(MAP[x][i]==0){
			cnt++;
			idx=i;
		}
		else
			sum-=MAP[x][i];
	}
	
	if(cnt>1 || cnt==0)
		return;
	else
		MAP[x][idx] = sum;
}

void Column_check(int x){
	int idx, cnt=0;
	int sum=45;
	for(int i=0;i<9;i++){
		if(MAP[i][x]==0){
			cnt++;
			idx=i;
		}
		else
			sum-=MAP[i][x];
	}
	
	if(cnt>1 || cnt==0)
		return;
	else
		MAP[idx][x] = sum;
}

void Square_check(int x,int y){
	int idx_x, idx_y, cnt=0;
	int sum=45;
	
	if(x>=0&&x<=2&&y>=0&&y<=2){
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else if(x>=0&&x<=2&&y>=3&&y<=5){
		for(int i=0;i<=2;i++)
			for(int j=3;j<=5;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else if(x>=0&&x<=2&&y>=6&&y<=8){
		for(int i=0;i<=2;i++)
			for(int j=6;j<=8;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else if(x>=3&&x<=5&&y>=0&&y<=2){
		for(int i=3;i<=5;i++)
			for(int j=0;j<=2;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else if(x>=3&&x<=5&&y>=3&&y<=5){
		for(int i=3;i<=5;i++)
			for(int j=3;j<=5;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else if(x>=3&&x<=5&&y>=6&&y<=8){
		for(int i=3;i<=5;i++)
			for(int j=6;j<=8;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else if(x>=6&&x<=8&&y>=0&&y<=2){
		for(int i=6;i<=8;i++)
			for(int j=0;j<=2;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else if(x>=6&&x<=8&&y>=3&&y<=5){
		for(int i=6;i<=8;i++)
			for(int j=3;j<=5;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
	
	else{
		for(int i=6;i<=8;i++)
			for(int j=6;j<=8;j++){
				if(MAP[i][j]==0){
					cnt++;
					idx_y = i;
					idx_x = j;
				}
				else
					sum-=MAP[i][j];
			}
		
		if(cnt>1||cnt==0)
			return;
		else
			MAP[idx_y][idx_x] = sum;
			
		return;
	}
}

bool Check_Completion(){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){
			if(MAP[i][j]==0)
				return false;	
		}
	return true;				
}

void Check(int k,int l){
	Row_check(k);
	Column_check(l);
	Square_check(k,l);
}

int main(){
	
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>MAP[i][j];
	
	while(!Completed){
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				Check(i,j);
				
		Completed = Check_Completion();		
	}
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
			cout<<MAP[i][j]<<' ';
		cout<<'\n';
	}	
	
	return 0;
} 
*/
