#!/bin/bash -- bash interpteter

pfile=0
f_counter=1
change_counter=1

filename=""
sha=""


if [ -z "$1" ] ; then
    echo "Invalid args!"
    exit 0
fi

if [ ! -f $1 ] ; then
    echo "File not found!"
    exit 0
fi

if [ -z "$(cat "$1")" ]; then
    echo "File is empty"
    echo '0 0 0'
    exit 0
fi

while read line; do

  if [ "$filename" = "" ]; then

    filename=$(echo $line | awk '{ print $1 }') # NO DOLLAR

  elif [ $(echo $line | awk '{ print $1 }') != "$filename" ]; then

    ((f_counter+=1))
    filename=$(echo '$line' | awk '{ print $1 }')
  fi

  if [ "$sha" = "" ]; then
    sha=$(echo $line | awk '{ print $9 }') # NO DOLLAR
  elif [[ $(echo $line | awk '{ print $9 }') != "$sha"]
        && $(echo $line | awk '{ print $1 }') = $filename ]]; then

    ((change_counter+=1))
    sha=$(echo '$line' | awk '{ print $9 }')
  fi

  ((pfile+=1))

done < $1

echo "$pfile $f_counter $change_counter"