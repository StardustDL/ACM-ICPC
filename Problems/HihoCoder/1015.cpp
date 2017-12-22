#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1000000;
namespace KMP{
	int fail[MAXN+3],lenS;
	char *S;
	void pre(char *s,int n){
		S=s;lenS=n;
		fail[0]=fail[1]=0;
		for(int i=1;i<n;i++){
			int j=fail[i];
			while(s[i]!=s[j] && j)j=fail[j];
			fail[i+1]=s[i]==s[j]?j+1:0;
		}
	}
	int kmp(char *t,int n){
		int j=0;int cnt=0;
		for(int i=0;i<n;i++){
			while(t[i]!=S[j] && j)j=fail[j];
			if(t[i]==S[j])j++;
			if(j==lenS){cnt++;j=fail[j];}
		}
		return cnt;
	}
}
char s[MAXN+3],t[MAXN+3];
int n;
int main(){
    cin>>n;
    while(n--){
        cin>>s>>t;
        KMP::pre(s,strlen(s));
        cout<<KMP::kmp(t,strlen(t))<<endl;
    }
    return 0;
}