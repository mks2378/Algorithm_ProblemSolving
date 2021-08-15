#include <iostream>
#include <vector>
using namespace std;

bool visited[1001];
vector<int> Node[1001];

void DFS(int node){
	for(int i=0;i<Node[node].size();i++){
		int next = Node[node][i];
		if(visited[next]==false){
			visited[next] = true;
			DFS(next);
		}
	}
}

int main(){
	int N, M;
	int cnt=0;
	
	cin>>N>>M;
	
	while(M--){
		int u, v;
		cin>>u>>v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}
	
	for(int i=1;i<=N;i++){
		if(visited[i]==false){
			DFS(i);
			cnt++;
		}		
	}
	
	cout<<cnt<<'\n';

	return 0;
}
