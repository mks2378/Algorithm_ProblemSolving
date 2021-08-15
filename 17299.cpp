// 17299 ¿ÀÅ«¼ö 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[1000000];
int cnt[1000001];

int main(){
	stack<int> st;
	int num, value;
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>arr[i];
		++cnt[arr[i]];
	}
	
	vector<int> ans(num, -1);
	
	for(int i=0;i<num;i++){
		while(!st.empty()&&cnt[arr[st.top()]]<cnt[arr[i]]){
			ans[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);		
	}
	
	for(int x:ans)
		cout<<x<<' ';
	
	return 0;
}
