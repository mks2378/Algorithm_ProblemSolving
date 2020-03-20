#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100000+1

vector<int> v[MAX];
bool visited[MAX];

int N;
bool Correct = true;
int order[MAX];
vector<int> ans;

bool compare(int a, int b){
	if(order[a]<order[b])
		return true;
	else
		return false;	
}

void bfs(){
	int cnt = 0;
	queue<int> q;
	visited[1] = true;
	q.push(1);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		if(ans[cnt]!=x){
			Correct = false;
			return;
		}
		
		for(int i=0;i<v[x].size();i++){
			int node = v[x][i];
			if(!visited[node]){
				visited[node] = true;
				q.push(node);	
			}
		}
		++cnt;
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
	
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		ans.push_back(x);	
	}
	
	// 방문순서에 따른 가중치 부여  
	for(int i=0;i<N;i++)
		order[ans[i]] = i;
	
	// 각 노드에 대해 답에 근거하여 빨리 방문한 노드가 앞쪽에 오도록
	// 가중치 기준으로 오름차순 정렬  
	for(int i=1;i<=N;i++)
		sort(v[i].begin(),v[i].end(),compare);
		
	bfs();
	
	if(Correct)
		cout<<1;
	else
		cout<<0;		
	
	return 0;
}
