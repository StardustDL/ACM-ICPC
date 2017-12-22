/*
Hanoi双塔问题
分析：通项公式是f(n)=2*(2^n-1)，可以看成是两个汉诺塔，由于n较大，用高精 
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 505;
struct bign{
	int len, s[MAXN];

	bign() {
		memset(s, 0, sizeof(s));
		len = 1;
	}
	
	bign(int num) {
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
};

ostream& operator << (ostream &out, const bign& x) {
	out << x.str();
	return out;
}

bign N;
int main(){
	int n;
	cin>>n;
	N=1;
	while(n-->0)N=N*(bign)2;
	N=N-1;
	N=N*2;
	cout<<N;
	return 0;
} 
