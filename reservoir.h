/*
Author: Max Koltovskiy
Course: CSCI-135
Instructor: Michael Zamansky
Assignment:Lab 3A,3B,3C,3D

Header file for reservoir.cpp that initializes functions in the file
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
std::ifstream read_file();

double get_east_storage(std::string);

double get_min_east();
double get_max_east();

std::string compare_basins(std::string date);
