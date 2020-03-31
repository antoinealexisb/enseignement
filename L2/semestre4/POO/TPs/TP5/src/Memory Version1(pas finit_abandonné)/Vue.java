import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;

/**
 * Classe qui modélise graphiquement le jeu 
 */
public class Vue extends JButton{
    //le tableau d'image 
    public static final ImageIcon[] TABIMAGES = {new ImageIcon(Vue.class.getResource("images/Bird.gif")), new ImageIcon(Vue.class.getResource("images/Rabbit.gif")), new ImageIcon(Vue.class.getResource("images/Cat.gif")), new ImageIcon(Vue.class.getResource("images/Dog.gif")), new ImageIcon(Vue.class.getResource("images/Bird2.gif")), new ImageIcon(Vue.class.getResource("images/Pig.gif")), new ImageIcon(Vue.class.getResource("images/Cat2.gif")), new ImageIcon(Vue.class.getResource("images/Dog2.gif")), new ImageIcon(Vue.class.getResource("images/Rien.gif")), new ImageIcon(Vue.class.getResource("images/Inconnu.gif"))};
    //indice carte inconnue
    public static final int INDINCONNU = 9;
    public static final int CACHE = 8;

    //indice de l'image pour chaque instance creer 
    private int indice;

    //coordonnées pour ActionListener
    private Point coordonnees;

    public Vue(int indice, int x, int y){
        this.indice = indice;
        //affichetoi(); //ça fonctionne youppiiiiiii 
        coordonnees = new Point(x,y);
        cacheCache();
    }

    public void affichetoi(){
        setIcon(TABIMAGES[indice]);
        setDisabledIcon(TABIMAGES[indice]);
        setEnabled(false);
    }

    /**
     * Fonction qui joue à cache-cache l'instance graphique de la carte (le sujet c'est des cartes ou des cases ?? :D je suis fatigué je pense)
     *      */
    public void cacheCache(){
        setEnabled(true);
        setIcon(TABIMAGES[9]);

    }

    public void rien(){
        setEnabled(false);
        setIcon(TABIMAGES[8]);
        setDisabledIcon(TABIMAGES[8]);
    }

    public int getIndice()
    {
      return indice;
    }

    public Point getCoords(){
        return coordonnees;
    }

}