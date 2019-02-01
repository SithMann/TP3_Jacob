#include <stdio.h>
#include <stdlib.h>

#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste.h>

#define N 5 

int
main( ) 
{
  err_t noerr = OK; 

  individu_t ** individus = NULL  ; 
  fraction_t ** fractions = NULL  ;
  string_t ** strings = NULL  ; 

  liste_t * liste = NULL ; 
  int i = 0 ; 
 
  individus = malloc( sizeof(individu_t *) * N )  ; 
  fractions = malloc( sizeof(fraction_t *) * N )  ;
  strings = malloc( sizeof(string_t *) * N )   ; 

  printf( "Debut du programme des test sur les listes de %d objets homogenes\n" , N ) ; 


 /* ---------- */

  individus = malloc( sizeof(individu_t *) * N )  ; 
  fractions = malloc( sizeof(fraction_t *) * N )  ;
  strings = malloc( sizeof(string_t *) * N )   ; 

  printf( "\nCreations des variables de travail\n" ) ;
  
  printf( "\tindividus..." ) ; fflush(stdout) ;
  char prenom[128] ;
  char nom[128] ; 
  for( i=0 ; i<N ; i++ ) 
    {
      sprintf( nom , "nom_%d" , N-i ) ;
      sprintf( prenom , "prenom_%d" , N-i ) ;
      individus[i] = individu_creer( prenom , nom ) ; 
    }
  printf("OK\n"); 

  printf( "\tfractions..." ) ; fflush(stdout) ;
  for( i=0 ; i<N ; i++ ) 
    {
      fractions[i] = fraction_creer( N-i , N-i+1 ) ; 
    }
  printf("OK\n");

  printf( "\tstrings..." ) ; fflush(stdout) ;
  char string[128] ;
  for( i=0 ; i<N ; i++ ) 
    {
      sprintf( string , "string_%d" , N-i ) ; 
      strings[i] = string_creer( string ) ; 
    }
  printf("OK\n");

  /* ---------- */

  printf( "\nTest creation d'une liste de %d individus \n" , N ) ;
  liste = liste_creer(N) ;  
  for( i=0 ; i<N ; i++ ) 
    {
      liste_elem_ecrire( liste , individus[i] , i ) ;
    }

  printf( "Test affichage liste d'individus AVANT tri \n" ) ;
  liste_afficher( liste , ' ' ) ; 
  printf( "\n");

  printf( "Test Tri de la liste des individus\n" );
  liste_trier( liste  ) ;

  printf( "Test affichage liste d'individus APRES tri\n" ) ;
  liste_afficher( liste , ' ' ) ; 
  printf( "\n");
 
  printf( "Test destruction liste d'individus\n" ) ;
  if( ( noerr = liste_detruire( &liste ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

  printf( "\nTest creation d'une liste de %d fractions \n" , N ) ;
  liste = liste_creer(N) ;  
  for( i=0 ; i<N ; i++ ) 
    {
      liste_elem_ecrire( liste , fractions[i] , i ) ;
    }

  printf( "Test affichage liste de fractions AVANT tri\n" ) ;
  liste_afficher( liste , ' ' ) ; 
  printf( "\n");

  printf( "Test Tri de la liste des fractions\n" );
  liste_trier( liste ) ;

  printf( "Test affichage liste des fractions APRES tri\n" ) ;
  liste_afficher( liste ,  ' ' ) ; 
  printf( "\n");
 
  printf( "Test destruction liste de fractions\n" ) ;
  if( ( noerr = liste_detruire( &liste ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  

  printf( "\nTest creation d'une liste de %d strings \n" , N ) ;
  liste = liste_creer(N) ;  
  for( i=0 ; i<N ; i++ ) 
    {
      liste_elem_ecrire( liste , strings[i] , i ) ;
    }

  printf( "Test affichage liste de strings AVANT tri\n" ) ;
  liste_afficher( liste ,  ' ' ) ; 
  printf( "\n");
 
  printf( "Test Tri de la liste des strings\n" );
  liste_trier( liste  ) ;
  
  printf( "Test affichage liste des strings APRES tri\n" ) ;
  liste_afficher( liste ,  ' ' ) ; 
  printf( "\n");
  
  printf( "Test destruction liste de strings\n" ) ;
  if( ( noerr = liste_detruire( &liste  ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }



 /* ---------- */

  printf( "\nDestructions des variables de travail\n" ) ;

  printf( "\tindividus..." ) ; fflush(stdout) ; 
  for( i=0 ; i<N ; i++ ) 
    {
      if( ( noerr = individu_detruire( &individus[i] ) ) )
	{ 
	  printf("Sortie avec code erreur = %d\n" , noerr ) ;
	  exit(-1) ; 
	}
    }
  free( individus ) ;
  printf("OK\n"); 


  printf( "\tfractions..." ) ; fflush(stdout) ; 
  for( i=0 ; i<N ; i++ ) 
    {
      if( ( noerr = fraction_detruire( &fractions[i] ) ) )
	{ 
	  printf("Sortie avec code erreur = %d\n" , noerr ) ;
	  exit(-1) ; 
	}
    }
  free( fractions ) ;
  printf("OK\n"); 

  
  printf( "\tstrings..." ) ; fflush(stdout) ; 
  for( i=0 ; i<N ; i++ ) 
    {
      if( ( noerr =string_detruire( &strings[i] ) ) )
	{ 
	  printf("Sortie avec code erreur = %d\n" , noerr ) ;
	  exit(-1) ; 
	}
    }
  free( strings ) ; 
  printf("OK\n"); 

  
  /* ---------- */


  printf( "\nFin du programme des test sur la lste d'objets homogenes\n" ) ; 
  
  printf( "Nombre de liste_t  = %lu\n" , liste_cpt ) ;

  return(0) ; 
}
