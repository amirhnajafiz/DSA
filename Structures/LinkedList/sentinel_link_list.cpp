#include <iostream>

using namespace std;

// Each link object is a node that we define in this class
class Node
{
    public:
        int key;
        Node* link;
        Node(int key);
};
// Node class constructor
Node::Node(int newKey) 
{
    key = newKey;
}

// Head address as a global variable
Node* head = NULL;
Node* root = NULL;

// To create the list
void initialize()
{
    root = new Node(-1);
    root->link = NULL;
    head = root;
}

// Methods of list :
// Create a node in memory and return the address
Node* create_node(int newkey)
{
    Node* temp = new Node(newkey);
    temp->link = NULL;
    return temp;
}

// Adds a new node anywhere in the list
void insert(int newKey, int index)
{
    Node* temp = root;
    for (int i = 1; i < index; i++)
    {
        temp = temp->link;
        if (temp == NULL)
            return;
    }
    Node* newNode = create_node(newKey);
    newNode->link = temp->link;
    temp->link = newNode;
    return;
}

// Removes a node at any given place from the list
void remove(int index)
{
    Node* temp = root;
    for (int i = 1; i < index; i++)
    {
        temp = temp->link;
        if (temp == NULL)
            return;
    }
    Node* temp1 = temp->link;
    temp->link = temp1->link;
    delete temp1;
}

// Reverses the link list
void reverse(Node* current)
{
    if (current->link == NULL)
    {
        root->link = current;
        current->link = NULL;
        return;
    }
    reverse(current->link);
    current->link->link = current;
    current->link = NULL;
    return;
}

// Returns the size of the linked list
int size()
{
    int x = 0;
    Node* current = root->link;
    while (current != NULL)
    {
        current = current->link;
        x++;
    }
    return x;
}

// Sortes the linked list based on the keys
void sort()
{
    int len = size();
    if (len == 1)
        return;
    for (int i = len-1; i > 0; i--)
    {
        Node* current = root->link;
        for (int j = 0; j < i; j++)
        {
            if (current->key > current->link->key)
            {
                int holder = current->key;
                current->key = current->link->key;
                current->link->key = holder;
            }
            current = current->link;
        }
    }    
    
}

// Prints the linked list objects
void print_list()
{
    Node* temp = root->link;
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->link;
    }
    cout << endl;
}

// A test case
int main() 
{
    initialize();
    insert(3, 1); // Expect only 3 in list
    insert(10, 1);
    insert(11, 1);
    insert(2, 1);
    print_list(); // Expect 2 11 10 3 in order
    remove(1); // Expect 11 10 3
    print_list();
    insert(5, 1); // Expect 5 11 10 3
    insert(6, 3); // Expect 5 11 6 10 3
    print_list();
    remove(5);
    remove(1); // Expect 11 6 10
    print_list();
    reverse(root->link); // Expect 10 6 11
    print_list();
    insert(5, 1); 
    reverse(root->link);
    print_list(); // Expect 11 6 10 5
    cout << size() << endl; // Expect 4
    sort();
    print_list(); // Expect 5 6 10 11
    return 0;
}