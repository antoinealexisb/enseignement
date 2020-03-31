//exo1
function randomint1(max) {
  "use strict"
  return Math.floor(Math.random() * Math.floor(max));
}
//exo2
function randomint2(min, max) {
  "use strict"
  return randomint1(max - min) + min;
}

//exo3
function randomIntArray(min, max, elmt) {
  "use stict"
  tab = [];
  for (var i = 0; i < elmt; i++) {
    tab[i] = randomint2(min, max);
  }
  return tab;
}

//exo4

function moyenne(tab) {
  "use srtict"
  moy = 0;
  for (var i = 0; i < tab.length; i++) {
    moy += tab[i];
  }
  return moy /= tab.length;
}

//exo5
function occurences(tab, min, max) {
  "use strict"
  dico = {};
  for (i = min; i < max; i++) {
    dico[i] = 0;
  }
  for (i = 0; i < tab.length; i++) {
    if (min <= tab[i] < max) {
      dico[tab[i]]++;
    }
  }
  return dico;
}

//exo6
function stats(tab, min, max) {
  "use strict"
  sortie = occurences(tab, min, max);
  for (var i = min; i < max; i++) {
    // sortie[i]*=100/tab.length; pourcentage
    sortie[i] /= tab.length;
  }
  return sortie;
}

//EXOOOOOOOO excusotron

function excusotron(textArray) {
  "use strict"
  retour = "";
  for (var i = 0; i < textArray.length; i++) {
    retour += textArray[i][Math.floor(Math.random() * Math.floor(textArray[i].length))] + " ";
  }
  return retour;
}
