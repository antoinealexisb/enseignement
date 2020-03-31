/**
* Ma premiere classe en Java
*
* @author Antoine-Alexis BOURDON
* @version 3.0
*/

import javax.swing.*;
import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;


/**
 * Classe servant à demarer le jeu et servant à la gestion des evenements. 
 * Il s'agit du controller.
 */
public class Demarreur extends JFrame implements ActionListener{
    private static final int CLIGNO = 7;
    private int cligno;

    //colonnes et lignes pour le GridLayout
    private int nbLig;
    private int nbCol;

    //tableau pour les cartes
    private Vue lesCartes[][];

    //pour sauvegarder ModeleMemory pour ensuite utilisé ses données
    private ModeleMemory test;
    private Vue carte1;
    private Vue carte2;

    //les composants timer
    private Timer temps;
    

    //vue des boutons des cartes
    private JPanel milieuVue;
    private boolean identiques;

    //nombre d'images gagnees  et nombre d'essais
    private JLabel jlabNbEssaie;
    private JLabel jlabNbImgs;


    public Demarreur(ModeleMemory test) { 
        
        //creation du fenetre
        super("My Memories");
        //this.setBounds(50,50,400,50);
        //this.setSize(500,500);
	    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	this.setVisible(true);
        Dimension dimEcran = this.getToolkit().getScreenSize();
        this.setLocation((dimEcran.width-this.getSize().width)/4,(dimEcran.height-this.getSize().height)/4);
        temps = new Timer(200, new ActionListener(){public void actionPerformed(ActionEvent evt){actionTimer();}});

        this.test = test;

        nbCol = test.getNBCOL();
        nbLig = test.getNBLIG();

        //emplacement pour mettre les cartes
        lesCartes = new Vue[nbLig][nbCol];

        //creation du milleu pour les cartes
        Container cont = this.getContentPane();
        milieuVue = new JPanel();
        milieuVue.setLayout(new GridLayout(nbLig, nbCol,15,15));

        jlabNbEssaie = new JLabel();
        jlabNbImgs = new JLabel();

        dessineMoiCarte();

        JPanel indicationEnBas = new JPanel(new GridLayout(1, 2));
        indicationEnBas.add(jlabNbEssaie);
        indicationEnBas.add(jlabNbImgs);

        cont.add(milieuVue);
        cont.add(indicationEnBas, "South");

        barreMenus();
        cont.add(barreEnHaut(),"North");

        //afficheGrille();
        this.pack();
    }

    /**
     * Fonction qui affiche graphiquement la barre d'outils (Quitter, Recommencer).
     * @return : Une instance de JToolBar.
     */
    public JToolBar barreEnHaut(){
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
                    dessineMoiCarte();
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
    public void barreMenus(){
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
                    dessineMoiCarte();
                }});
                //new Recommencer(this));

        menu1.add(menu1Item1);
        menu1.addSeparator();
        menu1.add(menu1Item2);
        menus.add(menu1);

        menu2Item1.addActionListener(
            new ActionListener(){
                public void actionPerformed(ActionEvent ea){
                    JOptionPane.showMessageDialog(null, "Memory V3.0 \nAjout d'un controler.\nAuteur: Antoine-Alexis BOURDON\nannée:2018-2019\nDiscipline:Programmation Orientée objet - L2", "Information", JOptionPane.INFORMATION_MESSAGE);
                }});//new aPropos());
        menu2.add(menu2Item1);
        menus.add(menu2);

        setJMenuBar(menus);

    }

    /**
     * Fonction qui reintialise le jeu et affiche les cartes.
     */
    private void dessineMoiCarte(){
        temps.stop();
        cligno = 0;
        carte1 = null;

        test.leTableauZero();
        milieuVue.removeAll();
        for (int i=0; i<nbLig; i++){
            for (int j=0; j<nbCol; j++){
                lesCartes[i][j] = new Vue(test.getIndice(i, j),i ,j);
                lesCartes[i][j].addActionListener(this);
                milieuVue.add(lesCartes[i][j]);
            }

        }
        jlabNbImgs.setText("Nombre d'images gagnees : 0");
        jlabNbEssaie.setText("Nombre d'essais : 0");
        validate();

    }

    /**
     * Fonction qui affiche graphiquement le nombre de pair d'images gagnées.
     */
    private void afficheCmbImgs(){
        int i = test.getNBPAIRES()-test.getAAvoirEncore();
        jlabNbImgs.setText("Vous avez gagné " + i  + " image" + (i > 1 ? "s" : "") + "!");
    }

    /**
     * Fonction qui affiche graphiquement le nombre d'essais effectué.
     */
    private void afficheCmbEssais(){
        int i = test.getNbEssais();
        jlabNbEssaie.setText("Vous avez fait " + i + " essai" + (i> 1? "s" : "") + "!");
    }

    /**
     * Fonction qui affiche la grille pour le terminal.
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
     * Fonction qui permet d'afficher les cartes un certain nombre de temps et fait clignoté les cartes identiques.
     */
    public void actionTimer()
    {
        cligno ++;
        if (cligno<CLIGNO){
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
            afficheCmbImgs();
            afficheCmbEssais();
            temps.stop();
        
            for (int i = 0; i < lesCartes.length; i++){
                for (int j = 0; j < lesCartes[i].length; j++){
                    if (test.pasTrouvee(i, j))
                        lesCartes[i][j].onClick();
                }
            }

            if (test.gagne()){
                JOptionPane.showMessageDialog(null, "Tu as gagné !!!!!!!!!!!!", "/!\\/!\\ TU AS RÉUSSI /!\\/!\\", JOptionPane.ERROR_MESSAGE);
                dessineMoiCarte();
            }
        }

    }


    /**
     * Fonction qui ecoute les évènements d'action.
     */
    public void actionPerformed(ActionEvent e) {
        Vue carteTmp;
        carteTmp = (Vue)e.getSource();//utilisé getsource() -> Methods inherited from class java.util.EventObject //pas de clone() AA !!!!!!!! cast !!!!!
        if (carte1 == null){
            carte1 = carteTmp;
            carteTmp.affichetoi();
        }
        else{
            carte2 = carteTmp;
            identiques = test.identiques(carte1.getCoords(), carteTmp.getCoords());

            for (int i = 0; i < lesCartes.length; i++) {
                for (int j = 0; j < lesCartes[i].length; j++) {
                    lesCartes[i][j].offClick(test.pasTrouvee(i, j));
                }
            }

            carte1.affichetoi();
            carteTmp.affichetoi();
            temps.start();
        }
    }

    public static void main(String[] args){
        new Demarreur(new ModeleMemory());

    }
}  
