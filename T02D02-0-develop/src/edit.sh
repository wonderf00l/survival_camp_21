#!/bin/bash -- bash interpteter

if [[ -z "$1" || -z "$2" || -z "$3" ]] ; then
    echo "Invalid args!"
    exit 0
fi

if [ ! -f $1 ] ; then
    echo "File not found!"
    exit 0
fi

while read line; do

    for word in $line; do # $ with mentioned variables
        
        if [ "$word" = "$2" ]; then #need brackets in condition!
            #word=$3 # no space!
            size=$(wc -c $1 | awk '{ print $1 }') #NO WHITESPACES!
            #echo $size
            
            sed -i -e "s/$word/$3/g" $1 # without brackets  #> edited.txt
            #if string insted of word -- just add \ before the whitespace
            
        fi
        
    done

done < $1

if [ ! -f files.log ] ; then
    echo "$1 - $size - $(date +%F) - $(date | awk {'print $4'}) - $(shasum $1 | awk {'print $1'}) - shasum $1" > files.log
else
    echo "$1 - $size - $(date +%F) - $(date | awk {'print $4'}) - $(shasum $1 | awk {'print $1'}) - shasum $1" >> files.log
fi


