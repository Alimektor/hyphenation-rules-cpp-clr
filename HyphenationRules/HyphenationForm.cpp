#include "HyphenationForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	HyphenationRules::HyphenationForm form;
	Application::Run(% form);
}

System::Void HyphenationRules::HyphenationForm::RenderText()
{
	RichTextBox^ sourceBox = this->SourceTextBox;
	RichTextBox^ resultBox = this->ResultTextBox;
	TrackBar^ bar = this->SizeTextTrackBar;

	SymbolsNumber = bar->Value;
	this->ResultLabel->Text = L"Result Text (Symbols in the line: " + SymbolsNumber + ")";

	String^ text = sourceBox->Text;

	String^ newText = HyphenationRules::HyphenationTextRender::Render(text, SymbolsNumber);

	resultBox->Text = newText;
}

System::Void HyphenationRules::HyphenationForm::SizeTextTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	this->RenderText();
}

System::Void HyphenationRules::HyphenationForm::SourceTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->RenderText();
}
