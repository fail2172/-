#pragma once

namespace оконныйбанкомат {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::PrintDialog^ printDialog1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;




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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(363, 527);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 85);
			this->button1->TabIndex = 0;
			this->button1->Text = L"¬¬ќƒ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(164, 258);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(63, 65);
			this->button2->TabIndex = 1;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(266, 258);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(63, 65);
			this->button3->TabIndex = 2;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(266, 437);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 65);
			this->button4->TabIndex = 3;
			this->button4->Text = L"8";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(164, 350);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(63, 65);
			this->button5->TabIndex = 4;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(363, 258);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(63, 65);
			this->button6->TabIndex = 5;
			this->button6->Text = L"3";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(363, 350);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(63, 65);
			this->button7->TabIndex = 6;
			this->button7->Text = L"6";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(266, 350);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(63, 65);
			this->button8->TabIndex = 7;
			this->button8->Text = L"5";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(266, 527);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(63, 65);
			this->button9->TabIndex = 8;
			this->button9->Text = L"0";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(363, 437);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(63, 65);
			this->button10->TabIndex = 9;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(164, 437);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(63, 65);
			this->button11->TabIndex = 10;
			this->button11->Text = L"7";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(90, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(403, 211);
			this->textBox1->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(449, 294);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(169, 22);
			this->textBox2->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 658);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
