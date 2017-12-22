/*
Subway tree systems
题意：给出两棵树的遍历序列，判断两棵树是否是同构的
分析：用树的最小表示法去做。这里用的最小表示法就是将树的所有子树分别用1个字符串表示，要按字典序排序将他们依依连接起来。连接后如果两个字符串是一模一样的，那么他们必然是同构的。这样原问题就变成了子问题，子树又是一颗新的树。
	  这样会比较慢，另一种类似的方法是：建树时把每个节点的深度，子节点数记下来，排个序比一下就可以判断同构。 
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

