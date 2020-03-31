package calculette;
import java.math.BigDecimal;

/**
 * Extension de la classe Operateur
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public class OperateurDiv extends Operateur {
	private int priorite = 2; 
	private char valeur = '/';
	
	/**
	 * Fonction qui retourne la priorité de l'opérateur.
	 * @return : la priorité.
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
	 * @param lesOperandes: pile des Operandes.
	 */
	public void evaluer(Pile<BigDecimal> lesOperandes) throws ArithException {
		
		BigDecimal tmp = lesOperandes.depiler(); 
		if (tmp.doubleValue() == 0) {
			throw new ArithException("Division par ");
		}else{
			lesOperandes.empiler(lesOperandes.depiler().divide(tmp,10,BigDecimal.ROUND_HALF_UP));
		}
	}
}
