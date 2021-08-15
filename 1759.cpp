#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L,C;
int vowel,consonant;

vector<char> letter;
vector<char> pw;
bool selected[15];

void dfs(int cnt,int idx){
	if(cnt==L&&vowel>0&&consonant>1){
		for(int i=0;i<pw.size();i++)
			cout<<pw[i];
		cout<<'\n';
		return;
	}
	
	for(int i=idx;i<letter.size();i++){
		if(!selected[i]){
			selected[i] = true;
			pw.push_back(letter[i]);
			
			if(letter[i]=='a'||letter[i]=='e'||letter[i]=='i'||letter[i]=='o'||letter[i]=='u'){
				vowel++;
				dfs(cnt+1,i+1);
				vowel--;
			}
			else{
				consonant++;
				dfs(cnt+1,i+1);
				consonant--;
			}
			
			pw.pop_back();
			selected[i] = false;	
		}		
	}
}

int main(){
	cin>>L>>C;
	for(int i=0;i<C;i++){
		char ch;
		cin>>ch;
		letter.push_back(ch);
	}
	
	sort(letter.begin(),letter.end());
	dfs(0,0);
	
	return 0;
}
