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
		// for���ȿ� i<q.size()��� �Ἥ for���ȿ��� q�� ���� push�Ǹ鼭 q�� ũ�Ⱑ ���� �Ǵ� ���� ��ó ���� ���� 
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

