EXO1

function abs(n) {
    'use strict';
    if (n < 0) {
        return (n * -1);
    } else {
        return (n);
    }
}

EXO 2

1------
la somme des n premiers termes de la suite harmonique.

function harm(n) {
    var save;
    var somme=0;
    for (var i=1; i<n; i++) {
        save = somme;
        somme += 1/i;
     }
     return somme;
}

2-----
function harmAlt(n) {
    var save;
    var somme=0;
    for (var i=1; i<n; i++) {
        save = somme;
        somme += Math.pow(-1,i)/i;
     }
     return somme;
}

3-----

function nbIterHarmAlt(w) {
        var test = Math.log(2);
        var i =0;
        while (abs(abs(harmAlt(i)) - abs(test)) >= w) {
                i+=1;
        }
        return i;
}
