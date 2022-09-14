/*
Author: Max Koltovskiy
Course: CSCI-135
Instructor: Michael Zamansky
Assignment:Lab 3D

Contains function reverse_order which takes an interval of dates and outputs the western elevation in descending order
*/
#include "reverseorder.h"
void reverse_order(std::string date1, std::string date2) {
   std::ifstream fin = read_file();

   std::string date_search;
   double eastSt;
   double eastEl;
   double westSt;
   double westEl;
   std::string dates[100];
   double elevations[100];
   int arrs_size = 0;
   
   while(fin >> date_search>> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');

      if(date_search.compare(date1) == 0) {
         
         while(date_search.compare(date2) != 0) {
         
            dates[arrs_size] = date_search;
            elevations[arrs_size] = westEl;
            
            //std::cout<<arrs_size<<std::endl;
            //std::cout<< "date" << date_search<<std::endl;

            fin >> date_search >> eastSt >> eastEl >> westSt >> westEl;
            fin.ignore(INT_MAX, '\n');
            arrs_size++;

         }// while compare date2
         dates[arrs_size] = date_search;
         elevations[arrs_size] = westEl;
      }// if compare date1
   }//while fin
   
   for(int i = arrs_size; i >= 0; i--) {
      std::cout<< dates[i]<< " " << elevations[i]<< std::endl; 
   }

}// main
