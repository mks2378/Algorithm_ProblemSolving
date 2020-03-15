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

// ��ȯ ���� idea: ��� �� �̵��� �߻��ÿ� cnt 1����(�� ��� ���� �̵� ��� ����)  
// but, ��������� �ٽ� ���ƿ� ��쿡, cnt ����x 

// �ش� ��尡 ��ȯ �׷����� ���ϴ��� ���� Ȯ�� 
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

// �ش� ���κ��� ��ȯ �׷��������� �ּ� �Ÿ� ���� 
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
