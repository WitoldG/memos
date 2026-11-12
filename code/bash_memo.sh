# GREP
grep string filename
grep -r string directory # recursively
-i # ignore case
grep -e "chaine 1" -e "chaine 2" filename # Differentes string

# FIND
find . -name "file_name" # automatically recursive

# FOR
for i in $(seq -w 1 1000); do
  docker exec -it database psql -U astar -d astar -h localhost -c "INSERT INTO preparationine(wmsid, preparationrequestfk, articlefk, requestedquantity) VALUES ('PR$i', 1, 1, 1)"
done