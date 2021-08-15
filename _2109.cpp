//처음에 잘못 푼 방법  
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

// 생각 : day만큼의 일의 개수를 유지하되, 그 개수안에서 priority queue로
// 최대값들만을 유지할 수 있도록 한다.
// day 빠른 일 먼저 처리하므로, day가 늦은 일이 뒤에서 이를 대체하는 것은 가능 
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>p[i].second>>p[i].first;
		
	sort(p,p+n);
	
	for(int i=0;i<n;i++){
		r += p[i].second;
		pq.push(-p[i].second);
		
		// 일의 개수(pq.size()) 와 day(p[i].first)의 수가 같아야 한다.  
		// 하루에 하나의 강연이 가능하므로 일의 개수가 day 보다 크면 하루에 2개 이상의 
		// 강연을 진행한다는 의미로 그 때는 현재 작업중 pay가 가장 작은 것을 제외  
		if(pq.size()>p[i].first){
			r += pq.top();
			pq.pop();
		}
	}
	
	cout<<r<<'\n';
	return 0;
}
