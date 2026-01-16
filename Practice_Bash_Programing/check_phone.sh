#!/bin/bash

#Set phone number pattern xxx-xxx-xxx or (xxx) xxx-xxx
phone_pattern='^(\([0-9]{3}\) [0-9]{3}-[0-9]{4}|[0-9]{3}-[0-9]{3}-[0-9]{4})$'

while IFS= read -r line
do
    if[[ $line =~ $phone_pattern ]];
        echo "Valid Phone Number: $line"
done < file.txt
