#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MAX 3000+1

int N;
int Start;
vector<int> Station[MAX];
bool visited[MAX];
bool Is_Circular[MAX];

// 순환 여부 idea: 노드 간 이동이 발생시에 cnt 1증가(두 노드 간의 이동 경우 제외)  
// but, 출발점으로 다시 돌아올 경우에, cnt 증가x 

// 해당 노드가 순환 그래프에 속하는지 여부 확인 
void dfs(int Cur, int Cnt){
	if(Start==Cur && Cnt>=3){
		Is_Circular[Start] = true;
		return;
	}
	
	visited[Cur] = true;
	for(int i=0;i<Station[Cur].size();i++){ 
		if(Is_Circular[Start]) return;			
		
		int Next = Station[Cur][i];
		if(!visited[Next])
			dfs(Next,Cnt+1);
		else
			if(Next==Start && Cnt>=2)
				dfs(Next,Cnt+1);
	}
}

// 해당 노드로부터 순환 그래프까지의 최소 거리 측정 
int bfs(int Idx){
	memset(visited,false,sizeof(visited));
	queue<pair<int, int>> Q;
	Q.push(make_pair(Idx,0));
	
	visited[Idx] = true;
	while(!Q.empty()){
		int Cur = Q.front().first;
		int Cnt = Q.front().second;
		Q.pop();
		
		if(Is_Circular[Cur]) return Cnt;			
		
		for(int i=0;i<Station[Cur].size();i++){
			int Next = Station[Cur][i];
			if(!visited[Next]){
				visited[Next] = true;
				Q.push(make_pair(Next,Cnt+1));
			}
		}
	}
}

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		int a, b;
		cin>>a>>b;
		
		Station[a].push_back(b);
		Station[b].push_back(a);
	}
	
	for(int i=1;i<=N;i++){
		memset(visited,false,sizeof(visited));
		Start = i;
		dfs(i,0);
	}
	
	for(int i=1;i<=N;i++)
		cout<<bfs(i)<<' ';
	
	return 0;
}
