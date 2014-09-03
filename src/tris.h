#ifndef __TRIS2_h__
#define __TRIS2_h__

//#ifdef __BORLANDC__
//	#pragma hdrstop
//#endif

#include <stdlib.h>

//#include <wx/wx.h>


//#ifndef WX_PRECOMP
//	#include <wx/wx.h>
//	#include <wx/frame.h>
//#else
//	#include <wx/wxprec.h>
//#endif

///////////////////////////

#define STAMPA_ALBERO 0


#define COMPUTER 2
#define GIOCATORE 1
#define LIBERA 0

#define PESO_TRIS_FATTO 30
#define PESO_TRIS_SUBITO -30
#define AGG_LIVELLO_TRIS_FATTO -3
#define AGG_LIVELLO_TRIS_SUBITO 3





//strutture
typedef struct nodo
{
   int *stato; //tabellone
   int giocatore;
   int bonta;
   int i; //dove muove
   int j;
   struct nodo *figlio[11];
   struct nodo *padre;
   int vincitore;
   int livello;
} nodo_t;


int abilita;
int vincitore;
int mosse;
int albero_creato;

nodo_t *head = NULL;
    nodo_t *inizio = NULL;
    nodo_t *temp = NULL;

//prototipi
void inizializza();


int is_libera(int m);

int controlla_tris(int *stato);
void stampa(int *stato);
int mossa_casuale(int g);
int cerca_tris(int g);
int impedisci_tris(int g, int c);
void crea_nodo(nodo_t **p, int *stato_corrente, int giocatore_di_turno, int livello, nodo_t **precedente);
void risali_aggiornando_bonta(nodo_t *p, int aggiunta);
void risposta();



//FILE *f;


char p1[6][12];
char p2[6][12];

int stato[10]; //memorizza stato del tabellone (indici 1-9)

int counter; //conta #nodi creati
//int counter2;
int counter2;




void click_giocatore_casella(int n)
{
    stato[n] = GIOCATORE;
}



//casella libera ?
int is_libera(int m)
{
   return (stato[m] == LIBERA);
}



int controlla_tris(int stato[])
{
  int i,j;
  int stato3x3[4][4];
  int corr=1;

  for (i=1; i<=3; i++)
    for (j=1; j<=3; j++)
       stato3x3[i][j] = stato[corr++];




  for (int g=1; g<=2; g++)
  {
      //controllo colonne
      for (j=1; j<=3; j++)
        if (stato3x3[1][j]==g && stato3x3[2][j]==g && stato3x3[3][j]==g)
           return g;

      //controllo righe
      for (i=1; i<=3; i++)
        if (stato3x3[i][1]==g && stato3x3[i][2]==g && stato3x3[i][3]==g)
           return g;

      //diagonali
      if (stato3x3[1][1]==g && stato3x3[2][2]==g && stato3x3[3][3]==g)
           return g;
      if (stato3x3[3][1]==g && stato3x3[2][2]==g && stato3x3[1][3]==g)
           return g;

  }
  return 0;
}




//
int mossa_casuale(int g)
{
  int m;
  srand(time(NULL));
  do
  {
     m = ((rand()*11*17)%9)+1;
    //if (limit++>100) printf("ERORRE !!!\n");
  } while (!is_libera(m));
  stato[m] = g;
  return m;
}

//vedo se posso fare tris con una mossa
int cerca_tris(int g)
{
          // x tutte le caselle...
         for (int m=1; m<10; m++)
          {
              // se è libera
              if ( is_libera(m) )
              {
                  //muovo
                  stato[m] = g;
                  //se la mossa nn mi ha fatto fare tris,...
                  if (!controlla_tris(stato))
                     stato[m]=LIBERA; //ri-libero casella
                  else
                  {
                     //lascio la mossa
                     //printf("COMPUTER: sono riuscito a fare tris !");
                     return m; //altrimenti ho fatto tris, quindi esco dalla funzione

                  }
              }
          }


          return 0; //non ho trovato casella vincente
}

  int impedisci_tris(int g, int c)
  {

         // x tutte le caselle...
        for (int m=1; m<10; m++)
          {
              // se è libera
              if ( is_libera(m) )
              {
                  //simulo mossa giocatore
                  stato[m]=g; //faccio la mossa
                  //se la mossa gli farebbe fare tris,...
                  if (!controlla_tris(stato))
                     stato[m]=LIBERA; //ri-libero casella, com'era inizialmente
                  else //se la mossa gli farebbe fare tris
                  {
                     //lascio la mossa
                     //printf("COMPUTER: ho evitato il tris al giocatore !");
                     stato[m]=c; //faccio la mossa
                     return m; //altrimenti ho fatto tris, quindi esco dalla funzione

                  }
              }
          }

          return 0; //non ho trovato casella vincente
  }



  void crea_nodo(nodo_t **p, int *stato_corrente, int giocatore_di_turno, int livello, nodo_t **precedente)
  {

      //alloco il puntatore passato
      *p = (nodo_t *)malloc(sizeof(nodo_t));
      (*p)->padre = *precedente; //salvo padre x ritorno
      (*p)->livello = livello;
       (*p)->bonta = 0;

      counter++;
      if ( STAMPA_ALBERO)
      {
               //fprintf(f"\n\nnodo %d allocato, livello %d\n", counter, livello);
               //fprintf(f, "%d%d%d\n%d%d%d\n%d%d%d\n", stato_corrente[1], stato_corrente[2], stato_corrente[3], stato_corrente[4], stato_corrente[5], stato_corrente[6], stato_corrente[7], stato_corrente[8], stato_corrente[9]);
      }
      //system("pause");

      //alloco memoria allo stato
      (*p)->stato = new int[10]; //(int *)calloc((size_t)10, sizeof(int));

      //copio stato nel nodo corrente
        for (int i=1; i<10; i++)
               (*p)->stato[i] = stato_corrente[i];

      //verifico il tris eventuale, in tal caso, non continuo
      (*p)->vincitore = controlla_tris( (*p)->stato );

      //se qualcuno vince..
      if ((*p)->vincitore)
      {
           //annullo figli
           for(int m=1; m<10; m++)
              (*p)->figlio[m] = NULL;
           //fprintf(f, "Nel nodo ha vinto il giocatore %d\n", (*p)->vincitore);
           counter2++;
           risali_aggiornando_bonta(*p, (*p)->vincitore==COMPUTER ? PESO_TRIS_FATTO:PESO_TRIS_SUBITO);

      }
      else
      {
               //rilancio ricorsivamente funzione sulle caselle libere
              (*p)->figlio[0] = NULL;   //non considerarlo nella navigazione

              //per ogni casella dello stato (tabellone):
              for(int m=1; m<10; m++)
              {
                 //se la casella è libera, rilanciaci funzione
                 if ((*p)->stato[m] == LIBERA)
                 {
                     //imposto la nuova mossa
                     (*p)->stato[m] = giocatore_di_turno;
                     //chiamo ricorsivamente con questo tabellone modificato
                     crea_nodo(  &((*p)->figlio[m])/*nodo espanso*/,  (*p)->stato /*verrà copiato*/,  (giocatore_di_turno==GIOCATORE)?COMPUTER:GIOCATORE , livello+1, &(*p) );
                     //rimetto a posto tabellone per cicli succesivi
                     (*p)->stato[m] = LIBERA;
                 }
                 else
                   (*p)->figlio[m] = NULL;  //no espansione => pongo a NULL
              }
      }
  }

void risali_aggiornando_bonta(nodo_t *p, int aggiunta)
{
    int sottraendo;

    if (aggiunta>0) //tris fatto
       sottraendo = AGG_LIVELLO_TRIS_FATTO;
    else
       sottraendo = AGG_LIVELLO_TRIS_SUBITO;   //tris subito

    //in modo che il valore delle bonta si avvicini a zero avvicinandosi alla radice
    // (il tris fatto/subito alla ultima mossa pesa di meno/di più che quello fatto ai livelli superiori)


    while ( p->padre != NULL)
    {
        p->bonta = p->bonta + aggiunta; //ad ogni nodo scalo

        aggiunta += sottraendo; //ad ogni nodo scalo bontà

        p = p->padre;
    }

 }




#endif
