// 17298 ¿ÀÅ«¼ö 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int num;
	cin>>num;
	
	vector<int> v(num);
	for(int i=0;i<num;i++)
		cin>>v[i];
	
	stack<int> st;
	vector<int> ans(v.size(), -1);
	
	for(int i=0;i<v.size();i++){
		while(!st.empty()&&v[st.top()]<v[i]){
			ans[st.top()] = v[i];
			st.pop();
		}
		st.push(i);		
	}
	
	for(int x:ans)
		cout<<x<<' ';
	
	return 0;
}

