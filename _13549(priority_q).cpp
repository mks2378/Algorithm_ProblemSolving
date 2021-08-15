#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

const int MAX = 100001;
bool visited[MAX];

int bfs(int N, int K){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	
	//경과시간 짧을수록 우선순위 크다  
	q.push(make_pair(0,N));
	visited[N] = true;
	
	while(!q.empty()){
		int curSec = q.top().first;
		int curLoc = q.top().second;
		q.pop();
		
		if(curLoc == K)
			return curSec;
			
		if(curLoc*2<MAX && !visited[curLoc*2]){
			q.push(make_pair(curSec, curLoc*2));
			visited[curLoc*2] = true;
		}
		if(curLoc+1<MAX && !visited[curLoc+1]){
			q.push(make_pair(curSec+1, curLoc+1));
			visited[curLoc+1] = true;
		}
		if(curLoc-1>=0 && !visited[curLoc-1]){
			q.push(make_pair(curSec+1, curLoc-1));
			visited[curLoc-1] = true;
		}
	}
}

int main(){
	int N, K;
	cin>>N>>K;
	cout<<bfs(N,K)<<'\n';
	
	return 0;
}
