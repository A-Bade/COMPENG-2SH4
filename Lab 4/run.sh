#!/bin/bash

out=`(./Lab4)`
echo $out
if [[ $out == *"failure"* ]]; then
  exit 1;
fi
