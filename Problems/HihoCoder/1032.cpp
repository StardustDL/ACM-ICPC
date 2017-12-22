#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1000010;
namespace Manacher{
	int p[2*MAXN+3],_s[2*MAXN+3],len;
	void pre(char *t,int n){
		_s[0]='#';len=1;
		for(int i=0;i<n;i++){
			_s[len++]=t[i];
			_s[len++]='#';
		}
	}
	int manacher(){
		int id=0,mx=0;
		memset(p,0,sizeof(p));
		for(int i=0;i<len;i++){
			if(mx>i)p[i]=min(mx-i,p[2*id-i]);
			for(;i-p[i]>=0&&i+p[i]<len&&_s[i-p[i]]==_s[i+p[i]];)p[i]++;
			if(i+p[i]>mx)mx=i+p[i],id=i;
		}
		int ans=0;
		for(int i=0;i<len;i++)ans=max(ans,2*(p[i]-1)+1);
		return ans/2;
	}
};
char s[MAXN+3];
int n;
int main(){
    cin>>n;
    while(n--){
        cin>>s;
        Manacher::pre(s,strlen(s));
        cout<<Manacher::manacher()<<endl;
    }
    return 0;
}