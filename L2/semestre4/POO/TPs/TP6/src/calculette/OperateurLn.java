package calculette;
import java.math.BigDecimal;

/**
 * Extension de la classe Operateur.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public class OperateurLn extends Operateur {
	private int priorite = 3; 
	private char valeur = '\u33D1';
	
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
	public void evaluer(Pile<BigDecimal> d)throws ArithException {
		BigDecimal tmp = d.depiler();
		if (tmp.doubleValue() <= 0) {
			throw new ArithException("Logarithme <= 0 : " + tmp.doubleValue());
		}else{
			d.empiler(new BigDecimal(Math.log(tmp.doubleValue())).setScale(10,BigDecimal.ROUND_HALF_DOWN));
		}
	}

}
