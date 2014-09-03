//---------------------------------------------------------------------------
//
// Name:        trisFrm.h
// Author:      Elvis Ciotti
// Created:     11/07/2007 15.20.28
// Description: trisFrm class declaration
//
//---------------------------------------------------------------------------

#ifndef __TRISFRM_h__
#define __TRISFRM_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
////Header Include End

////Dialog Style Start
#undef trisFrm_STYLE
#define trisFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End



class trisFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		trisFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("tris"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = trisFrm_STYLE);
		virtual ~trisFrm();
		void WxButton1Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		void WxButton_s1Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void WxButton4Click1(wxCommandEvent& event);
		void WxButton5Click(wxCommandEvent& event);
		void WxButton6Click(wxCommandEvent& event);
		void WxButton7Click(wxCommandEvent& event);
		void WxButton8Click(wxCommandEvent& event);
		void WxButton9Click(wxCommandEvent& event);
		void WxButton10Click(wxCommandEvent& event);
		void update_labels();
		void risposta_computer();
		void click_giocatore_casella(int n);
		void setta_label(int n, int g);
		void controlla_vincitore();

		void reset_pesi();

		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxChoice *WxChoice1;
		wxTextCtrl *WxMemo5;
		wxButton *WxButton10;
		wxButton *WxButton9;
		wxButton *WxButton8;
		wxButton *WxButton7;
		wxButton *WxButton6;
		wxButton *WxButton5;
		wxButton *WxButton4;
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxStatusBar *WxStatusBar1;
		wxTextCtrl *WxMemo4;
		wxTextCtrl *WxMemo3;
		wxTextCtrl *WxMemo2;
		wxRadioButton *WxRadioButton4;
		wxRadioButton *WxRadioButton3;
		wxTextCtrl *WxMemo1;
		wxRadioButton *WxRadioButton2;
		wxRadioButton *WxRadioButton1;
		wxStaticBox *WxStaticBox1;
		////GUI Control Declaration End

		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT9 = 1041,
			ID_WXSTATICTEXT8 = 1040,
			ID_WXSTATICTEXT7 = 1039,
			ID_WXSTATICTEXT6 = 1038,
			ID_WXSTATICTEXT5 = 1037,
			ID_WXSTATICTEXT4 = 1036,
			ID_WXSTATICTEXT3 = 1035,
			ID_WXSTATICTEXT2 = 1034,
			ID_WXSTATICTEXT1 = 1033,
			ID_WXCHOICE1 = 1023,
			ID_WXMEMO5 = 1021,
			ID_WXBUTTON10 = 1020,
			ID_WXBUTTON9 = 1019,
			ID_WXBUTTON8 = 1018,
			ID_WXBUTTON7 = 1017,
			ID_WXBUTTON6 = 1016,
			ID_WXBUTTON5 = 1015,
			ID_WXBUTTON4 = 1014,
			ID_WXBUTTON3 = 1013,
			ID_WXBUTTON2 = 1012,
			ID_WXBUTTON1 = 1011,
			ID_WXSTATUSBAR1 = 1010,
			ID_WXMEMO4 = 1009,
			ID_WXMEMO3 = 1008,
			ID_WXMEMO2 = 1007,
			ID_WXRADIOBUTTON4 = 1006,
			ID_WXRADIOBUTTON3 = 1005,
			ID_WXMEMO1 = 1004,
			ID_WXRADIOBUTTON2 = 1003,
			ID_WXRADIOBUTTON1 = 1002,
			ID_WXSTATICBOX1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

wxString int2string(int n);


#endif
