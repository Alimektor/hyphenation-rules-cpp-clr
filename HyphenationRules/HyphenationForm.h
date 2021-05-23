#pragma once

#include "HyphenationTextRender.h"

namespace HyphenationRules {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ HyphenationForm
	/// </summary>
	public ref class HyphenationForm : public System::Windows::Forms::Form
	{
	public:
		int SymbolsNumber = 120;
		HyphenationForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~HyphenationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TrackBar^ SizeTextTrackBar;



	private: System::Windows::Forms::Label^ ResultLabel;


	private: System::Windows::Forms::Label^ SourceLabel;
	private: System::Windows::Forms::RichTextBox^ SourceTextBox;
	private: System::Windows::Forms::RichTextBox^ ResultTextBox;




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SizeTextTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->SourceLabel = (gcnew System::Windows::Forms::Label());
			this->SourceTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->ResultTextBox = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SizeTextTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// SizeTextTrackBar
			// 
			this->SizeTextTrackBar->LargeChange = 20;
			this->SizeTextTrackBar->Location = System::Drawing::Point(1127, 31);
			this->SizeTextTrackBar->Maximum = 200;
			this->SizeTextTrackBar->Minimum = 20;
			this->SizeTextTrackBar->Name = L"SizeTextTrackBar";
			this->SizeTextTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->SizeTextTrackBar->Size = System::Drawing::Size(45, 370);
			this->SizeTextTrackBar->SmallChange = 20;
			this->SizeTextTrackBar->TabIndex = 1;
			this->SizeTextTrackBar->TickFrequency = 20;
			this->SizeTextTrackBar->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->SizeTextTrackBar->Value = 20;
			this->SizeTextTrackBar->Scroll += gcnew System::EventHandler(this, &HyphenationForm::SizeTextTrackBar_Scroll);
			// 
			// ResultLabel
			// 
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Location = System::Drawing::Point(380, 9);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(191, 13);
			this->ResultLabel->TabIndex = 5;
			this->ResultLabel->Text = L"Result Text (Symbols in the line: (20)";
			// 
			// SourceLabel
			// 
			this->SourceLabel->AutoSize = true;
			this->SourceLabel->Location = System::Drawing::Point(13, 10);
			this->SourceLabel->Name = L"SourceLabel";
			this->SourceLabel->Size = System::Drawing::Size(65, 13);
			this->SourceLabel->TabIndex = 4;
			this->SourceLabel->Text = L"Source Text";
			// 
			// SourceTextBox
			// 
			this->SourceTextBox->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SourceTextBox->Location = System::Drawing::Point(16, 31);
			this->SourceTextBox->Name = L"SourceTextBox";
			this->SourceTextBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->SourceTextBox->Size = System::Drawing::Size(350, 370);
			this->SourceTextBox->TabIndex = 2;
			this->SourceTextBox->Text = L"";
			this->SourceTextBox->TextChanged += gcnew System::EventHandler(this, &HyphenationForm::SourceTextBox_TextChanged);
			// 
			// ResultTextBox
			// 
			this->ResultTextBox->Font = (gcnew System::Drawing::Font(L"Georgia", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultTextBox->Location = System::Drawing::Point(383, 31);
			this->ResultTextBox->Name = L"ResultTextBox";
			this->ResultTextBox->ReadOnly = true;
			this->ResultTextBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->ResultTextBox->Size = System::Drawing::Size(738, 370);
			this->ResultTextBox->TabIndex = 3;
			this->ResultTextBox->Text = L"";
			this->ResultTextBox->WordWrap = false;
			// 
			// HyphenationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 418);
			this->Controls->Add(this->ResultTextBox);
			this->Controls->Add(this->SourceTextBox);
			this->Controls->Add(this->ResultLabel);
			this->Controls->Add(this->SourceLabel);
			this->Controls->Add(this->SizeTextTrackBar);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1200, 457);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1200, 457);
			this->Name = L"HyphenationForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Hyphenation Rules";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SizeTextTrackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RenderText();
	private: System::Void SizeTextTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SourceTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
