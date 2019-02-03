// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора



# ifndef __TMATRIX_H__
# define  __TMATRIX_H__

# include  < iostream >

using  namespace  std ;

const  int MAX_VECTOR_SIZE = 100000000 ;
const  int MAX_MATRIX_SIZE = 10000 ;

// modèle vectoriel
modèle < classe  ValType >
classe  TVector
{
protégé:
  ValType * pVector;
   taille int ;       // taille du vecteur
  int StartIndex; // index du premier élément du vecteur
public:
  TVector ( int s = 10 , int si = 0 );
  TVector ( const TVector & v);                // constructeur de copie
  ~ TVector ();
  int  GetSize () { return  Size ; } // taille du vecteur
  int  GetStartIndex () { return StartIndex; } // index du premier élément
  ValType & operator [] ( int pos);             // accès
   opérateur bool == ( const TVector & v) const ;  // comparaison
   opérateur bool ! = = ( const TVector & v) const ;  // comparaison
  TVector & operator = ( const TVector & v);     // affectation

  // opérations scalaires
Opérateur   TVector   + ( const ValType & val);   // ajouter un scalaire
Opérateur   TVector   - ( const ValType & val);   // soustrais le scalaire
Opérateur   TVector   * ( const ValType & val);   // multiplier par scalaire

  // opérations vectorielles
Opérateur   TVector   + ( const TVector & v);     // addition
Opérateur   TVector   - ( const TVector & v);     // soustraction
Opérateur   ValType   * ( const TVector & v);     // produit scalaire

  // I / O
  ami istream & opérateur >> (istream & in, TVector & v)
  {
    pour ( int i = 0 ; i <v. Size ; i ++)
      dans >> v. pVecteur [i];
    retourner dans;
  }
  ami ostream & opérateur << (ostream & out, const TVector & v)
  {
    pour ( int i = 0 ; i <v. Size ; i ++)
      out << v. pVector [i] << '  ' ;
    déclaration de retour sur;
  }
};

modèle < classe  ValType >
TVector <ValType> :: TVector ( int s, int si)
{
	if (s < 0 || s> || MAX_VECTOR_SIZE si < 0 || si> MAX_VECTOR_SIZE) instruction throw - 1 ;
	Taille = s;
	StartIndex = si;
	pVector = new ValType [ Size ];
	pour ( int i = 0 ; i < taille ; ++ i)
		pVecteur [i] = 0 ;
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // constructeur de copie
TVector <ValType> :: TVector ( const TVector <ValType> & v)
{
	Taille = v. Taille ;
	pVector = new ValType [v. Taille ];
	StartIndex = v. StartIndex ;
	pour ( int i = 0 ; i < taille ; ++ i)
		pVecteur [i] = v. pVecteur [i];
} / * --------------------------------------------------- -------------------------- * /

modèle < classe  ValType >
TVector <ValType> :: ~ TVector ()
{
	supprimer [] ceci -> pVector ;
} / * --------------------------------------------------- -------------------------- * /

template < classe  ValType > // accès
ValType & TVector <ValType> :: operator [] ( int pos)
{
	if ((pos < 0 ) || (pos> = taille ) || (pos <StartIndex)) jette - 1 ;
	retourne pVector [pos - this -> StartIndex ];
} / * --------------------------------------------------- -------------------------- * /

template < classe  ValType > // comparaison
bool TVector <ValType> :: operator == ( const TVector & v) const
{
	if ( this -> Size ! = v. Size ) renvoie  false ;
	if ( this -> StartIndex ! = v. StartIndex ) renvoie  false ;
	pour ( int i = 0 ; i < taille ; ++ i)
		if (pVector [i]! = v. pVector [i]) renvoie  false ;
	retourne  vrai ;
} / * --------------------------------------------------- -------------------------- * /

template < classe  ValType > // comparaison
bool TVector <ValType> :: operator ! = ( const TVector & v) const
{
	retour ! (* this == v);
} / * --------------------------------------------------- -------------------------- * /

modèle < classe  ValType > // affectation
TVector <ValType> & TVector <ValType> :: operator = ( const TVector & v)
{
	si ( ceci ! = & v) {
		si ( ceci -> Taille ! = v. Taille )
		{
			delete [] pVector;
			ceci -> Taille = v. Taille ;
			this -> pVector = new ValType [ Taille ];
		}
		this -> StartIndex = v. StartIndex ;
		pour ( int i = 0 ; i < taille ; ++ i)
			pVecteur [i] = v. pVecteur [i];
	}
	retourner * ceci ;
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // add scalar
TVector <ValType> TVector <ValType> :: operator + ( const ValType & val)
{
	TVector <ValType> tmp (* this );
	pour ( int i = 0 ; i < taille ; ++ i)
		tmp. pVecteur [i] + = val;
	tmp de retour ;
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // soustrait un scalaire
TVector <ValType> TVector <ValType> :: operator - ( const ValType & val)
{
	TVector <ValType> tmp (* this );
	pour ( int i = 0 ; i < taille ; ++ i)
		tmp. pVecteur [i] - = val;
	tmp de retour ;
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // multiplier par un scalaire
TVector <ValType> TVector <ValType> :: operator * ( const ValType & val)
{
	TVector <ValType> tmp (* this );
	pour ( int i = 0 ; i < taille ; ++ i)
		tmp. pVecteur [i] * = val;
	tmp de retour ;
} / * --------------------------------------------------- -------------------------- * /

template < classe  ValType > // addition
TVector <ValType> TVector <ValType> :: operator + ( const TVector <ValType> & v)
{
	si ( taille ! = v. taille ) lancer - 1 ;
	TVector <ValType> tmp (* this );
	pour ( int i = 0 ; i < 0 ; ++ i)
		tmp. pVecteur [i] = tmp. pVecteur [i] + v. pVecteur [i];
	tmp de retour ;
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // soustraction
TVector <ValType> TVector <ValType> :: operator - ( const TVector <ValType> & v)
{
	si ( taille ! = v. taille ) lancer - 1 ;
	TVector <ValType> tmp (* this );
	pour ( int i = 0 ; i < 0 ; ++ i)
		tmp. pVecteur [i] = tmp. pVecteur [i] - v. pVecteur [i];
	tmp de retour ;
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // produit scalaire
ValType TVector <ValType> :: operator * ( const TVector <ValType> & v)
{
	si ( taille ! = v. taille ) lancer - 1 ;
	ValType tmp = 0 ;
	pour ( int i = 0 ; i < taille ; ++ i)
		tmp + = pVector [i] * v. pVecteur [i];
	tmp de retour ;
} / * --------------------------------------------------- -------------------------- * /


// matrice triangulaire supérieure
modèle < classe  ValType >
classe  TMatrix : public  TVector <TVector <ValType >>
{
public:
  TMatrix ( int s = 10 );                           
  TMatrix ( const TMatrix & mt);                    // copie
  TMatrix ( const TVector <TVector <ValType >> & mt); // conversion de type
  bool  opérateur == ( const TMatrix mt &) const ;      // comparaison
   opérateur bool ! = = ( const TMatrix & mt) const ;      // comparaison
  TMatrix & operator = ( const TMatrix & mt);        // affectation
Opérateur   TMatrix   + ( const TMatrix & mt);        // addition
Opérateur   TMatrix   - ( const TMatrix & mt);        // soustraction

  // entrée / sortie
  ami istream & opérateur >> (istream & in, TMatrix & mt)
  {
    pour ( int i = 0 ; i < taille de la mt ; i ++)
      dans >> mt. pVecteur [i];
    retourner dans;
  }
  ami ostream & opérateur << (ostream & out, const TMatrix & mt)
  {
    pour ( int i = 0 ; i < taille de la mt ; i ++)
      sur << mt. pVector [i] << endl;
    déclaration de retour sur;
  }
};

modèle < classe  ValType >
TMatrix <ValType> :: TMatrix ( int s): TVector <TVector <ValType >> (s)
{
	if (s < 0 || s> MAX_MATRIX_SIZE) { Déclaration de projection - 2 ; };
	
	pour ( int i = 0 ; i <s; ++ i)
		this -> pVector [i] = TVector <ValType> (s - i, i);
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // constructeur de copie
TMatrix <ValType> :: TMatrix ( const TMatrix <ValType> & mt):
  TVector <TVector <ValType >> (mt) {}

template < class  ValType > // type constructeur de conversion
TMatrix <ValType> :: TMatrix ( const TVector <TVector <ValType >> & mt):
  TVector <TVector <ValType >> (mt) {}

template < classe  ValType > // comparaison
bool TMatrix <ValType> :: operator == ( const TMatrix <ValType> & mt) const
{
	return TVector <TVector <ValType >> :: operator == (mt);
} / * --------------------------------------------------- -------------------------- * /

template < classe  ValType > // comparaison
bool TMatrix <ValType> :: operator ! = = const TMatrix <ValType> & mt) const
{
	retour ! (* this == mt);
} / * --------------------------------------------------- -------------------------- * /

modèle < classe  ValType > // affectation
TMatrix <ValType> & TMatrix <ValType> :: operator = ( const TMatrix <ValType> & mt)
{
	si ( ceci ! = & mt) {
		this -> StartIndex = mt. StartIndex ;
		si ( ceci -> Taille ! = Taille en Mt )
		{
			ceci -> Taille = mt. Taille ;
			supprimer [] ceci -> pVector ;
			this -> pVector = new TVector <ValType> [mt. Taille ];
		}
		pour ( int i = 0 ; i < this -> Size ; ++ i)
			this -> pVector [i] = mt. pVecteur [i];
	}
	retourner * ceci ;
} / * --------------------------------------------------- -------------------------- * /

template < classe  ValType > // addition
TMatrix <ValType> TMatrix <ValType> :: operator + ( const TMatrix <ValType> & mt)
{
	si ( ceci -> Taille ! = Taille Mt ) jeter - 2 ;
	return TVector <TVector <ValType >> :: operator + (mt);
} / * --------------------------------------------------- -------------------------- * /

template < class  ValType > // soustraction
TMatrix <ValType> TMatrix <ValType> :: operator - ( const TMatrix <ValType> & mt)
{
	si ( ceci -> Taille ! = Taille Mt ) jeter - 2 ;
	return TVector <TVector <ValType >> :: operator - (mt);
} / * --------------------------------------------------- -------------------------- * /

// TVector O3 L2 P4 C6
// TMatrix O2 L2 P3 C3
# endif