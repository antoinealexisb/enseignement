package calculette;
import java.math.BigDecimal;

/**
 * Extension de la classe Operateur.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public class OperateurParO extends Operateur {
	private int priorite = 0;
	private char valeur = '(';

	/**
	 * Fonction qui retourne la priorité de l'opérateur.
	 * @return : la propriété.
	 */
	public int getPriorite() {
		return priorite;
	}

	/**
	* Fonction qui retourne la valeur de l'opérateur.
	* @return : valeur de l'opérateur.
	*/
	public char getValeur() {
		return valeur;
	}

	/**
	* Fonction qui calcul une opération
	* @param lesOperandes : pile des Operandes.
	*/
	public void evaluer(Pile<BigDecimal> d) {	
	}

}
