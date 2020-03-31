/*
BOURDON Antoine-Alexis 2018/2019
Controle continu de Programmation Web1
Le mot le plus long
Jeudi 25 octobre 2018 - L2 Informatique
*/

/* "use strict" = ReferenceError: assignment to undeclared variable , donc "use strict" pas dans test mais dans Jslint*/

/*Q1. Quelle est la taille d’un mot ?*/
function taille_mot(mot) {
    total = 0;
    for (var j in mot) {
        total+=1;
    }
    return total;
};
/*taille_mot("BOND"); // 4*/

/*Q2. Quelle est la taille maximale des mots d’une liste ?*/
function taille_max(mots) {
    var taille = 0;
    var i = 0;
    for (i=0 ; i < taille_mot(mots); i+=1) {
        if (taille < taille_mot(mots[i])) {
            taille = taille_mot(mots[i]);
        }
    }
    return taille
};
/*taille_max(["BOND", "BONJOUR", "BONBONS", "BOND"]); // 7*/

/*Q3. Un mot est-il possible ?*/
function possible(mot, tirage) {
    test = {};
    for (var j in tirage) {
        test[tirage[j]] === undefined ? test[tirage[j]] = 1 : test[tirage[j]]+=1;
    }
    //console.log(test);
    for (var j in mot) {
        if (test[mot[j]] === undefined) {
            return false
        } else {
            test[mot[j]]-=1;
            if (test[mot[j]] < 0) {
                return false
            }
        }
    }
    //console.log(test);
    return true
};
/*
possible("BONJOUR", "NOBD");
false
possible("BON", "NOBD");
true
possible("BOND", "NOBD");
true
possible("BONBON", "NOBD");
false*/


/*Q4. Liste de mots possibles*/
function possibles(mots, tirage) {
    sortie = new Array();
    for (mots_index in mots) {
        if (true == possible(mots[mots_index], tirage)) {
            sortie.push(mots[mots_index]);
        }
    }
    return sortie
};
/*possibles(["BONJOUR", "BONBON", "BOND", "BON", "BONS", "BONDS"], "NOBDJ") 
Array [ "BOND", "BON" ]*/


/*Q5. Un des mots les plus longs*/
function mot_plus_long(mots, tirage, i = 0) {
    sortie = possibles(mots, tirage);
    sortie2 = new Array();
    taille = taille_max(sortie);
    for (index in sortie) {
        if (tailleMot(sortie[index]) == taille) {
            sortie2.push(sortie[index]);
        }
    }
    if (i == 0) {
        return sortie2[0];
    }
    return sortie2
};
/*mot_plus_long(["BONBON", "BONJOUR", "BOND", "BONS", "BON"], "BNODS") 
"BOND" */


/*Q6. Uniquement les mots les plus longs*/
function plus_longs(mots, tirage) {
    var i=1;
    return mot_plus_long(mots, tirage, i);
};
/*plus_longs(["BONBON", "BONJOUR", "BOND", "BONS", "BON"], "BNODS");
Array [ "BOND", "BONS" ]*/


/*Q7. Le tirage*/
function faire_tirage(talon, taille) {
    sortie = new Array();
    for (i = 0; i < taille; i+=1) {
        alea = Math.floor(Math.random() * Math.floor(taille_mot(talon)));
        sortie += talon[alea];
    }
    return sortie
};
/*faire_tirage(talon, 10)
"doeteirzwv"
/*


/*Q8. Construire le talon*/
function faire_talon(probas) {
    sortie = new Array();
    for (var [cle, valeur] of Object.entries(probas)) {
        for (i = 0; i < valeur; i+=1) {
            sortie += cle;
        }
    }
    return sortie;
};
/*var probas = {'a': 9, 'b': 2, 'c': 2, 'd': 3, 'e': 15, 'f': 2, 'g': 2, 'h': 2, 'i': 8, 'j': 1, 'k': 1, 'l': 5, 'm': 3, 'n': 6, 'o': 6, 'p': 2, 'q': 1, 'r': 6, 's': 6, 't': 6, 'u': 6, 'v': 2, 'w': 1, 'x': 1, 'y': 1, 'z': 1};
undefined
faire_talon(probas)
"aaaaaaaaabbccdddeeeeeeeeeeeeeeeffgghhiiiiiiiijklllllmmmnnnnnnooooooppqrrrrrrssssssttttttuuuuuuvvwxyz"*/


/*Q9. La totale...*/
function jeu_long_mot(dico, probas, taille) {
    var fin = [];
    var talon = faire_talon(probas);
    var tirage = faire_tirage(talon, taille);
    fin += "Mots possibles : " + plus_longs(dico, tirage) + "; pour le tirage : " + talon;
    return fin;
};

/*jeu_long_mot(dico,probas,50)
"Mots possibles : abasourdissement,agroalimentaires,considerablement; pour le tirage : aaaaaaaaabbccdddeeeeeeeeeeeeeeeffgghhiiiiiiiijklllllmmmnnnnnnooooooppqrrrrrrssssssttttttuuuuuuvvwxyz"*/




/* "use strict" = ReferenceError: assignment to undeclared variable , donc "use strict" pas dans test mais dans Jslint*/
