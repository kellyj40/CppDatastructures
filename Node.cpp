#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
    Node(0);
}
Node::Node(int tempValue)
{
    value = tempValue;
    next = NULL;
    //ctor
}

