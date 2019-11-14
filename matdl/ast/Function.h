#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "Block.h"

namespace ast {

class Function {
public:
  Block &primary_block() { return m_primary_block; }
  
private:
  Block m_primary_block;
};

} // namespace ast

#endif
