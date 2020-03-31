package vue;

import calculette.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/**
 * Classe qui s'occupe de l'interface graphique de la calculatrice.
* @author BOURDON Antoine-Alexis
* @version 1.0
*/
public class Vue {
    ICalculette c;
    //
    private String[] elmntChiffreL1 = {"1", "2", "3"};
    private String[] elmntChiffreL2 = {"4", "5", "6"};
    private String[] elmntChiffreL3 = {"7", "8", "9"};
    

    /**
     * Constructeur d'une Vue.
     * @param iCalculette : parametre qui contient une instance de MaCalculette().
     */
    public Vue(ICalculette iCalculette) {
        this.c = iCalculette;
        JFrame fenetre = new JFrame("Ma Calculatrice");
	    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);
        
        JPanel zone_resultat = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JTextArea affichage = new JTextArea(1,25);
        affichage.setText("0");
        affichage.setEditable(false);
        zone_resultat.add(affichage);

        Container cont = fenetre.getContentPane();
    
        fenetre.setLayout(new GridLayout(2, 1));
        TextField textField = new TextField();//this.c.valeur());
        textField.setEditable(false);
        cont.add(affichage);

	    //BOUTONS
        //REPRESENTATION 
    

				/* {"Raz", "%", "/", "*",
                    "1", "2", "3","+",
                    "4", "5", "6", "-",
                    "7", "8", "9","=",
                    ".", "0", "(", ")",
                    "Corr", "Sqrt", "Ln", "+/-",
                    "Quit", "M+", "MR", "MZ"};*/

        JPanel zone_btns = new JPanel(new GridLayout(7,4));
 
        //LIGNE : 0
        JButton bouton = new JButton("Raz");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerRaz();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("%");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerMod();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);
        
        bouton = new JButton("/");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerDiv();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);
                        
        bouton = new JButton("*");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerMult();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        //LIGNE : 1
        for (String elt : elmntChiffreL1){
            bouton = new JButton(elt);
            bouton.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    c.enfoncerChiffre(Integer.valueOf(elt));
                    affichage.setText(c.valeur());
                    affichage.repaint();
                    }
                });
            zone_btns.add(bouton);
        }

        bouton = new JButton("+");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerPlus();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        //LIGNE : 2

        for (String elt : elmntChiffreL2){
            bouton = new JButton(elt);
            bouton.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    c.enfoncerChiffre(Integer.valueOf(elt));
                    affichage.setText(c.valeur());
                    affichage.repaint();
                    }
                });
            zone_btns.add(bouton);
        }

        bouton = new JButton("-");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerMoins();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        //LIGNE : 3

        for (String elt : elmntChiffreL3){
            bouton = new JButton(elt);
            bouton.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    c.enfoncerChiffre(Integer.valueOf(elt));
                    affichage.setText(c.valeur());
                    affichage.repaint();
                    }
                });
            zone_btns.add(bouton);
        }

        bouton = new JButton("=");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerEgal();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        //LIGNE : 4

        bouton = new JButton(".");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerPoint();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("0");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerChiffre(0);
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("(");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerPO();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton(")");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerPF();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        //LIGNE : 5

        bouton = new JButton("Corr");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerCorr();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("Sqrt");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerSqrt();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("Ln");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerLn();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("+/-");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerPlusMoins();
                affichage.setText(c.valeur());
                affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        //LIGNE : 6

        bouton = new JButton("Quit");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("M+");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerMPlus();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("MR");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
               c.enfoncerMRecup();
               affichage.setText(c.valeur());
               affichage.repaint();
                }
            });
        zone_btns.add(bouton);

        bouton = new JButton("MZ");
        bouton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                c.enfoncerMZero();
                }
            });
        zone_btns.add(bouton);





        cont.add(zone_btns);
        fenetre.pack();
    }
}
