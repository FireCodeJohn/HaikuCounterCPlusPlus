#include "HaikuCounter.h"

std::string GetWorkingDirectory();

int main()
{
    // gets working directory and instruct user to place input haikus there
    std::string workingDir = GetWorkingDirectory();
    std::cout << "Working directory: '" << workingDir << "'\n";
    std::cout << "Place your .txt input files in the working directory.  Press any key when ready to continue...\n";
    std::cin.get();

    CountHaikus(workingDir);
}

// Gets working directory
std::string GetWorkingDirectory() {
    return "C:\\HaikuCPlusPlus_WorkingFolder";
}