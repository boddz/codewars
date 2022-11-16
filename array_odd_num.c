/* Find Array Odd Number
 * ---------------------
 *
 * Find the odd number in an array and return it as the value */


#include <stdio.h>
#include <assert.h>


int find_odd(size_t, const int[]);


int main()
{
  const int arr1[] = { 1, 1, 1, 1, 3, 1, 1 };
  const int arr2[] = { 3, 3, 3, 3, 4, 4, 10, 10 };
  const int arr3[] = { 7, 7, 7 };

  assert(find_odd(7, arr1) == 3);
  assert(find_odd(8, arr2) == 0);
  assert(find_odd(7, arr3) == 7);

  return 0;
}


int find_odd(size_t length, const int array[length])
{
  size_t num;

  // loop over entire array
  for(size_t i = 0; i < length; i++) {
    num = 0;

    // get count of how many numbers match index i
    for(size_t i2 = 0; i2 < length; i2++) if(array[i] == array[i2]) num++;

    if(num % 2 == 1) return array[i]; // division has remainder 1 it's odd
  }

  return 0;
}
