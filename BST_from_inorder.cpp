#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000005
#define pp pair<int, int> 

int tree[4*M];
vector<pp> vec;


void construct_tree(int pre[], int n){

    stack<pp> st;
    st.push({pre[0], 0});
    tree[0] = pre[0];

    for(int i=1;i<n;i++){

        int temp = pre[i];
        int root = -1;
        int root_index = -1;

        while(!st.empty() && temp>st.top().first){
            root = st.top().first;
            root_index = st.top().second;
            st.pop();
        }

        if(root!=-1){
            tree[2*root_index+2] = temp;
            st.push({root, 2*root_index+2});
        }
        else{
            root_index = st.top().second;
            tree[2*root_index+1] = temp;
            st.push({temp, 2*root_index+1});
        }

    }
    
    return;
}

void show_tree(int n){
    for(int i=0;i<4*n;i++){cout<<tree[i]<<" ";}
    cout<<"\n";
    return;
}


int main(){

    int pre[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(pre)/sizeof(pre[0]);

    construct_tree(pre, n);
    show_tree(n);
    return 0;
}