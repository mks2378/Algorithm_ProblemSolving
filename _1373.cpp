#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin>>str;
	int len = str.size();
	
	if(len%3==1)
		cout<<str[0];
	else if(len%3==2)
		cout<<(str[0]-'0')*2+(str[1]-'0');
	for(int i=(len%3);i<len;i+=3)
		cout<<(str[i]-'0')*4+(str[i+1]-'0')*2+(str[i+2]-'0');
		
	return 0;
}


//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(){
//	string str;
//	string result="";
//	int sum, len, i;
//	cin>>str;
//	
//	len = str.length();
//	int first, second, third;
//	int th = len-(len/3)*3;
//	for(i=(len-1);i>=th;i-=3){
//		first = str[i]-'0';
//		second = (str[i-1]-'0')*2;
//		third = (str[i-2]-'0')*4;
//		sum = first + second + third;
//		result = to_string(sum) + result; 
//		// string은 객체를 만들어 복사하기 때문에 시간이 오래 걸림  
//	}
//	
//	sum=0;
//	if(i==1){
//		first = str[i--]-'0';
//		second = (str[i]-'0')*2;
//		sum = first + second;
//		result = to_string(sum) + result;
//	}
//	else{
//		first = str[i]-'0';
//		sum = first;
//		result = to_string(sum) + result;	
//	}
//	
//	cout<<result;
//
//	return 0;
//}
