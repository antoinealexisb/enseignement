import guilines.*;
import java.awt.*;
import java.util.Random;
import java.util.List;
import java.util.Vector;

/**
 * Classe qui modélise note jeu
 */
class MonJeu implements InterfaceDesBalles{

	public static final int VIDE = -1;
	// Attribut
	private int nbLigne = 10;
	private int nbColonne = 20;
	private int nbBallesAjoutees = 20;
	private int score = 0;
	private int nbCouleur = 8;
	private int[][] grille;
	private int[] couleur = new int[nbBallesAjoutees];
	private Point[] mesPoints = new Point[nbBallesAjoutees + 2];
	private Point[] mesPointTrouver = new Point[nbLigne];
	private int nbBallesSupp = 5;

	// constructeur

    /**
     * Constructeur de note Jeu.
     */
	public MonJeu() {
		grille = new int[nbLigne][nbColonne];
		this.reinit();
	}

	/**
     * Accesseur pour le nombre de lignes.
     * @return : retourne le nombre de ligne.
     */
	public int getNbLignes() {
		return nbLigne;
	}

    /**
     * Accesseur pour le nombre de Colonnes.
     * @return : retourne le nombre de colonnes.
     */
	public int getNbColonnes() {
		return nbColonne;
	}

    /**
     * Accesseur pour le nombre de balles ajoutées.
     * @return : retourne le nombre de balles ajoutées.
     */
	public int getNbBallesAjoutees() {
		return nbBallesAjoutees;
	}

    /**
     * Accesseur pour le score.
     * @return : retourne le score.
     */
	public int getScore() {
		return score;
	}

    /**
     * Accesseur pour le nombre de couleurs.
     * @return : retourne le nombre de couleurs.
     */
	public int getNbCouleurs() {
		return nbCouleur;
	}

    /**
     * Accesseur pour la couleur d'une case.
     * @param ligne : coordonnée x (ligne).
     * @param colonne : coordonnée y (colonne).
     * @return : retourne la couleur de la case
     */
	public int getCouleur(int ligne, int colonne) {
		return grille[ligne][colonne];
    }
    
    /**
     * Accesseur sur les prochaines couleurs.
     * @return : Le tableau retourne a pour taille le nombre de balles ajoutees apres chaque action du joueur. Si l'utilisateur a le droit de rejouer directement, le tableau retourne est identique au tableau precedemment retourne.
     */
    public int[] getNouvellesCouleurs() {
		return (couleur);
    }
    
    /**
     * Teste la fin de partie (plus aucune case n'est libre) 
     * @return : boolean.
     */
	public boolean partieFinie() {
		int cmpt = 0;
		for (int i = 0; i < nbLigne; i++)
			for (int j = 0; j < nbColonne; j++)
				if (grille[i][j] == VIDE)
					cmpt++;
					//return false;
		return cmpt > nbBallesAjoutees ? false : true;
		//return true;
    }
    
	public boolean deplace(int ligneD, int colonneD, int ligneA, int colonneA) {
		// Si la case n'est pas vide
		if ((grille[ligneD][colonneD] != VIDE) && (grille[ligneA][colonneA] == VIDE)) {
			// Change les boules
			grille[ligneA][colonneA] = grille[ligneD][colonneD];
			grille[ligneD][colonneD] = VIDE;
			// ajoute les point a rafraichir de changement de boule
			mesPoints[3] = new Point(ligneD, colonneD);
			mesPoints[4] = new Point(ligneA, colonneA);
			// regarde Si il y a une ligne ou collone de boule
			regardeVertical();
			// ajoute mes nouvellebille;
			if (mesPointTrouver[0] == null) {
				//System.out.println(this.partieFinie());
				ajoutNouvelleBille();
			}else{
				score = score + 10; 
			}
			// trouve les couleur de mes prochaine bille;
			trouveNouvelleCouleur();
			return true;
		}
		return false;
    }
    
 	public Point[] regardeVertical() {
		// pour chaque boule
		for (int i = 0; i < nbLigne; i++) {
			for (int j = 0; j < nbColonne; j++) {
				// si elle est pas vide
				if (grille[i][j] != VIDE) {
					// initialisation : il y a deja une boule et donc un point
					// aussi
					int intVertical = 1;
					int intHorizontal = 1;
					mesPointTrouver[0] = new Point(i, j);
					int nb = 1;
					// tant que je peut continuer
					while (true) {
						// si je reste dans la grille et que ma boule et de la
						// meme couleur que la boule a coté vers le bas
						if ((i + nb < nbLigne) && (grille[i][j] == grille[i + nb][j])) {
							// j'increment mon vertical
							intVertical = intVertical + 1;
							// j'ajoute pas la boule a mon tableau
							mesPointTrouver[nb] = new Point(i + nb, j);
						} else {
							break;
						}
						// j'incremente mon nb pour regarder la boule d'apres
						nb++;
					}
					nb = 1;
					while (true) {
						// si je reste dans la grille et ma boule est de la
						// meme couleur que la boule a coté vers le bas
						if ((j + nb < nbColonne)
								&& (grille[i][j] == grille[i][j + nb])) {
							// j'increment mon vertical
							intHorizontal = intHorizontal + 1;
							// j'ajoute pas la boule a mon tableau
							mesPointTrouver[nb] = new Point(i, j + nb);
						} else {
							break;
						}
						// j'incremente mon nb pour regarder la boule d'apres
						nb++;
					}
					// Si j'ai bien une ligne vertical
					if ((intVertical >= nbBallesSupp) || (intHorizontal >= nbBallesSupp)) {
						// j'efface ces point dans ma grille
						for (int y = 0; y < mesPointTrouver.length; y++) {
							if (mesPointTrouver[y] != null) {
								grille[mesPointTrouver[y].x][mesPointTrouver[y].y] = VIDE;
							}
						}
						// je retourne mes point et arréte la fonction
						return mesPointTrouver;
					} else {
						// sinon je reinitialise mes point a null
						for (int u = 0; u < mesPointTrouver.length; u++) {
							mesPointTrouver[u] = null;
						}
					}
				}
			}
		}
        return (mesPointTrouver);
    }

	public List<Point> getNouveaux() {
		//System.out.println("whouaaaaaaa");
		//Point[] toutMesPoint = new Point[mesPoint.length + mesPointTrouver.length];
		/**Vector <Point> tab toutMesPoint = new Vector <Point>
		for (int i = 0; i < mesPoint.length; i++) {
			toutMesPoint[i] = mesPoint[i];
		}
		int i = mesPoint.length;
		for (int j = 0; j < mesPointTrouver.length; j++) {
			toutMesPoint[i] = mesPointTrouver[j];
			i++;
		}
		for (int j = 0; j < toutMesPoint.length; j++) {
			if (toutMesPoint[j] == null) {
				toutMesPoint[j] = new Point();
			}
        }
		return toutMesPoint;*/
		Vector <Point> v = new Vector <Point>();
		for (int lig=0; lig < nbLigne; lig++)
			for (int col=0; col < nbColonne; col++)
				v.add(new Point(lig,col));
		return v;
    }
    
    
	public void reinit() {
		for (int i = 0; i < nbLigne; i++) {
			for (int j = 0; j < nbColonne; j++) {
				grille[i][j] = VIDE;
			}
		}
		score = 0;
		trouveNouvelleCouleur();
		ajoutNouvelleBille();
		trouveNouvelleCouleur();
    }
    
	public void trouveNouvelleCouleur() {
		Random r = new Random();
		for (int i = 0; i < nbBallesAjoutees; i++) {
			couleur[i] = 1;
			//couleur[i] = r.nextInt(nbCouleur);
		}
	}

	public void ajoutNouvelleBille() {
		Random r = new Random();
		for (int i = 0; i < nbBallesAjoutees; i++) {
			boolean val = false;
			while (val == false) {
				int bouleLigne = r.nextInt(nbLigne);
				int bouleColonne = r.nextInt(nbColonne);
				if (grille[bouleLigne][bouleColonne] == VIDE) {
					mesPoints[i] = new Point(bouleLigne, bouleColonne);
					grille[bouleLigne][bouleColonne] = couleur[i];
					val = true;
				}
			}
		}
	}

	public void afficheTableauPoint(Point[] tab) {
		for (int i = 0; i < tab.length; i++) {
			System.out.println(tab[i] + " \n");
		}

    }
}
