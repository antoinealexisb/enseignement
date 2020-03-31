import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;
import java.util.Random;

public class MaPremiereAppliGraphique{
    public static void main(String[] args){
        JFrame fenetre = new JFrame();
        fenetre.setTitle("Les images");
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);

        ImageIcon []TABIMAGES = new ImageIcon[7];
		URL url0 = MaPremiereAppliGraphique.class.getResource("images/Bird.gif");
		TABIMAGES[0] = new ImageIcon(url0);
		URL url1 = MaPremiereAppliGraphique.class.getResource("images/Bird2.gif");
		TABIMAGES[1] = new ImageIcon(url1);
		URL url2 = MaPremiereAppliGraphique.class.getResource("images/Cat.gif");
		TABIMAGES[2] = new ImageIcon(url2);
		URL url3 = MaPremiereAppliGraphique.class.getResource("images/Cat2.gif");
		TABIMAGES[3] = new ImageIcon(url3);
		URL url4 = MaPremiereAppliGraphique.class.getResource("images/Dog.gif");
		TABIMAGES[4] = new ImageIcon(url4);
		URL url5 = MaPremiereAppliGraphique.class.getResource("images/Dog2.gif");
		TABIMAGES[5] = new ImageIcon(url5);
		URL url6 = MaPremiereAppliGraphique.class.getResource("images/Rabbit.gif");
        TABIMAGES[6] = new ImageIcon(url6);
        
        JButton leBtn = new JButton(TABIMAGES[0]);
        leBtn.addActionListener(new GererClickButton(leBtn, TABIMAGES) );
        
        fenetre.getContentPane().add(leBtn);
        fenetre.pack();


    }

}