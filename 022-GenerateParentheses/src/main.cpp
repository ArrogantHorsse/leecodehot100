#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void drawParenthesis(int i,int j,int n,string &s,vector<string> &result) {
    if(s.size() == 2*n) {
        // 已经画完
        if(*(s.rbegin())== '(') {
            return;
        }
        result.push_back(s); 
        return;
    } 
    if(i>n) {
        return;
    }
    if(j > i){
        return;
    } else {
        s.push_back('(');
        drawParenthesis(i+1,j,n,s,result);
        s.pop_back();

        s.push_back(')');
        drawParenthesis(i,j+1,n,s,result);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    int i = 0;
    int j = 0;
    string s = "";
    vector<string> result;
    drawParenthesis(0,0,n,s,result);

    for(auto a : result) {
        cout<<a<<endl;
    }
    
    return  result;
}

int main() {
    cout<<"请输入要生成的括号对数："<<endl;
    int n;
    cin>>n;
    vector<string> parenthesis = generateParenthesis(n);

    return 0;
}