// 처음 짠 코드 - 시간 초과 (O(n^2))
// 보통 기준을 잘못 잡아 접근을 잘못한 경우  

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N;
//vector<pair<int,int>> v;
//int MAX, cnt;
//
//bool compare(const pair<int,int>& a, const pair<int,int>& b){
//	if(a.first==b.first)
//		return a.second<b.second;
//		
//	return a.first<b.first;	
//}
//
//int main(){
//	cin>>N;
//	
//	for(int i=0;i<N;i++){
//		int start, end;
//		cin>>start>>end;
//		v.push_back(make_pair(start,end));			
//	}
//	
//	sort(v.begin(), v.end(), compare);
//	
////	for(int i=0;i<N;i++)
////		cout<<v[i].first<<' '<<v[i].second<<'\n';
//	
//	for(int i=0;i<N;i++){
//		int end = v[i].second;
//		++cnt;
//		
//		for(int j=i+1;j<N;j++){
//			if(end<=v[j].first){
//				++cnt;
//				end = v[j].second;
//			}
//		}
//		
//		if(cnt>MAX)
//			MAX = cnt;
//		cnt=0;
//	}
//
//	cout<<MAX;
//	
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Start, End;

vector<pair<int,int>> order;

int schedule(){
	//earliest: 현재 회의가 가장 끝나는 시간  
	//selected: 지금까지 선택한 회의의 수 
	int earliest = 0, selected = 0;
	for(int i=0;i<N;i++){
		int meetingBegin = order[i].second;
		int meetingEnd = order[i].first;
		if(earliest<=meetingBegin){
			earliest = meetingEnd;
			selected++;
		}
	}
	return selected;
}

int main(){
	cin>>N;
	
	//일찍 끝나는 순서대로 정렬 
	for(int i=0;i<N;i++){
		cin>>Start>>End;
		order.push_back(make_pair(End,Start));
	}
	
	sort(order.begin(), order.end());
	
	cout<<schedule()<<endl;
		
	return 0;
}
