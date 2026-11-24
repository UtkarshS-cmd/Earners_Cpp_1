#include<iostream>
#include<queue>
using namespace std;
 
int main(){
 priority_queue<int> pq; //maxHeap
//   priority_queue<int,vector<int>,greater<int>> pq; //minHeap
 pq.push(5);
 cout<<pq.top()<<endl; //5
 pq.push(3);
 cout<<pq.top()<<endl; //5
 pq.push(8);
 cout<<pq.top()<<endl; //8
 pq.push(7);
 cout<<pq.top()<<endl; //8
 pq.pop(); //8 will be removed(max element is removed)
 cout<<pq.top()<<endl; //7
 cout<<pq.size()<<endl; //3
return 0;
}