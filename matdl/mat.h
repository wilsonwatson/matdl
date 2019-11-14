#ifndef MAT_H_
#define MAT_H_

#include <fstream>
#include <streambuf>
#include <string>
#include <vector>

class mat_module {
public:
  
private:
  
};

mat_module compile_source(const std::string& v);

inline std::string read_file(const std::string &v) {

  std::ifstream t(v);
  std::string str;

  t.seekg(0, std::ios::end);
  str.reserve(t.tellg());
  t.seekg(0, std::ios::beg);

  str.assign((std::istreambuf_iterator<char>(t)),
             std::istreambuf_iterator<char>());

  return str;
}

#endif
