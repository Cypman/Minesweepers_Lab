#include "xMain.h"
wxBEGIN_EVENT_TABLE(xMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()
xMain::xMain() : wxFrame(nullptr, wxID_ANY, "JoshuaInher Official - wxWidgets!", wxPoint(30, 30), wxSize(800, 600)) {
	///*btn = new wxButton(this, 10001, "Click Me Now", wxPoint(10, 10), wxSize(150, 50)); 
	//w_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 80), wxSize(400, 50));
	//list = new wxListBox(this, wxID_ANY, wxPoint(50, 170), wxSize(400, 400));*/
	btn = new wxButton * [nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	xWidth = new int[nFieldWidth * nFieldHeight];
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
			btn[y * nFieldWidth + x]->SetFont(font);
			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);
			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &xMain::OnButtonClicked, this);
			xWidth[y * nFieldWidth + x] = 0;
		}
	}
	this->SetSizer(grid);
	grid->Layout();

}
xMain::~xMain()
{
	delete[]btn;
}

void xMain::OnButtonClicked(wxCommandEvent& evt) {
	//list->AppendString(w_txt->GetValue());
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldHeight;
	if (btnClick)
	{

		int mines = 30;
		while (mines)
		{
			int rx = rand() % nFieldWidth;
			int ry = rand() % nFieldHeight;
			if (xWidth[ry * nFieldWidth + rx] == 0 && rx != x && ry != y)
			{
				xWidth[ry * nFieldWidth + rx] = -1;
				mines--;
			}
		}
		btnClick = false;
	}
	//Disable Button, preventing it being [ressed again
	btn[y * nFieldWidth + x]->Enable(false);
	evt.Skip();
	//Check if player hit mine
	if (xWidth[y * nFieldWidth + x] == -1)
	{
		wxMessageBox("Ohhh Yeah !! - Game Over :(");
		//Reset again
		btnClick = true;
		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
			{
				xWidth[y * nFieldWidth + x] = 0;
				btn[y * nFieldWidth + x]->SetLabel("");
				btn[y * nFieldWidth + x]->Enable(true);
			}
	}
	else
	{
		//Count neighbouring mines
		int x_count = 0;
		for (int m = -1; m < 2; m++)
			for (int k = -1; k < 2; k++)
			{
				if (x + m >= 0 && x + m < nFieldWidth && y + k >= 0 && y + k < nFieldHeight)
				{
					if (xWidth[(y + k) * nFieldWidth + (x + m)] == -1)
						x_count++;
				}
			}
		// Update buttons label to show mine count if > 0
		if (x_count > 0)
		{
			btn[y * nFieldWidth + x]->SetLabel(std::to_string(x_count));
		}
	}
	//evt.Skip();	

}

