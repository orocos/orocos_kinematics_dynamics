#!/bin/bash

echo "This scripts creates the debian/control and debian/*.install files from several template files."

major=$(head -1 changelog | sed "s/.*(\([0-9]\+\.[0-9]\+\).*/\1/g")

echo "Detected KDL Major version: $major"

# Prepare control file:
rm -f control

echo "Creating control ..."
cat control.common | sed -e"s/@LIBVER@/$major/g;s/@BUILD_DEPS@/$bdeps/g" > control

# Prepare *base.install files:
for i in $(ls *base*install); do
    # Copy contents to *.install files:
    fname=$(echo "$i" | sed -e"s/base/$major/g")
    echo "Creating $fname..."
    cat $i > $fname
done

echo "Done!"