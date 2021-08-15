#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000+1;

int N;
int far_node, diameter;

bool visited[MAX];
vector<pair<int,int>> v[MAX];

void dfs(int node, int cost){
	if(visited[node])
		return;
	
	visited[node] = true;
	
	if(diameter<cost){
		diameter = cost;
		far_node = node;
	}
	
	for(int i=0;i<v[node].size();i++){
		int sub_node = v[node][i].first;
		int weight = v[node][i].second;
		
		dfs(sub_node, cost+weight);
	}
}


int main(){
	cin>>N;
	
	int node1, node2, cost;
	for(int i=0;i<N-1;i++){
		cin>>node1>>node2>>cost;
		
		v[node1].push_back(make_pair(node2,cost));
		v[node2].push_back(make_pair(node1,cost));			
	}
	
	dfs(1,0);
	fill_n(visited,sizeof(visited),0);
	diameter = 0;
	
	dfs(far_node,0);
	cout<<diameter;
	
	return 0;
}
