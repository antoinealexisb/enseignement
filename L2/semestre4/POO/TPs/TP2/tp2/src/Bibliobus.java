/**
* Classe Bibliobus
*
* @author Codron Julien
* @version 1.0
*/

// Classe permettant de représenter un objet Livre

public class Bibliobus{

  private int maxLivre = 100;
  private final String nom;
  private Livre tabl[];
  private int  nbLivre = 0;

  /** Constructeur de Bibliobus
  *@param nom = nom du Bibliobus
  *@param maxLivre = le nombre de livre maximum dans le bilbliobus
  */
  public Bibliobus(String nom, int maxLivre){
    this.nom = nom;
    this.maxLivre = maxLivre;
    this.tabl = new Livre[maxLivre];
  }

  public Bibliobus(String nom){
    this(nom,100);
  }


  /** Methode renvoyant l'indice d'un livre si il est présent dans le bibliobus sinon return -1
  *@param titre = nom du livre
  *@param auteur = auteur du Livre
  *@param editeur = editeur du Livre
  *@return int = indice du livre dans le bibliobus ou -1 s'il n'y est pas
  */
  public int indiceLivre(String titre, String auteur, String editeur){
    Livre l = new Livre(titre,auteur,editeur);
    for (int i = 0 ; i < nbLivre ; i++){
      if (l.equals(tabl[i])){
        return i;
      }
    }
    return -1;
  }

  /** Methode renvoyant un boolean indiquand si un livre est dans le Bibliobus.
  *@param titre = nom du livre
  *@param auteur = auteur du Livre
  *@param editeur = editeur du Livre
  *@return bool = true si il y est, false s'il ne l'est pas
  */
  public boolean appartient(String titre, String auteur, String editeur){
    Livre l = new Livre(titre,auteur,editeur);
    for (int i = 0 ; i < nbLivre ; i++){
      if (l.equals(tabl[i])){
        return true;
      }
    }
    return false;
  }

  /** Methode qui ajoute un livre aubibliobus
  *@param titre = titre du livre
  *@param auteur = auteur du Livre
  *@param editeur = editeur du Livre
  *@param genre = genre du livre
  *@param nbEx = nombre d'exemplaires du livre
  *@return bool = True si des livre on était ajouter au bibliobus
  *A REFAIRE!!!!!
  */
  public boolean ajouteLivre(String titre, String auteur, String editeur, int nbEx, String genre){
    if (nbLivre+1 > maxLivre) return false;
    int ajoute = nbE;
    boolean ok = true;
    for (int i = 0 ; i < nbEx ; i++){
      if (nbLivre+i == maxLivre){
        ajoute = i;
      }
    Livre liaa = new Livre(titre,auteur,editeur,nbEx,genre);
    for (int j = 0 ; j < nbLivre ; j++){
      if (liaa.equals(tabl[j])){
        tabl[i].nbEx += ajoute;
        nbLivre += ajoute;
        ok = false;
      }
    if (ok){
      tabl[nbLivre+1]
    }
    }
  }


  /** Methode qui ajoute un livre aubibliobus
  *@param titre = titre du livre
  *@param auteur = auteur du Livre
  *@param editeur = editeur du Livre
  *@param genre = genre du livre
  *@return bool = True si des livre on était ajouter au bibliobus
  */
  public boolean ajouteLivre(String titre, String auteur, String editeur, String genre){

  }

}
