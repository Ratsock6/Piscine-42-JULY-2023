#!/bin/sh

cat /etc/passwd | sed 's/#.*//g' | awk 'NR % 2 == 0' | cut -d: -f-1 | rev | sort -d -r| awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | sed -z 's/\n/, /g; s/, $/./'
