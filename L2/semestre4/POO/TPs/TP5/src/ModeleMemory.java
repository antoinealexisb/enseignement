import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Collection;
/**
 * Classe qui s'occupe du modele du jeu (les données)
 */
public class ModeleMemory{
    
    //Constante (ligne/col)
    public static final int NBLIG = 3;
    public static final int NBCOL = 6;
    public static final int NBCARTES = NBLIG*NBCOL;
    public static final int NBPAIRES = 9;
    public static final int NBIMGSCARTES = 6;

    public int tabIndImgs[][]; //tableau qui contient les indices des images par rapport à TABIMGAGES
    public boolean tabEstTrouves[][]; //tableau permettant de savoir qu'elles sont les images trouvées :  1 trouvé 0 sinon.

    private int aAvoirEncore;
    private int nbEssais;

     /**
     * Construit une intense de Modele
     */
    public ModeleMemory(){
        tabIndImgs = new int[NBLIG][NBCOL]; //4*4=16 (prendre les constantes)
        tabEstTrouves = new boolean[NBLIG][NBCOL];
        aAvoirEncore = NBPAIRES;
    }

    /**
     * ATTENTION 16 N'EST PAS UNE CONSTANTE !!!!!!!!!
     */
    /**
     * Fonction permettant de melanger les cartes.
     */
    void leTableauZero(){

        java.util.List<Integer> l = new ArrayList<Integer>();
        for (int j = 0; j < NBPAIRES; j++) {
          l.add(Integer.valueOf(j%NBIMGSCARTES));
          l.add(Integer.valueOf(j%NBIMGSCARTES));
        }
        //System.out.println(l);
        java.util.Collections.shuffle(l);
        //System.out.println(l);
        int truc = 0;
        for (int i=0; i<NBLIG; i++){
            for (int j=0; j<NBCOL; j++){
                tabIndImgs[i][j] = (l.get(truc)).intValue();
                tabEstTrouves[i][j] = false;
                truc++;
            }
        }
        nbEssais = 0;
        aAvoirEncore = NBPAIRES;
    }

    /**
     * Fonction qui permet d'avoir l'indice de l'image choisi.
     * @param : ligne de l'image.
     * @param : colonne de l'image.
     * @return : l'indice de l'image choisi.
     */
    public int getIndice(int lig, int col){
        return tabIndImgs[lig][col];
    }

    /**
     * Fonction qui indique si deux cartes possède la même image.
     * @param : coordonnée de l'image1.
     * @param : coordonnée de l'image2.
     * @return : vrai si les deux cartes sont identiques, faux sinon.
     */
    public boolean identiques(Point carte1, Point carte2){
        int c1 = tabIndImgs[carte1.x][carte1.y];//*NBLIG+carte1.y];
        int c2 = tabIndImgs[carte2.x][carte2.y];//*NBLIG+carte2.y];
        nbEssais ++;
        if (c1 != c2)
            return false;
        tabEstTrouves[carte1.x][carte1.y] = true;//*NBLIG+carte1.y] = true;
        tabEstTrouves[carte2.x][carte2.y] = true;//*NBLIG+carte2.y] = true;
        aAvoirEncore--;
        return true;
    }


    /**
     * Fonction qui indique si les partie est gagné ou non.
     * @return : vrai si partie gagné, non sino.
     */
    public boolean gagne(){
        return aAvoirEncore == 0;
    }

    /**
     * Fonction qui indique si une carte n'a pas encore été trouver.
     * @param : ligne de la carte.
     * @param : colonne de la carte.
     * @return : vrai si la carte n'a pas encore été trouver, sinon non.
     */
    public boolean pasTrouvee(int lig, int col){
        return (tabEstTrouves[lig][col]==false);//*NBLIG+col] == false);
    }

    /**
     * Fonction qui retourne le nombre d'essais déjà effectué pour la grille de cartes en cours.
     * @return : le nombre d'essais du joueur.
     */
    public int getNbEssais(){
        return nbEssais;
    }

    /**
     * Fonction qui retourne le nombre de paires de cartes à découvrir encore.
     * @return : Le nombre de paires de cartes restantes.
     */
    public int getAAvoirEncore(){
        return aAvoirEncore;
    }

    /**
     * Fonction retournant le nombre de paires de cartes dans le jeu.
     * @return : Le nombre de paires de cartes du jeu.
     */
    public int getNBPAIRES(){
        return NBPAIRES;
    }

    /**
     * Fonction retournant le nombre de lignes du jeu.
     * @return : Le nombre de Lignes du jeu.
     */
    public int getNBLIG(){
        return NBLIG;
    }

    /**
     * Fonction retournant le nombre de colonnes du jeu.
     * @return : Le nombre de Lignes du jeu.
     */
    public int getNBCOL(){
        return NBCOL;
    }

}