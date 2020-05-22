#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>

namespace Creativity {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Сводка для Calculator
	/// </summary>
	public ref class Calculator : public System::Windows::Forms::Form
	{
	private:
		array<System::String^>^ alHelp;
    Dictionary<wchar_t, double>^ alphabet;
		Dictionary<int, String^>^ bAlphabet;

  private: System::Windows::Forms::Button^ EasterButton1;
	private:
		SoundPlayer^ sp, ^sBack, ^gBack;

	public:
		Calculator(void)
		{
			InitializeComponent();
      //
			//TODO: добавьте код конструктора
			//

  		this->sp = gcnew SoundPlayer(".\\Res\\sound.wav");
			this->gBack = gcnew SoundPlayer(".\\Res\GodBack.wav");
			this->sBack = gcnew SoundPlayer(".\\Res\\SunBack.wav");

			sBack->PlayLooping();

			std::srand(std::time(0));

			alHelp = gcnew array<System::String^> { "0", "1", "2", "3", "4",
																							"5", "6", "7", "8", "9",
																							"A", "B", "C", "D", "E", "F" };
			wchar_t alHelp2[]{ '0', '1', '2', '3', '4',
												 '5', '6', '7', '8', '9',
												 'A', 'B', 'C', 'D', 'E', 'F' };

			alphabet = gcnew Dictionary<wchar_t, double>(); //Перевод в 10 СС
			bAlphabet = gcnew Dictionary<int, String^>(); //Перевод в другую СС


			for (int i = 0; i < 16; i++)
			{
				alphabet->Add(alHelp2[i], i);
				bAlphabet->Add(i, alHelp[i]);
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox;

	private: System::Windows::Forms::RadioButton^ radioButtonBin;
	private: System::Windows::Forms::RadioButton^ radioButtonTer;
	private: System::Windows::Forms::RadioButton^ radioButtonOct;

	private: System::Windows::Forms::RadioButton^ radioButtonDec;
	private: System::Windows::Forms::Panel^ HexPanel;

	private: System::Windows::Forms::Button^ buttonA;
	private: System::Windows::Forms::Button^ buttonF;
	private: System::Windows::Forms::Button^ buttonE;
	private: System::Windows::Forms::Button^ buttonD;
	private: System::Windows::Forms::Button^ buttonC;
	private: System::Windows::Forms::Button^ buttonB;
	private: System::Windows::Forms::RadioButton^ radioButtonNon;
	private: System::Windows::Forms::RadioButton^ radioButtonHex;

	private: System::Windows::Forms::Button^ button0;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonDot;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Calculator::typeid));
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->radioButtonBin = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonTer = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonOct = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonDec = (gcnew System::Windows::Forms::RadioButton());
			this->HexPanel = (gcnew System::Windows::Forms::Panel());
			this->buttonF = (gcnew System::Windows::Forms::Button());
			this->buttonE = (gcnew System::Windows::Forms::Button());
			this->buttonD = (gcnew System::Windows::Forms::Button());
			this->buttonC = (gcnew System::Windows::Forms::Button());
			this->buttonB = (gcnew System::Windows::Forms::Button());
			this->buttonA = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButtonNon = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonHex = (gcnew System::Windows::Forms::RadioButton());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonDot = (gcnew System::Windows::Forms::Button());
			this->EasterButton1 = (gcnew System::Windows::Forms::Button());
			this->HexPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox
			// 
			this->textBox->BackColor = System::Drawing::SystemColors::Window;
			this->textBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->textBox->Location = System::Drawing::Point(18, 18);
			this->textBox->Margin = System::Windows::Forms::Padding(4);
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->Size = System::Drawing::Size(330, 46);
			this->textBox->TabIndex = 0;
			this->textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &Calculator::textBox_TextChanged);
			// 
			// radioButtonBin
			// 
			this->radioButtonBin->AutoSize = true;
			this->radioButtonBin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->radioButtonBin->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->radioButtonBin->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->radioButtonBin->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonBin->ForeColor = System::Drawing::Color::White;
			this->radioButtonBin->Location = System::Drawing::Point(220, 141);
			this->radioButtonBin->Margin = System::Windows::Forms::Padding(4);
			this->radioButtonBin->Name = L"radioButtonBin";
			this->radioButtonBin->Size = System::Drawing::Size(132, 27);
			this->radioButtonBin->TabIndex = 16;
			this->radioButtonBin->Text = L"Двоичная СС";
			this->radioButtonBin->UseVisualStyleBackColor = false;
			this->radioButtonBin->CheckedChanged += gcnew System::EventHandler(this, &Calculator::radioButtonBin_CheckedChanged);
			// 
			// radioButtonTer
			// 
			this->radioButtonTer->AutoSize = true;
			this->radioButtonTer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->radioButtonTer->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->radioButtonTer->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->radioButtonTer->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonTer->ForeColor = System::Drawing::Color::White;
			this->radioButtonTer->Location = System::Drawing::Point(220, 171);
			this->radioButtonTer->Name = L"radioButtonTer";
			this->radioButtonTer->Size = System::Drawing::Size(132, 27);
			this->radioButtonTer->TabIndex = 17;
			this->radioButtonTer->Text = L"Троичная СС";
			this->radioButtonTer->UseVisualStyleBackColor = false;
			this->radioButtonTer->CheckedChanged += gcnew System::EventHandler(this, &Calculator::radioButtonTer_CheckedChanged);
			// 
			// radioButtonOct
			// 
			this->radioButtonOct->AutoSize = true;
			this->radioButtonOct->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->radioButtonOct->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->radioButtonOct->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->radioButtonOct->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonOct->ForeColor = System::Drawing::Color::White;
			this->radioButtonOct->Location = System::Drawing::Point(220, 201);
			this->radioButtonOct->Name = L"radioButtonOct";
			this->radioButtonOct->Size = System::Drawing::Size(174, 27);
			this->radioButtonOct->TabIndex = 18;
			this->radioButtonOct->Text = L"Восьмеричная СС";
			this->radioButtonOct->UseVisualStyleBackColor = false;
			this->radioButtonOct->CheckedChanged += gcnew System::EventHandler(this, &Calculator::radioButtonOct_CheckedChanged);
			// 
			// radioButtonDec
			// 
			this->radioButtonDec->AutoSize = true;
			this->radioButtonDec->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->radioButtonDec->Checked = true;
			this->radioButtonDec->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->radioButtonDec->FlatAppearance->BorderSize = 0;
			this->radioButtonDec->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->radioButtonDec->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonDec->ForeColor = System::Drawing::Color::White;
			this->radioButtonDec->Location = System::Drawing::Point(220, 259);
			this->radioButtonDec->Name = L"radioButtonDec";
			this->radioButtonDec->Size = System::Drawing::Size(149, 27);
			this->radioButtonDec->TabIndex = 20;
			this->radioButtonDec->TabStop = true;
			this->radioButtonDec->Text = L"Десятичная СС";
			this->radioButtonDec->UseVisualStyleBackColor = false;
			this->radioButtonDec->CheckedChanged += gcnew System::EventHandler(this, &Calculator::radioButtonDec_CheckedChanged);
			// 
			// HexPanel
			// 
			this->HexPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->HexPanel->Controls->Add(this->buttonF);
			this->HexPanel->Controls->Add(this->buttonE);
			this->HexPanel->Controls->Add(this->buttonD);
			this->HexPanel->Controls->Add(this->buttonC);
			this->HexPanel->Controls->Add(this->buttonB);
			this->HexPanel->Controls->Add(this->buttonA);
			this->HexPanel->Location = System::Drawing::Point(18, 72);
			this->HexPanel->Name = L"HexPanel";
			this->HexPanel->Size = System::Drawing::Size(330, 50);
			this->HexPanel->TabIndex = 21;
			// 
			// buttonF
			// 
			this->buttonF->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonF->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonF->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonF->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonF->ForeColor = System::Drawing::Color::White;
			this->buttonF->Location = System::Drawing::Point(280, 0);
			this->buttonF->Name = L"buttonF";
			this->buttonF->Size = System::Drawing::Size(50, 50);
			this->buttonF->TabIndex = 15;
			this->buttonF->Text = L"F";
			this->buttonF->UseVisualStyleBackColor = false;
			this->buttonF->Click += gcnew System::EventHandler(this, &Calculator::buttonF_Click);
			// 
			// buttonE
			// 
			this->buttonE->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonE->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonE->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonE->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonE->ForeColor = System::Drawing::Color::White;
			this->buttonE->Location = System::Drawing::Point(224, 0);
			this->buttonE->Name = L"buttonE";
			this->buttonE->Size = System::Drawing::Size(50, 50);
			this->buttonE->TabIndex = 14;
			this->buttonE->Text = L"E";
			this->buttonE->UseVisualStyleBackColor = false;
			this->buttonE->Click += gcnew System::EventHandler(this, &Calculator::buttonE_Click);
			// 
			// buttonD
			// 
			this->buttonD->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonD->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonD->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonD->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonD->ForeColor = System::Drawing::Color::White;
			this->buttonD->Location = System::Drawing::Point(168, 0);
			this->buttonD->Name = L"buttonD";
			this->buttonD->Size = System::Drawing::Size(50, 50);
			this->buttonD->TabIndex = 13;
			this->buttonD->Text = L"D";
			this->buttonD->UseVisualStyleBackColor = false;
			this->buttonD->Click += gcnew System::EventHandler(this, &Calculator::buttonD_Click);
			// 
			// buttonC
			// 
			this->buttonC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonC->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonC->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonC->ForeColor = System::Drawing::Color::White;
			this->buttonC->Location = System::Drawing::Point(112, 0);
			this->buttonC->Name = L"buttonC";
			this->buttonC->Size = System::Drawing::Size(50, 50);
			this->buttonC->TabIndex = 12;
			this->buttonC->Text = L"C";
			this->buttonC->UseVisualStyleBackColor = false;
			this->buttonC->Click += gcnew System::EventHandler(this, &Calculator::buttonC_Click);
			// 
			// buttonB
			// 
			this->buttonB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonB->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonB->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonB->ForeColor = System::Drawing::Color::White;
			this->buttonB->Location = System::Drawing::Point(56, 0);
			this->buttonB->Name = L"buttonB";
			this->buttonB->Size = System::Drawing::Size(50, 50);
			this->buttonB->TabIndex = 11;
			this->buttonB->Text = L"B";
			this->buttonB->UseVisualStyleBackColor = false;
			this->buttonB->Click += gcnew System::EventHandler(this, &Calculator::buttonB_Click);
			// 
			// buttonA
			// 
			this->buttonA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonA->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonA->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonA->ForeColor = System::Drawing::Color::White;
			this->buttonA->Location = System::Drawing::Point(0, 0);
			this->buttonA->Name = L"buttonA";
			this->buttonA->Size = System::Drawing::Size(50, 50);
			this->buttonA->TabIndex = 10;
			this->buttonA->Text = L"A";
			this->buttonA->UseVisualStyleBackColor = false;
			this->buttonA->Click += gcnew System::EventHandler(this, &Calculator::buttonA_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Location = System::Drawing::Point(130, 128);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(50, 50);
			this->button9->TabIndex = 9;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Calculator::button9_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Location = System::Drawing::Point(74, 128);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(50, 50);
			this->button8->TabIndex = 8;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Calculator::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Location = System::Drawing::Point(18, 128);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 50);
			this->button7->TabIndex = 7;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Calculator::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(130, 184);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 50);
			this->button6->TabIndex = 6;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Calculator::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(74, 184);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 50);
			this->button5->TabIndex = 5;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Calculator::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(18, 184);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 50);
			this->button4->TabIndex = 4;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Calculator::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(130, 240);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 50);
			this->button3->TabIndex = 3;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Calculator::button3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(18, 240);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Calculator::button1_Click);
			// 
			// button0
			// 
			this->button0->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button0->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button0->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button0->ForeColor = System::Drawing::Color::White;
			this->button0->Location = System::Drawing::Point(18, 296);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(50, 50);
			this->button0->TabIndex = 0;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = false;
			this->button0->Click += gcnew System::EventHandler(this, &Calculator::button0_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(74, 240);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 50);
			this->button2->TabIndex = 0;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Calculator::button2_Click);
			// 
			// radioButtonNon
			// 
			this->radioButtonNon->AutoSize = true;
			this->radioButtonNon->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->radioButtonNon->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->radioButtonNon->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->radioButtonNon->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonNon->ForeColor = System::Drawing::Color::White;
			this->radioButtonNon->Location = System::Drawing::Point(220, 230);
			this->radioButtonNon->Name = L"radioButtonNon";
			this->radioButtonNon->Size = System::Drawing::Size(170, 27);
			this->radioButtonNon->TabIndex = 19;
			this->radioButtonNon->TabStop = true;
			this->radioButtonNon->Text = L"Девятеричная СС";
			this->radioButtonNon->UseVisualStyleBackColor = false;
			this->radioButtonNon->CheckedChanged += gcnew System::EventHandler(this, &Calculator::radioButtonNon_CheckedChanged);
			// 
			// radioButtonHex
			// 
			this->radioButtonHex->AutoSize = true;
			this->radioButtonHex->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->radioButtonHex->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->radioButtonHex->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->radioButtonHex->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonHex->ForeColor = System::Drawing::Color::White;
			this->radioButtonHex->Location = System::Drawing::Point(220, 289);
			this->radioButtonHex->Name = L"radioButtonHex";
			this->radioButtonHex->Size = System::Drawing::Size(222, 27);
			this->radioButtonHex->TabIndex = 21;
			this->radioButtonHex->TabStop = true;
			this->radioButtonHex->Text = L"Шестнадцатиричная СС";
			this->radioButtonHex->UseVisualStyleBackColor = false;
			this->radioButtonHex->CheckedChanged += gcnew System::EventHandler(this, &Calculator::radioButtonHex_CheckedChanged);
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonClear->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClear->ForeColor = System::Drawing::Color::White;
			this->buttonClear->Location = System::Drawing::Point(355, 18);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(106, 46);
			this->buttonClear->TabIndex = 22;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = false;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Calculator::buttonClear_Click);
			// 
			// buttonDot
			// 
			this->buttonDot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(212)));
			this->buttonDot->Cursor = System::Windows::Forms::Cursors::Default;
			this->buttonDot->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->buttonDot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDot->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDot->ForeColor = System::Drawing::Color::White;
			this->buttonDot->Location = System::Drawing::Point(74, 296);
			this->buttonDot->Name = L"buttonDot";
			this->buttonDot->Size = System::Drawing::Size(50, 50);
			this->buttonDot->TabIndex = 23;
			this->buttonDot->Text = L"•";
			this->buttonDot->UseVisualStyleBackColor = false;
			this->buttonDot->Click += gcnew System::EventHandler(this, &Calculator::buttonDot_Click);
			this->buttonDot->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Calculator::buttonDot_MouseMove);
			// 
			// EasterButton1
			// 
			this->EasterButton1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->EasterButton1->FlatAppearance->BorderSize = 5;
			this->EasterButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EasterButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->EasterButton1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->EasterButton1->Location = System::Drawing::Point(500, 70);
			this->EasterButton1->Name = L"EasterButton1";
			this->EasterButton1->Size = System::Drawing::Size(25, 25);
			this->EasterButton1->TabIndex = 24;
			this->EasterButton1->Text = L"&Spain";
			this->EasterButton1->UseVisualStyleBackColor = true;
			this->EasterButton1->Click += gcnew System::EventHandler(this, &Calculator::EasterButton1_Click);
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientSize = System::Drawing::Size(477, 356);
			this->Controls->Add(this->EasterButton1);
			this->Controls->Add(this->buttonDot);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->radioButtonHex);
			this->Controls->Add(this->radioButtonNon);
			this->Controls->Add(this->HexPanel);
			this->Controls->Add(this->radioButtonDec);
			this->Controls->Add(this->radioButtonOct);
			this->Controls->Add(this->radioButtonTer);
			this->Controls->Add(this->radioButtonBin);
			this->Controls->Add(this->textBox);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Calculator";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &Calculator::Calculator_Load);
			this->HexPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
  private: System::Void EnableBtn(int n)
		{
			switch (n)
			{ //fall-through
			case 10: 
				this->button9->Enabled = true;
			case 9:
				this->button8->Enabled = true;
			case 8:
				this->button3->Enabled = true;
				this->button4->Enabled = true;
				this->button5->Enabled = true;
				this->button6->Enabled = true;
				this->button7->Enabled = true;
			case 3:
				this->button2->Enabled = true;
			case 2:
				this->button1->Enabled = true;
				this->button0->Enabled = true;
				this->HexPanel->Enabled = false;
				break;

			default:
				EnableBtn(10);
				this->HexPanel->Enabled = true;
			}
		}

	private: System::Void DisableBtn(int n)
	{
		switch (n)
		{ //fall-through
		case 2:
			this->button2->Enabled = false;
		case 3:
			this->button3->Enabled = false;
			this->button4->Enabled = false;
			this->button5->Enabled = false;
			this->button6->Enabled = false;
			this->button7->Enabled = false;
		case 8:
			this->button8->Enabled = false;
		case 9:
			this->button9->Enabled = false;
			break;
		}
	}

	private:
		int tbCurrentSystem;

	private: 
		bool dotStatus; //Была ли нажата точка

	private: System::Void ChangeDotStatus()
	{
		this->dotStatus = !dotStatus;
		this->buttonDot->Enabled = !dotStatus;
	}

	private: System::Void InputLetter(System::String^ letter)
	{
		if (letter == "0" && this->textBox->Text == "0") return;

		if (letter == ".") ChangeDotStatus();
		if ((letter != "0" && letter != ".") && this->textBox->Text == "0") this->textBox->Text = "";
		this->textBox->Text += System::Convert::ToString(letter);
	}

	private: System::Void ConvertToOtherSystem(int sys)
	{
		if (this->textBox->Text == "" || sys == this->tbCurrentSystem)
			return;

		System::String^ newText = "";
		System::String^ oldText = this->textBox->Text;

		if (!dotStatus) //Если точки при вводе не было
		{
			int oldTextDec = 0; //Значит число будет целым

			for (int i = 0, N = this->textBox->Text->Length; i < N; i++) //Перевод в 10-ю СС
			{
				const wchar_t c = oldText[N - i - 1]; //Символ
				int weight = alphabet[c]; //"Вес" символа в 10-й СС
				oldTextDec += (weight * (std::pow(this->tbCurrentSystem, i))); //Перевод
			}

			oldText = ""; int c = 0;
			while (oldTextDec != 0) //Запись числа в новой СС
			{
				int index = oldTextDec % sys; //ПОлучение "веса" нового символа
				oldText += bAlphabet[index]; //Поиск нового символа
				oldTextDec /= sys; //Отсечение последнего
				c++; //Количество цифр в новом числе
			}

			for (int i = 0; i < c; i++) //Цикл реверса строки с числом (запись шла в обратном порядке)
				newText += oldText[c - i - 1];
		}
		else //Иначе
		{
			long double oldTextDec = 0.0; //Число было дробным

			int dPos = 0; //Позиция точки в строке
			bool dot = false; //Флаг найденной точки

			while (!dot) //Пока точка не найдена
			{
				if (oldText[dPos] == '.') //если символ -- точка
					dot = true; //Поднимаем флаг
				else dPos++; //Иначе переходим к следующему символу
			}

			for (int i = 0; i < dPos; i++) //Перевод целой части в 10-ю СС
			{
				const wchar_t c = oldText[dPos - i - 1];
				long double weight = alphabet[c];
				oldTextDec += (weight * (std::pow(this->tbCurrentSystem, i)));
			}

			for (int i = dPos + 1, N = this->textBox->Text->Length; i < N; i++) //Перевод дробной части в 10-ю СС
			{
				const wchar_t c = oldText[i];
				long double weight = alphabet[c];
				oldTextDec += (weight * (std::pow(this->tbCurrentSystem, (dPos - i))));
			}

			long double temp;
			long double afterDot = std::modf(oldTextDec, &temp); //Отделяем целую и дробную часть для работы отдеьно с каждой
			int beforeDot = int(std::trunc(temp));

			oldText = "";
			int c = 0;
			if (beforeDot == 0) //Если целой части не было
				newText += "0"; //Вписываем ноль
			else
			{
				while (beforeDot != 0) //Иначе переводим целую часть в новую СС
				{
					int index = beforeDot % sys;
					oldText += bAlphabet[index];
					beforeDot /= sys;
					c++;
				}

				for (int i = 0; i < c; i++)
					newText += oldText[c - i - 1];
			}

			newText += "."; //Точка после целой части

			c = 10; //Точность хранения дробной части
			while (c-- && afterDot != 0) //Переводим дробную часть в новую СС
			{
				afterDot *= sys;
				int index = int(std::trunc(afterDot));
				newText += bAlphabet[index];
				afterDot = std::modf(afterDot, &temp);
			}
		}
		this->textBox->Text = newText; //Обновление числа в textBox

		tbCurrentSystem = sys; //Изменение текущей активной СС
	}

	private: System::Void Calculator_Load(System::Object^ sender, System::EventArgs^ e) {
		EnableBtn(10);
		this->tbCurrentSystem = 10;
		this->dotStatus = false;
	}

	private: System::Void textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void radioButtonBin_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		EnableBtn(2);
		DisableBtn(2);
		ConvertToOtherSystem(2);
	}
	private: System::Void radioButtonTer_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		EnableBtn(3);
		DisableBtn(3);
		ConvertToOtherSystem(3);
	}
	private: System::Void radioButtonOct_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		EnableBtn(8);
		DisableBtn(8);
		ConvertToOtherSystem(8);
	}
	private: System::Void radioButtonNon_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		EnableBtn(9);
		DisableBtn(9);
		ConvertToOtherSystem(9);
	}
	private: System::Void radioButtonDec_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		EnableBtn(10);
		ConvertToOtherSystem(10);
	}
	private: System::Void radioButtonHex_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		EnableBtn(16);
		ConvertToOtherSystem(16);
	}
	private: System::Void button0_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter("0");
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button1->Text);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button2->Text);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button3->Text);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button4->Text);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button5->Text);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button6->Text);
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button7->Text);
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button8->Text);
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->button9->Text);
	}
	private: System::Void buttonA_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->buttonA->Text);
	}
	private: System::Void buttonB_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->buttonB->Text);
	}
	private: System::Void buttonC_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->buttonC->Text);
	}
	private: System::Void buttonD_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->buttonD->Text);
	}
	private: System::Void buttonE_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->buttonE->Text);
	}
	private: System::Void buttonF_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(this->buttonF->Text);
	}
	private: System::Void buttonDot_Click(System::Object^ sender, System::EventArgs^ e) {
		InputLetter(".");
	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox->Text = System::Convert::ToString("");
		if (this->dotStatus) this->ChangeDotStatus();
	}
private: System::Void buttonDot_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void EasterButton1_Click(System::Object^ sender, System::EventArgs^ e) {

  this->sp->Play();

	this->gBack->Play();
	this->sBack->PlayLooping();
}
};
}
