/*
Author: Max Koltovskiy
Course: CSCI-135
Instructor: Michael Zamansky
Assignment:Lab 3A,3B,3C

Contains functions get_east_storage, get_min_east, get_max_east, and compare_basins
*/
#include "reservoir.h"

std::ifstream read_file() { //function that stops the need to copy the code in every function
   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
   }
   std::string junk; 
   getline(fin,junk);

   return fin;
}

double get_east_storage(std::string date) {

   std::ifstream fin = read_file();   

   std::string date_search;
   double eastSt;
   while(fin >> date_search >> eastSt) { 
      fin.ignore(INT_MAX, '\n'); 

      if(date_search.compare(date)==0){
         return eastSt;
      }
   }

   fin.close();
   return 0;
}

double get_min_east() {
   std::ifstream fin = read_file();

   std::string date;
   double eastSt;
   double min_east = get_east_storage("01/01/2018");

   while(fin>> date>> eastSt) {
      fin.ignore(INT_MAX, '\n');

      if(eastSt < min_east) {
         min_east = eastSt;
      }
   }
   return min_east;
}

double get_max_east() {
   std::ifstream fin = read_file();

   std::string date;
   double eastSt;
   double max_east = get_east_storage("01/01/2018");

   while(fin>> date>> eastSt) {
      fin.ignore(INT_MAX, '\n');

      if(eastSt > max_east) {
         max_east = eastSt;
      }
   }
   return max_east;
}

std::string compare_basins(std::string date) {
   std::ifstream fin = read_file();

   std::string date_search;
   double eastSt;
   double eastEl;
   double westSt;
   double westEl;

   while(fin >> date_search >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');

      if(date_search.compare(date)==0) {
         if(eastEl > westEl) {
            return "East";
         }
         else if(eastEl < westEl) {
            return "West";
         }
         else {
            return "Equal";
         }
      }
   }
   return 0;
}