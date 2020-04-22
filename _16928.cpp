#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 101

int N,M;
int MAP[MAX]; // "snake" or "ladder" 통해 이동하는 곳의 index 저장  
int dist[MAX]; // 해당 값까지 던진 주사위 최소 횟수  
int dir[] = {1, 2, 3, 4, 5, 6};

int bfs(){
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	
	while(!q.empty()){
		int Cur = q.front();
		q.pop();
		
		for(int i=0;i<6;i++){
			int new_Cur = Cur + dir[i];
			
			if(new_Cur>100) continue;
			if(MAP[new_Cur]!=0) new_Cur = MAP[new_Cur];
			if(dist[new_Cur] == -1){
				dist[new_Cur] = dist[Cur] + 1;
				q.push(new_Cur);	
			}
		}		
	}
	
	return dist[100];	
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		MAP[x] = y;
	}
	
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		MAP[u] = v;	
	}
	
	cout<<bfs();	
	return 0;
}
