#!/bin/bash

PERCENTAGE_SEPARATORS=''
for ((i = 0 ; i < 80 ; i++)) ; do 
    PERCENTAGE_SEPARATORS+='%'
done

clear
echo "Input the folder name: "
read folder_name
clear
echo "Latex main file name: "
read latex_main_name
latex_main_name+='.tex'
clear

# Set the color variable
green_color='\033[0;32m'
# Clear the color after that
clear_color='\033[0m'

# create the folder and files.
echo -e "${green_color}"
echo -e "CREATING: \"./$folder_name\""
mkdir $folder_name
echo -e "CREATING: \"./$folder_name/classes\""
mkdir $folder_name/classes
echo -e "CREATING: \"./$folder_name/code\""
mkdir $folder_name/code
echo -e "CREATING: \"./$folder_name/figs\""
mkdir $folder_name/figs
echo -e "CREATING: \"./$folder_name/$latex_main_name\""
touch $folder_name/$latex_main_name
echo -e "${clear_color}"


LATEX_DT='\documentclass[openany]{book}\n\n'
LATEX_LIBS='\\usepackage[utf8]{inputenc}\n'
LATEX_LIBS+='\\usepackage{generalsnips}\n'
LATEX_LIBS+='\\usepackage{calculussnips}\n'
LATEX_LIBS+='\\usepackage{programmingsnips}\n'
LATEX_LIBS+='\\usepackage[margin=1in]{geometry}\n'
LATEX_LIBS+='\\usepackage{pdfpages}\n'
LATEX_LIBS+='\\usepackage{amsmath}\n'
LATEX_LIBS+='\\usepackage{amsthm}\n'
LATEX_LIBS+='\\usepackage{titlesec}\n'
LATEX_LIBS+='\\usepackage{xpatch}\n'
LATEX_LIBS+='\\usepackage{fancyhdr}\n'
LATEX_LIBS+='\\usepackage{tikz}\n'
LATEX_LIBS+='\\usepackage{hyperref}\n'
LATEX_LIBS+='\\usepackage{minted}\n'
LATEX_LIBS+='\\usepackage{multicol}\n'
LATEX_LIBS+='\\usepackage{float}\n'
LATEX_LIBS+='\\usepackage{verbatim}\n'
LATEX_LIBS+='\\usepackage{graphicx}\n'

echo "Enter latex document title: "
read LATEX_TITLE
clear

CURRENT_DATE=$(date +'%d %B %+4Y %I:%M %p')
AUTHOR='David Corzo'
BEFORE_DOC='\\title{'$LATEX_TITLE'}\n\\date{'$CURRENT_DATE'}\n\\author{'$AUTHOR'}'
BEFORE_DOC+='\\fvset{frame=single,numbers=left,numbersep=3pt,breakanywhere=true,breaklines=true}\n\n'
BEFORE_DOC+='\\newcommand{\\figs}{./figs}\n'
BEFORE_DOC+='\\newcommand{\\code}{./Code}\n'
BEFORE_DOC+='\\newcommand{\\width}{0.4}\n'
BEFORE_DOC+='\\darktheme\n'
BEFORE_DOC+='\\pagestyle{empty}\n'
BEFORE_DOC+='\\UseRawInputEncoding\n\n\n'
BEFORE_DOC+='\\begin{document}\n'
BEFORE_DOC+='\\maketitle\n'
BEFORE_DOC+='\\tableofcontents\n'
BEFORE_DOC+=$PERCENTAGE_SEPARATORS
BEFORE_DOC+='\n\n\n'

AFTER_DOC=$PERCENTAGE_SEPARATORS
AFTER_DOC+='\\end{document}'

DOCUMENT=${LATEX_DT}${LATEX_LIBS}${BEFORE_DOC}${AFTER_DOC}

echo -e $DOCUMENT > $folder_name/$latex_main_name

echo -e "${green_color}TERMINATED SUCCESSFULLY.${clear_color}"
