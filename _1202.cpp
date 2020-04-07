#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 300000;

int N, K;
int bag[MAX];
pair<int, int> jewelry[MAX];
priority_queue<int> pq; //maxHeap �̿� 

int main(){
	cin>>N>>K;
	
	for(int i=0;i<N;i++)
		cin>>jewelry[i].first>>jewelry[i].second;
	for(int i=0;i<K;i++)
		cin>>bag[i];
		
	sort(jewelry, jewelry+N);
	sort(bag,bag+K);
	
	long long result = 0;
	int idx = 0;
	
	// ���������� ���� ������� �ִ��� ��� ������ �ִ� ���  
	for(int i=0;i<K;i++){
		//i ��° ������ �������ѿ� �����ϴ� ���� �� ����  
		while(idx<N && jewelry[idx].first <= bag[i])
			pq.push(jewelry[idx++].second); 
		
		//pq�� ��Ʈ���� ���� ���� ���� ��� ������ ������� 
		if(!pq.empty()){
			result += pq.top();
			pq.pop();		
		}
	}
		
	cout<<result<<'\n';
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int MAX = 300000;
//
//vector<pair<int, int>> v1;
//vector<int> v2;
//
//bool visited[MAX];
//
//int N,K;
//int m,v,w;
//unsigned long long sum;
//
//bool cmp(const pair<int, int> a, const pair<int, int> b){
//	return a.second>b.second;
//}
//
//int main(){
//	cin>>N>>K;
//	
//	for(int i=0;i<N;i++){
//		cin>>m>>v;
//		v1.push_back(make_pair(m,v));		
//	}
//	
//	for(int i=0;i<K;i++){
//		cin>>w;
//		v2.push_back(w);
//	}
//		
//	sort(v1.begin(),v1.end(),cmp);
//	sort(v2.begin(),v2.end());
//	
//	for(int i=0;i<N;i++){
//		for(int j=0;j<K;j++){
//			if(v1[i].first<=v2[j] && !visited[j]){
//				visited[j] = true;
//				sum += v1[i].second;
//				break;
//			}		
//		}
//	}
//	
//	cout<<sum<<'\n';
//	
//	return 0;
//}
// O(N*M) -> �ð��ʰ�(���� �⺻���� ���ٹ��) 
