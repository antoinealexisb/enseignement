import java.awt.*;
/**
 * Classe qui s'occupe du modele du jeu (les données)
 */
public class ModeleMemory{
    /**
     * Constante (ligne/col)
     */
    public static final int NBLIG = 4;
    public static final int NBCOL = 4;

    public int tabIndImgs[]; //tableau qui contient les indices des images par rapport à TABIMGAGES
    public boolean tabEstTrouves[]; //tableau permettant de savoir qu'elles sont les images trouvées :  1 trouvé 0 sinon.

    private int aAvoirEncore;

    public ModeleMemory(){
        tabIndImgs = new int[16]; //4*4=16 (prendre les constantes)
        tabEstTrouves = new boolean[16];
        aAvoirEncore = 8;
    }

    /**
     * ATTENTION 16 N'EST PAS UNE CONSTANTE !!!!!!!!!
     */
    void leTableauZero(){
        for (int i=0; i<16; i++){
            tabIndImgs[i] = (i%8);
            tabEstTrouves[i] = false;
        }
    }

    /**
     * avoir l'indice de l'image choisi
     */
    public int getIndice(int lig, int col){
        return tabIndImgs[lig*4+col];
    }

    public boolean identiques(Point carte1, Point carte2){
        int c1 = tabIndImgs[carte1.x*4+carte1.y];
        int c2 = tabIndImgs[carte2.x*4+carte2.y];
        if (c1 != c2)
            return false;
        //tabEstTrouves[carte1.x*4+carte1.y] = true;
        //tabEstTrouves[carte2.x*4+carte2.y] = true;
        aAvoirEncore--;
        return true;
    }

    public boolean gagne(){
        return aAvoirEncore <= 0;
    }

}