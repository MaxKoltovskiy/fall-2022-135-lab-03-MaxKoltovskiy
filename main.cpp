/*
Author: Max Koltovskiy
Course: CSCI-135
Instructor: Michael Zamansky
Assignment:Lab 3A,3B,3C,3D

Drives tje program
*/
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  
  std::string date = "05/20/2018";
  double east_storage = get_east_storage(date);
  std:: cout<< date<< " East Basin Storage: "<< east_storage<< " billion gallons"<< std::endl;

  double min_east = get_min_east();
  std:: cout<< "\nMinimum storage in East Basin: "<< min_east<< " billion gallons"<< std::endl;
  double max_east = get_max_east();
  std:: cout<< "Maximum storage in East Basin: "<< max_east<< " billion gallons"<< std::endl;

  std::string compare_date = "06/28/2018";
  std::string higher_El = compare_basins(compare_date);
  std:: cout<< "\n" << compare_date << " " << higher_El << std::endl;

  std::cout<< "\n";
  reverse_order("05/29/2018", "06/02/2018");
}
