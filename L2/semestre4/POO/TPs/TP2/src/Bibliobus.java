/**
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 * 
 */

  // Classe permettant de représenter un objet Livre 

public class Bibliobus{
    private int maxLivre = 100;
    private final String nom;
    private Livre tabl[];
    private int  nbLivre = 0;

    /** Constructeur qui initialise une intense de Bibliobus
    *@param nom : nom du Bibliobus
    *@param maxLivre : le nombre de livre maximum dans le bilbliobus
    */
    public Bibliobus(String nom, int maxLivre){
        this.nom = nom;
        this.maxLivre = maxLivre;
        this.tabl = new Livre[maxLivre];
    }

    /**
     * Constructeur qui initialise une intense de Bibliobus
     * @param nom : nom du Bibliobus
     */
    public Bibliobus(String nom){
        this(nom,100);
    }

    /**
     * Methode qui retourne l'indice du livre qui se trouve dans le Bibliobus
     * @param titre : titre du livre
     * @param auteur : nom de l'auteur
     * @param editeur :  nom de la maison d'édition
     * @return int : indice du livre
     */
    public int indiceLivre(String titre, String auteur, String editeur){
        Livre l = new Livre(titre, auteur, editeur);
        for (int i=0; i<nbLivre; i++){
            if(l.equals(tab[i])){
                return i;
            }
        return -1;
        }
    }

    /**
     * Methode qui retourne vrai si le livre est dans le Bibliobus
     * @param titre : nom de livre
     * @param auteur : nom de l'auteur
     * @param editeur : nom de la maison d'édition
     * @return : boolean, vrai si le livre y est
     */
    public boolean appartient(String titre, String auteur, String editeur){
        Livre l = new Livre(titre, auteur, editeur);
        for (int i = 0; i<nbLivre; i++){
            if(l.equals(tab[i])){
                return true;
            }
        }
        return false;
    }

    /**
     * Methode qui ajoute un Livre dans la bibliobus;
     * @param titre : nom du livre
     * @param auteur : nom de l'auteur
     * @param editeur : nom de l'éditeur
     * @param genre : genre du livre
     * @param nbreEx :  nombre d'exemplaire
     */
    public boolean ajouteLivre(String titre, String auteur, String editeur, Genre genre, int nbreEx){
        if (nbLivre+nbreEx>maxLivre){
            return false;
        }
        if (this.appartient(titre,auteur,editeur,genre)){
            int var = this.indiceLivre(titre,auteur,editeur,genre);
            tabl[var].ajouteExemplaire(nbreEx);
            nbLivre +=nbEx;
            return true;
        }
        tabl[nbLivre] new Livre(titre, auteur, editeur, nbEx, genre);
        nbLivre+=nbEx;
        return true;
    }

    



}