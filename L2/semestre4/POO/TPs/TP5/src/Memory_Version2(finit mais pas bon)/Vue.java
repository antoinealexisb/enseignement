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
    public static final ImageIcon[] TABIMAGES = {new ImageIcon(Vue.class.getResource("images/Bird.gif")), new ImageIcon(Vue.class.getResource("images/Rabbit.gif")), new ImageIcon(Vue.class.getResource("images/Cat.gif")), new ImageIcon(Vue.class.getResource("images/Dog.gif")), new ImageIcon(Vue.class.getResource("images/Bird2.gif")), new ImageIcon(Vue.class.getResource("images/Pig.gif")), new ImageIcon(Vue.class.getResource("images/Cat2.gif")), new ImageIcon(Vue.class.getResource("images/Dog2.gif")), new ImageIcon(Vue.class.getResource("images/Rien.gif")), new ImageIcon(Vue.class.getResource("images/Inconnu.gif"))};
    //indice carte inconnue
    public static final int INDINCONNU = 9;
    public static final int CACHE = 8;

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
        //affichetoi(); //ça fonctionne youppiiiiiii 
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
        setIcon(TABIMAGES[9]);

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



    /* Fonction qui affiche graphiquement la barre d'outils (Quitter, Recommencer).
    */
   public static JToolBar barreEnHaut(ModeleMemory memo){
       JToolBar barre = new JToolBar();
       JButton QUITTER = new JButton("Quitter");
       JButton RECOMMENCER = new JButton("Recommencer");

       QUITTER.addActionListener(
           new ActionListener(){
               public void actionPerformed(ActionEvent ea){
                   System.exit(0);
               }});//new Quitter());

       RECOMMENCER.addActionListener(
           new ActionListener(){
               public void actionPerformed(ActionEvent ea){
                   dessineMoiCarte(memo);
               }});
               //new Recommencer(this));
       barre.add(QUITTER);
       barre.add(RECOMMENCER);

       return barre;
   }

       /**
     * Fonction qui affiche graphiquement une barre de Menus.
     * (Jeu -> Quitter,Recommencer || Aide -> À propos).
     */
    public static void barreMenus(ModeleMemory memo){
        JMenuBar menus = new JMenuBar();
        JMenu menu1 = new JMenu("Jeu");
        JMenu menu2 = new JMenu("Aide");

        JMenuItem menu1Item1 = new JMenuItem("Quitter");
        JMenuItem menu1Item2 = new JMenuItem("Recommencer");
        JMenuItem menu2Item1 = new JMenuItem("À propos");

        menu1Item1.addActionListener(
            new ActionListener(){
                public void actionPerformed(ActionEvent ea){
                    System.exit(0);
                }});
        menu1Item2.addActionListener(
            new ActionListener(){
                public void actionPerformed(ActionEvent ea){
                    dessineMoiCarte(memo);
                }});
                //new Recommencer(this));

        menu1.add(menu1Item1);
        menu1.addSeparator();
        menu1.add(menu1Item2);
        menus.add(menu1);

        menu2Item1.addActionListener(
            new ActionListener(){
                public void actionPerformed(ActionEvent ea){
                    JOptionPane.showMessageDialog(null, "Memory\nAuteur: Antoine-Alexis BOURDON\nannée:2018-2019\nDiscipline:Programmation Orientée objet - L2", "Information", JOptionPane.INFORMATION_MESSAGE);
                }});//new aPropos());
        menu2.add(menu2Item1);
        menus.add(menu2);

        memo.setJMenuBar(menus);

    }

    /**
     * Fonction qui affiche graphiquement le nombre de pair d'images gagnées.
     */
    public static void afficheCmbImgs(ModeleMemory memo){
        int i = memo.NBPAIR-memo.aAvoirEncore;
        memo.jlabNbImgs.setText("Vous avez gagné " + i  + " image" + (i > 1 ? "s" : "") + "!");
    }

    /**
     * Fonction qui affiche graphiquement le nombre d'essais effectué.
     */
    public static void afficheCmbEssais(ModeleMemory memo){
        memo.jlabNbEssaie.setText("Vous avez fait " + memo.nbEssais + " essai" + (memo.nbEssais> 1? "s" : "") + "!");
    }

    public static void dessineMoiCarte(ModeleMemory memo){
        memo.temps.stop();
        memo.cligno = 0;
        memo.carte1=null;

        memo.leTableauZero();
        memo.milieuVue.removeAll();
        for (int i=0; i<memo.NBLIG; i++){
            for (int j=0; j<memo.NBCOL; j++){
                memo.lesCartes[i][j] = new Vue(memo.getIndice(i, j),i ,j);
                memo.lesCartes[i][j].addActionListener(memo);
                memo.milieuVue.add(memo.lesCartes[i][j]);
            }

        }
        memo.jlabNbImgs.setText("Nombre d'images gagnees : 0");
        memo.jlabNbEssaie.setText("Nombre d'essais : 0");
        memo.validate(); //utile : https://docs.oracle.com/javase/8/docs/api/java/awt/Container.html#validate--
    }

}
