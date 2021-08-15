#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	queue<int> q;
	vector<int> v;
	
	int people, num;
	int temp;
	
	cin>>people>>num;
	
	for(int i=1;i<=people;i++)
		q.push(i);
	
//	cout<<"<";
//	while(people--){
//		for(int i=0;i<num-1;i++){
//			temp=q.front();
//			q.pop();
//			q.push(temp);
//		}
//		temp = q.front();
//		q.pop();
//		
//		if(people==0)
//			cout<<temp;
//		else
//			cout<<temp<<", ";
//	}
//	cout<<">";
	
	while(people--){
		for(int i=0;i<num-1;i++){
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		temp = q.front();
		v.push_back(temp);
		q.pop();
	}
	
	// 여러 가지 값들을 출력해야 할 때는 vector로 관리하는 것이 편하다. 
	cout<<"<";
	for(int i=0;i<v.size()-1;i++)
		cout<<v[i]<<", ";
	cout<<v[v.size()-1]<<">";
	
//	*** test *** 	
//	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
//		cout<<*it<<' ';
	
	return 0;
}
