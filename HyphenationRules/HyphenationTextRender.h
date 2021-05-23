#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace HyphenationRules {
	ref class HyphenationTextRender
	{
	private:
		static String^ Vowels = "������������������ި";
		static String^ Consonants = "����������������������������������������";
		static String^ Exclusions = "������";
		static array<String^>^ Hyphenate(String^ word, int linefeed);
		static bool IsVowel(Char character);
		static bool IsConsonant(Char character);
		static bool IsExclusion(Char character);
		static bool HasVowels(String^ chapter);
	public:
		static String^ Render(String^ text, int lineLength);
	};
}
