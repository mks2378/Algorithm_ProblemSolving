#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 2001  //처음 1001로 설정하여 런타임에러 발생( 
using namespace std;

// #define MAX 1001 : 런타임에러 발생(예를 들어, (999,999) 가능하여 그 다음에 2번째 조건에 의하여 
// (999+999, 999) 결과에 대해서는 리스트가 지정하지 않은 메모리에 접근하므로 런타임에러 발생. 
// 런타임에러는 거의 배열 인덱스를 잘못 접근하거나, 메모리와 관련된 경우 발생 

/* 런타임 에러  
배열에 할당된 크기를 넘어서 접근했을 때
전역 배열의 크기가 메모리 제한을 초과할 때
지역 배열의 크기가 스택 크기 제한을 넘어갈 때
0으로 나눌 때  
라이브러리에서 예외를 발생시켰을 때
재귀 호출이 너무 깊어질 때
이미 해제된 메모리를 또 참조할 때
*/

queue<pair<int,int> > q;
bool visited[MAX][MAX];

int bfs(int s){
	int time=0;
	pair<int, int> t = make_pair(1,0);
	q.push(t);
	
	while(true){
		unsigned long long size = q.size();
		for(int i=0;i<size;i++){
			auto p = q.front();
			q.pop();
			
			if(p.first==s){
				return time;
			}
			
			if(!visited[p.first][p.first]){
				visited[p.first][p.first] = true;
				q.push(make_pair(p.first,p.first));				
			}
			if(!visited[p.first+p.second][p.second] && p.first+p.second<=1000){
				visited[p.first+p.second][p.second] = true;
				q.push(make_pair(p.first+p.second,p.second));				
			}
			if(!visited[p.first-1][p.second] && p.first-1>=0){
				visited[p.first-1][p.second] = true;
				q.push(make_pair(p.first-1,p.second));	
			}
		}
		++time;
	}
}

int main(){
	int s;
	cin>>s;
	
	cout<<bfs(s);	
	
	return 0;
}
