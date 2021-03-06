/**
 * TODO: IMPORTANT!! Write your originality/source statement here.
 */

#include <iostream>

//1. Create a function, named "prime", which tests an
// integer, n, to see if it is prime. It should return a bool. 
// 
// You don't have to do
// anything tricky. Just try modding (%) it by every number
// between 2 and n-1. If it never gives 0, then it is prime.
// Special case: Only numbers 2 or greater can be prime.
// Example inputs:
// prime(1) --> false
// prime(-7) --> false
// prime(2) --> true
// prime(4) --> false
//
//Hints: This exercise uses for loops, if statements,
// and the % operator.

bool prime(int n)
{
    if (n < 2)
        return false;
    
    int count = n - 1;
    
    while (count > 0)
    {
       if (n % count == 0 && n != 2 && count != 1)
           return false;
        count--;
    }
    
    return true;
    
}

//This is a basic tester for the "prime" function
void testPrime()
{
  int nums[] = {-5, -1, 0, 1, 2 ,3, 4, 5, 6 };
  bool results[] = {false, false, false, false, true, true, false, true, false};
  for(int i=0; i<9;i++)
  {
    if(prime(nums[i]) != results[i])
    {
      std::string res = prime(nums[i]) ? "true" : "false";
      std::cout << "testPrime: ERROR: On " << nums[i] << " you returned " << res.c_str() << std::endl;
      return;
    }
  }
  
  std::cout << "testPrime: SUCCESS" << std::endl;
}

//2. Create a function, name "defix", which takes in a string and
//   returns a string. If the string starts with a pre-fix attached
//   by a dash, strip off the prefix and the dash. Otherwise, return
//   the string unchanged. If there is more than one prefix, remove only
//   the first one. Note that the input and output should both be type 
//   std::string
//
//Example inputs:
// defix("re-run") --> "run"
// defix("pre--text") --> "-text"
// defix("-ooh") --> "ooh"
// defix("moo") --> "moo"
//
//Hints: Check out the string API documentation at http://www.cplusplus.com/reference/string/string/
// The find functions and substr function will be easiest.

std::string defix (std::string word)
{
    std::string newWord;
    unsigned long wordSize = word.length();
    bool dashFound = false;
    
    for (int i = 0; i < wordSize && dashFound == false; i++) {
        if (word.at(i) == '-') {
            dashFound = true;
            newWord.append(&word.at(i + 1));

            return newWord;
        }
    }
    
    return word;
}

//This is a basic tester for "defix"
void testDefix()
{
  std::string inputs[] = {"re-run","pre--text","-ooh","moo","no-no-no", "foo-"};
  std::string outputs[] = {"run","-text","ooh","moo","no-no", ""};

  for(int i=0;i<5;i++)
  {
    if(outputs[i].compare(defix(inputs[i])) != 0)
    {
      std::cout << "testDefix: ERROR: Expected " << outputs[i].c_str() << " but got " << defix(inputs[i]).c_str() << std::endl;
      return;
    }
  }

  std::cout << "testDefix: SUCCESS" << std::endl;
}

//3. Create a function called "sumSlice" that takes 3 inputs. The first is
//   an array of integers, the second is an integer "s" that represents the
//   starting index, and the 3rd is an int "len" that represents the length. 
//   Sum up all entries in the array, starting with item "s" and ending with
//   s+len-1, and return the sum. s and len must both be >= 0. If not, return 0
//   Note: You may assume that the array is at least s+len items long. If not,
//   it is okay to crash or return unexpected results.
//
//Example inputs:
//sumSlice({1,2,3,4},1,1) --> 2
//sumSlice({1,2,3,4},1,3) --> 9
//sumSlice({1,-1,1,-1},0,4) --> 0
//sumSlice({1,2,3,4},1,0) --> 0
//
//Hints: Your answer is going to be very similar to what you would do in Java

int sumSlice (int intArray[], int startingIndex, int length)
{
    if (startingIndex < 0 || length < 0)
      return 0;
    
    int sum = 0;
    for (int i = startingIndex; i < (startingIndex + length); i++)
    {
        sum = sum + intArray[i];
    }
    
    return sum;
}

//This is a basic tester for "sumSlice"
void testSumSlice()
{
  int arrays[5][4] = { {1, 2, 3, 4},
		      {1, 2, 3, 4},
		      {1, -1, 1, -1},
		      {1, 2, 3, 4},
		      {1, -1, 1, -1}};
  int s[] = {1, 1, 0, 1, 1};
  int len[] = {1, 3, 4, 0, 3};
  int outputs[] = {2, 9, 0, 0, -1};

  for(int i=0; i<5; i++)
  {
    if(sumSlice(arrays[i],s[i],len[i]) != outputs[i])
    {
      std::cout << "testSumSlice: ERROR: on index i=" << i << " expected " << outputs[i] << " but got " << sumSlice(arrays[i],s[i],len[i]) << std::endl;
      return;
    }
  }
  std::cout << "testSumSlice: SUCCESS" << std::endl;
}

//4. Create a function called "square" which takes an int, n, as input,
//   but returns no output (so return type will be "void")
//   The function should use the std::cout object to print a square to the
//   screen that is n-by-n, with a border made of -, + and |, and the inside
//   filled with o
//   If n is <= 0, do nothing.
//
//Examples:
// square(5) should print:
// +---+
// |ooo|
// |ooo|
// |ooo|
// +---+
// square(2) should print:
// ++
// ++
// square(1) should print:
// +
// square(3) should print:
// +-+
// |o|
// +-+
//
//Note/warning: I did not write an automated tester for this one. Please
// test it however you can, to try to make sure it does the right thing for
// all possible inputs.

void square (int n)
{
    if (n <= 0)
        return;
    
    std::string topBottom;
    std::string middle;
    
    middle.append(1, '|');
    if (n > 2)
        middle.append(n - 2, 'o');
    middle.append(1, '|');
    
    topBottom.append(1, '+');
    if (n > 2)
        topBottom.append(n - 2, '-');
    
    if (n > 1)
        topBottom.append(1, '+');
        
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
            std::cout << topBottom << std::endl;
        else if (n > 2)
            std::cout << middle << std::endl;
    }
    
    std::cout << ' ' << std::endl;
}

void testSquare ()
{
    square (1);
    square (2);
    square (3);
    square (4);
    square (5);
    square (6);
    square (7);
    square (8);
    square (9);
    
}

//5. Create a function called listPrimes which takes an int, n, as input.
//   It should use "new" to allocate an array of length n, and then put
//   the first n prime numbers into it, in order. You should re-use your
//   prime method here.
//   Note: The return type of the method should be int*, 
//
//Example outputs:
// listPrimes(5) should return an array containing {2, 3, 5, 7, 11}
//
//Hint: While loops work better than for loops for this one.

int* listPrimes (int n) {
    int* primes = new int[100];
    bool isPrime = true;
    int top = 2;
    int count = 0;
    
    while (count < n)
    {
        isPrime = true;
        int check = 2;
        while (check < top)
        {
            if (top%check == 0 && top != 2)
                isPrime = false;
            
            check++;
        
        }
        
        if (isPrime)
        {
            primes[count] = top;
            count++;
        }
        
        top++;
    }
    
    return primes;
}

void testListPrimes(){
  int some_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  for(int i=1;i<10;i++){
    int* ret = listPrimes(i);
    for(int j=1;j<i;j++){
      if(ret[j] != some_primes[j]){
	std::cout << "testListPrimes: ERROR: Expected " << some_primes[j] << 
	  " but got " << ret[j] << std::endl;
	delete[] ret;
	return;
      }
    }
    delete[] ret;
  }
  
  std::cout << "testListPrimes: SUCCESS" << std::endl;
}

int main(){
    testPrime();
    testDefix();
    testSumSlice();
    testListPrimes();
    testSquare();

  return 0;
}
