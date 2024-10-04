// COMSC-210 | Lab 17 | Anthony R. Sarabia
// IDE used: Github
#include <iostream> 
using namespace std;

//Constants for linked list size/format
const int SIZE = 7;  

//Struct for Node
struct Node {
    float value;
    Node *next; 
};

//Let's add some function prototypes
void output(Node *h);
void addNode(Node*&head, float value);
void deleteNode(Node*&head, float value);
void insertNode(Node*&head, int specific position, float value);
void deleteList(Node *&head);

//MAIN
int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}
// output(Node *h) Displays linked list
// Arguments: Node Pointer to head of list
// returns: void (ALREADY DONE)
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// addNode(Node*&head, float value) adds a new node to  front of list
// arguments: reference to head node & value to add
// returns: void
void addNode(Node*&head, float value){
    Node *newNode = new Node; //First, we'll dynamically allocate memory for our new node
    newNode->value = value; // Next, we assign the value that's passed through to our new node
    newNode->next = head; // now, it points the new node to current head of list
    head - newNode; // update
}

// deleteNode(Node*&head, float value) deletes a node at a specified position
// arguments: reference to head node, position to delete
// returns: true if deleted, otherwise false
void deleteNode(Node*&head, float value) {
    //If statement for input validation
if(position < 1) { 
cout << "Invalid! Must be greater than/equal to 1" << endl;
    return false;
}
}

// insertNode(Node*&head, float value) inserts a node after a set position
// arguments: reference to head node, position to insert after, value to insert
// returns:  true if inserted, otherwise false
void insertNode(Node*&head, int specific position, float value) {

}

// deleteLinkedList() deletes ENTIRE linked list
// arguments: reference to head node
// returns: void
void deleteList(Node *&head) {

}}
