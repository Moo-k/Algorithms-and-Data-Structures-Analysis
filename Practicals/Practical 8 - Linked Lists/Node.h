#pragma once
#include <iostream>

class Node{
public:
    Node();
    Node(int inputdata);
    Node(int inputdata, Node *next);
    int getData();
    void setData(int input);
    Node *getNext();
    void setNext(Node *input);
    int data;
    Node *next;
};
