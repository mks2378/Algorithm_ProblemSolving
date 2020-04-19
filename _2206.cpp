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
		int B = Q.front().second.first; // 현재까지 벽을 부순 횟수  
		int Cnt = Q.front().second.second; // 현재까지 지나쳐 온 칸 수 
		Q.pop();
		
		if(x==N-1 && y==M-1)
			return Cnt;
			
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(nx>=0 && ny>=0 && nx<N && ny<M){
				// 다음에 방문할 곳이 벽이고, B==0이므로 현재까지 부순 벽이 없으므로 진행 가능  
				// 이미 하나의 벽을 부수고 같은 곳을 다시 방문할 때는 현재 상태가 B==1 이므로 재방문 불가  
				if(MAP[nx][ny]==1 && B==0){
					visited[nx][ny][B+1] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B+1, Cnt+1)));	
				}
				// visited[nx][ny][0], visited[nx][ny][1] 으로 나누는 이유는
				// 벽을 부수지 않고 또는 부수고 이전에 이미 방문했다면,  
				// 현재 벽을 부수었는지 상태에 따라 같은 상태에서 방문한다면  
				// 다시 방문하는 것은 중복이기 때문에 visited 이용  
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

/*
처음 작성한 시간초과 코드  
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1000

int Answer = 987654321;
int N,M;
bool MAP[MAX][MAX];
bool Broken_Wall;
bool Arrival;

bool visited[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int cnt, int y, int x){
	if(y==N-1 && x==M-1){
		Arrival = true;
		Answer = min(Answer, cnt+1);
		return;	
	}
	
	for(int i=0;i<4;i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(ny>=0 && ny<N && nx>=0 && nx<M){
			if(MAP[ny][nx]==1 && !Broken_Wall){
				Broken_Wall = true;
				dfs(cnt+1, ny, nx);
				Broken_Wall = false;
			}
		
			if(MAP[ny][nx]==0 && !visited[ny][nx]){
				visited[ny][nx] = true;
				dfs(cnt+1, ny, nx);
				visited[ny][nx] = false;
			}
		}
	}	
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<M;j++)
			MAP[i][j] = s[j]-'0';
	}		
	
	visited[0][0] = true;
	dfs(0, 0, 0);
	
	if(Arrival)
		cout<<Answer;
	else
		cout<<-1;
	
	return 0;
}

*/
