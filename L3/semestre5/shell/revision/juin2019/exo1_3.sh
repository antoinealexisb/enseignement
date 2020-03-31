#!/bin/bash

oldIFS=$IFS
IFS=""

exo1_3()
{
  absolu1=`source exo1_2.sh $1`
  test $? -ne 0 && echo "Merci de mettre un chemin valide pour le param 1" && exit 1
  absolu2=`source exo1_2.sh $2`
  test $? -ne 0 && echo "Merci de mettre un chemin valide pour le param 1" && exit 1 
  truc=`echo "$absolu2" |grep -E ^$absolu1`
  if [ "$?" -eq 0 ]
  then
    echo "$1 est inclus dans $2"
    return 0
  fi
  return 1
  IFS=$oldIFS
}

exo1_3 $@
