//
//  main.cpp
//  smart unique_ptr example
//
//  Created by Alex Wang on 2016-12-14.
//  Copyright © 2016 Alex Wang. All rights reserved.
//

#include <iostream>
#include <memory>
class dog {
  std::string name_;
public:
  dog(std::string name);
  ~dog();
  void bark()const;
};

dog::dog(std::string name){
  name_ = name;
}

void dog::bark()const {
  std::cout << name_ << ": Woof Woof!\n";
}

dog::~dog(){
  name_.clear();
}

int main(int argc, const char * argv[]) {
  /*Creating a temporary dog object, call it Snoopy and moving it into 
   unique_ptr variable snoopy*/
  std::unique_ptr<dog> snoopy (new dog("Snoopy"));
  
  /*
   When I use unique_ptr<dog>, this is the same as the RAW POINTER version of:
   dog* snoopy = new dog("Snoopy");
   
   The difference is that it is a smart pointer. This means the life time of
   Snoopy is managed by unique_ptr.
   
   When the program goes out of scope, it will automatically call snoopy's
   destructor.
   
   In the case of a raw pointer, I would have to perform "delete snoopy;"
   to prevent a memory leak, but now I don't need to call it because snoopy
   is automatically destroyed by unique_ptr.
   
   If an exception occurs while executing any snoopy's member functions,
   unique_ptr will also self-destruct snoopy safely. With raw pointers, this is
   not possible and you will have memory leak.
   
   Because unique_ptrs completely manage the life cycle of the object, you 
   cannot make copies of a unique_ptr, you can only move it from one unique_ptr
   to the next.
   */
  
  std::cout << "Looks like Snoopy wants to say something!\n";
  snoopy->bark();
  
  return 0;
}
