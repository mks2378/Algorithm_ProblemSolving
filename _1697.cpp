#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

bool visited[MAX];

int bfs(int n, int m){
	queue<int> q;
	int time=0;
	q.push(n);
	
	while(true){
		// for문안에 i<q.size()라고 써서 for문안에서 q에 값이 push되면서 q의 크기가 변동 되는 것을 미처 생각 못함 
		int size = q.size(); 
		for(int i=0;i<size;i++){
			n = q.front();
			q.pop();
		
			if(n==m){
				return time;
			}
			if(n-1>=0 && visited[n-1]==false){
				q.push(n-1);
				visited[n-1] = true;			
			}
			if(n+1<=100000 && visited[n+1]==false){
				q.push(n+1);
				visited[n+1] = true;	
			}
			if(n*2<=100000 && visited[n*2]==false){
				q.push(n*2);
				visited[n*2] = true;	
			}
		}
		++time;
	}	
}

int main(){
	int N, M;
	cin>>N>>M;
	cout<<bfs(N,M);
	
	return 0;	
}

