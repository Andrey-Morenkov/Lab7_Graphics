#pragma once
#include "TObject.h"
#include "TCircle.h"
#include "TPoint.h"
#include "TLine.h"
#include "TChart.h"

namespace Lab7_Graphics {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Box_X_mouse;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  Box_Y_mouse;
	private: System::Windows::Forms::RadioButton^  radio_point;
	private: System::Windows::Forms::RadioButton^  radio_line;
	private: System::Windows::Forms::RadioButton^  radio_circle;
	public: Graphics^ g;
	private: System::Windows::Forms::RadioButton^  radio_chart;
	public:





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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Box_X_mouse = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Box_Y_mouse = (gcnew System::Windows::Forms::TextBox());
			this->radio_point = (gcnew System::Windows::Forms::RadioButton());
			this->radio_line = (gcnew System::Windows::Forms::RadioButton());
			this->radio_circle = (gcnew System::Windows::Forms::RadioButton());
			this->radio_chart = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X:";
			// 
			// Box_X_mouse
			// 
			this->Box_X_mouse->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Box_X_mouse->Enabled = false;
			this->Box_X_mouse->Location = System::Drawing::Point(43, 13);
			this->Box_X_mouse->Name = L"Box_X_mouse";
			this->Box_X_mouse->ReadOnly = true;
			this->Box_X_mouse->Size = System::Drawing::Size(60, 20);
			this->Box_X_mouse->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(139, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y:";
			// 
			// Box_Y_mouse
			// 
			this->Box_Y_mouse->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Box_Y_mouse->Enabled = false;
			this->Box_Y_mouse->Location = System::Drawing::Point(169, 13);
			this->Box_Y_mouse->Name = L"Box_Y_mouse";
			this->Box_Y_mouse->ReadOnly = true;
			this->Box_Y_mouse->Size = System::Drawing::Size(60, 20);
			this->Box_Y_mouse->TabIndex = 3;
			// 
			// radio_point
			// 
			this->radio_point->AutoSize = true;
			this->radio_point->Checked = true;
			this->radio_point->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radio_point->Location = System::Drawing::Point(987, 14);
			this->radio_point->Name = L"radio_point";
			this->radio_point->Size = System::Drawing::Size(55, 18);
			this->radio_point->TabIndex = 4;
			this->radio_point->TabStop = true;
			this->radio_point->Text = L"Point";
			this->radio_point->UseVisualStyleBackColor = true;
			// 
			// radio_line
			// 
			this->radio_line->AutoSize = true;
			this->radio_line->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radio_line->Location = System::Drawing::Point(987, 38);
			this->radio_line->Name = L"radio_line";
			this->radio_line->Size = System::Drawing::Size(51, 18);
			this->radio_line->TabIndex = 5;
			this->radio_line->Text = L"Line";
			this->radio_line->UseVisualStyleBackColor = true;
			// 
			// radio_circle
			// 
			this->radio_circle->AutoSize = true;
			this->radio_circle->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radio_circle->Location = System::Drawing::Point(987, 62);
			this->radio_circle->Name = L"radio_circle";
			this->radio_circle->Size = System::Drawing::Size(57, 18);
			this->radio_circle->TabIndex = 6;
			this->radio_circle->Text = L"Circle";
			this->radio_circle->UseVisualStyleBackColor = true;
			// 
			// radio_chart
			// 
			this->radio_chart->AutoSize = true;
			this->radio_chart->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radio_chart->Location = System::Drawing::Point(987, 86);
			this->radio_chart->Name = L"radio_chart";
			this->radio_chart->Size = System::Drawing::Size(56, 18);
			this->radio_chart->TabIndex = 7;
			this->radio_chart->TabStop = true;
			this->radio_chart->Text = L"Chart";
			this->radio_chart->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1084, 618);
			this->Controls->Add(this->radio_chart);
			this->Controls->Add(this->radio_circle);
			this->Controls->Add(this->radio_line);
			this->Controls->Add(this->radio_point);
			this->Controls->Add(this->Box_Y_mouse);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Box_X_mouse);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		public: int x_mouse_current;
			    int y_mouse_current;
				int x_mouse_prev;
				int y_mouse_prev;
				int x_1;
				int y_1;
				int x_prev = -1;
				int y_prev = -1;
				bool line_is_drawing = false;
				TChart* chart;

#pragma endregion
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
				 x_mouse_current = e->X;
				 y_mouse_current = e->Y;
				 this->Box_X_mouse->Text = Convert::ToString(x_mouse_current);
				 this->Box_Y_mouse->Text = Convert::ToString(y_mouse_current);

				 if ((this->radio_line->Checked) && (line_is_drawing))
				 {
					 if ((x_prev != -1) && (y_prev != -1))
					 {
						 TLine TmpLine(x_1, y_1, x_prev, y_prev);
						 TmpLine.Hide(g);
					 }
					 TLine Line(x_1, y_1, e->X, e->Y);
					 Line.Draw(g);
					 x_prev = e->X;
					 y_prev = e->Y;
				 }
	}
private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 if (this->radio_point->Checked)
			 {
				 TPoint Point(e->X, e->Y);
				 Point.Draw(g);
			 }

			 if (this->radio_circle->Checked)
			 {
				 TCircle Circle(e->X, e->Y, 15);
				 Circle.Draw(g);
			 }
			 if (this->radio_line->Checked)
			 {
				 if (!line_is_drawing)
				 {
					 x_1 = e->X;
					 y_1 = e->Y;
					 line_is_drawing = true;
				 }
				 else
				 {
					 TLine Line(x_1, y_1, e->X, e->Y);
					 Line.Draw(g);
					 line_is_drawing = false;
				 }
					
			 }
			 if (this->radio_chart->Checked)
			 {
				 TObject* point_1;
				 point_1 = new TPoint(e->X, e->Y);
				 chart = new TChart();
				 chart->SetFirst(point_1);
				 chart->Draw(g);
			 }
    }
	private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (this->radio_chart->Checked)
				 {
					 TObject* point_last;
					 point_last = new TPoint(e->X, e->Y);
					 chart->SetLast(point_last);
					 chart->Draw(g);
				 }

	}
};
}
