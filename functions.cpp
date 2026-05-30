#include "functions.h"
std::string tvarkingasZodis(std::string zodis)
{
    std::string tinkamas;
    std::string skyryba = ".,!?;:\"'()[]{}-_<>";
    for(char w : zodis)
    {
        if(skyryba.find(w) == -1)
        {
            tinkamas += std::tolower(w);
        }
    }
    return tinkamas;
}

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
            zodis = tvarkingasZodis(zodis);
            zodziai[zodis].push_back(eilutesNr);
        } 
    }
}

void zodziuKiekioIsvedmas(const std::map<std::string, std::vector<int>>& zodziai, std::string Countoutput)
{
    std::ofstream output(Countoutput);
    output << std::left << std::setw(10) << "Žodis " << "Kartai\n";
    for(const auto& [zodis, kiekis] : zodziai)
    {
        if(kiekis.size() > 1)
        {
            output << std::left << std::setw(10) << zodis + ": " << kiekis.size() << std::endl;
        }
    }
}

void crossReferenceIsvedmas(const std::map<std::string, std::vector<int>>& zodziai, std::string CrossRefoutput)
{
    std::ofstream output(CrossRefoutput);
    output << std::left << std::setw(30) << "Žodis" << "Eilutės\n";
    for(const auto& [zodis, eilutes] : zodziai)
    {
        if(eilutes.size() > 1)
        {
            output << std::left << std::setw(30) << zodis + ": ";
            for(int vieta : eilutes)
            {
                output << vieta << " ";
            }
            output << "\n";
        }
    }
}
