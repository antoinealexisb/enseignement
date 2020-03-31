import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Exo2{
    public static void main(String[] args){
        JFrame fenetre = new JFrame();
        fenetre.setTitle("Nombre mystérieux ");
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);

        JButton btnFin = new JButton("Fin");
        JButton btnCommencer = new JButton("Commencer");

        JLabel lblResultat = new JLabel("Trouvez un nbre entre 0 et 99");
        JLabel lblNbCoups = new JLabel("0");

        JTextField txtSaisie = new JTextField(5);

        fenetre.getContentPane().add(btnFin);
        fenetre.getContentPane().add(btnCommencer);
        fenetre.getContentPane().add(lblResultat);
        fenetre.getContentPane().add(lblNbCoups);
        fenetre.getContentPane().add(txtSaisie);
    }


}