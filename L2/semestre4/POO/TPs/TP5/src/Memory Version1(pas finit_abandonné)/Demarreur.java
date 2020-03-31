import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;

//import test


/**
 * Classe ne devant servir qu'à demarer le jeu et sert à la gestion des evenements
 *  * Note : - deplacé vue vers Demarreur -> creer des objets de carte dans un tableau
 *          - sert aussi à la gestion entre ModeleMemory (qui sera les données) et Vue pour l'affichage graphique (demarreur = au controleur)
 */
public class Demarreur extends JFrame implements ActionListener{
    //le tableau d'image 

    //colonnes et lignes pour le GridLayout
    private int nbLig = 4; //mettre une methode get sur le ModeleMemory
    private int nbCol = 4;

    //tableau pour les cartes
    private Vue lesCartes[][];

    //pour sauvegarder ModeleMemory pour ensuite utilisé ses données
    private ModeleMemory test;
    private Vue carte1;



    public Demarreur(ModeleMemory test) { 
        
        //creation du fenetre
        super("My Memories");
        //this.setBounds(50,50,400,50);
        //this.setSize(500,500);
	    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	this.setVisible(true);
        Dimension dimEcran = this.getToolkit().getScreenSize();
        this.setLocation((dimEcran.width-this.getSize().width)/2,(dimEcran.height-this.getSize().height)/2);

        this.test = test;

        //emplacement pour mettre les cartes
        lesCartes = new Vue[nbLig][nbCol];

        //creation du milleu pour les cartes
        Container cont = this.getContentPane();
        JPanel milieuVue = new JPanel();
        milieuVue.setLayout(new GridLayout(nbLig, nbCol,15,15));
        dessineMoiCarte(milieuVue);
        cont.add(milieuVue);
        afficheGrille();
        this.pack();
    }

    private void dessineMoiCarte(JPanel milieuVueJPanel){
        test.leTableauZero();
        milieuVueJPanel.removeAll();
        for (int i=0; i<nbLig; i++){
            for (int j=0; j<nbCol; j++){
                lesCartes[i][j] = new Vue(test.getIndice(i, j),i ,j);
                lesCartes[i][j].addActionListener(this);
                milieuVueJPanel.add(lesCartes[i][j]);
            }

        }

    }

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

    public void actionPerformed(ActionEvent e) {
        Vue carteTmp;
        carteTmp = (Vue)e.getSource();//utilisé getsource() -> Methods inherited from class java.util.EventObject //pas de clone() AA !!!!!!!! cast !!!!!
        carteTmp.affichetoi();
        if (carte1 == null){
            carte1 = carteTmp;
            //carteTmp.affichetoi();
        }
        else{
            //carteTmp.affichetoi();
            //fonction identiques à faire dans modele (bool)
            boolean identiques = test.identiques(carte1.getCoords(), carteTmp.getCoords());
            //System.out.println(identiques);
            if (identiques){
                carte1.rien();
                carteTmp.rien();
            }
            else {
                carte1.cacheCache();
                carteTmp.cacheCache();
            }
            carte1 = null;

        }
    }

    public static void main(String[] args){
        new Demarreur(new ModeleMemory());
    }
}  