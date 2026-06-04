#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip>
#include <set>

std::string tvarkytiZodi(std::string zodis);
void skaitymas(std::string failoPav, std::map<std::string, std::set<int>>& zodziai, std::set<std::string>& pabaigos, std::set<std::string>& url, std::set<std::string>& unikalus);
void zodziuKiekioIsvedimas(const std::map<std::string, std::set<int>>& zodziai, std::string CountOutput);
void crossReferenceIsvedimas(const std::map<std::string, std::set<int>>& zodziai, std::string CrossRefOutput);
void nuskaitytiTLD(std::set<std::string>& pabaigos, const std::string& failoPav);
void rastiURL(const std::string& eilute, const std::set<std::string>& pabaigos, std::set<std::string>& url);
void isvetiURL(std::string failoPav, const std::set<std::string>& url);
bool Unikalus(const std::string& zodis);
void unikaliuIsvedimas(const std::string& failoPav, std::set<std::string>& unikalus);

#endif