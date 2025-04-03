#include "IntList.h"
#include "SortedSet.h"

#include <iostream>
using namespace std;

int main() {

   SortedSet bam = SortedSet();
      bam.push_front(0);
      bam.push_front(1);
      bam.push_front(2);
      bam.push_front(3);
      bam.push_front(4);

   SortedSet bon = SortedSet();
      bon.push_front(0);
      bon.push_front(-1);
      bon.push_front(-2);
      bon.push_front(-3);
      bon.push_front(-4);

   IntList veep = IntList();

      veep.push_front(3);
      veep.push_front(2);
      veep.push_front(3);
      veep.push_front(-3);
      veep.push_front(-3);

      // if(bam.in(3))
      // {

      //    cout << "I love my bf T" << endl;

      // }
      // else
      // {

      //    cout << "Fak F" << endl;

      // }

      // if(bam.in(2323))
      // {

      //    cout << "Fak T" << endl;

      // }
      // else
      // {

      //    cout << "I love my bf F" << endl;

      // }

   // cout << "Bam: " << bam << endl;

   // SortedSet cBam = bam;

   // cout << "cBam: " << cBam << endl;

   // SortedSet cVeep = veep;

   // cout << "cVeep: " << cBam << endl;

   SortedSet bonbam;

   bonbam = bon | bam;

   SortedSet bing;
   
   bing = bon & bam;
   
   cout << "bam: " << bam << endl;
   
   cout << "bon: " << bon << endl;

   cout << "bonbam: " << bonbam << endl;

   cout << "bing: " << bing << endl;

   // SortedSet bor = bam |= bon;

   // cout << "bor: " << bor << endl;
   // cout << "remade bam: " << bam << endl;
   // cout << "untouched bon: " << bon << endl;

   SortedSet band = bam &= bon;

   cout << "band: " << band << endl;
   cout << "remade bam: " << bam << endl;
   cout << "untouched bon: " << bon << endl;


   return 0;
}
