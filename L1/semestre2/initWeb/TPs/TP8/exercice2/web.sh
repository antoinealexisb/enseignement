read -p 'Titre: ' titre
read -p 'Description: ' descript
read -p 'Mots clé: ' cles
echo "<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.01 Transitional//EN'>\n <html>\n        <head>\n                <title> "$titre" </title>\n                <meta http-equiv='Content-Type' content='text/html; charset=utf-8' >\n                <meta name='author' content='BOURDON Antoine-Alexis' >\n                <meta name='description' content='"$descript"' >\n                <meta name='keywords' content='"$cles"' >\n                <meta name='viewport' content='width=device-width, initial-scale=1.0' >\n        </head>\n<body>\n\n\n</body>\n\n</html>\n "> index.html

