#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, Answer;
bool Alphabet[26];
vector<string> Words;

int Word_Count(){
   int NumOfWords=0;
   for(int i=0;i<Words.size();i++){
		bool completed = true;
		string str = Words[i];
        for(int j=0;j<str.length();j++){
        	int idx = str[j] - 'a';
        	if(!Alphabet[idx]){
            	completed = false;
            	break;
         	}
      	}
      	if(completed)
        	NumOfWords++;
   	}
   	return NumOfWords;
}

// 시간 제한 1초: 최대 연산 수 1500만 번 가능 
void dfs(int idx, int cnt){
   if(cnt==K){
   		// 최대값 비교할 때, 함수 리턴값을 max함수 안에 넣어 줘서 비교하는 코드 배움 
      	Answer = max(Answer, Word_Count());
      	return;   
   }
   
   for(int i=idx;i<26;i++){
      	if(!Alphabet[i]){
         	Alphabet[i] = true;
         	dfs(i, cnt+1);
         	Alphabet[i] = false;
      	}
   	}
}

// 'a', 'n', 't', 'i', 'c' 스펠링은 항상 포함되어 있다는 조건을 놓쳐서
// 계속 시간초과가 발생하는 결과 발생 
// 문제의 조건을 유심히 보자!  
int main(){
	cin>>N>>K;
	
	if(K<5){
		cout<<0;
		exit(0);
	}
   
	Alphabet['a' - 'a'] = true;
	Alphabet['n' - 'a'] = true;
	Alphabet['t' - 'a'] = true;
	Alphabet['i' - 'a'] = true;
	Alphabet['c' - 'a'] = true;
	K = K - 5;

    for(int i=0;i<N;i++){
		string s;
		cin>>s;
		Words.push_back(s);      
    }
   
	dfs(0, 0);
	cout<<Answer;
	return 0;
}
