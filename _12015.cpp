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
	
	// vector ������ �Ϻ��ϰ� ������ �ȸ��� �� ������, 
	// ex) 20 30 10 -> vector���� INT_MIN 10 30 ���� 
	// �������� �䱸�ϹǷ� �̿� ���� ���� ���� 
	cout<<cnt;
	
	return 0;
}
