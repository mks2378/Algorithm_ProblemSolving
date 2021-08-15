#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;

vector<int> v[MAX];
int parent[MAX];
bool visited[MAX];

int N;

// �湮�� �θ��忡�� �ڽĳ�� ���� ����  
void findparent(int node){	
	visited[node] = true; // �湮ó�� �׻� ����!! �߿�!!  
	
	for(int i=0;i<v[node].size();i++){
		int child_node = v[node][i];
		if(!visited[child_node]){
			parent[child_node] = node;
			findparent(child_node);
		}
	}
	
}

// dfs or bfs�� �湮�� ��忡�� ���� �Ǵ� ���� ��� �� 
// � ��忡 ���� ������ ������ ���� ������ �ʿ��� �� ����.  

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
