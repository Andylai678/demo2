#include <iostream>
 #include <vector>
 #include <algorithm> //for max_element(), min_element()
 using namespace std;

 long long recur_eval(bool flag);
 long long value(void);
 long long f(void);
 string s0;
 int pos = 0;
 int main(void){
 ios::sync_with_stdio(0);
 cin.tie(0);
 cin >> s0;
 cout << recur_eval(false);
 return 0;
 }
 long long recur_eval(bool flag){//true for '+', false for '*'
 long long v0;
 if(isdigit(s0[pos])) v0 = value();
 else v0 = f(); //�p�� f()
 if(flag || s0[pos]==',' || s0[pos]==')') return v0;
 while(pos < s0.length()){
 if(s0[pos] == '+'){
 pos++;
 v0 += recur_eval(false);
 }else if(s0[pos] == '*'){
 pos++;
 v0 *= recur_eval(true);
 }
 if(s0[pos]==','|| s0[pos]==')') return v0;
 }
 return v0;
 }
 long long value(void){
 long long val = 0;
 while(pos<s0.length() && isdigit(s0[pos])){
 val = val*10 + s0[pos++]-'0';
 }
 return val;
 }
 long long f(void){
 vector<long long> v;
 pos += 2; //"pos++; //',' => f�V("�e =��> �ʦV�e 1�� �Ӱʦr ��2 �Ӧr��
 v.push_back(recur_eval(false));
 while(s0[pos] != ')'){
 pos++; //',' => �V�e���� 1 �Ӧr��
 v.push_back(recur_eval(false));
 }
 pos++; //')' => �V�e���� 1 �Ӧr��

 return *max_element(v.begin(), v.end())- *min_element(v.begin(), v.end());
 }
