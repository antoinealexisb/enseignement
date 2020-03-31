/**
* Classe Livre
*
* @author Codron Julien
* @version 1.0
*/

// Classe permettant de représenter un objet Livre

public class Livre{

  private final static String lgenre[] = {"littérature française","littérature jeunesse","littérature étrangère","policier","politique","sciences","sciences humaines"};

  private final String titre;
  private final String auteur;
  private final String editeur;
  private int nbEx;
  private String genre;


  /** Constructeur d'un Livre
  * @param titre = titre du livre
  * @param auteur = nom de l'auteur du Livre
  * @param editeur = éditeur du livre
  * @param genre = genre litteraire du livre
  * @param nbEx = nombre d'exemplaire disponible
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

  public Livre( String titre, String auteur, String editeur){
    this(titre,auteur,editeur,1,"Non Spécifié");
  }

  /** accesseur pour le titre du livre
  @return le titre du livre */
  public String getTitre(){
    return titre;
  }

  /** accesseur pour l'auteur' du livre
  @return l'auteur du livre*/
  public String getAuteur(){
    return auteur;
  }

  /** accesseur pour l'editeur du livre
  @return l'editeur du livre */
  public String getEditeur(){
    return editeur;
  }




  /** Methode qui permet d'ajouter un nombre d'exemplaire definie d'un Livre
  @param nb = le nombre de livre ajouter au bibliobus
  @return boolean, true si l'action est effectué*/
  public boolean ajouteExemplaire(int nb){
    if (nb > 0){
      nbEx += nb;
      return true;
    }
    return false;
  }

  /** Methode qui permet d'ajouter un seul nombre d'exemplaire definie d'un Livre
  @return boolean, true si l'action est effectué*/
  public boolean ajouteExemplaire(){
    return this.ajouteExemplaire(1);
  }

  /** Methode qui permet de réduire le nbEx de 1 quand un livre set perdu
  @return boolean, true si l'action est effectué*/
  public boolean supprimeExemplaire(){
    if (nbEx > 0 ){
      nbEx-=1;
      return true;
    }
    return false;
  }

  /** Methode qui permet de voir si un livre est reelement dans le bibliobus
  @return boolean, true si il y est*/
  public boolean estPresent(){
    if (nbEx >= 0 ){
      return true;
    }
    return false;
  }

  /** Méthode permettant d'afficher un livre grace à ces paramètre.
  return: un string avec les caractèristiques du livre. */
  public String toString(){
    return "Titre : " + titre + "\nAuteur : " + auteur + "\nEditeur : " + editeur + "\ngenre : " + genre + "\nNombre d'exemplaires : " + nbEx +"\n\n";
  }

  public boolean equals(Livre liv){
    return ((titre == liv.getTitre()) && (auteur == liv.getAuteur()) && (editeur == liv.getEditeur()));
  }

  public Livre nouvelEditeur(String edit){
    return new Livre(titre,auteur,edit,nbEx,genre);
  }
}
