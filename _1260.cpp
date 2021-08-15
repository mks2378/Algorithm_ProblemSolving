#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1001];
vector<int> edge[10001];

int N,M,V;

queue<int> q;

void dfs(int node){
	visited[node] = true;
	cout<<node<<' ';
	
	for(int i=0;i<edge[node].size();i++){
		if(visited[edge[node][i]]==false){
			dfs(edge[node][i]);
		}		
	}
}
// 방문 처리 해준 것을 방문 때마다 풀지 않아 마지막에 이르면 모두가 방문처리 되어 
//  for문 내 코드들이 실행되지 않고, pass 된다.  

void bfs(int node){
	q.push(node);
	visited[node] = true;
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		cout<<node<<' ';
		
		for(int i=0;i<edge[node].size();i++){
			if(visited[edge[node][i]]==false){
				// 아래 두 줄에서 오류 못 잡음  
				q.push(edge[node][i]);
				visited[edge[node][i]] = true; // (1)
			}
		}		
	}	
}
// (1)번 라인을 적어주지 않아, 큐에 이미 방문한 노드들이 push되었다. 

int main(){
	int a,b;	
	cin>>N>>M>>V;
	
	for(int i=0;i<M;i++){
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i=1;i<=N;i++)
		sort(edge[i].begin(), edge[i].end());
		
	dfs(V);
	cout<<'\n';
	memset(visited, false, sizeof(visited));
	bfs(V);		
	
	return 0;
}
