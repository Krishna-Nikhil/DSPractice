#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hash {
  int bucket;
  list<int>* table ;
  public:
  
  Hash(int b) { bucket = b; table = new list<int>[bucket];}
  
  int hashFunction(int value) {
      int index = value%bucket;
      return index;
  }
  
  void insert(int value) {
      int index = hashFunction(value);
      table[index].push_back(value);
  }
  
  void printHash() {
      for(int i =0; i<bucket; i++) {
          cout << endl << i;
          for(auto x : table[i]) {
              cout << " --> " << x;
          }
      }
  }
  
  void deleteHash(int value) {
      int index = hashFunction(value);
      auto itr = find(table[index].begin(), table[index].end(), value);
      if(itr != table[index].end())
        table[index].erase(itr);
      else
        cout << "No element found" << endl;
  }
  
};

int main()
{
    int ar[] = {1,2,3,4,5,6,12,13};
    int n = sizeof(ar)/sizeof(ar[0]);
    Hash h(5);
    
    for(int i =0; i < n; i++) {
        h.insert(ar[i]);
    }
    
    h.printHash();

    h.deleteHash(5);
    
    h.printHash();

    return 0;
}
