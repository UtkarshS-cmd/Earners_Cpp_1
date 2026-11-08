#include<iostream>
#include<queue>
using namespace std;

void pushAtIdx(int idx, int ele, queue<int>& q){
    int n = q.size();
    for(int i=1;i<=idx;i++){
        q.push(q.front());
        q.pop();
    }
    q.push(ele);
    for(int i=1;i<=n-idx;i++){
        q.push(q.front());
        q.pop();
    }
}
void popAtIdx(int idx, queue<int>& q){
    int n = q.size();

    if(idx < 0 || idx >= n){
        cout<<"Invalid index"<<endl;
        return;
    }

    for(int i = 0; i < idx; i++){
        q.push(q.front());
        q.pop();
    }


    q.pop(); // pop ele at index

    for(int i = 0; i < n - idx - 1; i++){
        q.push(q.front());
        q.pop();
    }

}

int getAtIdx(int idx, queue<int>& q){
    int n = q.size();    

    if(idx < 0 || idx >= n){
        cout<<"Invalid index"<<endl;
        return -1;
    }

    int ans = -1;

    for(int i = 0; i < n; i++){
        int curr = q.front();
        q.pop();

        if(i == idx){
            ans = curr;
        }
        q.push(curr);
    }
    return ans;
}

void print(queue<int>& q){
    int n = q.size();
    while(n--){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(10); // add at back
    q.push(20);
    q.push(30);
    print(q);
    q.pop(); // remove the front
    q.push(40);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    print(q); // 20 30 40
    pushAtIdx(1,50,q);
    print(q); // 20 50 30 40
}