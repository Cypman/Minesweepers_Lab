#include "wxWidgets.h"
#include "xMain.h"
#include "wx/wx.h"
wxIMPLEMENT_APP(wxWidgets);
wxWidgets::wxWidgets() {

}
wxWidgets::~wxWidgets() {}
bool wxWidgets::OnInit()
{
	m_widget = new xMain();
	m_widget->Show();
	return true;
}
