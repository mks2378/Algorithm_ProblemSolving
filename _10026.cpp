#include<iostream>
#include<cstring>
#include<queue>
#define MAX 100

using namespace std;

int N; 
char MAP[MAX][MAX];
bool visited[MAX][MAX];

// MAP ������ �̵��� ��, �迭 �̿� good  
int dir_y[] = {0,0,1,-1};
int dir_x[] = {1,-1,0,0};

int result_same, result_diff;

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i,j}); // {a,b} �� ���� pair �ٷ� �Է� ���� 
	
	while(!q.empty()){
		// y, x �� �ٷ� �Է� �޴� ���� ������ ����  
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		// ���⿡ visited �ڵ尡 ������ �޸� �ʰ�. ��?
		// queue���� pop�� ��, �湮ó���� �ϰ� �Ǹ� ť�� ���� ��ġ�� �ߺ� push�Ǵ� ��찡 �߻��ϱ� ����.
		// ex) (a,b) ��ġ�� queue���� pop���� ���� ��ġ���, (a+1,b)�� (a-1,b) ���� queue���� pop�� �� (a,b)�� �ߺ� push�ϰ� �ȴ�.
		// �ߺ� push�ϰ� �Ǹ� queue�� ����Ǵ� ������ ��� �׿�, �޸� �ʰ��� ����Ų��. 
//		visited[y][x] = true;
		
		for(int i=0;i<4;i++){
			int ny = y + dir_y[i];
			int nx = x + dir_x[i];
			
			if(ny>=0 && ny<N && nx>=0 && nx<N){
				if(!visited[ny][nx] && MAP[ny][nx] == MAP[i][j]){
					q.push({ny,nx});
					visited[ny][nx] = true; // conclusion: bfs ���� Ǯ ���� queue�� push�� �� �湮ó���� �Բ� ���־�� �Ѵ�.  
				}				
			}
		}		
	}
}

int main(){
	cin>>N;
	
	// string �������� �ʰ�, �Ʒ��� ���� �Է¹ޱ� ���� 
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
