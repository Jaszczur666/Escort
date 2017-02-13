#pragma once
int i=0;
#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
#include <fstream>
using namespace System::IO;
using namespace System::IO::Ports;
double mnoznik(double freq,double range)
{
	if (freq==0||freq==1) return pow(10,range-12);
	if (freq==2) return pow(10,range-13);
	if (freq==3) return pow(10,range-14);
	return 0;
}
int metexg=0;
double volt[4]={0,0,0,0};
double cap;
double tand;

namespace Escort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected: 
	private: System::Windows::Forms::Timer^  timer1;
	private: System::IO::Ports::SerialPort^  Escort;
	private: System::IO::Ports::SerialPort^  Metex;


	private: System::Windows::Forms::Button^  RunButton;
	private: System::Windows::Forms::Button^  PauseButt;
	private: System::Windows::Forms::Button^  ResetButton;
	private: System::Windows::Forms::ComboBox^  MetexBox;
	private: System::Windows::Forms::ComboBox^  EscortBox;



	private: System::Windows::Forms::Button^  ScanButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  ABut;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;





	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Escort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->Metex = (gcnew System::IO::Ports::SerialPort(this->components));
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->PauseButt = (gcnew System::Windows::Forms::Button());
			this->ResetButton = (gcnew System::Windows::Forms::Button());
			this->MetexBox = (gcnew System::Windows::Forms::ComboBox());
			this->EscortBox = (gcnew System::Windows::Forms::ComboBox());
			this->ScanButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ABut = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(264, 8);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Color = System::Drawing::Color::Red;
			series1->Name = L"cap";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Color = System::Drawing::Color::RoyalBlue;
			series2->Name = L"loss";
			series2->YAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(910, 577);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &Form1::chart1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Escort
			// 
			this->Escort->DataBits = 6;
			this->Escort->DtrEnable = true;
			this->Escort->PortName = L"COM16";
			this->Escort->RtsEnable = true;
			this->Escort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived);
			// 
			// Metex
			// 
			this->Metex->DataBits = 7;
			this->Metex->DtrEnable = true;
			this->Metex->PortName = L"COM17";
			this->Metex->StopBits = System::IO::Ports::StopBits::Two;
			this->Metex->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::Metex_DataReceived);
			// 
			// RunButton
			// 
			this->RunButton->Location = System::Drawing::Point(12, 12);
			this->RunButton->Name = L"RunButton";
			this->RunButton->Size = System::Drawing::Size(75, 23);
			this->RunButton->TabIndex = 1;
			this->RunButton->Text = L"Run";
			this->RunButton->UseVisualStyleBackColor = true;
			this->RunButton->Click += gcnew System::EventHandler(this, &Form1::RunButton_Click);
			// 
			// PauseButt
			// 
			this->PauseButt->Location = System::Drawing::Point(93, 12);
			this->PauseButt->Name = L"PauseButt";
			this->PauseButt->Size = System::Drawing::Size(75, 23);
			this->PauseButt->TabIndex = 2;
			this->PauseButt->Text = L"Pause";
			this->PauseButt->UseVisualStyleBackColor = true;
			this->PauseButt->Click += gcnew System::EventHandler(this, &Form1::PauseButt_Click);
			// 
			// ResetButton
			// 
			this->ResetButton->Location = System::Drawing::Point(174, 12);
			this->ResetButton->Name = L"ResetButton";
			this->ResetButton->Size = System::Drawing::Size(75, 23);
			this->ResetButton->TabIndex = 3;
			this->ResetButton->Text = L"Reset";
			this->ResetButton->UseVisualStyleBackColor = true;
			this->ResetButton->Click += gcnew System::EventHandler(this, &Form1::ResetButton_Click);
			// 
			// MetexBox
			// 
			this->MetexBox->FormattingEnabled = true;
			this->MetexBox->Location = System::Drawing::Point(12, 353);
			this->MetexBox->Name = L"MetexBox";
			this->MetexBox->Size = System::Drawing::Size(75, 21);
			this->MetexBox->TabIndex = 4;
			// 
			// EscortBox
			// 
			this->EscortBox->FormattingEnabled = true;
			this->EscortBox->Location = System::Drawing::Point(104, 353);
			this->EscortBox->Name = L"EscortBox";
			this->EscortBox->Size = System::Drawing::Size(75, 21);
			this->EscortBox->TabIndex = 5;
			// 
			// ScanButton
			// 
			this->ScanButton->Location = System::Drawing::Point(12, 308);
			this->ScanButton->Name = L"ScanButton";
			this->ScanButton->Size = System::Drawing::Size(75, 23);
			this->ScanButton->TabIndex = 6;
			this->ScanButton->Text = L"Scan Ports";
			this->ScanButton->UseVisualStyleBackColor = true;
			this->ScanButton->Click += gcnew System::EventHandler(this, &Form1::ScanButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 337);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Metex";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(101, 337);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Escort";
			// 
			// ABut
			// 
			this->ABut->Location = System::Drawing::Point(104, 308);
			this->ABut->Name = L"ABut";
			this->ABut->Size = System::Drawing::Size(75, 23);
			this->ABut->TabIndex = 9;
			this->ABut->Text = L"Assign";
			this->ABut->UseVisualStyleBackColor = true;
			this->ABut->Click += gcnew System::EventHandler(this, &Form1::ABut_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1188, 606);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->ABut);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ScanButton);
			this->Controls->Add(this->EscortBox);
			this->Controls->Add(this->MetexBox);
			this->Controls->Add(this->ResetButton);
			this->Controls->Add(this->PauseButt);
			this->Controls->Add(this->RunButton);
			this->Controls->Add(this->chart1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 i++;
				 //			 String^ escmes;
				 //				 int freq;
				 double X=(0.25*(volt[0]+volt[1]+volt[2]+volt[3]))/0.04;
				 this->chart1->Series[0]->Points->AddXY(X,cap);
				 this->chart1->Series[1]->Points->AddXY(X,tand);
				 Metex->Write("D\r");

				 //std::cout <<freq<<std::endl;
			 }
	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
				 //ddd;
				 /*
				 freq:=strtoint(data[4]);
				 range:=strtoint(data[5]);
				 c:=copy(data,6,5);
				 podst:=strtoint(c);
				 wynik:=mnoznik(freq,range)*podst;
				 range:=strtoint(data[15]);
				 c:=copy(data,16,3);
				 delta:=strtoint(c)*deltam(range);
				 */

				 // SerialPort^ sp=(SerialPort^)sender;
				 // String^ indata=sp->ReadExisting();
				 // Console::Write(indata);
				 //std::cout<<"data";
				 String^ escmes;
				 int freq;
				 int range;
				 int trange;
				 int value;
				 int tangens;
				 escmes=Escort->ReadLine();
				 if (escmes->Length > 0){
					 freq=Int32::Parse(escmes->Substring(2,1));
					 range=Int32::Parse(escmes->Substring(3,1));
					 value=Int32::Parse(escmes->Substring(4,5));
					 Console::WriteLine(escmes/*->Substring(3,1)*/);
					 double capacity;
					 capacity=value*mnoznik(freq,range);
					 cap=capacity;
					 tangens=Int32::Parse(escmes->Substring(14,3));
					 tand=tangens*1e-3;
					 std::cout<<freq<<" "<<range<<" "<<value<<" "<<capacity<<std::endl;
				 }
			 }
	private: System::Void RunButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->timer1->Enabled=true;
				 ABut->Enabled=false;
				 Escort->Open();
				 Metex->NewLine="\r";
				 Metex->Open();
				 Metex->RtsEnable = false;
				 std::cout<<"Ports are open"<<std::endl;
			 }
	private: System::Void ResetButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->chart1->Series[0]->Points->Clear();
				 this->chart1->Series[1]->Points->Clear();
			 }
	private: System::Void ScanButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 for each (String^ s in System::IO::Ports::SerialPort::GetPortNames()) 
				 {
					 this->MetexBox->Items->Add(s);
					 this->EscortBox->Items->Add(s);
				 } 
			 }
	private: System::Void Metex_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
				 double value;

				 String^ line=Metex->ReadLine();
				 if (line[0]!=' '||metexg>3) metexg=0;
				 Double::TryParse(line->Substring(2,8),value);
				 std::cout<<"Metex sent row "<<metexg<<" "<<value<<std::endl;
				 volt[metexg]=value;
				 metexg++;
				 Console::WriteLine(line);
			 }
	private: System::Void PauseButt_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Enabled=!(timer1->Enabled);
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (saveFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK ){
					 StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
					 int size=chart1->Series[0]->Points->Count;
					 for (i=0;i<size;i++){
						 sw->WriteLine(chart1->Series[0]->Points[i]->XValue.ToString()+" "+chart1->Series[0]->Points[i]->YValues[0].ToString()+" "+chart1->Series[1]->Points[i]->YValues[0].ToString());
					 }
					 sw->Close();

				 }
			 }
	private: System::Void ABut_Click(System::Object^  sender, System::EventArgs^  e) {
				 Metex->PortName=MetexBox->Text;
				 Escort->PortName=EscortBox->Text;
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 std::string metexport, escortport;
				 std::ifstream inpfile("ports.cfg");
				 inpfile>>metexport>>escortport;
				 MetexBox->Text=gcnew String(metexport.c_str());
				 if (MetexBox->Text!="") Metex->PortName=MetexBox->Text;
				 EscortBox->Text=gcnew String(escortport.c_str());
				 if (EscortBox->Text!="") Escort->PortName=EscortBox->Text;
			 }
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 System::IO::StreamWriter^ sw=gcnew System::IO::StreamWriter("ports.cfg");
				 sw->WriteLine(MetexBox->Text+" "+EscortBox->Text);
				 sw->Close();
			 }
	};
}

