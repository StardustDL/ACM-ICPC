/*
整数的幂运算 2
分析：高精+快速幂 
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 3503;//1000^1000有3000多个0 
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

	bign operator = (const char* num) {
		len = strlen(num);
		for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
		return *this;
	}

	string str() const {
		string res = "";
		for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if(res == "") res = "0";
		return res;
	}

	void clean() {
		while(len > 1 && !s[len-1]) len--;
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
bign ksm(bign a,int n){
	bign ans=1;
	while(n|0){
		if(n&1)ans=ans*a;
		a=a*a;
		n>>=1;
	}
	return ans;
}
bign m;int n;
int main(){
	cin>>m>>n;
	cout<<ksm(m,n);
	return 0;
}
