#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int M,N;
int time = -1;

queue<pair<int,int> > q;
bool visited [MAX][MAX];
int status[MAX][MAX];

// 동시에 여러 지점에서 bfs로 서치해가는 문제  
void bfs(){
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			if(x-1>=1 && status[y][x-1]==0 && !visited[y][x-1]){
				visited[y][x-1] = true;
				status[y][x-1] = 1;
				q.push(make_pair(y,x-1));
			}
			
			if(y-1>=1 && status[y-1][x]==0 && !visited[y-1][x]){
				visited[y-1][x] = true;
				status[y-1][x] = 1;
				q.push(make_pair(y-1,x));
			}
			
			if(x+1<=M && status[y][x+1]==0 && !visited[y][x+1]){
				visited[y][x+1] = true;
				status[y][x+1] = 1;
				q.push(make_pair(y,x+1));
			}
			
			if(y+1<=N && status[y+1][x]==0 && !visited[y+1][x]){
				visited[y+1][x] = true;
				status[y+1][x] = 1;
				q.push(make_pair(y+1,x));
			}	
		}
		++time;
	}	
}

int main(){
	cin>>M>>N; // 가로, 세로 
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
	 		cin>>status[i][j];
	 		if(status[i][j]==1)
	 			q.push(make_pair(i,j));
		}
		
	bfs();
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
	 		if(status[i][j]==0)
	 			time = -1;
	
	cout<<time;
	
	return 0;
}
