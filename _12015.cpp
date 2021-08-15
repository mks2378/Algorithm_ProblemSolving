#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
	int N, temp, cnt=0;
	vector<int> v;
	
	v.push_back(INT_MIN);
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>temp;
		if(temp>v.back()){
			v.push_back(temp);
			cnt++;
		}				 
		else{
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp); 
			*low = temp;
		}
	}
	
	// vector 내에는 완벽하게 순서가 안맞을 수 있지만, 
	// ex) 20 30 10 -> vector에는 INT_MIN 10 30 존재 
	// 개수만을 요구하므로 이와 같이 구현 가능 
	cout<<cnt;
	
	return 0;
}
