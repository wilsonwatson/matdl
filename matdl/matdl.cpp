#include <string>
#include <iostream>

#include "mat.h"

int main(int argc, char* argv[]){
  
  if(argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
    return 1;
  }
  
  auto ast = compile_source(read_file(argv[1]));
  
  return 0;
}
