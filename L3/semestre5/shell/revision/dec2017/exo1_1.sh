#!/bin/bash
#grep -o "Noir" fichier.txt
test "$#" -gt 2 && echo "Prend juste 2 arguments" && return 1
! test -f "$1" && echo "Le paramètre 1 doit être un fichier existant" && return 1 
test `expr "$2" : ".*"` -eq 0 && echo "le mot est d'au moins 1 caractère :D" && return 1 

oldIFS=$IFS
IFS="

"

exo1_1()
{
compte=0
compteurligne=1
concat=""
cat "$1" | (while read fic
do
  tmp=`echo "$fic" |sed -E "s/$2/\n/g" |wc -l`
  compte=`expr $compte + $tmp`
  compte=`expr $compte - 1`
  if [ $tmp -gt 1 ]
  then
    concat=`echo "${concat},$compteurligne"`
  fi
  compteurligne=`expr $compteurligne + 1`
done
concat=`echo $concat |sed -E "s/^,//g" |sed -E "s/,\$//g"`
echo "${compte}:$concat"
IFS=$oldIFS
test $compte -eq 0 && return 2 )
test $? -eq 2 && return 2
return 0
}

exo1_1 $@
