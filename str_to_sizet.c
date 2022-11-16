/* String to size_t Conversion
 * ---------------------------
 *
 * This is an example of string into size_t (other num data type)
 * conversion without using atoi. */


#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


size_t into_sizet(const char*);


int main(void)
{
  const char* str1 = "-400000090080";
  const char* str2 = "-9999220000";
  const char* str3 = "00010000011100040023";

  assert(into_sizet(str1) == -400000090080);
  assert(into_sizet(str2) == -9999220000);
  assert(into_sizet(str3) == 10000011100040023);

  return 0;
}


size_t into_sizet(const char* strin)
{
  bool negative = false;
  size_t result = 0;

  if(*strin == '-') {
    negative = true; // is negative return value applicable
    ++strin; // push start ptr index past the '-' sign for loop
  }

  while(*strin) {
    /* Result is multiplied by 10 each time loop runs
     * (1, 10, 100, 1000, etc) and '0'/ 48 is removed from the
     * current char to give the correct value for that unit */
    result = result * 10 + *strin - '0';
    strin++;
  }

  if(negative == true) return -result;

  return result;
}
