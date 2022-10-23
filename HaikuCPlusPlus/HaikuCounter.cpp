#include "HaikuCounter.h"
#include "TrimHelper.h"
#include "SyllableCounter.h"
#include <filesystem>
#include <fstream>
#include <string>
namespace fs = std::filesystem;

// counts the number of haikus in the working directory
void CountHaikus(std::string path)
{
    // gets the files and loops through them
    int haikuCount = 0;
    for (const auto& entry : fs::directory_iterator(path))
    {
        fs::path filePath = entry.path();
        try
        {
            std::cout << filePath << "\n";
            std::ifstream infile(filePath);

            // read the lines in the file
            std::string line = "";
            int rowCount = 0;
            while (std::getline(infile, line))
            {
                // ignore blank lines
                trim(line);
                if (line._Equal(""))
                {
                    continue;
                }

                rowCount++;
                int syllables = GetSyllablesPerLine(line);
                if (rowCount == 1 || rowCount == 3)
                {
                    if (syllables != 5)
                    {
                        throw "Error: There are " + std::to_string(syllables) + " syllables in line " + std::to_string(rowCount);
                    }
                }
                if (rowCount == 2)
                {
                    if (syllables != 7)
                    {
                        throw "Error: There are " + std::to_string(syllables) + " syllables in line " + std::to_string(rowCount);
                    }
                }
            }

            if (rowCount != 3)
            {
                throw "Error: There are " + std::to_string(rowCount) + " lines";
            }

            std::cout << "Text in file " << filePath << " is a Haiku!\n\n";
            haikuCount++;
        }
        catch (std::string exception)
        {
            std::cout << filePath << " Is not a haiku due to the following error\n" << exception << "\n\n";
        }
    }

    std::cout << "The working directory had " << haikuCount << " haikus in it\n";
    std::cout << "Press any key to close the program...";
    std::cin.get();
}