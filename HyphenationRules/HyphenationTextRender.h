#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace HyphenationRules {
	ref class HyphenationTextRender
	{
	private:
		static String^ Vowels = "óåûàîıÿèş¸ÓÅÛÀÎİßÈŞ¨";
		static String^ Consonants = "öêíãøùçõôâïğëäæ÷ñìòáÖÊÍÃØÙÇÕÔÂÏĞËÄÆ×ÑÌÒÁ";
		static String^ Exclusions = "éüúÉÜÚ";
		static array<String^>^ Hyphenate(String^ word, int linefeed);
		static bool IsVowel(Char character);
		static bool IsConsonant(Char character);
		static bool IsExclusion(Char character);
		static bool HasVowels(String^ chapter);
	public:
		static String^ Render(String^ text, int lineLength);
	};
}
