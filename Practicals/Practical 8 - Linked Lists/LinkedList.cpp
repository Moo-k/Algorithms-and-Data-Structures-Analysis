#include "LinkedList.h"

LinkedList::LinkedList(){
  head = NULL;
}

LinkedList::LinkedList(int array[], int size){ // cant handle 2 linked lists??????????
  for (int i = 0; i < size; i++){
    addEnd(*(array+i));
  }
}

void LinkedList::addFront(int newItem){
  head = new Node(newItem,head);
}

void LinkedList::addEnd(int newItem){
  if (head==NULL){
    head = new Node(newItem);
    return;
  } else if (head->getNext()==NULL){
    head->setNext(new Node(newItem,NULL));
    return;
  }
  Node *temp = head;
  while (temp->getNext()!=NULL){
    temp = temp->getNext();
  }
  temp->setNext(new Node(newItem,NULL));
}

void LinkedList::addAtPosition(int position, int newItem){
  if (position <= 1){
    addFront(newItem);
    return;
  } else{
    Node *temp = head;
    for (int i = 1; i < position; i++){ // starting from position 1 (head)
      if (temp->getNext()==NULL){
        addEnd(newItem);
        return;
      }
      temp = temp->getNext();
    }
    temp = head;
    for (int i = 1; i < position-1; i++){ // find node before insertion
      temp = temp->getNext();
    }
    Node* temp2 = temp->getNext(); // address of node after new
    temp->setNext(new Node(newItem)); // set node before to link to new
    temp = temp->getNext(); // new item
    temp->setNext(temp2);
  }
}

int LinkedList::search(int item){
  if (head->getData()==item){
    std::cout << "1 ";
    return 1;
  }
  Node *temp = head->getNext();
  int count = 2;
  while (temp->getNext()!=NULL){
    if (temp->getData()==item){
      std::cout << count << " ";
      return count;
    }
    count++;
    temp=temp->getNext();
  }
  if (temp->getData()==item){
    std::cout << count << " ";
    return count;
  }
  std::cout << 0 << " ";
  return count;
}

void LinkedList::deleteFront(){
  if (head == NULL){
    return;
  }
  Node* temp = head;
  head = head->getNext();
  free(temp);
}

void LinkedList::deleteEnd(){
  if (head == NULL){
    return;
  } else if(head->getNext()==NULL){
    free(head);
    head = NULL;
    return;
  }
  Node *temp = head;
  int length = 1;
  while (temp->getNext()!=NULL){
    temp = temp->getNext();
    length++;
  }
  temp = head;
  for (int i = 1; i < length-1; i++){
    temp = temp->getNext();
  }
  free(temp->getNext());
  temp->setNext(NULL);
}

void LinkedList::deletePosition(int position){
  if (head == NULL){
    return;
  } else if (position < 1){
    std::cerr << "outside range";
    return;
  } else if (position == 1){
    deleteFront();
    return;
  }
  Node *temp = head;
  for (int i = 1; i < position-1; i++){ // end up at node before one to be deleted
    if ((temp->getNext()==NULL)|((temp->getNext())->getNext()==NULL)){
      std::cerr << "outside range";
      return;
    }
    temp = temp->getNext();
  }
  Node *temp2 = (temp->getNext())->getNext();
  free(temp->getNext());
  temp->setNext(temp2);
}

int LinkedList::getItem(int position){
  if (position < 1){
    std::cout << std::numeric_limits < int >::max() << " ";
    return std::numeric_limits < int >::max();
  } else if (position == 1){
    std::cout << head->getData() << " ";
    return head->getData();
  }
  Node *temp = head;
  for (int i = 1; i < position; i++){ // end up at node at position
    if (temp->getNext()==NULL){
      std::cout << std::numeric_limits < int >::max() << " ";
      return std::numeric_limits < int >::max();
    }
    temp = temp->getNext();
  }
  std::cout << temp->getData() << " ";
  return temp->getData();
}

void LinkedList::printItems(){
  if (head==NULL){
    return;
  }
  Node *temp = head;
  std::cout << temp->getData() << " ";
  while (temp->getNext()!=NULL){
    temp = temp->getNext();
    std::cout << temp->getData() << " ";
  }
  std::cout << std::endl;
}

LinkedList::~LinkedList(){
  while (head){
    deleteFront();
  }
}
