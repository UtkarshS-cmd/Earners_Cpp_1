class Solution{
    public:
        Node* temp = head;

        while(temp->next != head){
            cout<<temp->data;
            temp = temp->next;
        }
        temp->next = NULL;
}