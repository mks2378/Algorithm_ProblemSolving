#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100001

int parent[MAX];
bool visited[MAX];
vector<int> path;

int bfs(int N, int K){
	queue<pair<int, int>> q;
	
	q.push(make_pair(N, 0));
	visited[N] = true;
	
	while(!q.empty()){
		int curLoc = q.front().first;
		int curSec = q.front().second;
		q.pop();
		
		if(curLoc == K) // 목적지 도달 시 break
		{
			int idx = curLoc;
			
			while(idx != N)
			{
				path.push_back(idx);
				idx = parent[idx];				
			}
			path.push_back(N);
			
			return curSec;		
		}
		
		// 세 가지 경우의 수
		// 이미 방문한 지점은 큐에 넣지 않는다.
		// dijoint set 이용
		// curSec++으로 코딩하여 curLoc 마다 curSec이 증가하여 오류 잡는데 오래 걸림 
		if(curLoc+1<MAX && !visited[curLoc+1])
		{
			q.push(make_pair(curLoc+1, curSec+1));  
			visited[curLoc+1] = true;
			parent[curLoc+1] = curLoc;
		}
		if(curLoc-1>=0 && !visited[curLoc-1]){
			q.push(make_pair(curLoc-1, curSec+1));
			visited[curLoc-1] = true;
			parent[curLoc-1] = curLoc;			
		}
		if(curLoc*2<MAX && !visited[curLoc*2]){
			q.push(make_pair(curLoc*2, curSec+1));
			visited[curLoc*2] = true;
			parent[curLoc*2] = curLoc;
		}
	}	
}

int main(){
	int N, K;
	cin>>N>>K;
	
	cout<<bfs(N,K)<<'\n';
	
	for(int i=path.size()-1;i>=0;i--)
		cout<<path[i]<<" ";
	cout<<endl;
	
	return 0;
}


