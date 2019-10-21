#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>     // std::next, std::prev

using std::string;

template <typename T>
struct Node {
  T data;
  Node<T>* next;
  Node <T>* prev;

  Node() = delete;
  Node (const T & element) : data(element), next(nullprt), prev(nullptr) {}
};

class Website {
public:
  string uniform_rl;
  size_t page_size;

  Website(string url, size_t pgsize) : uniform_rl(url), page_size(pgsize) {}
  Website() {}
};

class BrowserHistory {
public:
    BrowserHistory();
    void backButton();
    void forwardButton();
    void visit(string url, size_t pagesize);
    void readFile(string fileName);
    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();
private:
  // TO BE COMPLETED
  Node<Website>* head;
  Node<Website>* tail;
  size_t length_;
  size_t adding_ = 0;
  Node<Website>* currNode;
};

BrowserHistory :: BrowserHistory() {
  head = new Node<Website>(Website());
  tail = new Node<Website>(Website());
  head->next = tail;
  tail->prev = head;
}

//current webpage changes to the previous one in the visit sequence
void BrowserHistory :: backButton() {
  if(currNode->prev == head) {
    std::cout << "No Previous Page/n";
  }
  else {
    currNode = currNode->prev;
    adding++;
  }
}

//current ewebpage changes to the next one in the visit sequence
void BrowserHistory :: forwardButton() {
  if(currNode->next == tail) {
    std::cout << "No Such Page'n";
  }
  else {
    currNode = currNode->next;
    adding_--;
  }
}

//user visits a webpage with the given URL and web page size 
void BrowserHistory :: visit(string url, size_t pagesize) {
  Website New;
  New.uniform_rl = url;
  New.page_size = pagesize;
  if(adding_ > 0) {
    while(adding_ > 0 && adding_ != 0) {
      remove(tail->prev);
      adding_--;
    }
  }
  Node<Website>* newNode = new Node<Website>(New);
  newNode->prev = tail->prev;
  newNode->next = tail;
  tail->prev->next = newNode;
  tail->prev = newNode;
  currNode = newNode;
}

void BrowserHistory :: readFile(string filename) {
  string wordZero, wordOne, wordThrow;
  int wordTwo;
  std::ifstream theFileName(filename);
  while(theFileName >> wordZero) {
   if(wordZero == "visit") {
     theFileName >> wordOne >> wordTwo;
     visitSite(wordOne,wordTwo);
   } else if(wordZero == "back") {
     backButton();
   } else if(wordZero == "forward") {
     forwardButton();
   }
 }
}

//return the empty string
string BrowserHistory :: currentUrl() {
  if(head->next == tail) {
    return"";
  } 
  return currNode->data.uniform_rl;
}

//return 0 is history is empty 
size_t BrowserHistory :: currentPageSize() {
  return currNode->data.page_size;
}

//return the length of the webpage visit sequence
size_t BrowserHistory :: getHistoryLength() {
  length_ = 0;
  Node<Website>* currNode2 = head->next;
  
  while(currNode2 != tail) {
    currNode2 = currNode2->next;
    length_++;
  }
  return length_;
}

//delete websites 
void BrowserHistory :: remove(Node<Website>* reNode) {
  if(head->next == tail) {
    std::cout << "ERROR\n";
    return;
  } if (reNode == head || reNode == tail) {
    std::cout << "ERROR\n";
    return;
  }
  Node<Website>* nextNode = reNode->next;
  Node<Website>* prevNode = reNode->prev;
  prevNode->next = nextNode;
  nextNode->prev = prevNode;
}
