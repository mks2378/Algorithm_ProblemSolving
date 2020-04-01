#include <iostream>

using namespace std;
#define MAX 9

int MAP[MAX][MAX];
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];

void Print(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++)
			cout<<MAP[i][j]<<' ';	
		cout<<'\n';
	}
}

void dfs(int cnt){
	int x = cnt/MAX;
	int y = cnt%MAX;
	
	if(cnt==81){
		Print();
		exit(0);
	}
	
	if(MAP[x][y] == 0){
		for(int i=1;i<=9;i++){
			if(Row[x][i] == false && Col[y][i] == false && Square[(x/3)*3 + (y/3)][i] == false){
				Row[x][i] = true;
				Col[y][i] = true;
				Square[(x/3)*3 + (y/3)][i] = true;
				MAP[x][y] = i;
				dfs(cnt+1);
				MAP[x][y] = 0;
				Row[x][i] = false;
				Col[y][i] = false;
				Square[(x/3)*3 + (y/3)][i] = false;
			}
		}		
	}
	else
		dfs(cnt+1);
}

int main(){
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
