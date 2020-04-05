#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define MAX 9

int N, tc;
int MAP[MAX][MAX];
bool Row[MAX][MAX+1];
bool Col[MAX][MAX+1];
bool Square[3][3][MAX+1];
bool Tile[MAX+1][MAX+1];
bool Flag;

void Initialization(){
	Flag = false;
	memset(MAP, 0, sizeof(MAP));
	memset(Row, false, sizeof(Row));
	memset(Col, false, sizeof(Col));
	memset(Square, false, sizeof(Square));
	memset(Tile, false, sizeof(Tile));
}

bool Check(int y, int x, int N1, int N2, char C){
	// C = 'G' 일 경우 가로로 놓는 경우 Check.
	// (y, x)에 N1과 N2가 붙어있는 타일을 가로로 놓는다.
	// (y, x)에 N1, (y, x + 1)에 N2를 놓는다.
	if(C=='G'){
		if(Row[y][N1] == true || Row[y][N2] == true) return false;
		if(Col[x][N1] == true || Col[x+1][N2] == true) return false;
		if(Square[y/3][x/3][N1] == true || Square[y/3][(x+1)/3][N2] == true) return false;
		return true;	
	}
	
	// C = 'S'일 경우 세로로 타일을 놓는 경우 Check.
	// (y, x)에 N1과 N2가 붙어있는 타일을 세로로 놓는다.
	// (y, x)에 N1, (y + 1, x)에 N2를 놓는다.
	else{
		if(Row[y][N1] == true || Row[y+1][N2] == true) return false;
		if(Col[x][N1] == true || Col[x][N2] == true) return false;
		if(Square[y/3][x/3][N1] == true || Square[(y+1)/3][x/3][N2] == true) return false;
		return true;
	}
}

void MakeVisit(int y, int x, int N1, int N2, char C, bool T){
	Tile[N1][N2] = T;
	Tile[N2][N1] = T;
	
	if(C=='G'){
		Row[y][N1] = Row[y][N2] = T;
		Col[x][N1] = Col[x+1][N2] = T;
		Square[y/3][x/3][N1] = Square[y/3][(x+1)/3][N2] = T;
		
		if(T==true){
			MAP[y][x] = N1;
			MAP[y][x+1] = N2;	
		}
		else
			MAP[y][x] = MAP[y][x+1] = 0;
	}
	else{
		Row[y][N1] = Row[y+1][N2] = T;
		Col[x][N1] = Col[x][N2] = T;
		Square[y/3][x/3][N1] = Square[(y+1)/3][x/3][N2] = T;
		
		if(T == true){
			MAP[y][x] = N1;
			MAP[y+1][x] = N2;
		}
		else
			MAP[y][x] = MAP[y+1][x] = 0;
	}
}

void Print(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++)
			cout<<MAP[i][j];
		cout<<'\n';	
	}	
}

void dfs(int idx){
	if(Flag==true) return;
	
	if(idx==81){
		Flag = true;
		cout<<"Puzzle "<<tc<<'\n';
		Print();
		return;	
	}
	
	int y = idx/MAX;
	int x = idx%MAX;
	
	if(MAP[y][x]!=0)
		dfs(idx+1);
	else{
		if(x<=7 && MAP[y][x+1]==0){
			for(int i=1;i<=9;i++){
				for(int j=i+1;j<=9;j++){
					if(Tile[i][j] ==false){
						if(Check(y, x, i, j, 'G')==true){
							MakeVisit(y, x, i, j, 'G', true);
							dfs(idx+2);
							MakeVisit(y, x, i, j, 'G', false);						
						}
						
						if(Check(y, x, j, i, 'G')==true){
							MakeVisit(y, x, j, i, 'G', true);
							dfs(idx+2);
							MakeVisit(y, x, j, i, 'G', false);						
						}
					}
				}
			}
		}
		
		if(y<=7 && MAP[y+1][x]==0){
			for(int i=1;i<=9;i++){
				for(int j=i+1;j<=9;j++){
					if(Tile[i][j] == false){
						if(Check(y, x, i, j, 'S') == true){
							MakeVisit(y, x, i, j, 'S', true);
							dfs(idx+1);
							MakeVisit(y, x, i, j, 'S', false);
						}
						
						if(Check(y, x, j, i, 'S') == true){
							MakeVisit(y, x, j, i, 'S', true);
							dfs(idx+1);
							MakeVisit(y, x, j, i, 'S', false);
						}
					}
				}
			}
		}
	}	
}

int main(){
	while(true){
		Initialization();
		
		cin>>N;
		if(N==0)
			break;
			
		++tc;
		for(int i=0;i<N;i++){
			int	U, V;
			string LU, LV;
			
			cin>>U>>LU>>V>>LV;
			int y = LU[0]-'A';
			int x = LU[1]-'1';
			int yy = LV[0]-'A';
			int xx = LV[1]-'1';
			
			MAP[y][x] = U;
			MAP[yy][xx] = V;
			
			Row[y][U] = true;
			Row[yy][V] = true;
			
			Col[x][U] = true;
			Col[xx][V] = true;
			
			Square[y/3][x/3][U] = true;
			Square[yy/3][xx/3][V] = true;
			
			Tile[U][V] = true;
			Tile[V][U] = true;
		}
		
		for(int i=1;i<=9;i++){
			string s;
			cin>>s;
			int y = s[0]-'A';
			int x = s[1]-'1';
			
			MAP[y][x] = i;
			Row[y][i] = true;
			Col[x][i] = true;
			Square[y/3][x/3][i] = true;
		}
		dfs(0);
	}
	
	return 0;
}
