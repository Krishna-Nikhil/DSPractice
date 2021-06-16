#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse1(string s) {
    int len = s.length();
    string token = "";
    for(int i =0; i<=len; i++) {
        if(s[i] != ' ' && i != len) {
            token = token+s[i];
        } else {
            for(int j = token.length()-1; j>=0; j--) {
                cout << token[j];
            }
            cout << " ";
            token = "";
        }
    } cout << endl;
}

void reverse2(string s) {
    vector<string> tok;
    int len = s.length();
    string token = "";
    for(int i =0; i<=len; i++) {
        if(s[i] != ' ' && i != len) {
            token = token+s[i];
        } else {
            tok.push_back(token);
            token = "";
        }
    }
    for(auto x = tok.rbegin(); x != tok.rend(); x++)
        cout << *x << " ";
    
    cout << endl;
}

void reverse3(string s) {
    for(int j = s.length(); j >=0; j--) {
        cout << s[j];
    }
}

int main()
{
    string s = "Hi, I'm Krishna Nikhil";
    
    cout << s << endl;    

    reverse1(s); //Reversing the words without reversing the order
    
    reverse2(s); //Reversing the order of words without reversing the words
    
    reverse3(s); //Reversing the words as well as their order
 
    return 0;
}
