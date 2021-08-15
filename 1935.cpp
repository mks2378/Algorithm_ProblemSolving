// 1935_후위표기식2 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

const int MAX = 26;

stack<double> st;
int num_arr[MAX];

int main(){
	double val1, val2;
	int cnt;
	string str;
	
	cin>>cnt;
	cin>>str;
	for(int i=0;i<cnt;i++)
		cin>>num_arr[i];
	
	for(int i=0;i<str.length();i++){
		if(str[i]>='A'&&str[i]<='Z'){
			st.push(num_arr[str[i]-'A']);	
		}
		else{
			val1 = st.top();
			st.pop();
			val2 = st.top();
			st.pop();
			
			switch(str[i]){
				case '+':
					val2 = val2 + val1;
					st.push(val2);
					break;
				case '-':
					val2 = val2 - val1;
					st.push(val2);
					break;
				case '*':
					val2 = val2 * val1;
					st.push(val2);
					break;
				case '/':
					val2 = val2 / val1;
					st.push(val2);
					break;
			}
		}
	}
	// c++ 소수자리 고정  
	cout<<fixed;
	cout.precision(2);
	cout<<st.top();	
	
	return 0;
}
