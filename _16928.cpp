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
	// 최소 이동 횟수가 0이므로 -1로 초기화 해주어
	// 해당 위치에 방문한 여부 판단  
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
			
			//한 번도 방문하지 않았다면, 최소 이동거리 업데이트  
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
