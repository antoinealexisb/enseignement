import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GererClickButton implements ActionListener{
    private static JButton leBtn;
    private static int compteur = 0;
    private static ImageIcon []TABIMAGES;

    public GererClickButton(JButton leBtn, ImageIcon[] TABIMAGES){
        this.leBtn = leBtn;
        this.TABIMAGES = TABIMAGES;
    }

    public void actionPerformed(ActionEvent e){
        compteur++;
        compteur%=7;
        leBtn.setIcon(TABIMAGES[compteur]);
    }
}