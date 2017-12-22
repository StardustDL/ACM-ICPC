/*
×Ö·ûÅä¶Ô
*/
#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
int a[26],ans=0;
char c;
int main(){
	memset(a,0,sizeof(a));
	while(cin>>c)
		if(islower(c))a[c-'a']++;
	for(int i=0;i<26;i++)
		if(a[i]&1)ans++;
	cout<<ans;
	return 0;
}
