#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;

vector<int> v[MAX];
int parent[MAX];
bool visited[MAX];

int N;

// 방문한 부모노드에서 자식노드 연산 수행  
void findparent(int node){	
	visited[node] = true; // 방문처리 항상 먼저!! 중요!!  
	
	for(int i=0;i<v[node].size();i++){
		int child_node = v[node][i];
		if(!visited[child_node]){
			parent[child_node] = node;
			findparent(child_node);
		}
	}
	
}

// dfs or bfs는 방문한 노드에서 이전 또는 다음 노드 중 
// 어떤 노드에 대한 연산을 할지에 대한 결정이 필요한 것 같다.  

int main(){
	cin>>N;
	
	for(int i=0;i<N-1;i++){
		int node1, node2;
		cin>>node1>>node2;	
		
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	
	findparent(1);
	
	for(int i=2;i<=N;i++)
		cout<<parent[i]<<'\n';	
	
	return 0;
}
