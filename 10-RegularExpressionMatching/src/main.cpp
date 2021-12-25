#include<iostream>

using namespace std;
bool isMatchSingle(string s,string p,int i,int j){
    if(i<s.size()&&j<p.size()){ 
        if(s[i] == p[j] || p[j]=='.'){
            return isMatchSingle(s,p,i+1,j+1);
        } else if(p[j]=='*') {
            
            if(s[i]==s[i-1]){
                return isMatchSingle(s,p,i+1,j);
            } else if(p[j-1] == '.'){
                return true;
            } else {
                return isMatchSingle(s,p,i,j+1);
            }
        } else {
            if(j==p.size()-1){
                return false;
            } else if(p[j+1]=='*') {
                return isMatchSingle(s,p,i,j+2);
            } else {
                return false;
            }
        }
    } else {
        if(i == s.size()){
            return true;
        } else {
            return false;
        }
    }
}
int main() {
    string s = "ab";
    string p = ".*";

    bool a = isMatchSingle(s,p,0,0);
    cout<<"result="<<a<<endl;
}