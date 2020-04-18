#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX 1000

int N,M;
int MAP[MAX][MAX];
bool visited[MAX][MAX][2];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(){
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(0,0), make_pair(0,1)));
	visited[0][0][0] = true;
	
	while(!Q.empty()){
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int B = Q.front().second.first;
		int Cnt = Q.front().second.second;
		Q.pop();
		
		if(x==N-1 && y==M-1)
			return Cnt;
			
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(nx>=0 && ny>=0 && nx<N && ny<M){
				if(MAP[nx][ny]==1 && B==0){
					visited[nx][ny][B+1] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B+1, Cnt+1)));	
				}
				else if(MAP[nx][ny]==0 && visited[nx][ny][B]==false){
					visited[nx][ny][B] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B, Cnt+1)));
				}
			}
		}	
	}
	return -1;	
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<M;j++)
			MAP[i][j] = s[j] - '0';
	}
	
	cout<<bfs();	
	return 0;
}
