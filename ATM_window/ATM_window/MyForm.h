#pragma once
#include "ATM.h"

namespace ATMwindow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:  System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ Cancel;
	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::Label^ label1;
	private: 
		int number_of_card;
		int push_card;
		bool insert_card = true;
		bool pincode_code_input = false;
		bool options = false;
		bool sum = false;
		bool chose = false;
		bool check = false;
		bool card = false;
		bool withdraw = false;
		bool phone = false;
		char* pincode = "";
		char* withdrawing_amount = "";
		char* other_card = "";
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
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
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::WindowText;
			this->textBox2->Location = System::Drawing::Point(539, 169);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(130, 22);
			this->textBox2->TabIndex = 11;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Ivory;
			this->button1->Location = System::Drawing::Point(203, 274);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 60);
			this->button1->TabIndex = 1;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Ivory;
			this->button2->Location = System::Drawing::Point(263, 274);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(61, 60);
			this->button2->TabIndex = 2;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Ivory;
			this->button3->Location = System::Drawing::Point(323, 274);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(61, 60);
			this->button3->TabIndex = 3;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Ivory;
			this->button4->Location = System::Drawing::Point(203, 333);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(61, 60);
			this->button4->TabIndex = 4;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Ivory;
			this->button5->Location = System::Drawing::Point(263, 333);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(61, 60);
			this->button5->TabIndex = 5;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Ivory;
			this->button6->Location = System::Drawing::Point(323, 333);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(61, 60);
			this->button6->TabIndex = 6;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Ivory;
			this->button7->Location = System::Drawing::Point(203, 392);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(61, 60);
			this->button7->TabIndex = 7;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Ivory;
			this->button8->Location = System::Drawing::Point(263, 392);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(61, 60);
			this->button8->TabIndex = 8;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Ivory;
			this->button9->Location = System::Drawing::Point(323, 392);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(61, 60);
			this->button9->TabIndex = 9;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::Ivory;
			this->button10->Location = System::Drawing::Point(263, 451);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(61, 60);
			this->button10->TabIndex = 10;
			this->button10->Text = L"0";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// Cancel
			// 
			this->Cancel->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Cancel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Cancel->Location = System::Drawing::Point(383, 274);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(113, 60);
			this->Cancel->TabIndex = 12;
			this->Cancel->Text = L"Отмена\r\nCancle";
			this->Cancel->UseVisualStyleBackColor = false;
			this->Cancel->Click += gcnew System::EventHandler(this, &MyForm::Cancel_Click);
			// 
			// Enter
			// 
			this->Enter->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Enter->ForeColor = System::Drawing::Color::Green;
			this->Enter->Location = System::Drawing::Point(383, 333);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(113, 60);
			this->Enter->TabIndex = 13;
			this->Enter->Text = L"Ввод\r\nEnter";
			this->Enter->UseVisualStyleBackColor = false;
			this->Enter->Click += gcnew System::EventHandler(this, &MyForm::Enter_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label1->Location = System::Drawing::Point(581, 149);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"карта";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->textBox1->Location = System::Drawing::Point(182, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(323, 221);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Вставте карту";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(97, 12);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(79, 30);
			this->button13->TabIndex = 15;
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(97, 77);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(79, 30);
			this->button14->TabIndex = 16;
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(97, 142);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(79, 30);
			this->button15->TabIndex = 17;
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(97, 203);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(79, 30);
			this->button16->TabIndex = 18;
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::MenuText;
			this->textBox3->ForeColor = System::Drawing::Color::Lime;
			this->textBox3->Location = System::Drawing::Point(252, 244);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(186, 22);
			this->textBox3->TabIndex = 19;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox4->Location = System::Drawing::Point(22, 268);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(131, 229);
			this->textBox4->TabIndex = 20;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button11->Location = System::Drawing::Point(383, 392);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(113, 60);
			this->button11->TabIndex = 21;
			this->button11->Text = L"Достать карту\r\n";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::Red;
			this->button12->Location = System::Drawing::Point(29, 229);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(27, 26);
			this->button12->TabIndex = 22;
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGreen;
			this->ClientSize = System::Drawing::Size(701, 517);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->textBox2);
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
			this->Controls->Add(this->textBox1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (insert_card) {
		Card card(stoi(msclr::interop::marshal_as<string>(textBox2->Text)));
		push_card = stoi(msclr::interop::marshal_as<string>(textBox2->Text));
		Bank bank;
		Session session(bank, card);
		session.initialization();
		number_of_card = session.position_of_card;
		textBox1->Text = "Введите пинкод :\r\n";
		pincode_code_input = true;
		insert_card = false;
	}
}   
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '1';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '1';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "1";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '1';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "1";
	}
	else if (phone) {
		textBox1->Text += "1";
	}
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '0';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '0';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "0";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '0';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "0";
	}
	else if (phone) {
		textBox1->Text += "0";
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '2';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '2';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "2";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '2';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "2";
	}
	else if (phone) {
		textBox1->Text += "2";
	}
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '9';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '9';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "9";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '9';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "9";
	}
	else if (phone) {
		textBox1->Text += "9";
	}
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '8';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '8';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "8";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '8';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "8";
	}
	else if (phone) {
		textBox1->Text += "8";
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '3';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '3';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "3";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '3';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "3";
	}
	else if (phone) {
		textBox1->Text += "3";
	}
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '7';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '7';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "7";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '7';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "7";
	}
	else if (phone) {
		textBox1->Text += "7";
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '6';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '6';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "6";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '6';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "6";
	}
	else if (phone) {
		textBox1->Text += "6";
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '5';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '5';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "5";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '5';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "5";
	}
	else if (phone) {
		textBox1->Text += "5";
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input) {
		string temp_pincode(pincode);
		pincode = new char[temp_pincode.size() + 2];
		for (size_t i = 0; i < temp_pincode.size(); ++i) {
			pincode[i] = temp_pincode[i];
		}
		pincode[temp_pincode.size()] = '4';
		pincode[temp_pincode.size() + 1] = '\0';
		textBox1->Text += "*";
	}
	else if (withdraw) {
		string temp_sum(withdrawing_amount);
		withdrawing_amount = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			withdrawing_amount[i] = temp_sum[i];
		}
		withdrawing_amount[temp_sum.size()] = '4';
		withdrawing_amount[temp_sum.size() + 1] = '\0';
		textBox1->Text += "4";
	}
	else if (card) {
		string temp_sum(other_card);
		other_card = new char[temp_sum.size() + 2];
		for (size_t i = 0; i < temp_sum.size(); ++i) {
			other_card[i] = temp_sum[i];
		}
		other_card[temp_sum.size()] = '4';
		other_card[temp_sum.size() + 1] = '\0';
		textBox1->Text += "4";
	}
	else if (phone) {
		textBox1->Text += "4";
	}
}
private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input && strlen(pincode)) {
		string temp_str(pincode);
		pincode = new char[temp_str.size()];
		for (size_t i = 0; i < temp_str.size() - 1; ++i) {
			pincode[i] = temp_str[i];
		}
		pincode[temp_str.size() - 1] = '\0';
		textBox1->Text = "Введите пинкод :\r\n";
		for (size_t i = 0; i < temp_str.size() - 1; i++) {
			textBox1->Text += "*";
		}
	}
	else if (chose) {
		textBox1->Text = "Печатать чек?\r\n";
		textBox1->Text += "ДА : ВВОД\r\n";
		textBox1->Text += "НЕТ : ОТМЕНА";
		chose = false;
		check = true;
	}
	else if (check) {
		textBox1->Text = "Вставте карту";
		pincode[0] = '\0';
		insert_card = true;
		check = false;
	}
	else if (withdraw && strlen(withdrawing_amount)) {
		string temp_str(withdrawing_amount);
		withdrawing_amount = new char[temp_str.size()];
		for (size_t i = 0; i < temp_str.size() - 1; ++i) {
			withdrawing_amount[i] = temp_str[i];
		}
		withdrawing_amount[temp_str.size() - 1] = '\0';
		textBox1->Text = "Введите сумму :\r\n";
		string element;
		for (size_t i = 0; i < strlen(withdrawing_amount); i++) {
			element = withdrawing_amount[i];
			textBox1->Text += gcnew String(element.c_str());
		}
	}
	else if (card && strlen(other_card)) {
		string temp_str(other_card);
		other_card = new char[temp_str.size()];
		for (size_t i = 0; i < temp_str.size() - 1; ++i) {
			other_card[i] = temp_str[i];
		}
		other_card[temp_str.size() - 1] = '\0';
		textBox1->Text = "Введите номер карты получателя :\r\n";
		string element;
		for (size_t i = 0; i < strlen(other_card); i++) {
			element = other_card[i];
			textBox1->Text += gcnew String(element.c_str());
		}
	}
}
private: System::Void Enter_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pincode_code_input || chose) {
		Bank bank;
		if (string(pincode) == bank.get_pincode(number_of_card)) {
			textBox1->Text = "Снять средства\r\n\r\n\r\n\r\n";
			textBox1->Text += "Положить деньги на телефон\r\n\r\n\r\n\r\n";
			textBox1->Text += "Перевести деньги на другую карту\r\n\r\n\r\n\r\n";
			textBox1->Text += "Прсмотреть данные";
			pincode_code_input = false;
			chose = false;
			options = true;
		}
		else {
			textBox1->Text = "Неверный пинкод\r\n";
			textBox1->Text += "Повторите попытку :\r\n";
			pincode[0] = '\0';
		}
	}
	else if (check) {
		Card card(push_card);
		Bank bank;
		Session session(bank, card);
		session.initialization();
		textBox1->Text = "Вставте карту";
		insert_card = true;
		check = false;
		pincode[0] = '\0';
		textBox4->Text = "\r\n--------------------\r\n\r\n";
		textBox4->Text += "Bank : " + gcnew String(session.get_bank_name().c_str()) + "\r\n";
		textBox4->Text += "Number of card : " + gcnew String(session.get_number_card().c_str()) + "\r\n";
		textBox4->Text += "Cardholder name : " + gcnew String(session.get_cardholder_name().c_str()) + "\r\n";
		textBox4->Text += "Cash : " + gcnew String(to_string(session.get_cash()).c_str()) + "\r\n";
	}
	else if (withdraw) {
		int withdraw_sum = 0;
		for (size_t i = 0; i < strlen(withdrawing_amount); ++i) {
			withdraw_sum = withdraw_sum * 10 + (int)withdrawing_amount[i] - '0';
		}
		Card card(push_card);
		Bank bank;
		Session session(bank, card);
		session.initialization();
		if (session.get_cash() >= withdraw_sum) {
			session.withdraw_money(withdraw_sum);
			textBox1->Text = "Средства успешно сняты\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			string withdrawn_sum(withdrawing_amount);
			withdrawn_sum = string("$") + withdrawn_sum;
			textBox3->Text = gcnew String(withdrawn_sum.c_str());
			sum = false;
			chose = true;
			session.end_of_session();
		}
		else {
			textBox1->Text = "Недостаточно средств!\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			sum = false;
			chose = true;
		}
	}
	else if (card) {
		Card bank_card(push_card);
		Bank bank;
		Session session(bank, bank_card);
		session.initialization();
		int position_of_any_card = 0;
		for(; position_of_any_card <bank.get_size_of_database();++position_of_any_card){
			if (bank.database[position_of_any_card].get_number_card() == string(other_card))break;
		}
		if (position_of_any_card != bank.get_size_of_database()) {
			textBox1->Text = "Введите сумму :\r\n";
			card = false;
			withdraw = true;
		}
		else {
			textBox1->Text = "Карта не найдена!\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			chose = true;
			card = false;
		}
	}
	else if (phone) {
		textBox1->Text = "Введите сумму :\r\n";
		phone = false;
		withdraw = true;
	}
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	if (options) {
		textBox1->Text = "1000\r\n\r\n\r\n\r\n";
		textBox1->Text += "500\r\n\r\n\r\n\r\n";
		textBox1->Text += "200\r\n\r\n\r\n\r\n";
		textBox1->Text += "Другая сумма";
		options = false;
		sum = true;
	}
	else if (sum) {
		Card card(push_card);
		Bank bank;
		Session session(bank, card);
		session.initialization();
		if (session.get_cash() >= 1000) {
			session.withdraw_money(1000);
			textBox1->Text = "Средства успешно сняты\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			textBox3->Text = "$1000";
			sum = false;
			chose = true;
			session.end_of_session();
		}
		else {
			textBox1->Text = "Недостаточно средств!\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			sum = false;
			chose = true;
		}
	}
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	if (options) {
		textBox1->Text = "Введите номер телефона\r\n";
		options = false;
		phone = true;
	}
	else if (sum) {
		Card card(push_card);
		Bank bank;
		Session session(bank, card);
		session.initialization();
		if (session.get_cash() >= 500) {
			session.withdraw_money(500);
			textBox1->Text = "Средства успешно сняты\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			textBox3->Text = "$500";
			sum = false;
			chose = true;
			session.end_of_session();
		}
		else {
			textBox1->Text = "Недостаточно средств!\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			sum = false;
			chose = true;
		}
	}
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	if (options) {
		textBox1->Text = "Введите номер карты получателя :\r\n";
		options = false;
		card = true;
	}
	else if (sum) {
		Card card(push_card);
		Bank bank;
		Session session(bank, card);
		session.initialization();
		if (session.get_cash() >= 200) {
			session.withdraw_money(200);
			textBox1->Text = "Средства успешно сняты\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			textBox3->Text = "$200";
			sum = false;
			chose = true;
			session.end_of_session();
		}
		else {
			textBox1->Text = "Недостаточно средств!\r\n";
			textBox1->Text += "Продолжить : ВВОД\r\n";
			textBox1->Text += "Завершить : ОТМЕНА";
			sum = false;
			chose = true;
		}
	}
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	if (options) {
		Bank bank;
		textBox1->Text = "Банк : " + gcnew String(bank.get_bank_name(number_of_card).c_str()) + "\r\n";
		textBox1->Text += "Номер карты : " + gcnew String(bank.get_number_card(number_of_card).c_str()) + "\r\n";
		textBox1->Text += "Имя пользователь : " + gcnew String(bank.get_cardholder_name(number_of_card).c_str()) + "\r\n";
		textBox1->Text += "Баланс : " + gcnew String(to_string(bank.get_cash(number_of_card)).c_str()) + "\r\n\r\n";

		textBox1->Text += "Продолжить : ВВОД\r\n";
		textBox1->Text += "Завершить : ОТМЕНА";
		options = false;
		chose = true;
	}
	else if (sum) {
		textBox1->Text = "Введите сумму :\r\n";
		withdraw = true;
		sum = false;
	}
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	insert_card = true;
	pincode_code_input = false;
	options = false;
	sum = false;
	chose = false;
	check = false;
	card = false;
	withdraw = false;
	phone = false;
	textBox1->Text = "Вставте карту";
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Clear();
}
};

}
