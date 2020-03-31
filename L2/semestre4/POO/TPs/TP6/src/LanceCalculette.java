import calculette.*;
import vue.*;

/**
* Classe qui lance une application en permettant de relier MaCalculette à la partie graphique.
*
* @author BOURDON Antoine-Alexis
* @version 1.0
*/
public class LanceCalculette {
	/**
	 * Methode pour lancer l'application.
	 * Cette méthode contient juste une instruction.
	 * @param args : parametre de la fonction principale.
	 */
	public static void main(String[] args){
		new Vue(new MaCalculette());
		

		}
	}

