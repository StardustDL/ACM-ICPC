/*
接龙游戏
分析：注意前缀才是接龙，这就启发我们将所有单词按字典序排序，这样就使得前缀相同的单词在一起了
	  然后我们维护一个栈，枚举所有的字符串（按字典序排好的）
	  如果当前的字符串能和栈顶的字符串接龙的话，那么当前字符串入栈，继续枚举下一个字符串，
	  如果不能接龙，那么栈顶字符串弹出，当前字符串继续与弹出后的栈顶字符串比较，直到当前字符串与栈顶字符串能接成龙，然后当前字符串入栈，
	  在这期间统计栈最多有多少个元素 
	  这个思想有点类似LIS的nlogn算法 
*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,ans=0;
string s[100000+3];
stack<string> S;
bool pp(string a,string b){
	if(a.length()>b.length())return false;
	for(int i=0;i<a.length();i++)if(a[i]!=b[i])return false;
	return a.length()<b.length();
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+n+1);
	S.push(s[1]);ans=1;
	for(int i=2;i<=n;i++){
		while(!S.empty()&&!pp(S.top(),s[i]))S.pop();
		S.push(s[i]);
		ans=max(ans,(int)S.size());
	}
	cout<<ans;
	return 0;
}
