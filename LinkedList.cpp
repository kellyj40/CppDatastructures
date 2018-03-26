#include "LinkedList.h"
#include "Node.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    //ctor
}

void LinkedList::add(int val)
{
    Node *newestNode = new Node; // Pointer to a location for a new node
    newestNode -> value = val; // Set the value for that node

    // Update  head and tail whhere applicable
    if (head == NULL){
        cout << "head value: "<< head << endl;
        head = newestNode;
        tail = newestNode;
    }else{
        cout << "not null: "<< endl;
        tail -> next = newestNode;
        tail = newestNode;
    }
}
