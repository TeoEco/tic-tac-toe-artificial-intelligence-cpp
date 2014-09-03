//---------------------------------------------------------------------------
//
// Name:        trisApp.cpp
// Author:      Elvis Ciotti
// Created:     11/07/2007 15.20.28
// Description: 
//
//---------------------------------------------------------------------------

#include "trisApp.h"
#include "trisFrm.h"

IMPLEMENT_APP(trisFrmApp)

bool trisFrmApp::OnInit()
{
    trisFrm* frame = new trisFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int trisFrmApp::OnExit()
{
	return 0;
}
