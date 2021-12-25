#include<iostream>
#include<string>
#include<stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

bool isValid(string s) {
    if(s.size()==0){
        return true;
    }
    if(s.size()==1){
        return false;
    }
    stack<char> mystack;
    for(int i=0;i<s.size();i++) {
        if(i>0){
            if(s[i-1] == '('&&(s[i]==']'||s[i]=='}')){
                cout<<"aaa"<<endl;
                return false;
            }
            if(s[i-1] == '['&&(s[i]==')'||s[i]=='}')){
                cout<<"bbb"<<endl;
                return false;
            }
            if(s[i-1] == '{'&&(s[i]==')'||s[i]==']')){
                cout<<"ccc"<<s[i-1]<<" "<<s[i]<<endl;
                return false;
            }
        }
        if(mystack.empty()){
            mystack.push(s[i]);
        } else {
            if(mystack.top() == '('&&s[i]==')'){
                mystack.pop();
            } else if(mystack.top() == '['&&s[i]==']') {
                mystack.pop();
            } else if(mystack.top() == '{'&&s[i]=='}') {
                mystack.pop();
            } else {
                mystack.push(s[i]);
            }
        }
    }
    return mystack.empty()?true:false;
}

int main(){
    string s = "()[]{}";
    bool a = isValid(s);
    if(a) {
        cout<<"Valid!!!!"<<endl;
    } else {
        cout<<"Invalid!!!!"<<endl;
    }
}