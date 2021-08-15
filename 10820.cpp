#include <iostream>
#include <string>
using namespace std;

int lc, uc, num, space;

int main(){
	string str;

	for(int i=0;i<100;i++){
		getline(cin,str);
		
		if(str.length()==0)
			break;
		
		for(int j=0;j<str.length();j++){
			if(str[j]>='a'&&str[j]<='z')
				++lc;
			else if(str[j]>='A'&&str[j]<='Z')
				++uc;
			else if(str[j]==' ')
				++space;
			else if(str[j]>='0'&&str[j]<='9')
				++num;
		}
		cout<<lc<<' '<<uc<<' '<<num<<' '<<space<<'\n';
		lc=0; uc=0; num=0; space=0;		
	}
	
	return 0;
}

//int main(){
//	string str;
//	// 소문자, 대문자, 숫자, 공백 순 출력 
//	int lower,upper,num,space;
//	
//	while(getline(cin,str,'\n')){ // getline 함수의 고정주소값만 반환된다  
//		lower=0, upper=0, num=0, space=0;
//		
//		for(int i=0;i<str.length();i++){
//			if(str[i]>='A'&&str[i]<='Z')
//				upper++;
//			if(str[i]>='a'&&str[i]<='z')
//				lower++;
//			if(str[i]>='0'&&str[i]<='9')
//				num++;
//			if(str[i]==' ')
//				space++;
//		}
//		
//		cout<<lower<<' '<<upper<<' '<<num<<' '<<space<<'\n';
//	}
//	
//	return 0;
//}

