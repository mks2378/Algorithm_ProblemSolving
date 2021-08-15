#include <iostream>
#include <queue>
#include <string>
#include <climits>
#define MAX 101
using namespace std;

int M,N;
string line;

bool room[MAX][MAX];
int min_wall[MAX][MAX];

void bfs(){
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(make_pair(1,1),0));
	min_wall[1][1] = 0;
	
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		
		if(p.first.first+1<=M && min_wall[p.first.first+1][p.first.second]>min_wall[p.first.first][p.first.second]+room[p.first.first+1][p.first.second]){
			min_wall[p.first.first+1][p.first.second]=min_wall[p.first.first][p.first.second]+room[p.first.first+1][p.first.second];
			q.push(make_pair(make_pair(p.first.first+1,p.first.second), min_wall[p.first.first+1][p.first.second]));
		}
		
		if(p.first.second+1<=N && min_wall[p.first.first][p.first.second+1]>min_wall[p.first.first][p.first.second]+room[p.first.first][p.first.second+1]){
			min_wall[p.first.first][p.first.second+1]=min_wall[p.first.first][p.first.second]+room[p.first.first][p.first.second+1];
			q.push(make_pair(make_pair(p.first.first,p.first.second+1), min_wall[p.first.first][p.first.second+1]));
		}
		
		if(p.first.first-1>=1 && min_wall[p.first.first-1][p.first.second]>min_wall[p.first.first][p.first.second]+room[p.first.first-1][p.first.second]){
			min_wall[p.first.first-1][p.first.second]=min_wall[p.first.first][p.first.second]+room[p.first.first-1][p.first.second];
			q.push(make_pair(make_pair(p.first.first-1,p.first.second), min_wall[p.first.first-1][p.first.second]));
		}
		
		if(p.first.second-1>=1 && min_wall[p.first.first][p.first.second-1]>min_wall[p.first.first][p.first.second]+room[p.first.first][p.first.second-1]){
			min_wall[p.first.first][p.first.second-1]=min_wall[p.first.first][p.first.second]+room[p.first.first][p.first.second-1];
			q.push(make_pair(make_pair(p.first.first,p.first.second-1), min_wall[p.first.first][p.first.second-1]));
		}
	}
}

int main(){
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			min_wall[i][j] = INT_MAX;	
	
	for(int i=1;i<=M;i++){
		cin>>line;
		for(int j=1;j<=N;j++){
			room[i][j] = line[j-1] - '0';
		}
	}
	
	bfs();
	cout<<min_wall[M][N];
	
	return 0;
}
