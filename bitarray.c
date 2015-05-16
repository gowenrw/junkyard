/************************************************************************
* bitarray.c
* Richard Gowen
*
* This was taken from an online c course syllabus web page
*http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/1-C-intro/bit-array.html
*
************************************************************************/
#include<stdio.h>

extern void  SetBit( int A[ ],  int k );
extern void  ClearBit( int A[ ],  int k );
extern int   TestBit( int A[ ],  int k );

void  SetBit( int A[ ],  int k )
{
   int i = k/32;
   int pos = k%32;

   unsigned int flag = 1;  // flag = 0000.....00001

   flag = flag << pos;     // flag = 0000...010...000   (shifted k positions)

   A[i] = A[i] | flag;     // Set the bit at the k-th position in A[i]
}

void  ClearBit( int A[ ],  int k )
{
   int i = k/32;
   int pos = k%32;

   unsigned int flag = 1;  // flag = 0000.....00001

   flag = flag << pos;     // flag = 0000...010...000   (shifted k positions)
   flag = ~flag;           // flag = 1111...101..111

   A[i] = A[i] & flag;     // RESET the bit at the k-th position in A[i]
}

int TestBit( int A[ ],  int k )
{
   int i = k/32;
   int pos = k%32;

   unsigned int flag = 1;  // flag = 0000.....00001

   flag = flag << pos;     // flag = 0000...010...000   (shifted k positions)

   if ( A[i] & flag )      // Test the bit at the k-th position in A[i]
      return 1;
   else
      return 0;
}

int main( int argc, char* argv[] )
{
   int A[8];
   int i;

   for ( i = 0; i < 8; i++ )
      A[i] = 0;                    // Clear the bit array

   printf("Set bit poistions 100, 200 and 300\n");
   SetBit( A, 100 );               // Set 3 bits
   SetBit( A, 200 );
   SetBit( A, 300 );

   for ( i = 0; i < 320; i++ )
      if ( TestBit(A, i) )
         printf("Bit %d was set !\n", i);

   printf("\nClear bit poistions 200 \n");
   ClearBit( A, 200 );

   // Check if ClearBit() works:

   for ( i = 0; i < 320; i++ )
      if ( TestBit(A, i) )
         printf("Bit %d was set !\n", i);
}

