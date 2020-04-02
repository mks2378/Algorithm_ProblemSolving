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

/*
<ó�� ���� ����>
- 2���� �迭���� �� ��ġ���� ����, ����, �簢��(9�� ���)�� ���Ͽ� for������ 1~9 ���� 1���� �ִ��� Ȯ�� 
- Ư��, Square_check() �Լ����� �簢��(9�� ���)�� ���� ��� ����� ���� ����Ͽ� �ڵ尡 �������. 
- ������ �ϼ��Ǿ����� �Ǵ� ���� Check_Completion()�� �ð��� �������״�.

<�ذ� ���>
- ������ row, column, square�� 2���� �迭�� �����Ͽ� ù ��° �ε����� �� ��°������ ����Ű��, �� ��° �ε�����
  �ε��� ��ü�� ���� �ǹ��ϰ� �Ͽ�, �ش� ���� �����ϴ��� ���θ� ǥ���Ͽ���.
- ���̵��: 81�� ������ ��ġ�� ���Ͽ� ���� 0�� ��, �ش� ��ġ�� ���� row, column, square���� �ߺ����� �ʴ� ��(1~9)�� �����Ͽ� dfs ���� 
- ������ ��ġ�� ��� square�� �ش��ϴ��� �ε����� ǥ���ϴ� ���̵��  
- void dfs(int cnt) ���� cnt==81���� ����, cnt 0~80�� 2���� �迭�� �ε���(y,x)�� ǥ���ϴ� ���̵��  

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
