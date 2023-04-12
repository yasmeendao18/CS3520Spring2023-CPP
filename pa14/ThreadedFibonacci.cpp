// Fig. 24.11: ThreadedFibonacci.cpp
// Fibonacci calculations performed in separate threads
#include <iostream>
#include <iomanip>
#include <future>
#include <ctime>
using namespace std;

// class to represent the results
class ThreadData 
{
public:
   time_t startTime; // time thread starts processing
   time_t endTime; // time thread finishes processing
}; // end class ThreadData

unsigned long long int fibonacci( unsigned int n ); // function prototype
ThreadData startFibonacci( unsigned int n ); // function prototype

int main()
{
   int num1,num2,num3; 
   cout << "Enter three numbers greater than 30"<<endl; 
   cout << fixed << setprecision( 6 );
   cout << "num1: ";
   cin >> num1;
   cout << "num2: ";
   cin >> num2;
   cout << "num3: ";
   cin >> num3;

   cout << "Calculating fibonacci(" << num1 << "),fibonacci( "<< num2 <<"), and fibonacci("<< num3 << ")" << "in separate threads" << endl;

   cout << "Starting thread to calculate fibonacci("<<num1<<")" << endl;
   auto futureResult3 = async( launch::async, startFibonacci, num1 );
   cout << "Starting thread to calculate fibonacci("<<num2<<")" << endl;
   auto futureResult2 = async( launch::async, startFibonacci, num2 );
   cout << "Starting thread to calculate fibonacci("<<num3<<")"<< endl;
   auto futureResult1 = async( launch::async, startFibonacci, num3 );

   // wait for results from each thread
   ThreadData result1 = futureResult1.get(); 
   ThreadData result2 = futureResult2.get();
   ThreadData result3 = futureResult3.get();

   // determine time that first thread started
   time_t startTime = ( result1.startTime < result2.startTime ) ? 
      result1.startTime : result2.startTime;
   startTime = ( startTime < result3.startTime ) ? startTime : result3.startTime;


   // determine time that last thread terminated
   time_t endTime = ( result1.endTime > result2.endTime ) ? 
      result1.endTime : result2.endTime;
   endTime = ( endTime > result3.endTime ) ? endTime : result3.endTime;

   // display total time for calculations
   cout << "Total calculation time = " 
      << difftime(endTime, startTime ) / 60.0 << " minutes" << endl;
} // end main

// executes function fibonacci asynchronously
ThreadData startFibonacci( unsigned int n )
{
   // create a ThreadData object to store times
   ThreadData result = { 0, 0 };
 
   cout << "Calculating fibonacci( " << n << " )" << endl;
   result.startTime = time( nullptr ); // time before calculation
   auto fibonacciValue = fibonacci( n );
   result.endTime = time( nullptr ); // time after calculation

   // display fibonacci calculation result and total calculation time
   cout << "fibonacci( " << n << " ) = " << fibonacciValue << endl;
   cout << "Calculation time = " 
      << difftime( result.endTime, result.startTime ) / 60.0 
      << " minutes\n" << endl; 
   return result;
} // end function startFibonacci

// Recursively calculates fibonacci numbers
unsigned long long int fibonacci( unsigned int n )   
{                                                    
   // base case                                      
   if ( 0 == n || 1 == n ) 
   {                         
      return n;                                      
   } // end if                                       
   else // recursive step
   { 
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   } // end else                                     
} // end function fibonacci 

// utilizes 12 cpu cores