/*
矩阵取数游戏
分析：对于n行输入，各行之间的独立的，只需要找到各行的最大值即可。它们的和即为所求。
	  对于输入的任一行a[m]，第x次取数的状态转移为：
	  dp[i][j] = max{dp[i+1][j]+a[i]*2^x, dp[i][j-1]+a[j]*2^x};
	  dp[i][j]表示每行第i到j个数可得到的最大值。
	  其中的高精度乘法和加法部分，采用int数组，每个数最大100000-1，相当于100000进制，节省空间。 
*/

#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;
int n,m,a[81];
int f[81][81][31];
int ys[81][31];
int ans[31];
int c[31];
void mul(int *x,int *y,int z){
    memset(c,0,sizeof(c));
    c[0]=y[0];
    for(int i=1;i<=c[0];++i)
        c[i]=y[i]*z;
    for(int i=1;i<=c[0];++i){
        c[i+1]+=c[i]/100000;
        c[i]%=100000;
    }
    while(c[c[0]+1]){
        c[0]++;
        c[c[0]+1]+=c[c[0]]/100000;
        c[c[0]]%=100000;
    }
    for(int i=0;i<=30;++i) x[i]=c[i];
}
void add(int *x,int *y,int *z){
    memset(c,0,sizeof(c));
    if(y[0]>z[0]) c[0]=y[0];
    else c[0]=z[0];
    for(int i=1;i<=c[0];++i)
        c[i]=y[i]+z[i];
    for(int i=1;i<=c[0];++i){
        c[i+1]+=c[i]/100000;
        c[i]%=100000;
    }
    if(c[c[0]+1]) c[0]++;
    for(int i=0;i<=30;++i) x[i]=c[i];
}
bool MAX(int *x,int *y){
    if(x[0]>y[0]) return 1;
    else if(y[0]>x[0]) return 0;
    else{
        for(int i=x[0];i>=1;--i)
        if(x[i]>y[i]) return 1;
        else if(y[i]>x[i]) return 0;
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    ys[0][0]=1; ys[0][1]=1;
    for(int i=1;i<=m;++i)
        mul(ys[i],ys[i-1],2);
    ans[0]=1; ans[1]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&a[j]);
            mul(f[j][j],ys[m],a[j]);
        }
        for(int k=2;k<=m;++k)
            for(int lx=1;lx<=m-k+1;++lx){
                int ly=lx+k-1,ll;
                int xm[31],ym[31],cm[31];
                ll=ly;
                mul(cm,ys[m-k+1],a[lx]);
                ly=ll;//不记录一下ly会莫名的变成0，xm的值也是一样。???
                add(xm,cm,f[lx+1][ly]);
                mul(ym,ys[m-k+1],a[ly]);
                add(ym,ym,f[lx][ly-1]);
                if(MAX(xm,ym))
                    memcpy(f[lx][ly],xm,sizeof(int)*31);
                else
                    memcpy(f[lx][ly],ym,sizeof(int)*31);
            }
        add(ans,ans,f[1][m]);
    }
    printf("%d",ans[ans[0]]);
    for(int i=ans[0]-1;i>=1;--i) printf("%05d",ans[i]);
    printf("\n");
    return 0;
}

/*60分 
#include<iostream>
#include<cstring>
#include<cstdio> 
using namespace std;

namespace Bign{

const int MAXN = 21;
struct bign{
	int len, s[MAXN];

	bign() {
		memset(s, 0, sizeof(s));
		len = 1;
	}

	bign(int num) {
	  *this = num;
	}

	bign(const char* num) {
		*this = num;
	}

	bign operator = (int num) {
		char s[MAXN];
		sprintf(s, "%d", num);
		*this = s;
	 	return *this;
	}
	
	void clean() {
		while(len > 1 && !s[len-1]) len--;
	}

	bign operator = (const char* num) {
		len = strlen(num);
		for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
		clean(); 
		return *this;
	}

	string str() const {
		string res = "";
		for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if(res == "") res = "0";
		return res;
	}

	bign operator + (const bign& b) const{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
			int x = g;
			if(i < len) x += s[i];
			if(i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		c.clean();
		return c;
	}

	bign operator * (const bign& b) {
		bign c; c.len = len + b.len;
		for(int i = 0; i < len; i++)
			for(int j = 0; j < b.len; j++)
				c.s[i+j] += s[i] * b.s[j];
		for(int i = 0; i < c.len-1; i++){
			c.s[i+1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}

	bign operator - (const bign& b) {
		bign c; c.len = 0;
		for(int i = 0, g = 0; i < len; i++) {
			int x = s[i] - g;
			if(i < b.len) x -= b.s[i];
			if(x >= 0) g = 0;
			else {
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}

	bool operator < (const bign& b) const{
		if(len != b.len) return len < b.len;
		for(int i = len-1; i >= 0; i--)
			if(s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}

	bool operator > (const bign& b) const{
		return b < *this;
	}

	bool operator <= (const bign& b) {
		return !(b > *this);
	}

	bool operator == (const bign& b) {
		return !(b < *this) && !(*this < b);
	}

	bign operator += (const bign& b) {
		*this = *this + b;
		return *this;
	}
};

istream& operator >> (istream &in, bign& x) {
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const bign& x) {
	out << x.str();
	return out;
}

} 

typedef Bign::bign num;
const int MAXN=81;
const num two=2;

template<typename T>
T Max(T a,T b){
	return a<b?b:a;
}

int n,m;
num opt[MAXN][MAXN],mp[MAXN],ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[j];opt[j][j]=mp[j]*2;
		}
		for(int len=2;len<=m;len++){
			for(int k=1;k+len-1<=m;k++){
				int j=k+len-1;
				opt[k][j]=Max(opt[k+1][j]+mp[k],opt[k][j-1]+mp[j]);
				opt[k][j]=opt[k][j]+opt[k][j];
			}
		}
		ans=ans+opt[1][m];
	}
	cout<<ans;
	return 0;
}*/
