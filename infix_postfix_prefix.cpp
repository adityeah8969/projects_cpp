#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int precedence(char temp){
    if(temp=='^'){return 3;}
    if(temp=='/' || temp == '*'){return 2;}
    if(temp=='+' || temp == '-'){return 1;}
    return -1;
}

bool is_char(char temp){return (temp>='a' && temp<='z');}

bool is_operator(char temp){return (temp =='%' || temp =='*' || temp =='+' || temp =='-' || temp =='/');}

// inside stack precedence order of the operators should be in increasing order from bottom to top
string infix_to_postfix(string exp){

    int len = exp.length();
    string ans="";

    stack<char> st;

    for(int i=0;i<len;i++){
        if(is_char(exp[i])){ans+=exp[i];continue;}
        if(exp[i] == '('){st.push(exp[i]);continue;}
        if(exp[i] == ')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty() && st.top()=='('){st.pop();}
            continue;                                   // * continue
        }

        while(!st.empty() && precedence(st.top()) >= precedence(exp[i])){
                ans+=st.top();
                st.pop();
        }
        st.push(exp[i]);
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

// reverse the infix expression (taking care of '(' & ')')
// get the postfix expression corresponding to the reversed infix
// reverse the postfix expression obtained and return the same
string infix_to_prefix(string infix) { 

    int len = infix.size(); 
    reverse(infix.begin(), infix.end()); 

    for (int i = 0; i < len; i++) { 
        if (infix[i] == '(') { infix[i] = ')';continue;}       // * continue
        if (infix[i] == ')') { infix[i] = '(';continue;}       // * continue
    } 
  
    string prefix = infix_to_postfix(infix); 
    reverse(prefix.begin(), prefix.end()); 
  
    return prefix; 
} 

string prefix_to_infix(string exp){

    stack<string> st;
    int len = exp.length();

    string char_string;
    for(int i=len-1;i>=0;i--){                  // prefix : len-1 -> 0 
        if(is_operator(exp[i])){

            string string1 = st.top(); st.pop();
            string string2 = st.top(); st.pop();

            string temp_string = "";
            temp_string += string1;             // str1 (exp) str2
            temp_string += exp[i];
            temp_string += string2;

            st.push(temp_string);
        }
        else{
            char_string = "";
            char_string+=exp[i];
            st.push(char_string);
        }
    }
    return st.top();
}


string postfix_to_infix(string exp){

    stack<string> st;
    int len = exp.length();

    string char_string;
    for(int i=0;i<len;i++){                     // postfix : 0 -> len-1 
        if(is_operator(exp[i])){

            string string1 = st.top(); st.pop();
            string string2 = st.top(); st.pop();

            string temp_string = "";
            temp_string += string2;             // str2 (exp) str1
            temp_string += exp[i];
            temp_string += string1;
            
            st.push(temp_string);
        }
        else{
            char_string = "";
            char_string+=exp[i];
            st.push(char_string);
        }
    }
    return st.top();
}

string prefix_to_postfix(string exp){

    stack<string> st;
    int len = exp.length();

    string char_string;
    for(int i=len-1;i>=0;i--){                  // prefix : len-1 -> 0 
        if(is_operator(exp[i])){

            string string1 = st.top(); st.pop();
            string string2 = st.top(); st.pop();

            string temp_string = "";            // str1  str2 (exp)
            temp_string += string1;
            temp_string += string2;
            temp_string += exp[i];

            st.push(temp_string);
        }
        else{
            char_string = "";
            char_string+=exp[i];
            st.push(char_string);
        }
    }
    return st.top();
}


string postfix_to_prefix(string exp){

    stack<string> st;
    int len = exp.length();

    string char_string;
    for(int i=0;i<len;i++){                     // postfix : 0 -> len-1 
        if(is_operator(exp[i])){

            string string1 = st.top(); st.pop();
            string string2 = st.top(); st.pop();

            string temp_string = "";
            temp_string += exp[i];              // (exp) str2  str1 
            temp_string += string2;
            temp_string += string1;
            
            st.push(temp_string);
        }
        else{
            char_string = "";
            char_string+=exp[i];
            st.push(char_string);
        }
    }
    return st.top();
}


int main(){

    string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    cout<<infix_to_postfix(exp);
    cout<<"\n";

    exp = "(a-b/c)*(a/k-l)";
    cout<<infix_to_prefix(exp);
    cout<<"\n";

    exp = "*-A/BC-/AKL";
    cout<<prefix_to_infix(exp);
    cout<<"\n";
    
    exp = "*-A/BC-/AKL";
    cout<<prefix_to_postfix(exp);
    cout<<"\n";

    exp = "ABC/-AK/L-*";
    cout<<postfix_to_prefix(exp);
    cout<<"\n";

    exp = "ab*c+";
    cout<<postfix_to_infix(exp);
    cout<<"\n";

    
    
    return 0;
}