cd front/bitbusy
npm run build
cd ..
cd ..
rm -rf data/dist
mkdir -p data/dist
cp -a front/bitbusy/dist data/