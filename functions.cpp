#include "functions.h"


std::string tvarkytiZodi(std::string zodis)
{
    std::string tinkamas;
    std::string skyryba = ".,!?;:\"'„()[]{}-_<>–°";
    for(char w : zodis)
    {
        if(skyryba.find(w) == -1)
        {
            tinkamas += std::tolower((unsigned char)w);
        }
    }
    return tinkamas;
}

void skaitymas(std::string failoPav, std::map<std::string, std::set<int>>& zodziai, std::set<std::string>& pabaigos, std::set<std::string>& url)
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
        rastiURL(eilute, pabaigos, url);
        std::stringstream srautas(eilute);
        while(srautas >> zodis)
        {
            zodis = tvarkytiZodi(zodis);
            bool skaicius = true;
            if(zodis.empty()) { continue; }
            for(const char& z : zodis)
            {
                if(!std::isdigit((unsigned char)z)) { skaicius = false; break; }
            }
            if(skaicius) { continue; }
            zodziai[zodis].insert(eilutesNr);
        } 
    }
}

void zodziuKiekioIsvedimas(const std::map<std::string, std::set<int>>& zodziai, std::string CountOutput)
{
    std::ofstream output(CountOutput);
    output << std::string(50, '=') << "\n";
    output << std::right << std::setw(40) << "Žodžių pasikartojimas\n";
    output << std::string(50, '=') << "\n";
    output << std::left << std::setw(40) << "Žodis" << "Kartai\n";
    for(const auto& [zodis, kiekis] : zodziai)
    {
        if(kiekis.size() > 1)
        {
            output << std::left << std::setw(40) << zodis << kiekis.size() << std::endl;
        }
    }
}

void crossReferenceIsvedimas(const std::map<std::string, std::set<int>>& zodziai, std::string CrossRefOutput)
{
    std::ofstream output(CrossRefOutput);
    output << std::string(50, '=') << "\n";
    output << std::right << std::setw(40) << "Cross-Reference lentelė\n";
    output << std::string(50, '=') << "\n";

    output << std::left << std::setw(40) << "Žodis" << "Eilutės\n";
    output << std::string(50, '-') << "\n";
    for(const auto& [zodis, eilutes] : zodziai)
    {
        if(eilutes.size() > 1)
        {
            output << std::left << std::setw(40) << zodis;
            for(int vieta : eilutes)
            {
                output << vieta << " ";
            }
            output << "\n";
        }
    }
}

void nuskaitytiTLD(std::set<std::string>& pabaigos, const std::string& failoPav)
{
    std::ifstream input(failoPav);
    std::string eilute;
    std::getline(input, eilute);
    while(std::getline(input, eilute))
    {
        for(char& a : eilute)
        {
            a = std::tolower((unsigned char)a);
        }
        pabaigos.insert(eilute);

    }
}

void rastiURL(const std::string& eilute, const std::set<std::string>& pabaigos, std::set<std::string>& url)
{
    std::stringstream srautas(eilute);
    std::string zodis;
    while(srautas >> zodis)
    {
        size_t taskas = zodis.rfind('.');
        if(taskas != std::string::npos)
        {
            std::string pabaiga = zodis.substr(taskas + 1);
            if(pabaigos.count(pabaiga) || zodis.find("http") != std::string::npos)
            {
                url.insert(zodis);
            }
        }
    }
}

void isvetiURL(std::string failoPav, const std::set<std::string>& url)
{
    std::ofstream output(failoPav);
    output << "url'ai rasti tekste: \n";
    for(const std::string& u : url)
    {
        output << u << "\n";
    }
}
