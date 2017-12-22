/*
遍历问题
分析：（a代表前序，b代表后序） 
	 1.首先这里要明白一件事情，即只有一个节点下有一个子树，才可以出现两种中序遍历。
	 	找出一共有几个节点下有一棵子树，然后答案就是2^个数
	 2.求个数，可以先建立一棵树，然后寻找即可。但是这个方法复杂度高，空间高，编程长度长。所以不建议使用这种方法。
	 	通过观察前后遍历序可以发现，如果一个节点只有一棵子树，
	 	假设这个子树的位置在前序中为i，在后序中j，
	 	那么a[i-1]==b[j+1]是一定成立的。
	 	即在字符串a和b中有多少组i和j满足
	 	a[i]==a[j]&&a[i-1]==a[j+1]，
	 	设这个组数为X，那么答案就是2^X
*/
#include<iostream>
#include<cstring>
using namespace std;
char a[29],b[29];
int n,ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin>>a>>b;
	n=strlen(a);
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n;j++){
			if(a[i]==b[j]&&a[i+1]==b[j-1])ans<<=1;
		}
	}
	cout<<ans;
	return 0;
}
