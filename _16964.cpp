#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000+1

int N;
vector<int> v[MAX];
bool visited[MAX];
int order[MAX];

void dfs(vector<int> &d, int x){
	visited[x] = true;
	d.push_back(x);
	
	for(int i=0;i<v[x].size();i++){
		if(visited[v[x][i]] == true) continue;
		dfs(d,v[x][i]);
	}
}

int main(){	
	cin>>N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);	
	}
	
	vector<int> ans;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		ans.push_back(x);
		order[x] = i;	
	}
	
	// order 함수값으로 오름차순 정렬  
	for(int i=1;i<=N;i++){
		sort(v[i].begin(), v[i].end(), [](const int &x, const int &y){
				return order[x]<order[y];
		});
	}
	
	vector<int> d;
	dfs(d,1);
	
	if(d == ans) // vector 차원 같을 시, 등호 비교 가능  
		cout<<1;
	else
		cout<<0;
	
	return 0;
}

// https://github.com/surinoel/boj/blob/master/16964.cpp
