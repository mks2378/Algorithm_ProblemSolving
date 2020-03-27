#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// recursive function
//int gcd(int num1, int num2){
//	if(a%b==0)
//		return b;

//	return gcd(b, a%b);
//}

const int MAX = 100;
int arr[MAX];

// 유클리드 호제법  
int gcd(int num1, int num2){
	int a = num1>num2?num1:num2;
	int b = num1>num2?num2:num1;
	
	int temp;
	while(b>0){
		temp = a;
		a=b;
		b=temp%b;
	}
	return a;
}

int main(){
	int tc;
	cin>>tc;
	
	int val, N;
	for(int i=0;i<tc;i++){
		cin>>N;
		for(int j=0;j<N;j++){ // N값을 이용하여 하나의 배열로 계산 가능  
			cin>>val;
			arr[j] = val;
		}
		
		long long sum = 0;
		for(int j=0;j<N-1;j++){
			for(int k=j+1;k<N;k++){
				sum+=gcd(arr[j],arr[k]);
			}
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}
