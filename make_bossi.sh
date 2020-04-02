module load boost
g++ -I$mkBoostInc -c autocorr_bossi.cpp
g++ -L$mkBoostLib -lboost_iostreams -lboost_system -lboost_filesystem  autocorr_bossi.o -o autocorr_bossi

./autocorr_bossi
