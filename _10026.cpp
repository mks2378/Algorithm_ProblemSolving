#include<iostream>
#include<cstring>
#include<queue>
#define MAX 100

using namespace std;

int N; 
char MAP[MAX][MAX];
bool visited[MAX][MAX];

// MAP 내에서 이동할 때, 배열 이용 good  
int dir_y[] = {0,0,1,-1};
int dir_x[] = {1,-1,0,0};

int result_same, result_diff;

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i,j}); // {a,b} 와 같이 pair 바로 입력 가능 
	
	while(!q.empty()){
		// y, x 로 바로 입력 받는 것이 가독성 좋아  
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		// 여기에 visited 코드가 있으면 메모리 초과. 왜?
		// queue에서 pop될 때, 방문처리를 하게 되면 큐에 같은 위치가 중복 push되는 경우가 발생하기 때문.
		// ex) (a,b) 위치가 queue에서 pop되지 않은 위치라면, (a+1,b)와 (a-1,b) 각각 queue에서 pop될 때 (a,b)를 중복 push하게 된다.
		// 중복 push하게 되면 queue에 저장되는 값들이 계속 쌓여, 메모리 초과를 일으킨다. 
//		visited[y][x] = true;
		
		for(int i=0;i<4;i++){
			int ny = y + dir_y[i];
			int nx = x + dir_x[i];
			
			if(ny>=0 && ny<N && nx>=0 && nx<N){
				if(!visited[ny][nx] && MAP[ny][nx] == MAP[i][j]){
					q.push({ny,nx});
					visited[ny][nx] = true; // conclusion: bfs 문제 풀 때는 queue에 push할 때 방문처리를 함께 해주어야 한다.  
				}				
			}
		}		
	}
}

int main(){
	cin>>N;
	
	// string 선언하지 않고, 아래와 같이 입력받기 가능 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>MAP[i][j];
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				bfs(i,j);
				result_diff++;
			}
		}
	}
	
	memset(visited,false,sizeof(visited));	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(MAP[i][j] == 'G')
				MAP[i][j] = 'R';
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				bfs(i,j);
				result_same++;				
			}
		}
	}
	
	cout<<result_diff<<' '<<result_same;
	
	return 0;
}
