#include "HaikuCounter.h"
#include <filesystem>
namespace fs = std::filesystem;

std::string GetWorkingDirectory();

int main()
{
    // gets working directory and instruct user to place input haikus there
    std::string workingDir = GetWorkingDirectory();
    std::cout << "Working directory: '" << workingDir << "'\n";
    std::cout << "Place your input files in the working directory.  Press any key when ready to continue...\n";
    std::cin.get();

    if (!fs::exists(workingDir))
    {
        fs::create_directory(workingDir);
    }
    CountHaikus(workingDir);
}

// Gets working directory
std::string GetWorkingDirectory() {
    return "C:\\HaikuCPlusPlus_WorkingFolder";
}