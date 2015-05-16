/************************************************************************
* bitvector.c
* Richard Gowen
*
* This is a test for extracting bits from bytes in a bitvector
*
************************************************************************/
#include<stdio.h>

extern void BitsFromByte( char byte, char bits[ ], int k );

void BitsFromByte( char byte, char bits[ ], int k )
{
   unsigned char mask = 1;
   int i;

   for ( i = 0; i < 8; i++ ) {
      bits[i+k] = ( byte & ( mask << i ) ) != 0;
   }

}

int main( int argc, char* argv[] )
{
   // A
   unsigned char byte[8] = { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00 };
   // B
   //unsigned char byte[8] = { 0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00 };
   // a
   //unsigned char byte[8] = { 0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00 };
   // b
   //unsigned char byte[8] = { 0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00 };
   // G
   //unsigned char byte[8] = { 0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00 };
   // g
   //unsigned char byte[8] = { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F };
   //unsigned char byte[8] = {  };
   //unsigned char byte[8] = {  };
   unsigned char bits[64];
   int i;
   int k;

   for ( i = 0; i < 8; i++ ) {
     k = i * 8;
     BitsFromByte( byte[i], bits, k );
   }

   for ( i = 0; i < 64; i++ ) {
      printf("%d ",bits[i]);
      if ( i == 7 || i == 15 || i == 23 || i == 31 || i == 39 || i == 47 || i == 55 || i == 63) {
         printf("\n");
      } 
   }
   printf("\n");

}
