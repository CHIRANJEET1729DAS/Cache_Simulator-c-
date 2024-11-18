#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

class Allocator{
 private:

  char* freePointer;
  char* memoryStart;
  char* memoryEnd;
  char* allocatedMemory;
  
  vector<char*> allocated_addresses;

  size_t size;

 public:

  void memory_allocate(const size_t size){
   memoryStart = static_cast<char*>(sbrk(size));
   if (memoryStart == (void*)-1){
    throw runtime_error("sbrk was unable to allocate memory");
   }
   freePointer = memoryStart;
   memoryEnd = memoryStart + size;
  }
  
  char* allocate_memory(size_t size_demanded){
   if (freePointer + size_demanded > memoryEnd){
     throw bad_alloc();
   }
   allocatedMemory = freePointer;
   allocated_addresses.push_back(allocatedMemory);
   freePointer += size_demanded;
   return allocatedMemory;
  }

  void printAllocatedaddresses(){
   for(void* item:allocated_addresses){
    cout<<item<<endl;
   }
  }

  vector<char*> getAllocatedaddresses(){
   return allocated_addresses;
  }
  
};

#endif
