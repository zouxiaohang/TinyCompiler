TinyCompiler
============
TinyCompiler是一款能编译一个经过裁剪的C语言的子的简易编译器，采用了C++11编写

编译环境：VS2013或以上

词法测试代码(选择了lua源码中的lmem.c文件并经过了删除不符合TinyCompiler词法的部分)：
void *luaM_growaux_ (lua_State *L, void *block, int *size, size_t size_elems,
                     int limit, const char *errormsg) {
  void *newblock;
  int newsize;
  if (*size >= limit/2) {  
    if (*size >= limit)  
      luaG_runerror(L, errormsg);
    newsize = limit;  
  }
  else {
    newsize = (*size)*2;
    if (newsize < MINSIZEARRAY)
      newsize = MINSIZEARRAY;  
  }
  newblock = luaM_reallocv(L, block, *size, newsize, size_elems);
  *size = newsize; 
  return newblock;
}


void *luaM_toobig (lua_State *L) {
  luaG_runerror(L, "memory allocation error: block too big");
  return NULL;  
}

void *luaM_realloc_ (lua_State *L, void *block, size_t osize, size_t nsize) {
  global_State *g = G(L);
  lua_assert((osize == 0) == (block == NULL));
  block = (*g->frealloc)(g->ud, block, osize, nsize);
  if (block == NULL && nsize > 0)
    luaD_throw(L, LUA_ERRMEM);
  lua_assert((nsize == 0) == (block == NULL));
  g->totalbytes = (g->totalbytes - osize) + nsize;
  return block;
}
