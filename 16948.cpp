#include <iostream>
#include <queue>
using namespace std;

#define MAX 200

bool visited[MAX][MAX];

int N;
int r1, c1, r2, c2;

int dir_y[] = {-2, -2, 0, 0, +2, +2};
int dir_x[] = {-1, +1, -2, +2, -1, +1};

int bfs(){
	queue<pair<pair<int, int>, int>> q;
	q.push({{r1,c1},0}); // make_pair 대신 {} 사용 가능 
	
	while(!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(y==r2 && x==c2){
			return cnt;	
		}
		
		for(int i=0;i<6;i++){
			int ny = y + dir_y[i];
			int nx = x + dir_x[i];
			
			if(ny>=0 && ny<200 && nx>=0 && nx<200){
				// 방문했던 곳에서 또 진행하면 중복이므로 
				// 최소 이동이 아니기 때문에 버린다  
				if(!visited[ny][nx]){
					visited[ny][nx] = true;
					q.push({{ny,nx},cnt+1});
				}
			}	
		}	
	}
	return -1;
}

int main(){
	cin>>N;
	cin>>r1>>c1>>r2>>c2;
	
	cout<<bfs();	
	return 0;
}
