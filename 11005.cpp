#include <iostream>
#include <vector>
using namespace std;

vector<char> ans;

int main(){
	long long N;
	int B;
	int conv = 'A'-10;
	cin>>N; cin>>B;
	
	if(B>=2&&B<=10)
	{
		while(N!=0){
			ans.push_back((N%B)+('0'));
			N = N/B;
		}
	}
	else{
		while(N!=0){
			if((N%B)<=9)
				ans.push_back((N%B)+('0'));
			else
				ans.push_back((N%B)+conv);
			N = N/B;
		}
	}
	
	for(int i=ans.size()-1;i>=0;--i)
		cout<<ans[i];	

	return 0;
}
