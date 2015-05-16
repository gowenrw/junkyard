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
   //unsigned char byte[8] = { 0x18, 0x18, 0x24, 0x3C, 0x42, 0x42, 0x00, 0x00 };
   unsigned char byte[8] = { 0x78, 0x44, 0x78, 0x44, 0x44, 0x78, 0x00, 0x00 };
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
