import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Collection;
/**
 * Classe qui s'occupe du modele du jeu
 */
public class ModeleMemory extends JFrame implements ActionListener{
    /**
     * Constante (ligne/col)
     */
    public static final int NBLIG = 4;
    public static final int NBCOL = 4;

    public int tabIndImgs[]; //tableau qui contient les indices des images par rapport à TABIMGAGES
    public boolean tabEstTrouves[]; //tableau permettant de savoir qu'elles sont les images trouvées :  1 trouvé 0 sinon.


    //nombre d'image à avoir encore;
    public int aAvoirEncore;
    public int nbEssais;

    public final int NBPAIR = 8;

    //tableau pour les cartes
    public Vue lesCartes[][];

    //pour sauvegarder ModeleMemory pour ensuite utilisé ses données
    public Vue carte1;
    public Vue carte2;
    public boolean identiques = false;

    //les composantes timer
    public Timer temps;
    public int cligno;

    //vue des boutons des cartes
    public JPanel milieuVue;

    //nombre d'images gagnees  et nombre d'essais
    public JLabel jlabNbEssaie;
    public JLabel jlabNbImgs;


    /**
     * Construit une intense de Modele
     */
    public ModeleMemory(){
        //Creation de la fenetre
        super("My Memories");

        tabIndImgs = new int[16]; //4*4=16 (prendre les constantes)
        tabEstTrouves = new boolean[16];
        aAvoirEncore = 8;

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	this.setVisible(true);
        Dimension dimEcran = this.getToolkit().getScreenSize();
        this.setLocation((dimEcran.width-this.getSize().width)/2,(dimEcran.height-this.getSize().height)/2);
        temps = new Timer(500, new ActionListener(){public void actionPerformed(ActionEvent evt){actionTimer();}});

         //emplacement pour mettre les cartes
        lesCartes = new Vue[NBLIG][NBCOL];

        //creation du milleu pour les cartes
        milieuVue = new JPanel();
        Container cont = this.getContentPane();
        milieuVue.setLayout(new GridLayout(NBLIG, NBCOL,15,15));

        jlabNbEssaie = new JLabel();
        jlabNbImgs = new JLabel();

        Vue.dessineMoiCarte(this);

        JPanel indicationEnBas = new JPanel(new GridLayout(1, 2));
        indicationEnBas.add(jlabNbEssaie);
        indicationEnBas.add(jlabNbImgs);

        cont.add(milieuVue);
        cont.add(indicationEnBas, "South");

        Vue.barreMenus(this);
        cont.add(Vue.barreEnHaut(this),"North");
        afficheGrille();
        this.pack();
    }

    /**
     * Fonction qui permet d'afficher les cartes un certain nombre de temps et fait clignoté les cartes identiques.
     */
    public void actionTimer()
    {
        //System.out.println("Prout");
        cligno ++;
        if (cligno<7){//((cligno<7)&&(identiques)){
            if (identiques){
            carte1.setVisible(cligno%2 == 0);
            carte2.setVisible(cligno%2 == 0);}
        }
        else{
            if (identiques){
                carte1.rien();
                carte2.rien();
                identiques = false;
            }
            else {
                carte1.cacheCache();
                carte2.cacheCache();
            }
            cligno = 0;
            carte1=null;
            Vue.afficheCmbImgs(this);
            Vue.afficheCmbEssais(this);
            temps.stop();
        
            for (int i = 0; i < lesCartes.length; i++){
                for (int j = 0; j < lesCartes[i].length; j++){
                    if (this.pasTrouvee(i, j))
                        lesCartes[i][j].onClick();
                }
            }

            if (this.gagne()){
                JOptionPane.showMessageDialog(null, "Tu as gagné !!!!!!!!!!!!", "/!\\/!\\ TU AS RÉUSSI /!\\/!\\", JOptionPane.ERROR_MESSAGE);
                Vue.dessineMoiCarte(this);
            }
        }

    }

    /**
     * Fonction qui ecoute les évènements d'action.
     */
    public void actionPerformed(ActionEvent e) {
        Vue carteTmp;
        carteTmp = (Vue)e.getSource();//utilisé getsource() -> Methods inherited from class java.util.EventObject //pas de clone() AA !!!!!!!! cast !!!!!
        //carteTmp.affichetoi();
        if (carte1 == null){
            carte1 = carteTmp;
            carteTmp.affichetoi();
        }
        else{
            carte2 = carteTmp;
            //fonction identiques à faire dans modele (bool)
            identiques = this.identiques(carte1.getCoords(), carteTmp.getCoords());
            //System.out.println(identiques);
            //temps.setInitialDelay(1000);

            //desactiver les boutons
            for (int i = 0; i < lesCartes.length; i++) {
                for (int j = 0; j < lesCartes[i].length; j++) {
                    lesCartes[i][j].offClick(this.pasTrouvee(i, j));
                }
            }
            carte1.affichetoi();
            carteTmp.affichetoi();

            temps.start();

        }
    }


    ///////////////////////////////////////////////////////////
    /**
     * ATTENTION 16 N'EST PAS UNE CONSTANTE !!!!!!!!!
     */
    /**
     * Fonction permettant de melanger les cartes.
     */
    void leTableauZero(){

        java.util.List<Integer> l = new ArrayList<Integer>();
        for (int j = 0; j < 16; j++) {
          l.add(Integer.valueOf(j%8));
        }
        //System.out.println(l);
        java.util.Collections.shuffle(l);
        System.out.println(l);
        for (int i=0; i<16; i++){
            tabIndImgs[i] = (l.get(i)).intValue();
            tabEstTrouves[i] = false;
        }
        nbEssais = 0;
        aAvoirEncore = 8;
    }

    /**
     * foncction qui permet d'avoir l'indice de l'image choisi.
     * @param : ligne de l'image.
     * @param : colonne de l'image.
     * @return : l'indice de l'image choisi.
     */
    public int getIndice(int lig, int col){
        return tabIndImgs[lig*4+col];
    }

    /**
     * Fonction qui indique si deux cartes possède la même image.
     * @param : coordonnée de l'image1.
     * @param : coordonnée de l'image2.
     * @return : vrai si les deux cartes sont identiques, faux sinon.
     */
    public boolean identiques(Point carte1, Point carte2){
        int c1 = tabIndImgs[carte1.x*4+carte1.y];
        int c2 = tabIndImgs[carte2.x*4+carte2.y];
        nbEssais ++;
        if (c1 != c2)
            return false;
        tabEstTrouves[carte1.x*4+carte1.y] = true;
        tabEstTrouves[carte2.x*4+carte2.y] = true;
        aAvoirEncore--;
        return true;
    }

    /**
     * fonction qui indique si les partie est gagné ou non.
     * @return : vrai si partie gagné, non sino.
     */
    public boolean gagne(){
        return aAvoirEncore == 0;
    }

        /**
     * Fonction qui affiche la grille pour le terminal
     */
    public void afficheGrille()
    {
      for (int i = 0; i < lesCartes.length; i++) {
        for (int j = 0; j < lesCartes[i].length; j++) {
          if (j == 0)
            System.out.print("ligne "+i+" : ");
          System.out.print(lesCartes[i][j].getIndice() + " - ");
        }
        System.out.println();
      }
    }

    /**
     * fonction qui indique si une carte n'a pas encore été trouver.
     * @param : ligne de la carte.
     * @param : colonne de la carte.
     * @return : vrai si la carte n'a pas encore été trouver, sinon non.
     */
    public boolean pasTrouvee(int lig, int col){
        return (tabEstTrouves[lig*4+col] == false);
    }

    public static void main(String[] args){
        new ModeleMemory();
    }


}


/*class Quitter implements ActionListener{
    public void actionPerformed(ActionEvent e){
        System.exit(0);
    }
}*/

/*class Recommencer implements ActionListener{
    ModeleMemory save;
    public Recommencer(ModeleMemory save){
        this.save = save;
    }

    public void actionPerformed(ActionEvent e){
        save.dessineMoiCarte();
    }
}*/
