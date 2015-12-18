$ codeset=UTF-8
$set 255
1 UTF-8
$ $tcsh: set1,v 1.5 2011/02/04 18:19:35 christos Exp $
$ Messages d 'erreur
$set 1 
1 Erreur de syntaxe
2 %s n'est pas autorisé
3 Mot trop long
4 $< ligne trop longue
5 Pas de fichier pour $0
6 Modificateur [] incomplet
7 $ l'expansion doit se terminer avant ]
8 Mauvais : modificateur dans $ (%c)
9 Erreur d'indice
10 Numéro mal formé
11 Plus de mots
12 Nom de fichier manquant
13 Erreur globale interne
14 Commande introuvable
15 Trop peu d'arguments
16 Trop d'arguments
17 Trop dangereux d'attribuer un alias à cela
18 `If' vide
19 `Then' incorrect
20 Les mots ne sont pas placés entre parenthèses
21 %s introuvable
22 Masque incorrect
23 Pas de limite de ce type
24 Argument trop long
25 Facteur d'échelle incorrect ou inconnu
26 Variable pas définie
27 La pile de répertoires n'a pas cette taille
28 Mauvais numéro de signal
29 Signal inconnu; "kill -l" permet de lister les signaux
30 Le nom de la variable doit commencer par une lettre
31 Le nom de la variable est trop long
32 Le nom de la variable ne doit contenir que des caractères alphanumériques
33 Pas de gestion des travaux dans ce shell
34 Syntaxe de l'expression
35 Pas de répertoire personnel
36 Impossible de passer dans le répertoire personnel
37 Commande nulle incorrecte
38 Il manque l'affectation dans l'expression
39 Opérateur inconnu
40 ambigu
41 %s: Le fichier existe
42 L'argument pour -c se termine avec un anti-slash
43 Interrompu
44 Indice hors limites
45 Dépassement de capacité de ligne
46 Pas de travail de ce type
47 Impossible à partir d'un terminal
48 Vous n'êtes pas dans une boucle while ou foreach
49 Plus de processus
50 Pas de correspondance
51 %c manquant
52 %c sans correspondance
53 Mémoire insuffisante
54 Impossible de créer un tube
55 %s: %s
56 %s
57 Syntaxe: jobs [ -l ]
58 Les arguments doivent être des ID de processus ou des numéros de travaux
59 Pas de travail en cours
60 Pas de travail précédent
61 Pas de travail de cette forme
62 Emboîtement des `Fork' > %d; peut-être une boucle `...`
63 Pas de gestion des travaux dans les sous-shells
64 Faute `Sync': Processus %d pas trouvé
65 %s Il y a des travaux interrompus
66 %s Il y a des travaux arrêtés
67 Pas d'autre répertoire
68 La pile de répertoires est vide
69 Répertoire incorrect
70 Syntaxe: %s [-%s]%s
71 Pas d'opérande pour l'indicateur -h
72 Ce n'est pas un shell de connexion
73 Division par zéro
74 Modulo par zéro
75 Mise à l'échelle incorrecte ; cela signifie-t-il ``%s'' ?
76 Impossible d'interrompre un shell de connexion
77 Utilisateur inconnu : %s
78 Pas de variable `$home' définie
79 Syntaxe: history [-%s] [# nombre d'évènements]
80 $, ! ou < pas autorisés avec $# or $?
81 Retour-chariot dans un nom de variable
82 * pas autorisé avec $# or $?
83 $?<digit> ou $#<digit> pas autorisé
84 Nom de variable incorrect
85 Retour-chariot dans l'index de variable
86 Dépassement de capacité de la mémoire tampon d'expansion
87 Syntaxe de variable
88 Forme ! incorrecte
89 Pas de remplacement précédent
90 Remplacement incorrect
91 Pas de partie gauche précédente
92 Partie droite trop longue
93 Modificateur ! incorrect: %c
94 Echec du modificateur
95 Dépassement de capacité de la mémoire tampon de substitution
96 Sélecteur d'argument ! incorrect
97 Pas de recherche précédente
98 %s: événement introuvable
99 Trop de caractères )
100 Trop de caractères (
101 Caractère ( mal placé
102 Il manque un nom pour rediriger
103 Redirection de sortie ambigue
104 Pas de << entre les caractères ( et )
105 Redirection d'entrée ambigue
106 Caractères () mal placés
107 Boucle dans les alias
108 Pas de variable `$watch' définie
109 Pas d'évènement prévu
110 Syntaxe: sched -<#numéro>.\nSyntaxe: sched [+]hh:mm <commande>
111 Pas tant d'évènements prévus
112 Pas de commande à lancer
113 Temps incorrect pour l'évènement
114 Temps relatif incompatible avec am/pm
115 Pas assez de place pour la chaine termcap
116 Syntaxe: settc %s [yes|no]
117 Capacité `%s' inconnue
118 Paramètre termcap inconnu `%%%c'
119 Trop d'arguments pour `%s' (%d)
120 `%s' nécessite %d arguments
121 Syntaxe: echotc [-v|-s] [<capacité> [<args>]]
122 %s: %s. Mauvaise Architecture
123 !# Boucle dans l'historique
124 Mauvaise recherche de fichier
125 Dépassement de capacité de sélecteur
126 Option inconnue: `-%s'\nSyntaxe: %s [ -bcdefilmnqstvVxX -Dnom[=valeur] ] [ argument ... ]
127 Option inconnue: `-%s'\nSyntaxe: %s [ -bcdefFilmnqstvVxX ] [ argument ... ]
128 Option inconnue: `-%s'\nSyntaxe: %s [ -bcdefilmnqstvVxX ] [ argument ... ]
129 \nComplément incorrect: "%s"
130 \n%s incorrect: '%c'
131 \nIl manque le séparateur '%c' après %s "%s"
132 \n%s incomplet: "%s" 
133 Pas d'opérande pour l'indicateur -m
134 Syntaxe: unlimit [-fh] [limites]
135 $%S est en lecture seule
136 Pas de travail de ce type
137 Unknown colorls variable `%c%c'
$ $tcsh: set10,v 1.3 2011/02/04 18:19:35 christos Exp $
$ ma.setp.c
$set 10 
1 setpath: commande incorrecte '%s'.\n
2 setpath: pas assez d'arguments pour la commande '%s'.\n
3 setpath: donnée manquante dans le chemin '%s'\n
4 setpath: %s pas trouvé dans %s\n
5 setpath: %d pas une position correcte dans %s\n
$ $tcsh: set11,v 1.4 2011/02/04 18:19:35 christos Exp $
$ sh.c
$set 11 
1 Attention: pas d'accès au tty (%s).\n
2 Ainsi pas de contrôle de job dans ce shell.\n
3 Vous avez %d messages courrier (mail).\n
4 Vous avez %d messages courrier (mail) dans %s.\n
5 Vous avez du %scourrier.\n
6 nouveau 
7 Vous avez du %scourrier dans %s.\n
$ $tcsh: set12,v 1.4 2011/02/04 18:19:35 christos Exp $
$ sh.dir.c
$set 12 
1 %s: Essaie de démarrer à partir de "%s"\n
$ $tcsh: set13,v 1.3 2011/02/04 18:19:35 christos Exp $
$ sh.exec.c
$set 13 
1 hash=%-4d dir=%-2d prog=%s\n
2 %d groupes de hashage de %d bits chacun\n
3 masque de déboguage = 0x%08x\n
4 %d réussis, %d manqués, %d%%\n
5 %S: commande intégrée au shell.\n
6 %S: Commande pas trouvée.\n
7 où: / dans la commande n'a pas de sens\n
8 %S est un alias avec 
9 %S est intégré(e) au shell\n
10 hashage manqués: 
$ $tcsh: set14,v 1.2 2006/03/02 18:46:46 christos Exp $
$ sh.file.c
$set 14 
1 \nTrop de %s !!\n
2 noms dans le fichier des mots de passe
3 fichiers
$ $tcsh: set15,v 1.3 2011/02/04 18:19:35 christos Exp $
$ sh.func.c
$set 15 
1 %s: %s: ne peut %s la limite%s\n
2 enlever
3 positionner
4  matérielle
$ $tcsh: set16,v 1.4 2011/02/04 18:19:35 christos Exp $
$ sh.lex.c
$set 16 
1 Réinitialise le groupe de processus des terminaux de %d à %d\n
2 \nUtilisez "logout" pour vous déconnecter.\n
3 \nUtilisez "exit" pour quitter %s.\n
4 seek to eval %x %x\n
5 seek to alias %x %x\n
6 seek to file %x\n
7 Mauvais type pour seek %d\n
8 tell eval %x %x\n
9 tell alias %x %x\n
10 tell file %x\n
$ $tcsh: set17,v 1.5 2011/02/04 18:19:35 christos Exp $
$ sh.proc.c
$set 17 
1 BUG: attente de travail en tâche de fond !\n
2 Sortie %d\n
3 BUG: processus vidé deux fois
4 Tourne 
5 Signal 
6 Sortie %-25d
7 Fait
8 BUG: état=%-9o
9 \040(core dumped)
10 \040(wd:
11 wd maintenant: 
12 %S: Déjà suspendu\n
13 %S: Déjà arrêté\n
14 %S: Badly formed number\n
$ $tcsh: set18,v 1.3 2011/02/04 18:19:35 christos Exp $
$ sh.set.c
$set 18 
1 Attention: le PATH exagérément long est tronqué\n
$ $tcsh: set19,v 1.6 2011/02/25 23:58:07 christos Exp $
$ tc.alloc.c
$set 19 
1 nbytes=%d: Plus de mémoire\n
2 free(%lx) appelé avant allocation.
3 free(%lx) au delà de la limite memoire.
4 free(%lx) en deçà de la limite memoire.
5 free(%lx) mauvais bloc.
6 free(%lx) limites incorrectes.
7 free(%lx) index de bloc incorrect.
8 %s allocation mémoire actuelle:\nfree:\t
9 utilisé
10 \n\tTotal utilisé: %d, total libre: %d\n
11 \tMémoire allouée de 0x%lx à 0x%lx.  Limite réelle supérieure à 0x%lx\n
12 Mémoire allouée de 0x%lx à 0x%lx (%ld).\n
13 %s current memory allocation:\n
14 Total space allocated from system: %d\n
15 Number of non-inuse chunks: %d\n
16 Number of mmapped regions: %d\n
17 Total space in mmapped regions: %d\n
18 Total allocated space: %d\n
19 Total non-inuse space: %d\n
20 Top-most, releasable space: %d\n
$ $tcsh: set2,v 1.4 2011/02/04 18:19:35 christos Exp $
$ Messages Signaux
$set 2
1 Signal nul
2 Interrompu
3 Arrêté
4 Sortie
5 Instruction interdite
6 Piège Trace/BPT
7 Abandon
8 Piège IOT
9 Plantage système imminent
10 Sortie erreur
11 Piège EMT
12 Exception de calcul en virgule flottante
13 Supprimé
14 Signal utilisateur 1
15 Signal utilisateur 2
16 Incident de segmentation
17 Erreur de bus
18 Program range error
19 Operand range error
20 Appel système incorrect
21 Tube détruit
22 Alarme
23 Terminé
24 L'état du fils a changé
25 Mort du fils
26 Faute spécifique Apollo
27 Fils arrêté ou sorti
28 Fils sorti
29 Coupure d'alimentation
30 Ressource perdue
31 Break (Ctrl-Break)
32 Signal d'E-S possible
33 Entrée-Sortie asynchrone (select)
34 Condition urgente sur canal d'E-S
35 Reprise multi-tâche
36 Terminaison multi-tâche
37 Achèvement d'E-S asynchrone Fortran
38 Reprise
39 Erreur mémoire irrécupérable
40 Limite temps CPU dépassée
41 Arrêt du système imminent
42 Groupe micro-tasking-pas d'option de réveil définie
43 Erreur de thread - (utilisez cord -T pour plus d'infos)
44 Erreur de parité de registre du CRAY Y-MP
45 Demande d'information
46 Interrompu (Signal)
47 Stoppé (Signal)
48 Interrompu
49 Stoppé
50 Continue
51 Entrée tty suspendue
52 Entrée tty arrêtée
53 Sortie tty suspendue
54 Sortie tty arrêtée
55 Etat de la fenêtre modifié
56 Taille de la fenêtre modifiée
57 Etat du téléphone modifié
58 Limite temps CPU dépassée
59 Taille limite de fichier dépassée
60 Signal de l'horloge virtuelle
61 Signal de profil
62 Signal DIL
63 Un évènement à scruter est arrivé
64 Process's lwps are blocked
65 Signal Special LWP
66 Signal Special CPR
67 Signal Special CPR
68 Premier signal temps réel
69 Deuxième signal temps réel
70 Troisième signal temps réel
71 Quatrième signal temps réel
72 Quatrième signal temps réel avant la fin
73 Antépénultième signal temps réel
74 Avant-dernier signal temps réel
75 Dernier signal temps réel
76 E-S asynchrone LAN
77 Lecture/Ecriture PTY disponible
78 Intervention E-S nécessaire
79 Mode moniteur HFT accordé
80 Le mode moniteur HFT doit être abandonné
81 Le contrôle du son HFT est terminé
82 Données en buffer circulaire HFT
83 Processus de transfert
84 Touche d'attention sécurisée
85 Re-séquencement
86 Signal SS$_DEBUG
87 Priorité modifiée
88 detecté
89 Nouveau caractère d'entrée
90 Stack limit exceeded
91 Unused signal
$ $tcsh: set20,v 1.3 2011/02/04 18:19:35 christos Exp $
$ tc.bind.c
$set 20 
1 Nom de touche incorrect `%S'\n
2 Mauvais nom de touche: %S\n
3 Mauvais nom de commande: %S\n
4 Mauvaise touche spécifiée %S\n
5 Chaine nulle spécifiée\n
6 Définition de touches standard\n
7 Définition de touches alternatives\n
8 Définition Multi-caractères\n
9 Définition des touches de direction\n
10 %-15s->  n'est pas défini\n
11 BUG!!! %s n'est lié à rien.\n
12 Usage: bindkey [options] [--] [TOUCHE [COMMANDE]]\n
13     -a   liste ou définit la TOUCHE dans la table des touches alternatives\n
14     -b   interprète TOUCHE comme un nom de touche C-, M-, F- or X-\n
15     -s   interprète COMMANDE comme une chaine littérale devant être sortie\n
16     -c   interprète COMMANDE comme une commande intégrée ou externe\n
17     -v   redéfinit toutes les touches pour vi\n
18     -e   redéfinit toutes les touches pour emacs\n
19     -d   redéfinit toutes les touches pour de l'éditeur par defaut\n
20     -l   liste les commandes de l'éditeur avec descriptions\n
21     -r   enlève la correspondance pour la TOUCHE\n
22     -k   interprète TOUCHE comme un nom de touche de direction symbolique\n
23     --   force un arrêt dans le traitement de l'option\n
24     -u   (ou toute option incorrecte) ce message\n
25 Sans TOUCHE ni COMMANDE, imprime toutes les associations\n
26 Sans COMMANDE, imprime l'association pour TOUCHE.\n
27 mauvaise spécification de touche -- chaine nulle\n
28 mauvaise spécification de touche -- chaine vide\n
29 mauvaise spécification de touche de fonction.  Touche nulle pas autorisé\n
30 mauvaise spécification de touche -- nombre hexa mal formé\n
31 mauvaise spécification de touche -- nombre octal mal formé\n
32 mauvaise spécification de touche -- nombre décimal mal formé\n
33 Mauvaise spécification de touche de fonction.\n
34 Touche nulle pas autorisé\n
35 Mauvaise spécification de touche -- nom inconnu "%S"\n
36 Syntaxe: bind [TOUCHE | COMMANDE TOUCHE | "emacs" | "vi" | "-a"]\n
37 Fonction incorrecte
38  %s\t\tn'est pas défini\n
$ $tcsh: set21,v 1.3 2011/02/04 18:19:35 christos Exp $
$ tc.disc.c
$set 21 
1 ne peut obtenir les caractères locaux.\n
2 ne peut définir les catactères locaux.\n
$ $tcsh: set22,v 1.3 2011/02/04 18:19:35 christos Exp $
$ tc.func.c
$set 22 
1 %S: \t a comme alias 
2 \nMot de passe incorrect pour %s\n
3 Erreur alias 'precmd' enlevé.\n
4 Erreur alias 'cwdcmd' enlevé.\n
5 Erreur alias 'beepcmd' enlevé.\n
6 Erreur alias 'periodic' enlevé.\n
7 étude de la ligne de commande\n
8 Voulez vous vraiment supprimer tous les fichiers? [n/y] 
9 passe la suppression des fichiers!\n
10 la ligne de commande est maintenant :\n
11 étude de la ligne de commande\n
12 dans une des listes\n
13 la ligne de commande est maintenant :\n
14 OoyY
$ $tcsh: set23,v 1.4 2011/02/04 18:19:35 christos Exp $
$ tc.os.c
$set 23 
1 Mauvais nom de cpu/site
2 Chemin du site trop mong
3 inconnu
4 site: %s\n
5 %d: Site pas trouvé\n
6 setlocal: %s: %s\n
7 Site pas trouvé
8 Vous êtes piégé dans un univers que vous n'avez jamais créé
9 Getwarp a échoué
10 warp invalide
11 Setwarp a échoué
12 Univers incorrect
13 Erreur inconnue : %d
14 sysname:  %s\n
15 nodename: %s\n
16 release:  %s\n
17 version:  %s\n
18 machine:  %s\n
19 getwd: Ne peut ouvrir ".." (%s)
20 getwd: Ne peut effectuer chdir vers ".." (%s)
21 getwd: Erreur en lecture dans ".." (%s)
22 getwd: Ne peut revenir à "." (%s)
23 getwd: Ne peut effectuer stat "/" (%s)
24 getwd: Ne peut effectuer stat "." (%s)
25 getwd: Ne peut effectuer stat sur répertoire "%s" (%s)
26 getwd: Ne peut ouvrir le répertoire "%s" (%s)
27 getwd: Ne peut trouver "." dans ".." (%s)
28 Type de système incorrect
29 Le type de système n'est pas défini
30 XXX: Too many arguments 
31 XXX: Invalid argument
$ $tcsh: set24,v 1.2 2006/03/02 18:46:46 christos Exp $
$ tc.sched.c
$set 24 
1 kludge
$ $tcsh: set25,v 1.3 2011/02/04 18:19:35 christos Exp $
$ tc.sig.c
$set 25 
1 notre attente %d\n
2 erreur: bsd_signal(%d) signal hors limites\n
3 erreur: bsd_signal(%d) - sigaction a échoué, errno %d\n
$ $tcsh: set26,v 1.3 2011/02/04 18:19:35 christos Exp $
$ tc.who.c
$set 26 
1 ne peut effectuer stat %s.  S.V.P effectuez "unset watch".\n
2 %s ne peut être ouvert.  S.V.P effectuez "unset watch".\n
3 BUG! le dernier élément n'est pas whotail!\n
4 arrière: 
5 BUG! le premier élément n'est pas whohead!\n
6 nouveau: %s/%s\n
7 %n a %a %l from %m.
8 %n a %a %l.
9 connecté
10 déconnecté
11 remplacé %s
12 local
$ $tcsh: set27,v 1.3 2011/02/04 18:19:35 christos Exp $
$ tw.comp.c
$set 27 
1 commande
2 séparateur
3 motif
4 intervalle
5 complément
$ $tcsh: set29,v 1.2 2006/03/02 18:46:46 christos Exp $
$ tw.help.c
$set 29 
1 Pas de fichier d'aide pour %S\n
$ $tcsh: set3,v 1.4 2011/02/04 18:19:35 christos Exp $
$ Description des fonctions éditeur
$set 3 
1 Recule d'un caractère
2 Efface le caractère derrière le curseur
3 Coupe depuis le début du mot jusqu'au curseur - sauvegardé dans le tampon de copie
4 Coupe depuis le début de la ligne jusqu'au curseur - sauvegardé dans le tampon de copie
5 Va au début du mot courant
6 Va au début de la ligne
7 Met en majuscules les caractères depuis le curseur jusqu'à la fin du mot
8 Vi change la casse du caractère sous le curseur et avance d'un caractère
9 Vi change jusqu'à la fin de la ligne
10 Efface l'écran en laissant la ligne courant au dessus
11 Complète le mot courant
12 Tab avance parmi les fichiers
13 Tab recule parmi les fichiers
14 Complète le mot courant en ignorant les compléments programmables
15 Copie le mot courant jusqu'au curseur
16 Copie la zone entre la marque et le curseur dans le tampon de copie
17 Développe vers le mot précédent pour lequel c'est un préfixe
18 Efface le caractère sous le curseur
19 Efface le caractère sous le curseur, ou signale la fin de fichier si ligne vide
20 Efface le caractère sous le curseur, ou liste les compléments si fin de ligne
21 Efface le caractère sous le curseur, liste les compléments ou signale la fin de fichier
22 Coupe depuis le curseur jusqu'à la fin du mot courant - sauvegardé dans le tampon de copie
23 Ajoute aux arguments si démarré ou entre le chiffre
24 Chiffre au début de l'argument
25 Va à la prochaine ligne de l'historique
26 Met en minuscules les caractères depuis le curseur jusqu'à la fin du mot
27 Indique la fin de fichier
28 Déplace le curseur à la fin de la ligne
29 Echange le curseur et la marque
30 Développe les jokers du nom de fichier
31 Développe les échappements de l'historique
32 Développe les échappements de l'historique en une ligne
33 Développe les variables
34 Avance d'un caractère
35 Avance à la fin du mot courant
36 Echange les deux caractères avant le curseur
37 Cherche en arrière dans l'historique une ligne commençant comme la ligne courante
38 Cherche en avant dans l'historique une ligne commençant comme la ligne courante
39 Insère le dernier elément de la commande précédente
40 Recherche en avant incrémentale
41 Recherche en arrière incrémentale
42 Efface la ligne
43 Coupe jusqu'à la fin de la ligne et sauvegarde dans le tampon de copie
44 Coupe la zone entre la marque et le curseur et sauvegarde dans le tampon de copie
45 Coupe toute la ligne et sauvegarde dans le tampon de copie
46 Liste les choix pour le complément
47 Liste les choix pour le complément sur-définissant le complément programmable
48 Liste les correspondances pour le nom de fichier avec joker
49 Liste les choix pour le complément ou indique la fin de fichier si ligne vide
50 Affiche la charge moyenne et l'état courant des processus
51 Développe les échappements de l'historique et insère une espace
52 Exécute la commande
53 Développe les nom de répertoires, éliminant les `.' et `..' en tête
54 Développe les commandes pour le chemin ou l'alias résultant
55 Passe du mode insertion au mode recouvrement et vice-versa
56 Ajoute le 8ième bit au prochain caractère saisi
57 Ajoute le prochain caractère saisi à la ligne 
58 Réaffiche tout
59 Redémarre l'éditeur
60 Cherche de l'aide pour la commande courante
61 Ce caractère est ajouté à la ligne
62 Ca caractère est le premier dans une séquence de caractères
63 Définit la marque à la position du curseur
64 Corrige la syntaxe du mot courant
65 Corrige la syntaxe de la ligne complète
66 Envoie le caractère au tty en mode 
67 Bascule la ligne courante de l'historique entre le mode littéral et lexical
68 Echange le caractère à la gauche du curseur avec celui en dessous du curseur
69 Echange les deux caractères avant le curseur
70 Caractère tty de suspension différé
71 Caractère tty de vidage de sortie
72 Caractère tty d'interruption
73 Caractère tty de sortie
74 Caractère tty de suspension
75 Caractère tty de validation de sortie
76 Caractère tty d'invalidation de sortie
77 Indique un caractère pas attaché
78 Argument universel Emacs (argument x 4)
79 Va à la ligne précédente de l'historique
80 Met en majuscule les caractères depuis le curseur jusqu'à la fin du mot courant
81 Vi va au début du prochain mot
82 Vi passe en mode insertion après le curseur
83 Vi passe en mode insertion à la fin de la ligne
84 Vi change la casse du caractère sous le curseur et avance d'un caractère
85 Vi change la commande `prefix'
86 Vi change jusqu'à la fin de la ligne
87 Passe au mode de commande Vi (redéfinition des touches alternatives)
88 Le mode commande de Vi complète le mot courant
89 Vi va au caractère précédent (retour-arrière)
90 Vi efface la commande `prefix'
91 Vi va à la fin du mot courant délimité par des espaces
92 Vi va à la fin du mot courant
93 Vi va vers le caractère spécifié avant
94 Vi va vers le caractère spécifié après
95 Vi remonte vers le caractère spécifié avant
96 Vi remonte vers le caractère spécifié après
97 Passe en mode insertion Vi
98 Passe en mode insertion Vi au début de la ligne
99 Vi répète la recherche du caractère en cours dans la même direction
100 Vi répète la recherche du caractère en cours dans la direction opposée
101 Vi répète la recherche en cours dans la même direction
102 Vi répète la recherche en cours dans la direction opposée
103 Vi remplace le caractère sous le curseur avec le prochain caractère saisi
104 Mode de remplacement Vi
105 Vi cherche dans l'historique en arrière
106 Vi cherche dans l'historique en avant
107 Vi remplace le caractère sous le curseur et passe en mode insertion
108 Vi remplace la ligne entière
109 Vi va au mot précédent
110 Vi va au prochain mot
111 Vi défait la dernière modification
112 Vi va au début de la ligne
113 Exécute quelle commande en cours
114 Colle le tampon de copie à la position du curseur
115 Replace just-yanked text with yank from earlier kill
116 (WIN32 only) Copy cut buffer to system clipboard
117 (WIN32 only) Paste clipboard buffer at cursor position
118 (WIN32 only) Convert each '/' in next word to '\\\\'
119 (WIN32 only) Convert each '/' in previous word to '\\\\'
120 (WIN32 only) Page visible console window up
121 (WIN32 only) Page visible console window down
$ $tcsh: set30,v 1.4 2011/02/04 18:19:35 christos Exp $
$ tw.parse.c
$set 30 
1 démarre une commande %d\n
2 complete %d 
3 complete %d %S\n
4 %s: Erreur interne de correspondance.\n
5 éléments
6 colonnes
7 Il y a %d %s, les lister quand même ? [n/y] 
8 looking = %d\n
9 \nerreur interne %s: Je ne sais pas ce que je recherche !\n
10 pas un répertoire
11 pas trouvé
12 pas lisible
13 oOyY
$ $tcsh: set31,v 1.3 2011/02/04 18:19:35 christos Exp $
$ vms.termcap.c
$set 31 
1 Ne peut ouvrir TERMCAP: [%s]\n
2 Ne peut ouvrir %s.\n
3 Trouvé %s dans %s.\n
4 Pas de correspondance trouvée pour %s dans le fichier %s\n
$ $tcsh: set4,v 1.3 2011/02/04 18:19:35 christos Exp $
$ Termcap strings
$set 4
1 ajoute une nouvelle ligne vide
2 bip audible
3 efface jusqu'en bas
4 efface jusqu'à la fin de la ligne
5 curseur vers un position horizontale
6 efface l'écran
7 efface un caractère
8 efface une ligne
9 commence le mode d'effacement
10 termine le mode d'effacement
11 termine le mode d'insertion
12 curseur de la ligne d'état
13 curseur origine
14 insère caractère
15 commence le mode insertion
16 insère du remplissage
17 curseur vers le bas
18 curseur vers la gauche
19 curseur vers la droite
20 curseur vers le haut
21 commence le gras
22 fin attributs
23 espaces non-destructives
24 fin mise en évidence
25 commence mise en évidence
26 curseur à la ligne d'état
27 curseur d'une vers le haut
28 commence souligné
29 fin souligné
30 bip `visible'
31 efface plusiseurs caractères
32 curseur vers le bas (plusieurs)
33 insert plusieurs caractères
34 curseur vers la gauche (plusieurs)
35 curseur vers la droite (plusieurs)
36 curseur vers le haut (plusieurs)
37 A les marge automatiques
38 Peut utiliser les tabulations physiques
39 Nombre de lignes
40 Nombre de colonnes
41 A les touches `alternatives'
42 retoure-chariot ignoré à la droite de la marge
$ $tcsh: set5,v 1.2 2006/03/02 18:46:46 christos Exp $
$ ed.chared.c
$set 5
1 Charge moyenne indisponible\n
$ $tcsh: set6,v 1.3 2011/02/04 18:19:35 christos Exp $
$ ed.inputl.c
$set 6
1 ERREUR: commande interdite de la touche 0%o\r\n
2 oui\n
3 edit\n
4 arrête\n
5 non\n
6 Pas de commande correspondante\n
7 Commande ambigue\n
8 *** ERREUR fatale de l'éditeur ***\r\n\n
$ $tcsh: set7,v 1.4 2011/02/04 18:19:36 christos Exp $
$ ed.screen.c
$set 7
1 \n\tTcsh a déterminé que votre terminal a les\n
2 \tcaractéristiques suivantes :\n\n
3 \tIl a %d colonnes et %d lignes\n
4 \tIl %s touche `alternative'\n
5 a une
6 n'a pas de
7 \tIl %speut utiliser les tabulations\n
8 ne 
9 \tIl %s les marges automatiques\n
10 a
11 n'a pas
12 \tIl %s les marges magiques\n
13 (vide)
14 oui
15 non
16 ERREUR: ne peut pas effacer\r\n
17 DeleteChars: num est ridicule: %d\r\n
18 ERREUR: ne peut insérer\r\n
19 StartInsert: num est ridicule: %d\r\n
20 %s: Ne peut ouvrir /etc/termcap.\n
21 %s: Pas d'entrée pour le type de terminal "%s"\n
22 %s: utilise la configuration d'un terminal banal.\n
23 %s: ATTENTION: Votre terminal ne peut effectuer de déplacement vers le haut.\n
24 L'édition peut être incorrecte pour les longues lignes.\n
25 pas de capacité d'effacement jusqu'à fin de ligne.\n
26 pas de capacité d'effacement de caractère.\n
27 pas de capacité d'insertion de caractère.\n
$ $tcsh: set8,v 1.3 2011/02/04 18:19:36 christos Exp $
$ ed.term.c
$set 8
1 Sélecteur inconnu
2 Argument incorrect
$ $tcsh: set9,v 1.3 2011/02/04 18:19:36 christos Exp $
$ ed.xmap.c
$set 9
1 AddXkey: touche d'extension nulle pas autorisé.\n
2 AddXkey: commande séquence d'introduction (sequence-lead-in) pas autorisé\n
3 DeleteXkey: touche d'extension nulle pas autorisé.\n
4 Touche d'extension pas définie "%S"\n
5 Certaines touches d'extension trop longues pour tampon d'impression interne
6 Enumerate: BUG!! Pointeur Null passé!\n
7 pas d'entrée
8 Quelque chose doit suivre: %c\n
9 Une constante Octale ne peut pas tenir dans un caractère.\n
