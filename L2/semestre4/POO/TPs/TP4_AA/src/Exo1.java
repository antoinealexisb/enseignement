import javax.swing.*;


import java.awt.*;

public class Exo1{
    public static void main(String[] args){
        JFrame fenetre = new JFrame();
        fenetre.setTitle("Une fenetre");
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);

        fenetre.setBounds(50,100,500,300);
        Dimension DimEcran = new Dimension();
        DimEcran = fenetre.getToolkit().getScreenSize();
        System.out.println(DimEcran.getWidth());

        JLabel label = new JLabel("Taille de l'ecran : "+DimEcran);
        fenetre.getContentPane().add(label);

        fenetre.setLocation((int)DimEcran.getWidth()/2,(int)DimEcran.getHeight()/2);

        fenetre.pack();
    } 


}