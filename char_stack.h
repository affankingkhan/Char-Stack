;/* File: char_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/
#include <string>
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();

  private:
   // fill this in
    static const int capacity = 250000;
    char A[capacity];
    int top_index; 
};
