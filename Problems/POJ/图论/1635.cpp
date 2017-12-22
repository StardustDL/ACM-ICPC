/*
Subway tree systems
���⣺�����������ı������У��ж��������Ƿ���ͬ����
��������������С��ʾ��ȥ���������õ���С��ʾ�����ǽ��������������ֱ���1���ַ�����ʾ��Ҫ���ֵ����������������������������Ӻ���������ַ�����һģһ���ģ���ô���Ǳ�Ȼ��ͬ���ġ�����ԭ����ͱ���������⣬��������һ���µ�����
	  ������Ƚ�������һ�����Ƶķ����ǣ�����ʱ��ÿ���ڵ����ȣ��ӽڵ������������Ÿ����һ�¾Ϳ����ж�ͬ���� 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
string str1,str2;
string minpre(string str){
	vector<string> vs;string ans="";
	int st=0,back=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='0')back++;else back--;
		if(!back){
			if(i-1>st+1)vs.push_back("0"+minpre(str.substr(st+1,i-1-st))+"1");
			else vs.push_back("01");
			st=i+1;
		}
	}
	sort(vs.begin(),vs.end());
	for(int i=0;i<vs.size();i++)ans+=vs[i];
	return ans;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>str1>>str2;
		if(minpre(str1)==minpre(str2))puts("same");
		else puts("different"); 
	}
	return 0;
}

