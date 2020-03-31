//Modules à importer.
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;

/**
 * Classe qui modélise graphiquement une instance d'un Bouton representant une carte.
 */
public class Vue extends JButton{
    //le tableau d'image (non modifiable)
    public static final ImageIcon[] TABIMAGES = {new ImageIcon(Vue.class.getResource("images/1.png")),new ImageIcon(Vue.class.getResource("images/2.png")),new ImageIcon(Vue.class.getResource("images/3.png")),new ImageIcon(Vue.class.getResource("images/4.png")),new ImageIcon(Vue.class.getResource("images/5.png")),new ImageIcon(Vue.class.getResource("images/6.png")),new ImageIcon(Vue.class.getResource("images/7.png")),new ImageIcon(Vue.class.getResource("images/rien.png"))};
    //{new ImageIcon(Vue.class.getResource("images/Bird.gif")), new ImageIcon(Vue.class.getResource("images/Rabbit.gif")), new ImageIcon(Vue.class.getResource("images/Cat.gif")), new ImageIcon(Vue.class.getResource("images/Dog.gif")), new ImageIcon(Vue.class.getResource("images/Bird2.gif")), new ImageIcon(Vue.class.getResource("images/Pig.gif")), new ImageIcon(Vue.class.getResource("images/Cat2.gif")), new ImageIcon(Vue.class.getResource("images/Dog2.gif")), new ImageIcon(Vue.class.getResource("images/Rien.gif")), new ImageIcon(Vue.class.getResource("images/Inconnu.gif"))};
    //indice carte inconnue
    public static final int INDINCONNU = 6;
    public static final int CACHE = 7;

    //indice de l'image pour chaque instance creer 
    private int indice;

    //coordonnées pour ActionListener
    private Point coordonnees;

    /**
     * Construit une instance de Vue concernant une seule image.
     * @param indice : indice de l'image, correspondant à l'emplacement dans le TABIMAGES[].
     * @param x : entier correspondant à la ligne afficher dans l'interface du jeu.
     * @param y : entier correspondant à la colonne afficher dans l'interface du jeu.
     */
    public Vue(int indice, int x, int y){
        this.indice = indice;
        coordonnees = new Point(x,y);
        cacheCache();
    }

    /**
     * Fonction qui affiche graphiquement une image et empeche d'interagir avec l'image afficher.
     */
    public void affichetoi(){
        setIcon(TABIMAGES[indice]);
        setDisabledIcon(TABIMAGES[indice]);
        setEnabled(false);
    }

    /**
     * Fonction qui retourne graphiquement une carte.
     *      */
    public void cacheCache(){
        setEnabled(true);
        setIcon(TABIMAGES[INDINCONNU]);

    }

    /**
     * Fonction qui affiche l'image "Rien.gif" et empeche d'interagir avec l'instance JButton correspond.
     */
    public void rien(){
        //setEnabled(false);
        indice = CACHE;
        setIcon(TABIMAGES[CACHE]);
        setDisabledIcon(TABIMAGES[CACHE]);
    }

    /**
     * Fonction retournant l'indice de l'image par raport au TABIMAGES[].
     * @return : indice de l'image.
     */
    public int getIndice()
    {
      return indice;
    }

    /**
     * Fonction retournant les coordonnées (x,y) de l'instance de l'image.
     * @return : Coordonnées de l'image (x,y).
     */
    public Point getCoords(){
        return coordonnees;
    }

    /**
     * Fonction qui ne rend plus "clickable" les cartes.
     * @param : boolean qui indique si la carte à dejà était decouvert ou non.
     */
    public void offClick(boolean pasTrouve){
        setEnabled(false);
        if (pasTrouve)
            setDisabledIcon(TABIMAGES[INDINCONNU]);
        else
            setDisabledIcon(TABIMAGES[indice]);
    }

    /**
     * Fonction qui rend "clickable" les cartes.
     */
    public void onClick(){
        setEnabled(true);
    }
}