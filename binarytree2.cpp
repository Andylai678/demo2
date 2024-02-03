#include<bits/stdc++.h>
using namespace std;
void recur_pre(string infix, string postfix);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string infix,postfix;
	getline(cin,infix);
	getline(cin,postfix);
	recur_pre(infix,postfix);
}
void recur_pre(string infix, string postfix){
	int infixrootpos;
	string infixL,infixR;
	string postfixL,postfixR;
	
	if(infix=="")return;
	cout<<postfix[postfix.size()-1];
	infixrootpos=infix.find(postfix[postfix.size()-1]);
	
	infixL=infix.substr(0,infixrootpos);
	infixR=infix.substr(infixrootpos+1);
	postfixL=postfix.substr(0,infixL.length());
	postfixR=postfix.substr(infixL.length(),infixR.length());
	
	recur_pre(infixL,postfixL);
	recur_pre(infixR,postfixR);
}
