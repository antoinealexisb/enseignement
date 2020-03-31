package calculette;

/**
 * Classe d'erreur.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public class ArithException extends Exception {
	
	/**
	 * Renvoie le message d'erreur.
	 * @param msg : Message d'erreur.
	 */
	public ArithException(String msg) {
		super(msg);
	}
}
