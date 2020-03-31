/**
* Ma premiere classe en Java
*
* @author BOURDON Antoine-Alexis
* @version 1.0
*/

public class Premiere{

    private String message;
    /** 
    * On utilise le constucteur par defaut
    */
    
    /**Constructeur de notre première classe
    @param chaine : chaine de caractère qui sera utiliser pour
    l'initialiser l'attribut message
     */
    public Premiere(String chaine){
        message = chaine;

    }


    /**
    * Cette méthode affiche le contenu de l'attribut privé
    * message à l'écran
     */
    public void affiche(){
        System.out.println(message);

    }

    /**
     * Accesseur pour le message de Premiere
     * @return : le message de Premiere
     */
    public String getMessage(){
        return message;
    }

    /**
     * Accesseur pour le message de Premiere
     * @param message : chaine de caractère qui sera utiliser pour l'attribut message.
     */
    public void setMessage(String message){
        this.message = message;
    }

    /**méthode principale de mon programme */
    public static void main(String [] args){
        //Cree un objet de type Premiere();
        Premiere prem = new Premiere("Salut");
        prem.affiche();
        System.out.println(prem.getMessage());
        prem.setMessage("J'aime les chats, j'aime les chats !!!!!!!");
        prem.affiche();

    }

}