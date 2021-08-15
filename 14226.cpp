#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 2001  //ó�� 1001�� �����Ͽ� ��Ÿ�ӿ��� �߻�( 
using namespace std;

// #define MAX 1001 : ��Ÿ�ӿ��� �߻�(���� ���, (999,999) �����Ͽ� �� ������ 2��° ���ǿ� ���Ͽ� 
// (999+999, 999) ����� ���ؼ��� ����Ʈ�� �������� ���� �޸𸮿� �����ϹǷ� ��Ÿ�ӿ��� �߻�. 
// ��Ÿ�ӿ����� ���� �迭 �ε����� �߸� �����ϰų�, �޸𸮿� ���õ� ��� �߻� 

/* ��Ÿ�� ����  
�迭�� �Ҵ�� ũ�⸦ �Ѿ �������� ��
���� �迭�� ũ�Ⱑ �޸� ������ �ʰ��� ��
���� �迭�� ũ�Ⱑ ���� ũ�� ������ �Ѿ ��
0���� ���� ��  
���̺귯������ ���ܸ� �߻������� ��
��� ȣ���� �ʹ� ����� ��
�̹� ������ �޸𸮸� �� ������ ��
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
