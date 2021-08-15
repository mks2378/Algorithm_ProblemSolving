#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 101;
int N,M;
int time;
string s;

bool status[MAX][MAX];
bool visited[MAX][MAX];

int bfs(){
	queue<pair<int,int> > q;
	q.push(make_pair(1,1));
	visited[1][1] = true;
	
	while(!q.empty()){
		++time;
		
		int size = q.size();
		for(int i=0;i<size;i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			if(y==N && x==M)
				return time;
			
			if(x-1>=1 && status[y][x-1] && !visited[y][x-1]){
				visited[y][x-1] = true;
				q.push(make_pair(y,x-1));	
			}
			
			if(y-1>=1 && status[y-1][x] && !visited[y-1][x]){
				visited[y-1][x] = true;
				q.push(make_pair(y-1,x));	
			}
			
			if(x+1<=M && status[y][x+1] && !visited[y][x+1]){
				visited[y][x+1] = true;
				q.push(make_pair(y,x+1));	
			}
			
			if(y+1<=N && status[y+1][x] && !visited[y+1][x]){
				visited[y+1][x] = true;
				q.push(make_pair(y+1,x));	
			}
		}
	}
}

int main(){
	cin>>N>>M;
	
	for(int i=1;i<=N;i++){
		cin>>s;
		for(int j=1;j<=M;j++)
			status[i][j] = s[j-1] - '0';
	}
	
	cout<<bfs();

	return 0;
}
