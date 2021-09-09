using namespace std;

class LL {
private:
    struct Node {
        int data;
        Node* next = NULL;
    };
    Node* start;
    Node* temp;
    Node* newNode;
    int n;

public:
    LL() {
        n = 0;
    }

    static void help() {
        cout<<"Linked List Class Help:"<<endl<<endl;
    }

    static void info() {
        cout<<"Linked List Class Information:"<<endl<<endl;
        cout<<"    Created by Jameel Kaisar"<<endl;
        cout<<endl;
    }

    void insert(int a, int b = -1) {
        int index;
        if (b>=0)
            index = b;
        else
            index = n+b+1;
        if (!(index>=0 && index<=n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        if (n == 0) {
            start = new Node;
            start -> data = a;
        }
        else if (index == 0) {
            newNode = new Node;
            newNode -> data = a;
            newNode -> next = start;
            start = newNode;
        }
        else {
            newNode = new Node;
            newNode -> data = a;
            temp = start;
            for (int i=1; i<index; i++)
                temp = temp -> next;
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
        n++;
    }

    void set(int a, int b) {
        int i;
        if (b>=0)
            i = b;
        else
            i = n+b;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        // array[i] = a;
    }

    int get(int a) {
        int index;
        if (a>=0)
            index = a;
        else
            index = n+a;
        if (!(index>=0 && index<n)) {
            cout<<"Invalid index!"<<endl;
            return -1;
        }
        // return array[index];
    }

    void append(int a) {
        insert(a, -1);
    }

    void print() {
        temp = start;
        cout<<temp -> data<<" ("<<temp -> next<<")";
        for (int i=1; i<n; i++) {
            temp = temp -> next;
            cout<<", "<<temp -> data<<" ("<<temp -> next<<")";
        }
        cout<<endl;
    }
};
