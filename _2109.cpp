//ó���� �߸� Ǭ ���  
//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//const int MAX = 10001;
//priority_queue<int> pq[MAX];
//
//int d,p;
//int total;
//
//int main(){
//	int num;
//	
//	cin>>num;
//	for(int i=0;i<num;i++){
//		cin>>p>>d;
//		pq[d].push(p);
//	}
//	
//	for(int i=1;i<MAX;i++){
//		if(!pq[i].empty()){
//			total += pq[i].top();
//		}
//	}
//	
//	cout<<total<<'\n';
//	
//	return 0;
//}


#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, r;

pair<int, int> p[10000];
priority_queue<int> pq;

// ���� : day��ŭ�� ���� ������ �����ϵ�, �� �����ȿ��� priority queue��
// �ִ밪�鸸�� ������ �� �ֵ��� �Ѵ�.
// day ���� �� ���� ó���ϹǷ�, day�� ���� ���� �ڿ��� �̸� ��ü�ϴ� ���� ���� 
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>p[i].second>>p[i].first;
		
	sort(p,p+n);
	
	for(int i=0;i<n;i++){
		r += p[i].second;
		pq.push(-p[i].second);
		
		// ���� ����(pq.size()) �� day(p[i].first)�� ���� ���ƾ� �Ѵ�.  
		// �Ϸ翡 �ϳ��� ������ �����ϹǷ� ���� ������ day ���� ũ�� �Ϸ翡 2�� �̻��� 
		// ������ �����Ѵٴ� �ǹ̷� �� ���� ���� �۾��� pay�� ���� ���� ���� ����  
		if(pq.size()>p[i].first){
			r += pq.top();
			pq.pop();
		}
	}
	
	cout<<r<<'\n';
	return 0;
}
