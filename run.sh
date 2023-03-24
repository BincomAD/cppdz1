wget https://data.metabrainz.org/pub/musicbrainz/data/fullexport/20230322-002138/mbdump.tar.bz2
tar xvf mbdump.tar.bz2
mv mbdump/artist ./artist
cmake build .
make
./dz1 ./artist 1970 1970
