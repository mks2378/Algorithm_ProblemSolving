/*
void * memset(void * ptr, int value, size_t num);
- ptr : 채우고자 하는 메모리의 시작 포인터(시작 주소)
- value : 메모리에 채우고자 하는 값. int형이지만 내부에서는
unsigned char로 변환되어 저장된다 
- num : 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기 
>> cstring 라이브러리 필요  
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 2001
bool visited[MAX];
vector<int> v[MAX];

bool answer;

void dfs(int node, int cnt){
	if(cnt==4){
		answer = true;
		return;
	}
	
	visited[node] = true;
	for(int i=0;i<v[node].size();i++){
		if(visited[v[node][i]]==false){
			dfs(v[node][i], cnt+1);	
		}
	}
	visited[node] = false;
}

int main(){
	int n,m;
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=0;i<n;i++){
		memset(visited, false, sizeof(visited));
		dfs(i,0);
		if(answer == true)
			break;
	}
	
	if(answer == true)
		cout<<1<<'\n';
	else
		cout<<0<<'\n';
	
	return 0;
}

/* my solution 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 2001

bool visited[MAX];
vector<int> edge[MAX];

int N, M;
bool answer;

void dfs(int node, int cnt){
	visited[node] = true;
	
	if(cnt==4){
		answer = true;
		return;
	}
	
	for(int i=0;i<edge[node].size();i++){
		if(visited[edge[node][i]]==false)
			dfs(edge[node][i], cnt+1);
	}
	visited[node] = false;
}

int main(){
	int a, b;
	
	cin>>N>>M;
	
	for(int i=0;i<M;i++){
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);	
	}
	
	for(int i=0;i<N;i++){
		memset(visited, false, sizeof(visited));
		dfs(i,0);
		
		if(answer==true){
			cout<<1<<'\n';
			return 0;
		}
	}

	cout<<0<<'\n';
	
	return 0;
}
*/
