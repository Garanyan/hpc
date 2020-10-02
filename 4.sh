#!/bin/bash

FILE=Linux
if [ -f "$FILE" ]; then
    echo "course"
else
	echo "very easy" > Linux
fi