#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100001

int time[MAX];
int N,K;

// ���������� ������ ��ġ x���� ���� �ҿ�ð��� �� ��ġ���� ��ġ x���� ���� �ð����� ũ�� 
// �� ��ġ���� ��ġ x���� ���޽ð����� ��������� �ּ� �ð����� ����� ���� �� �ִ�.
// ��ǥ ������ �����ϸ� �����ϹǷ� �� ������ ��ģ ��ġ�鿡 ���� ���� �ּҽð����� �����ؾ�  
// ����� �ּҽð����� ���� �� �ִ�.  

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
