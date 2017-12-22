/*
单词翻转
注意：++，--的使用 
*/ 
#include<iostream>
using namespace std;
char str[51][255];
int n=0;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>str[++n]);//这里实际上会读入单词数+1 
	while(n-->0)cout<<str[n]<<" ";//这里由于是n--，所以会从n-1开始输出 
	return 0;
}
