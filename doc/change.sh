#!/bin/sh
# changes the names from lrl to kdl for
#   - namespaces
#   - includes
#
for i in pv*.cpp pv*.h; do 
	echo "changing file " $i; 
	sed -e 's/PV/Jacobian/g' < $i > $i.tmp 
	mv $i $i.orig
	mv $i.tmp $i
done


