//---------------------------------------------------------------------------
//
// Name:        trisApp.h
// Author:      Elvis Ciotti
// Created:     11/07/2007 15.20.28
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __TRISFRMApp_h__
#define __TRISFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class trisFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
