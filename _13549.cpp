#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100001

int time[MAX];
int N,K;

// 시작점에서 임의의 위치 x까지 계산된 소요시간이 현 위치에서 위치 x까지 도달 시간보다 크면 
// 현 위치에서 위치 x까지 도달시간으로 갱신해줘야 최소 시간으로 결과를 얻을 수 있다.
// 목표 지점에 도착하면 종료하므로 그 전까지 거친 위치들에 대해 각각 최소시간으로 갱신해야  
// 결과도 최소시간으로 얻을 수 있다.  

int bfs(){
	queue<int> q;
	q.push(N);
	time[N] = 0;
	
	while(true){		
		int p = q.front();
		q.pop();
		
		if(p == K){
			return time[p];			
		}
		
		if(p*2<MAX && time[p*2]>time[p]){
			time[p*2] = time[p];
			q.push(p*2);
		}
		if(p+1<MAX && time[p+1]>time[p]+1){
			time[p+1] = time[p]+1;
			q.push(p+1);					
		}
		if(p-1>=0 && time[p-1]>time[p]+1){
			time[p-1] = time[p]+1;
			q.push(p-1);					
		}
	}
}


int main(){
	fill_n(time,MAX,INT_MAX);	
	cin>>N>>K;
	cout<<bfs();
	
	return 0;
}
