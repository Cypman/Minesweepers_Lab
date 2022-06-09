#pragma once
#include "wx/wx.h"
#include"xMain.h"

class wxWidgets : public wxApp
{
public:
	wxWidgets();
	~wxWidgets();
private:
	xMain* m_widget = nullptr;
public:
	virtual bool OnInit();

};
