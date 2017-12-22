/*
Computer Transformation
题意：开始的数字是1，每次1变为01,0变为10，问经过n步后，有多少对连续的0，即多少对00.
分析：数据不大：1000，打表观察：发现ans[i]=ans[i-1]*2+{1|i is even,-1|i is odd}
	  高精处理 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
char temp[MAXN+3];
struct bign{
	int v[MAXN+3],len;
	bign(){init();}
	void init(){len=1;memset(v,0,sizeof(v));}
	void set(int t){
		init();
		for(len=1;t;len++,t/=10)v[len-1]=t%10;
	}
	void adjust(){
		for(int i=0;i<len;i++){
			if(v[i]>9){
				v[i+1]+=v[i]/10;
				v[i]%=10;
			}
			if(v[len])len++;
		}
		while(!v[len-1]&&len>1)len--;
	}
	void add(){
		v[0]++;
		adjust();
	}
	void minus(){
		v[0]--;
		for(int i=0;i<len;i++){
			if(v[i]<0)v[i]+=10,v[i+1]--;
			else break;
		}
		adjust();
	}
	bign operator *(const int t)const{
		bign ans;
		ans=*this;
		for(int i=0;i<len;i++){
			ans.v[i]*=t;
		}
		ans.adjust();
		return ans;
	}
	void input(){
		init();
		scanf("%s",temp);
		len=strlen(temp);
		for(int i=len;i;i--){
			v[len-i]=temp[i-1]-'0';
		}
	}
	void output(){
		for(int i=len-1;i>=0;i--)putchar(v[i]+'0');
	}
};
bign Table[1001];
inline void build(){
	Table[1].set(0);
	for(int i=2,t;i<=1000;i++){
		Table[i]=Table[i-1]*2;
		if(i&1)Table[i].minus();
		else Table[i].add();
		//Table[i].output();cin>>t;
	}
}
int main(){
	int n;build();
	while(~scanf("%d",&n)){
		Table[n].output();puts("");
	}
	return 0;
}
/*
Table：
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
int s1[1000];
int s2[1000];
int main()
{
    int i=0;
    memset(s1,-1,sizeof(s1));
    memset(s2,-1,sizeof(s2));
    s1[0]=1;
    while(i<10)
    {
        i++;
        int cc=0;
        for(int j=0;;j++)
        {
            if(s1[j]!=-1)
            {
                if(s1[j]==0) {s2[cc++]=1;s2[cc++]=0;}
                else {s2[cc++]=0;s2[cc++]=1;}
            }
            else break;
        } 
        int count=0;
        for(int j=0;j<cc-1;j++)
        {
            if(s2[j]==0&&s2[j+1]==0)
            count++;
        }
        cout<<i<<" "<<count<<endl;
        for(int j=0;j<cc;j++)
        s1[j]=s2[j];
    }
}
 
*/ 

