/** Test de la classe livre
*javac -d bin -cp bin:src src/TestLivre.java
*java -cp bin TestLivre
*/

public class TestLivre{
  public static void main(String[] args){
    Livre l1 = new Livre("ex1","Julien","Larousse",5,"sciences");
    Livre l2 = new Livre("ex2","Remy","bleu",2,"littérature française");
    Livre l3 = new Livre("ex3","Théo","vert",1,"littérature jeunesse");
    Livre l4 = new Livre("ex4","Jèrome","rouge",3,"zoologie");
    Livre l5 = new Livre("ex5","Adrien","orange");
    Livre l6 = new Livre("ex6","Robert","rose");

    System.out.println(l1);
    l1.ajouteExemplaire(3);
    System.out.println(l1);
    l1.ajouteExemplaire();
    System.out.println(l1);
    l1.supprimeExemplaire();
    System.out.println(l1);
    System.out.println(l1.estPresent());
    System.out.println(l1.equals(l2));
    System.out.println(l1.equals(l1));
    System.out.println(l1.nouvelEditeur("Nouvel Editeur"));
  }
}
