//---------------------------------------------------------------------------
//
// Name:        trisFrm.cpp
// Author:      Elvis Ciotti
// Created:     11/07/2007 15.20.28
// Description: trisFrm class implementation
//
//---------------------------------------------------------------------------

#include "trisFrm.h"

#include "tris.h"

wxString stemp;


int partita_avviata;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// trisFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(trisFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(trisFrm::OnClose)
	EVT_BUTTON(ID_WXBUTTON10,trisFrm::WxButton10Click)
	EVT_BUTTON(ID_WXBUTTON9,trisFrm::WxButton9Click)
	EVT_BUTTON(ID_WXBUTTON8,trisFrm::WxButton8Click)
	EVT_BUTTON(ID_WXBUTTON7,trisFrm::WxButton7Click)
	EVT_BUTTON(ID_WXBUTTON6,trisFrm::WxButton6Click)
	EVT_BUTTON(ID_WXBUTTON5,trisFrm::WxButton5Click)
	EVT_BUTTON(ID_WXBUTTON4,trisFrm::WxButton4Click1)
	EVT_BUTTON(ID_WXBUTTON3,trisFrm::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON2,trisFrm::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,trisFrm::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

trisFrm::trisFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

trisFrm::~trisFrm()
{
}

void trisFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, wxT("Scegli livello abilità computer"), wxPoint(7,10), wxSize(267,340));
	WxStaticBox1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton1 = new wxRadioButton(this, ID_WXRADIOBUTTON1, wxT("Livello 1"), wxPoint(17,27), wxSize(179,23), 0, wxDefaultValidator, wxT("WxRadioButton1"));
	WxRadioButton1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton2 = new wxRadioButton(this, ID_WXRADIOBUTTON2, wxT("Livello 2"), wxPoint(16,105), wxSize(186,26), 0, wxDefaultValidator, wxT("WxRadioButton2"));
	WxRadioButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxMemo1 = new wxTextCtrl(this, ID_WXMEMO1, wxT(""), wxPoint(14,46), wxSize(251,51), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo1"));
	WxMemo1->SetMaxLength(0);
	WxMemo1->AppendText(wxT("Mosse legali (il computer mette il proprio segno in "));
	WxMemo1->AppendText(wxT("una casella vuota "));
	WxMemo1->AppendText(wxT("scelta a caso),  Agente a riflessi semplici"));
	WxMemo1->SetFocus();
	WxMemo1->SetInsertionPointEnd();
	WxMemo1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
	WxMemo1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton3 = new wxRadioButton(this, ID_WXRADIOBUTTON3, wxT("Livello 3"), wxPoint(15,185), wxSize(208,28), 0, wxDefaultValidator, wxT("WxRadioButton3"));
	WxRadioButton3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton4 = new wxRadioButton(this, ID_WXRADIOBUTTON4, wxT("Livello 4"), wxPoint(15,265), wxSize(230,24), 0, wxDefaultValidator, wxT("WxRadioButton4"));
	WxRadioButton4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxMemo2 = new wxTextCtrl(this, ID_WXMEMO2, wxT(""), wxPoint(17,208), wxSize(251,51), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo2"));
	WxMemo2->SetMaxLength(0);
	WxMemo2->AppendText(wxT("Agente che, non potendo fare una mossa "));
	WxMemo2->AppendText(wxT("vincente (non potendo far filetto), cerca di "));
	WxMemo2->AppendText(wxT("impedire una mossa vincente dell’avversario, cioè "));
	WxMemo2->AppendText(wxT("il filetto dell’avversario (Agente che manifesta il "));
	WxMemo2->AppendText(wxT("proprio obiettivo)"));
	WxMemo2->SetFocus();
	WxMemo2->SetInsertionPointEnd();
	WxMemo2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
	WxMemo2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxMemo3 = new wxTextCtrl(this, ID_WXMEMO3, wxT(""), wxPoint(16,127), wxSize(251,51), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo3"));
	WxMemo3->SetMaxLength(0);
	WxMemo3->AppendText(wxT("Cerca una mossa vincente (fare filetto, se è "));
	WxMemo3->AppendText(wxT("possibile) o altrimenti gioca a caso, tenendo conto "));
	WxMemo3->AppendText(wxT("del mondo (lo  stato del mondo in quel momento) "));
	WxMemo3->AppendText(wxT("e delle regole del gioco"));
	WxMemo3->SetFocus();
	WxMemo3->SetInsertionPointEnd();
	WxMemo3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
	WxMemo3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxMemo4 = new wxTextCtrl(this, ID_WXMEMO4, wxT(""), wxPoint(17,286), wxSize(251,51), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo4"));
	WxMemo4->SetMaxLength(0);
	WxMemo4->AppendText(wxT("Non potendo fare una mossa vincente (non "));
	WxMemo4->AppendText(wxT("potendo far filetto), cerca di impedire una mossa "));
	WxMemo4->AppendText(wxT("vincente dell’avversario (il filetto dell’avversario) "));
	WxMemo4->AppendText(wxT("facendo una mossa che lo metta in condizioni di "));
	WxMemo4->AppendText(wxT("vantaggio nel turno successivo (Agente che ha il "));
	WxMemo4->AppendText(wxT("senso dell’ottimizzazione e dell’utilità.)"));
	WxMemo4->SetFocus();
	WxMemo4->SetInsertionPointEnd();
	WxMemo4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
	WxMemo4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStatusBar1 = new wxStatusBar(this, ID_WXSTATUSBAR1);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("AVVIA"), wxPoint(159,359), wxSize(112,36), 0, wxDefaultValidator, wxT("WxButton1"));
	WxButton1->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Tahoma")));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT(""), wxPoint(290,17), wxSize(62,60), 0, wxDefaultValidator, wxT("WxButton2"));
	WxButton2->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton3 = new wxButton(this, ID_WXBUTTON3, wxT(""), wxPoint(366,18), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton3"));
	WxButton3->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton4 = new wxButton(this, ID_WXBUTTON4, wxT(""), wxPoint(442,18), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton4"));
	WxButton4->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton5 = new wxButton(this, ID_WXBUTTON5, wxT(""), wxPoint(291,104), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton5"));
	WxButton5->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton6 = new wxButton(this, ID_WXBUTTON6, wxT(""), wxPoint(366,104), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton6"));
	WxButton6->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton7 = new wxButton(this, ID_WXBUTTON7, wxT(""), wxPoint(442,104), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton7"));
	WxButton7->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton8 = new wxButton(this, ID_WXBUTTON8, wxT(""), wxPoint(291,191), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton8"));
	WxButton8->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton9 = new wxButton(this, ID_WXBUTTON9, wxT(""), wxPoint(366,191), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton9"));
	WxButton9->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxButton10 = new wxButton(this, ID_WXBUTTON10, wxT(""), wxPoint(442,191), wxSize(60,60), 0, wxDefaultValidator, wxT("WxButton10"));
	WxButton10->SetFont(wxFont(36, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Wingdings")));

	WxMemo5 = new wxTextCtrl(this, ID_WXMEMO5, wxT(""), wxPoint(288,278), wxSize(288,115), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo5"));
	WxMemo5->SetMaxLength(0);
	WxMemo5->AppendText(wxT(""));
	WxMemo5->SetFocus();
	WxMemo5->SetInsertionPointEnd();
	WxMemo5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxArrayString arrayStringFor_WxChoice1;
	arrayStringFor_WxChoice1.Add(wxT("Inizia il GIOCATORE"));
	arrayStringFor_WxChoice1.Add(wxT("Inizia il COMPUTER"));
	WxChoice1 = new wxChoice(this, ID_WXCHOICE1, wxPoint(10,365), wxSize(127,21), arrayStringFor_WxChoice1, 0, wxDefaultValidator, wxT("WxChoice1"));
	WxChoice1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));
	WxChoice1->SetSelection(0);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT(" "), wxPoint(291,81), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT(" "), wxPoint(366,82), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT(" "), wxPoint(443,82), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT(" "), wxPoint(289,165), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, wxT(" "), wxPoint(365,164), wxDefaultSize, 0, wxT("WxStaticText5"));
	WxStaticText5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, wxT(" "), wxPoint(442,164), wxDefaultSize, 0, wxT("WxStaticText6"));
	WxStaticText6->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, wxT(" "), wxPoint(290,254), wxDefaultSize, 0, wxT("WxStaticText7"));
	WxStaticText7->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, wxT(" "), wxPoint(365,254), wxDefaultSize, 0, wxT("WxStaticText8"));
	WxStaticText8->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, wxT(" "), wxPoint(443,255), wxDefaultSize, 0, wxT("WxStaticText9"));
	WxStaticText9->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	SetStatusBar(WxStatusBar1);
	SetTitle(wxT("Gioco del filetto (tris) a due contententi a conoscenza totale - Computer contro Giocatore"));
	SetIcon(wxNullIcon);
	SetSize(8,8,592,453);
	Center();
	
	////GUI Items Creation End
}

void trisFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}


void trisFrm::update_labels()
{
     for (int m=1; m<10; m++)
       setta_label(m, LIBERA);
}

void trisFrm::click_giocatore_casella(int n)
{
    if (!partita_avviata)
    {
        WxMemo5->AppendText("Scegli abilità computer a sinistra !\n");
        return;
    }
    
    if (!is_libera(n))
    {
        WxMemo5->AppendText("Giocatore: scelta non valida\n");
        return;
    }    
    
    if (mosse>8)
    {
            WxMemo5->AppendText("\nFine gioco ! nessun vincitore\n\n");
            vincitore = 3;
            return ;
    }

    
    if (!vincitore )
    {
        stato[n] = GIOCATORE; //set array
        setta_label(n, GIOCATORE); //set window
        mosse++;
        if (!vincitore) controlla_vincitore();
        if (!vincitore)  
        {
            if (mosse>8)
            {
                    WxMemo5->AppendText("\nFine gioco ! nessun vincitore\n\n");
                    vincitore = 3;
                    return ;
            }
            //livello 4: muovo il giocatore nell'albero
            if (abilita==4 && albero_creato)
               temp = temp->figlio[n]; 
            risposta_computer();
             
            WxMemo5->AppendText("Computer: ho fatto !\n---\n");
            mosse++;
        }    
        if (!vincitore) controlla_vincitore();
        if (!vincitore) WxMemo5->AppendText("Giocatore: tocca a te !\n");

    }
}

//setta la label del bottone n-esimo allo stato g
void trisFrm::setta_label(int n, int g)
{
    wxString *s = new wxString;
    switch(g)
    {
        case GIOCATORE:
            (*s) = "J";
            break;
        case COMPUTER:
            (*s) = ":";
            break;
        case LIBERA:
            (*s) = "";
            break;
    }     
    
    switch(n)
    {
        case 1:
            WxButton2->SetLabel(*s);
            break;
        case 2:
            WxButton3->SetLabel(*s);
            break;
        case 3:
            WxButton4->SetLabel(*s);
            break;
        case 4:
            WxButton5->SetLabel(*s);
            break;
        case 5:
            WxButton6->SetLabel(*s);
            break;
        case 6:
            WxButton7->SetLabel(*s);
            break;
        case 7:
            WxButton8->SetLabel(*s);
            break;
        case 8:
            WxButton9->SetLabel(*s);
            break;
        case 9:
            WxButton10->SetLabel(*s);
            break;
    }

}    

void trisFrm::controlla_vincitore()
{
     
     vincitore = controlla_tris(stato);
             //incremento mosse
              
    if (vincitore==COMPUTER)
        //WxStatusBar1->SetStatusText("Partita FINITA ! vince il computer");
        WxMemo5->AppendText("Partita FINITA ! vince il computer\n");
    if (vincitore==GIOCATORE)
        WxMemo5->AppendText("Partita FINITA ! vince il giocatore\n");

    
}


void trisFrm::risposta_computer()
{
    int tmp, max, max_ind, t;
    
   
    switch (abilita)
    {
           case 1:
                /*un agente che fa a caso una delle mosse legali (mette il proprio
                segno in una casella vuota scelta a caso), è un agente “a riflessi
                semplici”;*/
                tmp = mossa_casuale(COMPUTER);
                setta_label(tmp, COMPUTER);
                
                break;
                
            case 2:
                 /*un agente che cerca di fare una mossa vincente (fare filetto, se è
                 possibile) o altrimenti gioca a caso, tiene conto del mondo
                 (lo  stato del mondo in quel momento) e delle regole del gioco;*/
                tmp = cerca_tris(COMPUTER);
                if (tmp) //se sono riuscito a fare tris con una mossa...
                {
                  setta_label(tmp, COMPUTER);
                  WxMemo5->AppendText("Computer: riesco a fare tris con questa mossa !\n");
                } 
                else //muovo a caso
                {
                    WxMemo5->AppendText("Computer: non riesco a fare tris con una mossa, muovo a caso !\n");
                    tmp = mossa_casuale(COMPUTER);
                    setta_label(tmp, COMPUTER);
                }         
               
                break;
                /*se non riesco a fare tris con una mossa, ne faccio una casuale*/
            case 3:
                /*un agente che, non potendo fare una mossa vincente (non potendo
                far filetto), cerca di impedire una mossa vincente dell’avversario (il
                filetto dell’avversario), manifesta il proprio obiettivo;*/
                tmp = cerca_tris(COMPUTER);
                if (tmp) //se sono riuscito a fare tris con una mossa...
                {
                  setta_label(tmp, COMPUTER);
                  WxMemo5->AppendText("Computer: riesco a fare tris con questa mossa !\n");
                }
                // altrimenti...
                else
                {
                    WxMemo5->AppendText("Computer: non riesco a fare tris con questa mossa !\n");
                    tmp = impedisci_tris(GIOCATORE,COMPUTER);
                    if (tmp)
                    {
                        setta_label(tmp, COMPUTER);
                        WxMemo5->AppendText("Computer: ho impedito il tris al giocatore !\n");
                    }
                    else
                    {
                        tmp = mossa_casuale(COMPUTER);
                        setta_label(tmp, COMPUTER);
                        WxMemo5->AppendText("Computer: non ci sono tris da impedire al giocatore, muovo a caso !\n");
                    }        
                }    

                /*se non riesco a fare tris con una mossa, cerco di impedire il tris.
                  se non riesco a impedirlo, muovo casualmente */
                break;  
            case 4:
                
                tmp = cerca_tris(COMPUTER);
                if (tmp) //se sono riuscito a fare tris con una mossa...
                {
                  reset_pesi();
                  setta_label(tmp, COMPUTER);
                  WxMemo5->AppendText("Computer: riesco a fare tris con questa mossa !\n");
                  // temp = temp->figlio[max_ind]; // fine partita, nn avanzo albero
                }
                else
                {
                   tmp = impedisci_tris(GIOCATORE,COMPUTER);
                    if (tmp)
                    {
                        setta_label(tmp, COMPUTER);
                        WxMemo5->AppendText("Computer: ho impedito il tris al giocatore !\n");
                        if (albero_creato)
                          temp = temp->figlio[tmp]; 
                    }
                    else
                    {
                       WxMemo5->AppendText("Computer: non riesco a fare tris con una sola mossa !\n");
                       //se l'albero nn c'è
                       if (!albero_creato)
                       {
                           crea_nodo(&head, stato, COMPUTER, 1, &inizio); //creo albero
                           albero_creato = 1;
                           temp = head;
                           WxMemo5->AppendText("Computer: ho creato l'albero delle possibili risposte alla mossa del giocatore !\n");
                           
                       }
                        
                        
                       WxMemo5->AppendText("Computer: cerco nell'albero la mossa più conveniente (vedi pesi sotto le caselle) ...\n"); 
                       
                       reset_pesi();
                       
                        if (temp->figlio[1] && is_libera(1))
                         WxStaticText1->SetLabel(int2string(temp->figlio[1]->bonta));
                        if (temp->figlio[2] && is_libera(2))
                         WxStaticText2->SetLabel(int2string(temp->figlio[2]->bonta));
                        if (temp->figlio[3] && is_libera(3))
                         WxStaticText3->SetLabel(int2string(temp->figlio[3]->bonta));
                        if (temp->figlio[4] && is_libera(4))
                         WxStaticText4->SetLabel(int2string(temp->figlio[4]->bonta));
                        if (temp->figlio[5] && is_libera(5))
                         WxStaticText5->SetLabel(int2string(temp->figlio[5]->bonta));
                        if (temp->figlio[6] && is_libera(6))
                         WxStaticText6->SetLabel(int2string(temp->figlio[6]->bonta));
                        if (temp->figlio[7] && is_libera(7))
                         WxStaticText7->SetLabel(int2string(temp->figlio[7]->bonta));
                        if (temp->figlio[8] && is_libera(8))
                         WxStaticText8->SetLabel(int2string(temp->figlio[8]->bonta));
                        if (temp->figlio[9] && is_libera(9))
                         WxStaticText9->SetLabel(int2string(temp->figlio[9]->bonta));
        
                       //parto da una mossa possibile per la ricerca della massima bontà
                       for (t=0; t<10; t++)
                          if (temp->figlio[t] && is_libera(t))
                             break;
        
                        max = temp->figlio[t]->bonta;
                        max_ind = t;
        
                        //cerco bonta maggiore
                        while(t<10)
                        {
                           //considero 
                           if ( temp->figlio[t] && (temp->figlio[t]->bonta > max) && is_libera(t)/* && cerca_tris(GIOCATORE)*/)
                           {
                                  max = temp->figlio[t]->bonta; //imposto la bontà massima corrente
                                  max_ind = t; //figlio con, al momento, maggiore bonta
                           }
                           t++;
                        }
        
                        stato[max_ind] = COMPUTER;
                        setta_label(max_ind, COMPUTER);
                        stemp.Printf(wxT("Computer: ho calcolato la mossa migliore per me (bontà %d)\n"),max);
                        WxMemo5->AppendText(stemp);
        
                        //avanzo puntatore nell'albero
                        temp = temp->figlio[max_ind]; 
                    }  
                }
                break;        
    }

}


void trisFrm::reset_pesi()
{
     WxStaticText1->SetLabel(" ");
    WxStaticText2->SetLabel(" ");
    WxStaticText3->SetLabel(" ");
    WxStaticText4->SetLabel(" ");
    WxStaticText5->SetLabel(" ");
    WxStaticText6->SetLabel(" ");
    WxStaticText7->SetLabel(" ");
    WxStaticText8->SetLabel(" ");
    WxStaticText9->SetLabel(" ");
}


/*
 * WxButton1Click
 */ //main
void trisFrm::WxButton1Click(wxCommandEvent& event)
{
	int tmp;
    
    abilita = 0;
	mosse=0;
	vincitore=0;
	head = NULL;
    inizio = NULL;
    temp = NULL;
    albero_creato = 0;
	
    if (WxRadioButton1->GetValue())
	  abilita=1;
    else if (WxRadioButton2->GetValue())
	  abilita=2;
	else if (WxRadioButton3->GetValue())
	  abilita=3;
	else if (WxRadioButton4->GetValue())
	  abilita=4;
    
    
    if (abilita!=0)
    {
         stemp.Printf(wxT("Abilità computer livello %d\n"), abilita); 
         WxStatusBar1->SetStatusText(stemp);
         WxMemo5->AppendText(stemp);
         stemp.clear();
         
         update_labels();
         
         //libero tabellone
         for (int m=0; m<10; m++)
           stato[m] = LIBERA;
         
         partita_avviata=1; 

         reset_pesi();

         WxMemo5->Clear();
         WxMemo5->AppendText(" -- Nuova partita --\n");  
         WxMemo5->AppendText(stemp); 
        
         //inizia il computer
         if  (WxChoice1->GetSelection()==1) 
         {
            tmp = mossa_casuale(COMPUTER);
            setta_label(tmp, COMPUTER);
            mosse++;
            WxMemo5->AppendText("Giocatore: tocca a te !\n");
         }    
    }
    else 
    {
         WxStatusBar1->SetStatusText("Scegli livello abilità computer\n");
         WxMemo5->AppendText("Scegli livello abilità computer\n");
    }
    // insert your code here
}



/*
 * WxButton2Click
 */
void trisFrm::WxButton2Click(wxCommandEvent& event)
{
	click_giocatore_casella(1);// insert your code here
}


 
    

/*
 * WxButton3Click
 */
void trisFrm::WxButton3Click(wxCommandEvent& event)
{
click_giocatore_casella(2);	// insert your code here
}

/*
 * WxButton4Click1
 */
void trisFrm::WxButton4Click1(wxCommandEvent& event)
{
click_giocatore_casella(3);	// insert your code here
}

/*
 * WxButton5Click
 */
void trisFrm::WxButton5Click(wxCommandEvent& event)
{
click_giocatore_casella(4);	// insert your code here
}

/*
 * WxButton6Click
 */
void trisFrm::WxButton6Click(wxCommandEvent& event)
{
click_giocatore_casella(5);	// insert your code here
}

/*
 * WxButton7Click
 */
void trisFrm::WxButton7Click(wxCommandEvent& event)
{
click_giocatore_casella(6);	// insert your code here
}

/*
 * WxButton8Click
 */
void trisFrm::WxButton8Click(wxCommandEvent& event)
{
click_giocatore_casella(7);	// insert your code here
}

/*
 * WxButton9Click
 */
void trisFrm::WxButton9Click(wxCommandEvent& event)
{
click_giocatore_casella(8);	// insert your code here
}

/*
 * WxButton10Click
 */
void trisFrm::WxButton10Click(wxCommandEvent& event)
{
click_giocatore_casella(9);	// insert your code here
}





wxString int2string(int n)
{
    wxString s;
    s.Printf(wxT("%d\n"), n);
    return s;  
    
}    
