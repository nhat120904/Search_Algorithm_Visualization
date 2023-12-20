#pragma once
#include "GridForm.h"
#include "Scenario.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Scenario* myScenario;
	public:

		MyForm(void)
		{
			InitializeComponent();
		}

		MyForm(Scenario* scenario)
		{
			myScenario = scenario;
			InitializeComponent();
		}
		void ResetScenario()
		{
			for (int i = 0; i < myScenario->grid.rows; i++)
			{
				for (int j = 0; j < myScenario->grid.cols; j++)
				{
					if (myScenario->grid.map[i][j] != 1)
					{
						myScenario->grid.map[i][j] = 0;
					}
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (myScenario != nullptr)
			{
				delete myScenario;
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ BFS;
	private: System::Windows::Forms::Button^ DFS;
	private: System::Windows::Forms::Button^ AStar;
	private: System::Windows::Forms::Button^ GBFS;
	private: System::Windows::Forms::Button^ IDDFS;
	private: System::Windows::Forms::Button^ Dijkstra;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->BFS = (gcnew System::Windows::Forms::Button());
			this->DFS = (gcnew System::Windows::Forms::Button());
			this->AStar = (gcnew System::Windows::Forms::Button());
			this->GBFS = (gcnew System::Windows::Forms::Button());
			this->IDDFS = (gcnew System::Windows::Forms::Button());
			this->Dijkstra = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBox1->Location = System::Drawing::Point(12, 21);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(205, 60);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Search Algorithm Visualization";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// BFS
			// 
			this->BFS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->BFS->Location = System::Drawing::Point(62, 109);
			this->BFS->Name = L"BFS";
			this->BFS->Size = System::Drawing::Size(100, 48);
			this->BFS->TabIndex = 3;
			this->BFS->Text = L"BFS";
			this->BFS->UseVisualStyleBackColor = true;
			this->BFS->Click += gcnew System::EventHandler(this, &MyForm::BFS_Click);
			// 
			// DFS
			// 
			this->DFS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->DFS->Location = System::Drawing::Point(62, 186);
			this->DFS->Name = L"DFS";
			this->DFS->Size = System::Drawing::Size(100, 47);
			this->DFS->TabIndex = 4;
			this->DFS->Text = L"DFS";
			this->DFS->UseVisualStyleBackColor = true;
			this->DFS->Click += gcnew System::EventHandler(this, &MyForm::DFS_Click);
			// 
			// AStar
			// 
			this->AStar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->AStar->Location = System::Drawing::Point(62, 347);
			this->AStar->Name = L"AStar";
			this->AStar->Size = System::Drawing::Size(100, 46);
			this->AStar->TabIndex = 5;
			this->AStar->Text = L"AStar";
			this->AStar->UseVisualStyleBackColor = true;
			this->AStar->Click += gcnew System::EventHandler(this, &MyForm::AStar_Click);
			// 
			// GBFS
			// 
			this->GBFS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->GBFS->Location = System::Drawing::Point(62, 426);
			this->GBFS->Name = L"GBFS";
			this->GBFS->Size = System::Drawing::Size(100, 41);
			this->GBFS->TabIndex = 6;
			this->GBFS->Text = L"GBFS";
			this->GBFS->UseVisualStyleBackColor = true;
			this->GBFS->Click += gcnew System::EventHandler(this, &MyForm::GBFS_Click);
			// 
			// IDDFS
			// 
			this->IDDFS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->IDDFS->Location = System::Drawing::Point(62, 265);
			this->IDDFS->Name = L"IDDFS";
			this->IDDFS->Size = System::Drawing::Size(100, 50);
			this->IDDFS->TabIndex = 7;
			this->IDDFS->Text = L"IDDFS";
			this->IDDFS->UseVisualStyleBackColor = true;
			this->IDDFS->Click += gcnew System::EventHandler(this, &MyForm::IDDFS_Click);
			// 
			// Dijkstra
			// 
			this->Dijkstra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->Dijkstra->Location = System::Drawing::Point(62, 499);
			this->Dijkstra->Name = L"Dijkstra";
			this->Dijkstra->Size = System::Drawing::Size(100, 40);
			this->Dijkstra->TabIndex = 8;
			this->Dijkstra->Text = L"Dijkstra";
			this->Dijkstra->UseVisualStyleBackColor = true;
			this->Dijkstra->Click += gcnew System::EventHandler(this, &MyForm::Dijkstra_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->Dijkstra);
			this->Controls->Add(this->IDDFS);
			this->Controls->Add(this->GBFS);
			this->Controls->Add(this->AStar);
			this->Controls->Add(this->DFS);
			this->Controls->Add(this->BFS);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"RobotNavigation";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BFS_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetScenario();
		GridForm^ form1 = gcnew GridForm(myScenario, 1);
		form1->ShowDialog();
	}
	private: System::Void DFS_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetScenario();
		cout << "helo";
		GridForm^ form1 = gcnew GridForm(myScenario, 2);
		form1->ShowDialog();
	}
	private: System::Void IDDFS_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetScenario();
		GridForm^ form1 = gcnew GridForm(myScenario, 3);
		form1->ShowDialog();
	}
	private: System::Void Dijkstra_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetScenario();
		GridForm^ form1 = gcnew GridForm(myScenario, 4);
		form1->ShowDialog();
	}
	private: System::Void AStar_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetScenario();
		GridForm^ form1 = gcnew GridForm(myScenario, 5);
		form1->ShowDialog();
	}
	private: System::Void GBFS_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetScenario();
		GridForm^ form1 = gcnew GridForm(myScenario, 6);
		form1->ShowDialog();
	}
	};

}
