# - created 07/11/2022 -
# - Goose -

echo -e "-\e[34m Started Compiling \e[0m- \n"
for f in src/*.cc
do echo -e -n "\e[34mcompiling: \e[0m $f" 

#compile each cc file to .o
g++ -c -o $f.o $f `pkg-config gtkmm-4.0 --cflags --libs `

echo -e " [\e[32mComplete\e[0m]"
done
echo ""

echo -e -n "\e[34mcompiling: \e[0m Final Build"

#compile all .o files to final build
g++ src/*.o -o build `pkg-config gtkmm-4.0 --cflags --libs `

echo -e " [\e[32mComplete\e[0m]"
echo ""

echo -e -n "\e[34mCleaning tempFiles\e[0m"
rm src/*.o
echo -e  " [\e[32mcomplete\e[0m]"
echo ""

echo -e "- \e[32mLog Start\e[0m -----------------------"

./build.exe

echo -e "- \e[31mLog END\e[0m -----------------------"