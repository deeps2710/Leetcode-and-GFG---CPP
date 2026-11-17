class BrowserHistory {
private:
    struct Node{
        string url;
        Node* prev;
        Node* next;
        Node(string s){
            url=s;
            next=nullptr;
            prev=nullptr;
        }
    };
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        //delete all forward history
        Node* temp=curr->next;
        while(temp!=nullptr){
            Node* next=temp->next;
            delete temp;
            temp=next;
        }
        //insert new page
        Node* newNode = new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=newNode;
    }
    
    string back(int steps) {
        while(steps>0 && curr->prev!=nullptr){
            curr=curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps>0 && curr->next!=nullptr){
            curr=curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
