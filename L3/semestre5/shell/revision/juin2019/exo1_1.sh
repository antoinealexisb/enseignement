#!/bin/bash
test "$#" -ne 1 && echo "Merci de mettre un argument , un lien symbolique" && exit 1

oldIFS=$IFS
IFS=""

exo1_1()
{
  if ! [ -L "$1" ]
  then
    echo "Merci de mettre un lien symbolique"
    return 1
  else
    cd "$1" 2>/dev/null
    test "$?" -ne 0 && return 1
    pwd -P
  fi
  IFS=$oldIFS
}

exo1_1 $@
