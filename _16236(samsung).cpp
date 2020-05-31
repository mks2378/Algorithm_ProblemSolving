#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

#define MAX 20
using namespace std;

typedef struct{
	int y,x;
	int size;
	int eat_num;
	int time;
}Shark;

typedef struct{
	int y,x;
	int dist;
}Food;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int N;
int MAP[MAX][MAX];
bool visited[MAX][MAX];

vector<Food> V;
Shark S;

// 최단거리로 이동했을 때, 그 위치에서 다른 곳으로의 최단거리 이동을 위한 후보 위치 탐색  
void bfs(int b, int a){
	queue<pair<pair<int, int>, int>> q;
	q.push({{b,a},0});
	visited[b][a] = true;
	
	while(!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny>=0 && nx>=0 && ny<N && nx<N){
				if(!visited[ny][nx]){
					if(MAP[ny][nx]==0){
						visited[ny][nx] = true;
						q.push({{ny,nx},dist+1});
					}
					else if(MAP[ny][nx]<S.size){
						Food temp;
						temp.y = ny;
						temp.x = nx;
						temp.dist = dist + 1;
						
						V.push_back(temp);
						visited[ny][nx] = true;
						q.push({{ny,nx},dist+1});
					}
					else if(MAP[ny][nx] == S.size){
						visited[ny][nx] = true;
						q.push({{ny,nx},dist+1});
					}
				}				
			}			
		}		
	}	
}

// 문제에서 요구한 최단거리 기준 
bool Sorting_Standards(Food A, Food B){
	if(A.dist<=B.dist){
		if(A.dist==B.dist){
			if(A.y<=B.y){
				if(A.y==B.y){
					if(A.x<B.x)
						return true;
					return false;	
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

// 접근방법
// 맨 처음 위치로부터 bfs 1번에 최단거리의 위치로 이동 
// Food의 dist는 상어가 현재 있는 위치로부터 각 목표물까지의 최단거리 의미
// S.dist는 상어가 현재 있는 위치까지의 누적 이동 거리  
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>MAP[i][j];
			if(MAP[i][j] == 9){
				S.y = i;
				S.x = j;
				S.size = 2;
				S.eat_num = 0;
				S.time = 0;
			}
		}
	}
	
	while(true){
		// 이전의 bfs를 통해 얻은 최단거리 위치 후보군과 MAP의 방문 정보를 초기화 
		V.clear();
		memset(visited,0,sizeof(visited));
		
		bfs(S.y,S.x); // 다음으로 이동할 최단거리 후보군 탐색 -> vector<Food> V  
		if(V.size()==0){
			cout<<S.time;
			break;	
		}
		
		// V에 속해있는 것 자체가 현재 상어의 크기보다 작다는 것을 의미하므로  
		// 1개 남았을 때는 그 위치로 이동하면 끝  
		if(V.size()==1){  
			MAP[V[0].y][V[0].x] = 9;
			MAP[S.y][S.x] = 0;
			S.y = V[0].y;
			S.x = V[0].x;
			S.eat_num++;
			S.time += V[0].dist;
			
			if(S.size == S.eat_num){
				S.size++;
				S.eat_num = 0;	
			}
		}
		
		// bfs를 통해 얻은 후보군(vector<Food> V) 중 최단 거리의 위치로 이동을 위해 
		// 문제에서 요구한 조건을 반영한 sorting 진행
		// 가장처음에 있는 위치가 현 위치에서 최단거리 위치  
		else{
			sort(V.begin(), V.end(), Sorting_Standards);
			MAP[V[0].y][V[0].x] = 9;
			MAP[S.y][S.x] = 0;
			S.y = V[0].y;
			S.x = V[0].x;
			S.eat_num++;
			S.time += V[0].dist;
			
			if(S.size == S.eat_num){
				S.size++;
				S.eat_num = 0;
			}
		}		
	}
	
	return 0;
}

/*
typedef struct{
	int x;
	int y;
	int Size;
	int Eat_Num;
	int Time;
}Shark;

typedef struct{
	int x;
	int y;
	int Dist;
}Food;

int N;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];

Shark S;
vector<Food> V;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void BFS(int a, int b){
	queue<pair<pair<int, int>, int>> Q;
	Q.push({{a,b},0});
	Visit[a][b] = true;
	
	while(Q.empty() == 0){
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int Dist = Q.front().second;
		Q.pop();
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx>=0 && ny>=0 && nx<N && ny<N){
				if(!Visit[nx][ny]){
					if(MAP[nx][ny] == 0){
						Visit[nx][ny] = true;
						Q.push({{nx,ny}, Dist+1});
					}
					else if(MAP[nx][ny]<S.Size){
						Food Temp;
						Temp.x = nx;
						Temp.y = ny;
						Temp.Dist = Dist + 1;
						
						V.push_back(Temp);
						Visit[nx][ny] = true;
						Q.push({{nx,ny},Dist+1});
					}
					else if(MAP[nx][ny] == S.Size){
						Visit[nx][ny] = true;
						Q.push({{nx,ny},Dist+1});
					}
				}
			}
		}
	}
}

bool Sorting_Standard(Food A, Food B){
	if(A.Dist<=B.Dist){
		if(A.Dist == B.Dist){
			if(A.x<=B.x){
				if(A.x==B.x){
					if(A.y<B.y)
						return true;
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>MAP[i][j];
			if(MAP[i][j] == 9){
				S.x = i;
				S.y = j;
				S.Size = 2;
				S.Eat_Num = 0;
				S.Time = 0;	
			}
		}
	}
	
	while(true){
		V.clear();
		memset(Visit, false, sizeof(Visit));
		
		BFS(S.x, S.y);
		if(V.size()==0){
			cout<<S.Time<<'\n';
			break;
		}
		else if(V.size()==1){
			MAP[V[0].x][V[0].y] = 9;
			MAP[S.x][S.y] = 0;
			S.x = V[0].x;
			S.y = V[0].y;
			S.Eat_Num++;
			S.Time = S.Time + V[0].Dist;
			
			if(S.Eat_Num == S.Size){
				S.Eat_Num = 0;
				S.Size++;
			}
		}
		else{
			sort(V.begin(), V.end(), Sorting_Standard);
			MAP[V[0].x][V[0].y] = 9;
			MAP[S.x][S.y] = 0;
			S.x = V[0].x;
			S.y = V[0].y;
			S.Eat_Num++;
			S.Time = S.Time + V[0].Dist;
			
			if(S.Eat_Num == S.Size){
				S.Eat_Num = 0;
				S.Size++;
			}
		}
	}
	
	return 0;
}
*/
