#include "functions.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);  // UTF-8 output
    SetConsoleCP(65001); 

    std::map<std::string, std::vector<int>> zodeliai;
    skaitymas("tekstas.txt", zodeliai);
    zodziuKiekioIsvedmas(zodeliai,"isvedimas1.txt");
    crossReferenceIsvedmas(zodeliai, "CrossReferenceOutput.txt");
}
