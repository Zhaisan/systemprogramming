clear 
echo --------------------------------------------- 
echo '\tMenu Implementation' 
echo --------------------------------------------- 
echo 1.ls
echo 2.grep
echo 3.cat
echo Enter your choice 
read choice 
case $choice in 
        1)ls -1;;
        2)grep 'girls' test.txt;; 
        3)cat test.txt;; 
        *)echo This is not a choice 
esac 