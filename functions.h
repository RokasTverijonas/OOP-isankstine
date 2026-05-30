#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip>

std::string tvarkingasZodis(std::string zodis);
void skaitymas(std::string failoPav, std::map<std::string, std::vector<int>>& zodziai);
void zodziuKiekioIsvedmas(const std::map<std::string, std::vector<int>>& zodziai, std::string Countoutput);
void crossReferenceIsvedmas(const std::map<std::string, std::vector<int>>& zodziai, std::string CrossRefoutput);

#endif