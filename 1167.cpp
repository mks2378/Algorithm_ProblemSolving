#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000+1;

bool visited[MAX];
vector<pair<int,int>> graph[MAX];
int V, far_node, diameter;

void dfs(int node, int cost){
	if(visited[node])
		return;
	
	visited[node] = true;
			
	if(diameter<cost){
		diameter = cost;
		far_node = node;	
	}
	
	for(int i=0;i<graph[node].size();i++){
		int sub_node = graph[node][i].first;
		int weight = graph[node][i].second;
		
		if(!visited[sub_node])
			dfs(sub_node,cost+weight);		
	}	
}

int main(){
	cin>>V;
	
	for(int i=0;i<V;i++){
		int node1, node2, distance, last;
		cin>>node1>>node2>>distance>>last;		
		
		graph[node1].push_back(make_pair(node2,distance));
		
		while(last!=-1){
			node2 = last;
			cin>>distance>>last;
			
			graph[node1].push_back(make_pair(node2,distance));
		}
	}
	
	dfs(1,0);
	fill_n(visited, MAX, 0);
	diameter = 0;
	
	dfs(far_node, 0);
	cout<<diameter;
	
	return 0;
}
