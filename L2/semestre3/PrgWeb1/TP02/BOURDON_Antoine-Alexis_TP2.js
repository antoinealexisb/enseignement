//Exercice 1

function estPalindrome(mot) {
  //inversion du mot
  var truc = "";
  for (var i = 0; i < mot.length; i++) {
    truc += mot[(mot.length - 1) - i];
  }
  //comparaison du mot
  //alert(truc);
  if (mot == truc) {
    return True;
  } else {
    return False;
  }
}


function estPalindrome2(phrase) {
    "use strict";
    var tmp = "", i = 0, test = "az";
    for (i = 0; i <= (phrase.length - 1); i += 1) {
        if ((phrase.toLowerCase().charCodeAt(i) <= test.charCodeAt(1)) && (phrase.toLowerCase().charCodeAt(i) >= test.charCodeAt(0))) {
            tmp += phrase[i].toLowerCase();
        }
    }
    return estPalindrome(tmp);
}



//Exercice2

function compteMots(s) {
  truc = s.split(' ');
  return truc.length;
}


function compteMots2(s) {
  s = s.replace(/[\s]{2,}/g, " ").replace(/^[\s]/, "").replace(/[\s]$/, ""); // Enlève les espaces doubles, triples, etc.; les espaces au debut , à la fin.
  return compteMots(s);
}  


function compteMots3(s, sep)
{
for (var i=0; i<sep.length; i++)
{
	if (sep[i] != " "){
		s = s.replace(sep[i],"");
}
}
	return compteMots2(s)
}
