#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 101

int N,M;
int Move[MAX];
int dist[MAX];

int dir[] = {1,2,3,4,5,6};

int bfs(){
	// �ּ� �̵� Ƚ���� 0�̹Ƿ� -1�� �ʱ�ȭ ���־�
	// �ش� ��ġ�� �湮�� ���� �Ǵ�  
	memset(dist,-1,sizeof(dist));
	
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	
	while(!q.empty()){
		int Cur = q.front();
		q.pop();
		
		if(Cur==100)
			return dist[100];
		
		for(int i=0;i<6;i++){
			int new_Cur = Cur + dir[i];
			if(new_Cur>100) continue;
			if(Move[new_Cur]!=0) new_Cur = Move[new_Cur];			
			
			//�� ���� �湮���� �ʾҴٸ�, �ּ� �̵��Ÿ� ������Ʈ  
			if(dist[new_Cur]==-1){
				q.push(new_Cur);
				dist[new_Cur] = dist[Cur]+1;	
			}
		}		
	}	
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N+M;i++){
		int x, y;
		cin>>x>>y;
		Move[x] = y;
	}
	
	cout<<bfs();	
	return 0;
}
