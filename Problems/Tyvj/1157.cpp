/*
阿达马矩阵2
分析：假设
		(x - 1)10 = (a)2 
		(y - 1)10 = (b)2
		答案就等于a位与b后1的个数是否为0
		先用高精度二进制转换 
*/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 20000 + 10;
int k;
char buff[maxn];
struct Integer10 {
	int len, a[maxn];
	inline void read(){
        memset(a,0,sizeof a);
        scanf("%s",buff);
		len=strlen(buff);
		for(int i=0;i<len;i++)a[len-i]=buff[i]-48;
	}
	inline void div2(){
		for(int i=len,c=0;i>=1;i--){
			c=a[i]+c*10;
			a[i]=c/2;
			c%=2;
		}
		while (a[len]==0&&len)--len;
	}
	inline void subone(){
		if(a[1])a[1]--;
		else{
			int pos;
			for(int i=2;i<=len;i++)
				if(a[i]){
					a[pos=i]--;
					break;
				}
			for(int i=1;i<pos;i++)a[i]=9;
		}
	}
	inline bool zero(){
		return (!len||len==1)&&a[1]==0;
	}
}temp_x,temp_y;
struct Integer2{
	int len, a[maxn];
}x,y;
void convert(Integer2& to, Integer10 a){
	a.read();
	a.subone();
	while(!a.zero()){
		to.a[++ to.len] = a.a[1] & 1;
		a.div2();
	}
}
int main(){
	scanf("%d", &k);
	convert(x,temp_x);
	convert(y,temp_y);
	int count=0;
	for (int i=k;i>=1;i--)count^=x.a[i]&y.a[i];
	puts(count ? "0" : "1");
}
