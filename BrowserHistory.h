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

class WebInfo {
public:
  string uniform_rl;
  size_t page_size;

  WebInfo(string url, size_t pgsize) : uniform_rl(url), page_size(pgsize) {}
  WebInfo() {}
};

class BrowserHistory {
public:
    BrowserHistory();

    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();

private:
  // TO BE COMPLETED
  Node<WebInfor>* head;
  Node<WebInfo>* tail;
  size_t length_;
  size_t accumilator_ = 0;
  Node<WebInfo>* currNode;
};

BrowserHistory :: BrowserHistory() {
  head = new Node<WebInfo>(WebInfo());
  tail = new Node<WebInfor>(WebInfo());

  head->next = tail;
  tail->prev = head;
}

void BrowserHistory :: visitSite(string url, size_t filesize) {
  WebInfo New;
  New.uniform_rl = url;
  New.page_size = filesize;
  if(accumilator_ > 0) {
    while(accumilator_ > 0 && accumilator_ != 0) {
      remove(tail->prev);
      accumilator_--;
    }
  }
  Node<WebInfo>* newNode = new Node<WebInfo>(New);

  newNode->prev = tail->prev;
  newNode->next = tail;
  tail->prev->next = newNode;
  tail->prev = newNode;

  currNode = newNode;
}

void BrowserHistory :: backButton() {
  if(currNode->prev == head) {
    std::cout << "No Previous Page/n";
  }
  else {
    currNode = currNode->prev;
    accumilator++;
  }
}

void BrowserHistory :: forwardButton() {
  if(currNode->next == tail) {
    std::cout << "No Such Page'n";
  }
  else {
    currNode = currNode->next;
    accumilator_--;
  }
}

void BrowserHistory :: readFile(string filename) {
  string var0, var1, varTrash;
  int var2;
  std::ifstream meesafile(filename);
  
}
