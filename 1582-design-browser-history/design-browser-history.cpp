class Node{
    public:
    string data;
    Node* next;
    Node* back;
    Node(): data(""), next(nullptr), back(nullptr){}
    Node(string x): data(x), next(nullptr), back(nullptr){}
    Node(string x, Node* next, Node* random): data(x), next(next), back(random){};
};

class BrowserHistory {
    Node* CurrentPage;
public:
    BrowserHistory(string homepage) {
        CurrentPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        CurrentPage->next = newNode;
        newNode->back = CurrentPage;
        CurrentPage = newNode;
    }
    
    string back(int steps) {
        while(steps){
            if(CurrentPage->back) CurrentPage = CurrentPage->back;
            else break;
            steps--;
        }
        return CurrentPage->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(CurrentPage->next) CurrentPage = CurrentPage->next;
            else break;
            steps--;
        }
        return CurrentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */