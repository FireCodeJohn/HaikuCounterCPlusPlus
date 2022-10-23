#include "SyllableCounter.h"
#include <string>

// Get syllables for a line
int GetSyllablesPerLine(std::string line)
{
    // split into words and add up syllables for each word
    int syllables = 0;
    std::string word;
    while (line.find(" ") != std::string::npos)
    {
        word = line.substr(0, line.find(" "));
        syllables += GetSyllablesPerWord(word);
        line.erase(0, line.find(" ") + 1);
        std::cout << word << " ";
    }
    if (line.length() > 0)
    {
        word = line;
        syllables += GetSyllablesPerWord(word);
        std::cout << word << "\n";
    }

    return syllables;
}

// Get syllables for a word
int GetSyllablesPerWord(std::string word)
{
    int syllables = 0;

    // iterate through each character to check for traditional vowels
    for (int i = 0; i < word.length(); i++)
    {
        // if it is a vowel, this is a syllable (except for cases in nested if statements)
        if (IsVowel(word[i]))
        {
            // If the current letter is a vowel and the next letter is a vowel (or the next letter is an ending y ie key), don't count the syllable and continue 
            if (i < word.length() - 1 &&
                (IsVowel(word[i + 1]) || (i == word.length() - 2 && word[i + 1] == 'y')))
            {
                continue;
            }

            // if the word ends in e and has another vowel, the e is silent and not a vowel (ie home)
            // If the word ends with a vowel than an e, don't continue, count it as a syllable (ie ouchie)
            if (i == word.length() - 1 && word[i] == 'e' && syllables > 0 && !(word.length() > 1 && IsVowel(word[i - 1])))
            {
                continue;
            }

            syllables++;
        }
    }

    // if the last letter is y, that is a vowel
    if (word[word.length() - 1] == 'y')
    {
        syllables++;
    }

    // log message if no syllables found
    if (syllables <= 0)
    {
        throw "Error: Got " + std::to_string(syllables) + " syllables for the word " + word + ". Is the word valid? An Invalid word means the text is not a haiku";
    }

    return syllables;
}

// returns whether the character is vowel
bool IsVowel(char c)
{
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }

    return false;
}