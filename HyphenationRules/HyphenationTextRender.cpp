#include "HyphenationTextRender.h"

array<String^>^ HyphenationRules::HyphenationTextRender::Hyphenate(String^ word, int linefeed)
{
    if (word->Length == 0)
        return gcnew array<String^> { word, "" };

    List<String^>^ chapters = gcnew List<String^>();

    int vowelsCounter = 0;
    int consonantsCounter = 0;
    int exclusions = 0;
    int last = 0;
    for (int i = 0; i < word->Length; i++)
    {
        Char c = word[i];

        // 1. Two consecutive vowels can be separated if the first of them is preceded by a consonantand
        // the second is followed by at least one letter(the letter `é` in this case is considered
        // together with the preceding vowel as a whole).
        if (IsVowel(c))
        {
            vowelsCounter++;
            if (vowelsCounter == 2 && i >= 2 && i + 1 < word->Length)
            {
                if (IsConsonant(word[i - 2]) && (IsConsonant(word[i + 1]) || IsExclusion(word[i + 1])))
                {
                    chapters->Add(word->Substring(0, i));
                    last = i;
                    vowelsCounter = 0;
                    break;
                }
            }
        }
        else
        {
            vowelsCounter = 0;
        }

        // 2. Two consecutive consonants can be separated if the first of them is preceded by a voweland there
        // is at least one vowel in the part of the word that comes after the second consonant
        // (the letters `ü`, `ú` together with the preceding consonant are treated as one whole).
        if (IsConsonant(c))
        {
            consonantsCounter++;
            if (consonantsCounter == 2 && i >= 2 && i + 1 < word->Length)
            {
                if (IsVowel(word[i - 2]) && (IsConsonant(word[i + 1]) || IsExclusion(word[i + 1])))
                {
                    chapters->Add(word->Substring(0, i));
                    last = i;
                    consonantsCounter = 0;
                    break;
                }
            }
        }
        else
        {
            consonantsCounter = 0;
        }
    }

    if (chapters->Count < 1)
    {
        // 3. If you fail to apply the clauses `(1)`, `(2)`, you should try to divide the word so that the first part contains more than one 
        // letterand ends in a vowel, the second part contains at least one vowel.The probability of correct partitioning increases if we first use
        // at least an incomplete list of prefixes containing vowels and try to distinguish such a prefix from a word first.
        for (int i = 0; i < word->Length; i++)
        {
            Char c = word[i];
            if (IsVowel(c) && i >= 1 && i + 1 < word->Length)
            {
                if (HasVowels(word->Substring(i)))
                {
                    chapters->Add(word->Substring(0, i + 1));
                    last = i + 1;
                    break;
                }
            }
        }
    }
    chapters->Add(word->Substring(last));

    if (chapters->Count < 2)
        return gcnew array<String^> { word, "" };

    return gcnew array<String^> { chapters[0] + "-", chapters[1] };
}

bool HyphenationRules::HyphenationTextRender::IsVowel(Char character)
{
    for (int i = 0; i < Vowels->Length; i++)
    {
        if (Vowels[i] == character)
        {
            return true;
        }
    }
    return false;
}

bool HyphenationRules::HyphenationTextRender::IsConsonant(Char character)
{
    for (int i = 0; i < Consonants->Length; i++)
    {
        if (Consonants[i] == character)
        {
            return true;
        }
    }
    return false;
}

bool HyphenationRules::HyphenationTextRender::IsExclusion(Char character)
{
    for (int i = 0; i < Exclusions->Length; i++)
    {
        if (Exclusions[i] == character)
        {
            return true;
        }
    }
    return false;
}

bool HyphenationRules::HyphenationTextRender::HasVowels(String^ chapter)
{
    for (int i = 0; i < chapter->Length; i++)
    {
        if (IsVowel(chapter[i]))
        {
            return true;
        }
    }
    return false;
}

String^ HyphenationRules::HyphenationTextRender::Render(String^ text, int lineLength)
{
    if (text->Length == 0)
        return "";

    List<String^>^ newTextList = gcnew List<String^>();
    array<Char>^ sep = gcnew array<Char>{
        ' ',
    };
    List<String^>^ words = gcnew List<String^>(text->Split(sep, StringSplitOptions::None));
    String^ newLineText = "";
    

    for (int i = 0; i < words->Count; i++)
    {
        int linefeed = newLineText->Length + words[i]->Length;
        if (linefeed >= lineLength)
        {
            array<String^>^ word = Hyphenate(words[i], linefeed);
            String^ firstChapter = word[0];
            String^ secondChapter = word[1];

            if (newLineText->Length + firstChapter->Length >= lineLength)
            {
                newTextList->Add(newLineText);
                newLineText = gcnew String("");
                newLineText += words[i] + " ";
            }
            else
            {
                newTextList->Add(newLineText + " " + firstChapter);
                newLineText = gcnew String("");
                newLineText += secondChapter + " ";
            }
        }
        else
        {
            newLineText += words[i] + " ";
        }
    }



    newTextList->Add(newLineText);
    return String::Join("\n", newTextList);
}
