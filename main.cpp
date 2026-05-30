#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <windows.h>
#include <vector>



void skaitymas(std::string failoPav, std::map<std::string, std::vector<int>>& zodziai)
{
    std::ifstream input(failoPav);

    if(!input)
    {
        throw std::runtime_error("Nepavyko atidaryti tekstinio failo!" + failoPav);
    }
    std::string eilute;
    std::string zodis;
    int eilutesNr = 0;
    while(std::getline(input,eilute))
    {
        eilutesNr++;
        std::stringstream srautas(eilute);
        while(srautas >> zodis)
        {
            zodziai[zodis].push_back(eilutesNr);
        } 
    }
}

void zodziu_kiekio_isvedmas(std::map<std::string, std::vector<int>>& zodziai)
{
    for(const auto& [zodis, kiekis] : zodziai)
    {
        if(kiekis.size() > 1)
        {
            std::cout << zodis << ": " << kiekis.size() << std::endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);  // UTF-8 output
    SetConsoleCP(65001); 

    std::map<std::string, std::vector<int>> zodeliai;
    skaitymas("tekstas.txt", zodeliai);
    zodziu_kiekio_isvedmas(zodeliai);
}
