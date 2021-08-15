#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 51;
int w,h;
int cnt;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

bool arr[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;

void bfs(int y, int x){
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	visited[y][x] = true;
	
	while(q.size()){
		
		auto p = q.front();
		q.pop();
		
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				int new_y = p.first + dy[i];
				int new_x = p.second + dx[j];
				
				if(new_x>=1 && new_y>=1 && new_x<=50 && new_y<=50)
					if(!visited[new_y][new_x] && arr[new_y][new_x]){
						visited[new_y][new_x] = true;
						q.push(make_pair(new_y,new_x));
					}
			}
		}
	}	
	
	++cnt;
}

int main(){
	
	while(true){
		cin>>w>>h;
		
		if(w==0 && h==0)
			break;
			
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				cin>>arr[i][j];
			
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(!visited[i][j] && arr[i][j])
					bfs(i,j);			
			}
		}
		
		cout<<cnt<<'\n';
		
		memset(arr, 0, sizeof(arr)); // cstring
		memset(visited, 0, sizeof(visited)); // cstring
		cnt=0;
	}
	
	return 0;
}
