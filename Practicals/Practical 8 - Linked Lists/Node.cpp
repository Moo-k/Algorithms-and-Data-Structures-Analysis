#include "Node.h"

Node::Node(){
  next = NULL;
}

Node::Node(int inputdata){
  next = NULL;
  data = inputdata;
}

Node::Node(int inputdata, Node *inputnode){
  data = inputdata;
  next = inputnode;
}

int Node::getData(){
  return data;
}

void Node::setData(int input){
  data = input;
}

Node *Node::getNext(){
  return next;
}

void Node::setNext(Node *input){
  next = input;
}
