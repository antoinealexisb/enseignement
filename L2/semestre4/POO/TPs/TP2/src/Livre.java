/*
@author BOURDON Antoine-Alexis
@version 1.0
*/

// Classe permettant de représenter un objet Livre
public class Livre{
  private final static String lgenre[] = {"littérature française","littérature jeunesse","littérature étrangère","policier","politique","sciences","sciences humaines"};

  private final String titre;
  private final String auteur;
  private final String editeur;
  private int nbEx;
  private String genre;

  /**
   * Construteur qui initialise une intense de Livre
   * @param titre : titre du livre
   * @param auteur : nom de l'auteur
   * @param editeur : nom de l'editeur
   * @param nbEx : nombre d'exmplaire disponible
   * @param genre : genre du livre
   */
  public Livre( String titre, String auteur, String editeur, int nbEx, String genre){
    this.titre = titre;
    this.auteur = auteur;
    this.editeur = editeur;
    int cpt = 0;
    if (nbEx > 0) {
      this.nbEx = nbEx;
    }

    for (int i = 0 ; i < lgenre.length ; i++ ){
      if( genre == lgenre[i] ){
        this.genre = genre;
        cpt +=1;
      }
    }
    if (cpt == 0){
      this.genre ="Non spécifié";
    }
    cpt = 0;
  }

  /**
   * Constructeur d'une instence de Livre (titre, auteur , editeur)
   * @param titre : titre du livre
   * @param auteur : nom de l'auteur
   * @param editeur : nom de l'diteur
   */
  public Livre( String titre, String auteur, String editeur){
    this(titre,auteur,editeur,1,"Non Spécifié");
  }

  //EXO3 Accesseurs
  /** 
  * accesseur pour le titre du livre
  * @return le titre du livre 
  */
  public String getTitre(){
    return titre;
  }

  /**
   * accesseur pour le nom de l'Auteur
   * @return le nom de l'Auteur
   */
  public String getAuteur(){
    return Auteur;
  }

  /**
   * accesseur pour le nom de l'éditeur
   * @return le nom de l'éditeur
   */
  public String getEditeur(){
    return editeur;
  }

  /**
   * accesseur pour le nombre d'exemplaire
   * @return le nombre d'exemplaire
   */
  public String getNbEx(){
    return nbEx;
  }

  /**
   * acceusseur pour le genre du livre
   * @return le genre du livre
   */
  public String getGenre(){
    return genre;
  }
  

  //EXO 4 
/** Methode qui ajoute un nombre d'exemplaire definie d'un Livre
  @param nb : le nombre de livre ajouter au bibliobus
  @return : boolean, vrai si l'action est effectué*/
  public boolean ajouteExemplaire(int nb){
    if (nb > 0){
      nbEx += nb;
      return true;
    }
    return false;
  }

  /** Methode qui ajoute un seul nombre d'exemplaire definie d'un Livre
  @return boolean, vrai si l'action est effectué*/
  public boolean ajouteExemplaire(){
    return this.ajouteExemplaire(1);
  }

  /** Methode qui réduit de 1 le nbEx de 1 quand un livre et perdu .
  @return boolean, vrai si l'action est effectué*/
  public boolean supprimeExemplaire(){
    if (nbEx > 0 ){
      nbEx-=1;
      return true;
    }
    return false;
  }

  //Exo 5 
  /** Méthode qui affiche un Livre grâce à ses paramètres
   * @return informations du livre
   */
  public String toString(){
    return "Titre : "+ titre + ", auteur : " + auteur + ", editeur : " + editeur + ", nombre d'Exemplaire : " + nbEx + ", genre : " + genre ;
  }

  //Exo 6
  /** Methode qui retourne le fait qu'il y a au moins un exemplaire de ce livre
  @return boolean, vrai s'il y est*/
  public boolean estPresent(){
    if (nbEx >= 0 ){
      return true;
    }
    return false;
  }

  //Exo 7 

  /**
   * Methode qui retourne le fait que deux livres ont le même titre, le même auteur et le même editeur
   * @param truc : Livre
   * @return : boolean, vrai s'ils sont pareilles
   */
  public boolean equals(Livre truc){
    return ((titre == truc.getTitre()) && (auteur == truc.getAuteur()) && (editeur == truc.getEditeur()));
  }

  //Exo8
  /**
   * Methode qui retourne une nouvelle intance de Livre
   * @param editeur : nom de l'editeur
   * @return : instance de Livre
   */
  public Livre nouvelEditeur(String editeur){
    return new Livre(titre,auteur,editeur,nbEx,genre);
  }
}
