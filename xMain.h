#pragma once
#include "wx/wx.h"
class xMain : public wxFrame
{
public:
	xMain();
	~xMain();

public: ///*wxButton *btn = nullptr;
	   //wxTextCtrl *w_txt = nullptr;
	  //wxListBox *list = nullptr;*/	
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn;
	int* xWidth = nullptr;
	bool btnClick = true;
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};



