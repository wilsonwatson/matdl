#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

namespace ast {

template <typename T> class Maybe {
public:
  inline Maybe() : m_exists(false) {}
  inline Maybe(void *v) : m_exists(true), m_ptr(static_cast<T *>(v)) {}

  inline operator bool() const { return m_exists; }

  inline T &operator()() { return *m_ptr; }

private:
  bool m_exists;
  T *m_ptr;
};

class Instruction {
public:
  template <typename T> Maybe<T> as() {
    if (type == T::type) {
      return Maybe<T>(m_data);
    } else {
      return Maybe<T>();
    }
  }

private:
  inline Instruction(){}
  
  friend class FunctionCallInst;
  void *m_data;
  int type;
};

enum class InstType {
  FUNCTION_CALL
};

class Function;

class FunctionCallInst {
public:
  constexpr static int type = static_cast<int>(InstType::FUNCTION_CALL);
  
  inline static Instruction create(Function *f){
    Instruction i;
    FunctionCallInst *fci = new FunctionCallInst;
    fci->func = f;
    i.m_data = static_cast<void*>(fci);
    i.type = type;
    return i;
  }
private:
  Function *func;
};

} // namespace ast

#endif
