#include "functions.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);  // UTF-8 output
    SetConsoleCP(65001); 

    std::map<std::string, std::set<int>> zodeliai;
    std::set<std::string> url;
    std::set<std::string> pabaigos;

    nuskaitytiTLD(pabaigos, "endings.txt");
    skaitymas("tekstas.txt", zodeliai, pabaigos, url);
    zodziuKiekioIsvedimas(zodeliai,"countOutput.txt");
    crossReferenceIsvedimas(zodeliai, "CrossReferenceOutput.txt");
    isvetiURL("urlOutput.txt", url);
}
