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

// �ִܰŸ��� �̵����� ��, �� ��ġ���� �ٸ� �������� �ִܰŸ� �̵��� ���� �ĺ� ��ġ Ž��  
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

// �������� �䱸�� �ִܰŸ� ���� 
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

// ���ٹ��
// �� ó�� ��ġ�κ��� bfs 1���� �ִܰŸ��� ��ġ�� �̵� 
// Food�� dist�� �� ���� �ִ� ��ġ�κ��� �� ��ǥ�������� �ִܰŸ� �ǹ�
// S.dist�� �� ���� �ִ� ��ġ������ ���� �̵� �Ÿ�  
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
		// ������ bfs�� ���� ���� �ִܰŸ� ��ġ �ĺ����� MAP�� �湮 ������ �ʱ�ȭ 
		V.clear();
		memset(visited,0,sizeof(visited));
		
		bfs(S.y,S.x); // �������� �̵��� �ִܰŸ� �ĺ��� Ž�� -> vector<Food> V  
		if(V.size()==0){
			cout<<S.time;
			break;	
		}
		
		// V�� �����ִ� �� ��ü�� ���� ����� ũ�⺸�� �۴ٴ� ���� �ǹ��ϹǷ�  
		// 1�� ������ ���� �� ��ġ�� �̵��ϸ� ��  
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
		
		// bfs�� ���� ���� �ĺ���(vector<Food> V) �� �ִ� �Ÿ��� ��ġ�� �̵��� ���� 
		// �������� �䱸�� ������ �ݿ��� sorting ����
		// ����ó���� �ִ� ��ġ�� �� ��ġ���� �ִܰŸ� ��ġ  
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
