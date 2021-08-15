#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int num, cnt;

int main(){
	
	cin>>cnt;
	
	for(int i=0;i<cnt;i++){
		cin>>num;
		v.push_back(num);
	}
		
	sort(v.begin(),v.end());
	
	for(int i=0;i<cnt;i++)
		cout<<v[i]<<'\n';

	return 0;
}
