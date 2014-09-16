TinyCompiler
============
TinyCompiler是一款能编译一个经过裁剪的C语言的子的简易编译器，采用了C++11编写

编译环境：VS2013或以上

词法测试代码(选择了lua源码中的lmem.c文件并经过了删除不符合TinyCompiler词法的部分)：
void *luaM_toobig (lua_State *L) {
  luaG_runerror(L, "memory allocation error: block too big");
  return NULL;  
}
