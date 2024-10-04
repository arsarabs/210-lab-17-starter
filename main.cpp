// COMSC-210 | Lab 17 | Anthony R. Sarabia
// IDE used: Github & Visual
#include <iostream> 
using namespace std;

//Constants for linked list size/format
const int SIZE = 7;

//Struct for Node
struct Node {
    float value;
    Node* next;
};

//Let's add some function prototypes
void output(Node* h);
void addNode(Node*& head, float value);
bool deleteNode(Node*& head, float value);
bool insertNode(Node*& head, int specificPosition, float value);
void deleteList(Node*& head);

//MAIN
int main() {
    Node* head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addNode(head, static_cast<float>(tmp_val));
    }
    output(head);

    // deleting a node
    
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // Attempts to delete the specified node and displays the list if successful
    if (deleteNode(head, entry)) {
        output(head); // Displays the list after deletion
    }

    // Inserting a node
    cout << "After which node to insert 10000? " << endl;
    count = 1; // Resets the counter for displaying node positions
    Node* current = head; // Temporary pointer to traverse the list

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    // Displays the current list with node positions for insertion reference
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next; // Moves to the next node
    }
    cout << "Choice --> ";
    cin >> entry; // Takes user input for the node position after which to insert

    // Attempts to insert the new node and displays the list if successful
    if (insertNode(head, entry, 10000)) {
        output(head); // Displays the list after insertion
    }

    // Deleting the entire linked list
    deleteList(head); // Deletes all nodes in the list
    output(head); // Confirms that the list is now empty

  
    return 0;
}
// output(Node *h) Displays linked list
// Arguments: Node Pointer to head of list
// returns: void (ALREADY DONE)
void output(Node* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// addNode(Node*&head, float value) adds a new node to  front of list
// arguments: reference to head node & value to add
// returns: void
void addNode(Node*& head, float value) {
    Node* newNode = new Node; //First, we'll dynamically allocate memory for our new node
    newNode->value = value; // Next, we assign the value that's passed through to our new node
    newNode->next = head; // now, it points the new node to current head of list
    head - newNode; // update
}

// deleteNode(Node*&head, float value) deletes a node at a specified position
// arguments: reference to head node, position to delete
// returns: true if deleted, otherwise false
bool deleteNode(Node*& head, float specificPosition) {
    //If statement for input validation
    if (specificPosition < 1) {
        cout << "Invalid! Must be greater than/equal to 1" << endl;
        return false;
    }
    Node* current = head; //ptr to transverse
    Node* previous = nullptr; //to keep track of previous node

    //Now, we need to traverse list to reach a specific position
    //so we'll use a for-loop
    for (int i = 1; i < specificPosition && current != nullptr; i++) {
        previous = current; // this updates previous node
        current = current->next; //& now it moves to the next node
    }

    //Now, if previous is nullptr, then we know we're deleting head node
    if (!previous) {
        head = current->next; //update
    }
    else {
        previous->next = current->next; //By pass current node
    }
    delete current; //deallocate to prevent memory leaks
    return true;
}

// insertNode(Node*&head, float value) inserts a node after a set position
// arguments: reference to head node, position to insert after, value to insert
// returns:  true if inserted, otherwise false
bool insertNode(Node*& head, int specificPosition, float value) {
    //If statement for input validation
    if (specificPosition < 0) {
        cout << "Invalid! Must be greater than/equal to 0" << endl;
        return false;
    }
    Node* current = head; //ptr to transverse
    //Now, we need to traverse list. New node is inserted once we reach the node.
    //so we'll use a for-loop
    for (int i = 1; i < specificPosition && current != nullptr; i++) {
        current = current->next; // this moves to next node over
    }

    //Some more input validaton: 
    if (current && specificPosition != 0) {
        cout << "Position: " << specificPosition << " does not exist" << endl;
        return false;
    }

    Node* newNode = new Node; //Let's dynamically allocate memory 
    newNode->value = value; // in order to assign our given value to new node
    newNode->next = current ? current->next : nullptr; // and then we'll set it to the next pointer
    //// If current is not nullptr, insert after it
    if (current) {
        current->next = newNode; //Assigns the given value to new node
    }
    else {
        head = newNode; // this links the new node
    }
    return true;
}

// deleteLinkedList() deletes ENTIRE linked list
// arguments: reference to head node
// returns: void
void deleteList(Node*& head) {
    Node* current = head; // Pointer to traverse the list
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
