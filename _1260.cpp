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
// �湮 ó�� ���� ���� �湮 ������ Ǯ�� �ʾ� �������� �̸��� ��ΰ� �湮ó�� �Ǿ� 
//  for�� �� �ڵ���� ������� �ʰ�, pass �ȴ�.  

void bfs(int node){
	q.push(node);
	visited[node] = true;
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		cout<<node<<' ';
		
		for(int i=0;i<edge[node].size();i++){
			if(visited[edge[node][i]]==false){
				// �Ʒ� �� �ٿ��� ���� �� ����  
				q.push(edge[node][i]);
				visited[edge[node][i]] = true; // (1)
			}
		}		
	}	
}
// (1)�� ������ �������� �ʾ�, ť�� �̹� �湮�� ������ push�Ǿ���. 

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
