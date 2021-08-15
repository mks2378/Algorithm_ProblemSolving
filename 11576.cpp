#include <iostream>
using namespace std;
#include <vector>

int A, B;
int m;

int get_ex(){
	int ex = 1;
	
	for(int i=1;i<m;i++)
		ex*=A;
		
	return ex;
}

int main(){
	int val, Ex;
	int remain;
	int result = 0;
	vector<int> v;
	
	cin>>A; cin>>B;
	cin>>m;
	
	Ex = get_ex();
	
	for(int i=0;i<m;i++){
		cin>>val;
		result += val*Ex;
		Ex/=A;
	}
	
	while(result!=0){
		v.push_back(result%B);
		result = result/B;		
	}
	
	for(int i=(v.size()-1);i>=0;i--)
		cout<<v[i]<<' ';
	
	return 0;
}
