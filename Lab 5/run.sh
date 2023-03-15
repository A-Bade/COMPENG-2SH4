out=`(./Lab5)`
echo $out
if [[ $out == *"failure"* ]]; then
  exit 1;
fi
