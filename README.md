TinyCompiler
============
####TinyCompiler是一款能编译一个经过裁剪的C语言的子的简易编译器，采用了C++11编写

####编译环境：VS2013或以上

#####词法测试代码(选择了lua源码中的lmem.c文件并经过了删除不符合TinyCompiler词法的部分)：
<pre><code>
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
</pre></code>
#####分词结果：
<pre><code>
Token: {name = void attr = KEYWORD loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = luaM_growaux_ attr = VARIABLE loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = lua_State attr = VARIABLE loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = void attr = KEYWORD loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = int attr = KEYWORD loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size attr = VARIABLE loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size_t attr = VARIABLE loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size_elems attr = VARIABLE loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 1 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = int attr = KEYWORD loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = limit attr = VARIABLE loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = const attr = KEYWORD loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = char attr = KEYWORD loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = errormsg attr = VARIABLE loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = { attr = DELIMITER loc = 2 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = void attr = KEYWORD loc = 3 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 3 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newblock attr = VARIABLE loc = 3 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 3 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = int attr = KEYWORD loc = 4 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newsize attr = VARIABLE loc = 4 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 4 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = if attr = KEYWORD loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size attr = VARIABLE loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = >= attr = DELIMITER loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = limit attr = VARIABLE loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = / attr = DELIMITER loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = 2 attr = INTEGER loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = { attr = DELIMITER loc = 5 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = if attr = KEYWORD loc = 6 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 6 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 6 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size attr = VARIABLE loc = 6 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = >= attr = DELIMITER loc = 6 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = limit attr = VARIABLE loc = 6 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 6 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = luaG_runerror attr = VARIABLE loc = 7 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 7 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 7 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 7 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = errormsg attr = VARIABLE loc = 7 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 7 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 7 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newsize attr = VARIABLE loc = 8 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 8 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = limit attr = VARIABLE loc = 8 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 8 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = } attr = DELIMITER loc = 9 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = else attr = KEYWORD loc = 10 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = { attr = DELIMITER loc = 10 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newsize attr = VARIABLE loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size attr = VARIABLE loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = 2 attr = INTEGER loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 11 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = if attr = KEYWORD loc = 12 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 12 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newsize attr = VARIABLE loc = 12 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = < attr = DELIMITER loc = 12 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = MINSIZEARRAY attr = VARIABLE loc = 12 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 12 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newsize attr = VARIABLE loc = 13 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 13 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = MINSIZEARRAY attr = VARIABLE loc = 13 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 13 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = } attr = DELIMITER loc = 14 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newblock attr = VARIABLE loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = luaM_reallocv attr = VARIABLE loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size attr = VARIABLE loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newsize attr = VARIABLE loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size_elems attr = VARIABLE loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 15 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 16 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size attr = VARIABLE loc = 16 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 16 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newsize attr = VARIABLE loc = 16 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 16 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = return attr = KEYWORD loc = 17 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = newblock attr = VARIABLE loc = 17 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 17 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = } attr = DELIMITER loc = 18 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = void attr = KEYWORD loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = luaM_toobig attr = VARIABLE loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = lua_State attr = VARIABLE loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = { attr = DELIMITER loc = 19 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = luaG_runerror attr = VARIABLE loc = 20 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 20 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 20 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 20 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = "memory allocation error: block too big" attr = STRING loc = 20 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 20 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 20 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = return attr = KEYWORD loc = 21 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = NULL attr = VARIABLE loc = 21 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 21 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = } attr = DELIMITER loc = 22 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = void attr = KEYWORD loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = luaM_realloc_ attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = lua_State attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = void attr = KEYWORD loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size_t attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = osize attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = size_t attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = nsize attr = VARIABLE loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = { attr = DELIMITER loc = 23 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = global_State attr = VARIABLE loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = g attr = VARIABLE loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = G attr = VARIABLE loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 24 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = lua_assert attr = VARIABLE loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = osize attr = VARIABLE loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = == attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = 0 attr = INTEGER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = == attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = == attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = NULL attr = VARIABLE loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 25 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = * attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = g attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = -> attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = frealloc attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = g attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = -> attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ud attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = osize attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = nsize attr = VARIABLE loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 26 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = if attr = KEYWORD loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = == attr = DELIMITER loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = NULL attr = VARIABLE loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = && attr = DELIMITER loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = nsize attr = VARIABLE loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = > attr = DELIMITER loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = 0 attr = INTEGER loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 27 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = luaD_throw attr = VARIABLE loc = 28 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 28 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = L attr = VARIABLE loc = 28 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = , attr = DELIMITER loc = 28 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = LUA_ERRMEM attr = VARIABLE loc = 28 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 28 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 28 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = lua_assert attr = VARIABLE loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = nsize attr = VARIABLE loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = == attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = 0 attr = INTEGER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = == attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = == attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = NULL attr = VARIABLE loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 29 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = g attr = VARIABLE loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = -> attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = totalbytes attr = VARIABLE loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = = attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ( attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = g attr = VARIABLE loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = -> attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = totalbytes attr = VARIABLE loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = - attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = osize attr = VARIABLE loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ) attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = + attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = nsize attr = VARIABLE loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 30 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = return attr = KEYWORD loc = 31 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = block attr = VARIABLE loc = 31 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = ; attr = DELIMITER loc = 31 file = C:\Users\zxh\Desktop\lmem.c }
Token: {name = } attr = DELIMITER loc = 32 file = C:\Users\zxh\Desktop\lmem.c }
</pre></code>
