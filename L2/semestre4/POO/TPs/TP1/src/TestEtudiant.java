/** Classe qui permet de lancer une application qui teste la classe Etudiant.
*/
public class TestEtudiant {
    public static void main(String[] args){
        Etudiant e1 = new Etudiant("Dupont","Jean");
        Etudiant e2 = new Etudiant("Durand","Paul");
        System.out.println(e1);
        System.out.println(e2);
        e1.ajouteNote(15);
        e2.ajouteNote(17);
        e1.ajouteNote(13);
        e2.ajouteNote(8);
        System.out.println(e1);
        System.out.println(e2);
        }
    }