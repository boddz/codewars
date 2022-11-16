/* Confirm Braces Match
 * --------------------
 *
 * Confirm that the braces in a string are valid/ the braces are
 * balanced and have a corresponding opening or closing brace. */


#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


bool valid_parentheses(const char*);


int main(void)
{
  const char* str1 = "  (";
  const char* str2 = "";
  const char* str3 = "((()()()))";
  const char* str4 = "foo(bar)()";
  const char* str5 = ")(";

  assert(valid_parentheses(str1) == false);
  assert(valid_parentheses(str2) == true);
  assert(valid_parentheses(str3) == true);
  assert(valid_parentheses(str4) == true);
  assert(valid_parentheses(str5) == false);

  return 0;
}


bool valid_parentheses(const char *str_in)
{
  unsigned int bracecount = 0;

  while(*str_in) {
    if(*str_in == '(') ++bracecount;
    if(*str_in == ')') {
      if(bracecount == 0) return false;
      else --bracecount;
    }
    ++str_in;
  }

  if(bracecount == 0) return true;
  else return false;
}
