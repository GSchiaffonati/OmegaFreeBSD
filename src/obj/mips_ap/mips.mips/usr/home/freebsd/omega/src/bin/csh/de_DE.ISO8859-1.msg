$ codeset=UTF-8
$set 255
1 UTF-8
$ $tcsh: set1,v 1.7 2011/02/04 18:19:36 christos Exp $
$ Error messages
$set 1
1 Syntaxfehler
2 %s nicht erlaubt
3 Word zu lang
4 $< Zeile zu lang
5 Keine Datei für $0
6 Unvollständiger [] Modifizierer
7 $ Ausweitung muß vor ] enden
8 Falscher : Modifizierer in $ (%c)
9 Indexfehler
10 Falsche Nummer
11 Keine Worte mehr
12 Dateiname fehlt
13 Interner Fehler (glob)
14 Befehl nicht gefunden
15 Zu wenig Argumente
16 Zu viele Argumente
17 Zu gefährlich für ein Alias
18 Leeres If
19 Unpassendes Then
20 Worte nicht in Klammern
21 %s nicht gefunden
22 Ungeeignete Maske
23 Keine bekannte Begrenzung
24 Argument zu groß
25 Ungeeigneter oder unbekannter Vergrößerungsfaktor
26 Undefinierte Variable
27 Verzeichnisstapel nicht so tief
28 Falscher Signalname
29 Unbekanntes Signal; kill -l listet Signale auf
30 Variablenname muß mit einem Buchstaben beginnen
31 Variablenname zu lang
32 Variablenname muß Buchstaben oder Ziffern enthalten
33 Keine Jobkontrolle in dieser Shell
34 Ausdruck nicht korrekt
35 Kein Startverzeichnis
36 Kann nicht in das Startverzeichnis wechseln
37 Ungültiger leerer Befehl
38 Zuweisung ohne Ausdruck
39 Unbekannter Operator
40 Mehrdeutig
41 %s: Datei existiert
42 Argument für -c endet mit einem Backslash (\\)
43 Abgebrochen
44 Index nicht im gültigen Bereich
45 Zeilenüberlauf
46 Kein solcher Job
47 Kann nicht vom Terminal
48 Nicht in while/foreach
49 Keine Prozesse mehr
50 Kein Treffer
51 Fehlendes %c
52 Überflüssiges %c
53 Kein Speicher mehr
54 Kann keine Pipe erzeugen
55 %s: %s
56 %s
57 Benutzung: jobs [ -l ]
58 Argumente können Job- oder Prozeß-ID's sein
59 Kein aktueller Job
60 Kein vorhergehender Job
61 Kein Job entspricht dem Muster
62 Fork-Ebene > %d; evtl. `...` Schleife?
63 Keine Jobkontrolle in Unter-Shells
64 Sync-Fehler: Prozeß %d nicht gefunden
65 %sEs gibt noch angehaltene Jobs
66 %sEs gibt noch angehaltene Jobs
67 Kein anderes Verzeichnis
68 Verzeichnisstapel leer
69 Ungültiges Verzeichnis
70 Benutzung: %s [-%s]%s
71 Kein Operand für -h
72 Nicht in einer Login-Shell
73 Division durch 0
74 Mod durch 0
75 Bad scaling; did you mean "%s"?
76 Kann Login-Shell (noch) nicht anhalten
77 Unbekannter Benutzer: %s
78 Keine $home-Variable gesetzt
79 Benutzung: history [-%s] [# Anzahl der Befehle]
80 $, ! oder < nicht erlaubt mit $# or $?
81 Zeilenumbruch in Variablenname
82 * nicht erlaubt bei $# or $?
83 $?<digit> or $#<digit> nicht erlaubt
84 Ungültiger Variablenname
85 Zeilenumbruch in Variablenindex
86 Überlauf des Erweiterungspuffers
87 Variablen-Syntax
88 Falsche ! Form
89 Keine vorhergehende Ersetzung
90 Falsche Ersetzung
91 Keine vorhergehende linke Seite
92 Rechte Seite zu lang
93 Falscher ! Modifizierer: %c
94 Modifizierer fehlgeschlagen
95 Überlauf des Ersetzungspuffers
96 Falscher ! Argumentbezeichner
97 Keine vorhergehende Suche
98 %s: Befehl nicht gefunden
99 Zu viele ')'
100 Zu viele '('
101 Falsch plazierte '('
102 Fehlender Name für Umlenkung
103 Mehrdeutige Ausgabeumlenkung
104 Kann keine << innerhalb von ()
105 Mehrdeutige Eingabeumlenkung
106 Falsch plazierte ()
107 Alias-Schleife
108 Keine $watch-Variable gesetzt
109 Keine vorgemerkten Befehle
110 Benutzung: sched -<item#>.\nBenutzung: sched [+]hh:mm <Befehl>
111 Nicht so viele vorgemerkte Befehle
112 Kein auszuführender Befehl
113 Ungültige Zeit für Befehl
114 Relative Zeit inkonsistent mit am/pm
115 Kein Platz mehr für Termcap-Eintrag
116 Benutzung: settc %s [yes|no]
117 Unbekannte Fähigkeit `%s'
118 Unbekannter Termcap-Parameter `%%%c'
119 Zu viele Argumente für `%s' (%d)
120 `%s' erfordert %d Argumente
121 Benutzung: echotc [-v|-s] [<Fähigkeit> [<Argumente>]]
122 %s: %s. Falsche Architektur
123 !# History-Schleife
124 Falsche Dateianforderung
125 Selector-Überlauf
126 Unbekannte Option: `-%s'\nBenutzung: %s [ -bcdefilmnqstvVxX -Dname[=Wert] ] [ Argument ... ]
127 Unbekannte Option: `-%s'\nBenutzung: %s [ -bcdefFilmnqstvVxX ] [ Argument ... ]
128 Unbekannte Option: `-%s'\nBenutzung: %s [ -bcdefilmnqstvVxX ] [ Argument ... ]
129 \nUngültige Vervollständigung: "%s"
130 \nUngültiger %s: '%c'
131 \nFehlende Trennung '%c' nach %s "%s"
132 \nUnvollständiger/-ges %s: "%s"
133 Kein Operand für -m Option
134 Benutzung: unlimit [-fh] [Grenzen]
135 $%S ist nur lesbar
136 Kein solcher Job
137 Unknown colorls variable `%c%c'
$ $tcsh: set10,v 1.6 2011/02/04 18:19:36 christos Exp $
$ ma.setp.c
$set 10
1 setpath: ungültiger Befehl '%s'.\n
2 setpath: unzureichende Argumente für Befehl '%s'.\n
3 setpath: Wert fehlt in Pfad '%s'\n
4 setpath: %s nicht in %s gefunden\n
5 setpath: %d keine gültige Position in %s\n
$ $tcsh: set11,v 1.5 2006/03/02 18:46:46 christos Exp $
$ sh.c
$set 11
1 Warnung: kein Zugriff auf Tty (%s).\n
2 Daher keine Job Control in dieser Shell.\n
3 Sie haben %d Mails.\n
4 Sie haben %d Mails in %s.\n
5 Sie haben %sMail.\n
6 neue\040
7 Sie haben %sMail in %s.\n
$ $tcsh: set12,v 1.4 2006/03/02 18:46:46 christos Exp $
$ sh.dir.c
$set 12
1 %s: Versuche von "%s" zu starten.\n
$ $tcsh: set13,v 1.4 2011/02/04 18:19:36 christos Exp $
$ sh.exec.c
$set 13
1 hash=%-4d dir=%-2d prog=%s\n
2 %d Hash-Buckets mit jeweils %d Bits\n
3 debug mask = 0x%08x\n
4 %d Treffer, %d Fehler, %d%%\n
5 %S: Befehl in Shell eingebaut.\n
6 %S: Befehl nicht gefunden.\n
7 where: / in Befehl ist nicht sinnvoll\n
8 %S ist ein Alias für 
9 %S ist ein eingebauter Shell-Befehl\n
10 Hash-Fehler: 
$ $tcsh: set14,v 1.4 2006/03/02 18:46:46 christos Exp $
$ sh.file.c
$set 14
1 \nAuweia!! Zu viele %s!!\n
2 Namen in Passwort-Datei
3 Dateien
$ $tcsh: set15,v 1.5 2011/02/04 18:19:36 christos Exp $
$ sh.func.c
$set 15
1 %s: %s: Kann Begrenzung nicht %s%s\n
2 löschen
3 setzen
4 \040(hard limit)
$ $tcsh: set16,v 1.4 2011/02/04 18:19:36 christos Exp $
$ sh.lex.c
$set 16
1 Setze Prozeßgruppe des Terminals von %d auf %d\n
2 \nBitte "logout" zum Abmelden benutzen.\n
3 \nBitte "exit" zum Verlassen der Tcsh benutzen.\n
4 seek to eval %x %x\n
5 seek to alias %x %x\n
6 seek to file %x\n
7 Falscher Typ für seek: %d\n
8 tell eval %x %x\n
9 tell alias %x %x\n
10 tell file %x\n
$ $tcsh: set17,v 1.6 2011/02/04 18:19:36 christos Exp $
$ sh.proc.c
$set 17
1 FEHLER: Warte auf Hintergrund-Job!\n
2 Exitcode %d\n
3 FEHLER: Prozeß "flushed" zum zweitenmal
4 Läuft
5 Signal 
6 Exitcode %-25d
7 Fertig
8 FEHLER: Status=%-9o
9 \040(core dumped)
10 \040(Verz:\040
11 (Verz jetzt:
12 %S: Bereits angehalten\n
13 %S: Bereits angehalten\n
14 %S: Badly formed number\n
$ $tcsh: set18,v 1.4 2011/02/04 18:19:36 christos Exp $
$ sh.set.c
$set 18
1 Warnung: lächerlich langer PATH abgeschnitten\n
$ $tcsh: set19,v 1.7 2011/02/25 23:58:07 christos Exp $
$ tc.alloc.c
$set 19
1 nbytes=%d: Out of memory\n
2 free(%lx) aufgerufen vor irgendeiner Allokation.
3 free(%lx) vor dem Start des Speichers.
4 free(%lx) hinter dem Ende des Speichers.
5 free(%lx) falschen Block.
6 free(%lx) falscher Bereichs-Check.
7 free(%lx) falscher Block-Index.
8 Tcsh's augenblickliche Speicherbelegung:\nfrei:\t
9 benutzt
10 \n\tInsgesamt in Benutzung: %d, insgesamt frei: %d\n
11 \tAllokierter Speicher von 0x%lx bis 0x%lx.  Wirklicher Anfang 0x%lx\n
12 Allokierter Speicher von 0x%lx bis 0x%lx (%ld).\n
13 Tcsh's augenblickliche Speicherbelegung:\n
14 Gesamter vom System angeforderter Speicher: %d\n
15 Anzahl nicht benutzter BlÃ¶cke:: %d\n
16 Anzahl via mmap angeforderter Speicherbereiche: %d\n
17 Via mmap angeforderter Speicher: %d\n
18 Gesamter benutzer Speicher im Pool: %d\n
19 Gesamter freier Speicher im Pool: %d\n
20 Speicher der freigegeben werden kann: %d\n
$ $tcsh: set2,v 1.6 2011/02/04 18:19:36 christos Exp $
$ Signal names
$set 2
1 Null signal
2 Aufgelegt
3 Unterbrochen
4 Verlassen
5 Fehlerhafte Prozessoranweisung
6 Trace/BPT trap
7 Abbruch
8 IOT trap
9 Systemabsturz steht bevor
10 Fehlerhaft beendet
11 EMT trap
12 Fließkommafehler
13 Abgebrochen
14 Benutzersignal 1
15 Benutzersignal 2
16 Speicherschutzverletzung
17 Bus error
18 Programmbereichsfehler
19 Operandenbereichsfehler
20 Falscher Systemaufruf
21 Ausgabeweitergabe abgebrochen
22 Alarm clock
23 Beendet
24 Kindprozeß hat Zustand geändert
25 Abbruch eines Kindprozesses
26 Apollo-spezifischer Fehler
27 Kindprozeß angehalten oder beendet
28 Kindprozeß beendet
29 Stromunterbrechung
30 Ressource verloren
31 Unterbrechung (Ctrl-Break)
32 Mögliches Ein-/Ausgabesignal
33 Asynchrone I/O (select)
34 Dringende Anfrage von Ein-/Ausgabekanal
35 Multitasking wake-up
36 Multitasking kill
37 Fortran asynchrones Ein-Ausgabeende
38 Wiederaufsetzen
39 Nicht korrigierbarer Speicherfehler
40 CPU-Zeitbeschränkung überschritten
41 Systembeendigung absehbar
42 micro-tasking group-no wakeup flag set
43 Thread error - (use cord -T for detailed info)
44 CRAY Y-MP register parity error
45 Information request
46 Angehalten (Signal)
47 Angehalten (Signal)
48 Angehalten
49 Angehalten
50 Fortsetzen
51 Angehalten (Tty-Eingabe)
52 Angehalten (Tty-Eingabe)
53 Angehalten (Tty-Ausgabe)
54 Angehalten (Tty-Ausgabe)
55 Fensterzustand hat sich geändert
56 Fenstergröße hat sich geändert
57 Phone status changed
58 CPU-Zeitbeschränkung überschritten
59 Beschränkung der Dateigröße überschritten
60 Virtueller Zeitalarm
61 Profiling time alarm
62 DIL signal
63 Pollable event occured
64 Process's lwps are blocked
65 Special LWP signal
66 Special CPR Signal
67 Special CPR Signal
68 First Realtime Signal
69 Second Realtime Signal
70 Third Realtime Signal
71 Fourth Realtime Signal
72 Fourth Last Realtime Signal
73 Third Last Realtime Signal
74 Second Last Realtime Signal
75 Last Realtime Signal
76 LAN Asyncronous I/O
77 PTY read/write availability
78 I/O intervention required
79 HFT monitor mode granted
80 HFT monitor mode should be relinguished
81 HFT sound completed
82 Data in HFT ring buffer
83 Migrate process
84 Secure attention key
85 Reschedule
86 Signaling SS$_DEBUG
87 Priority changed
88 Echte Verklemmung entdeckt
89 New input character
90 Stack limit exceeded
91 Unused signal
$ $tcsh: set20,v 1.4 2011/02/04 18:19:36 christos Exp $
$ tc.bind.c
$set 20
1 Ungültiger Tastenname `%S'\n
2 Falsche Tastenname: %S\n
3 Falsche Befehlsname: %S\n
4 Falsche Tastenangabe %S\n
5 Leere Zeichenkette angegeben\n
6 Standard Tastenbelegung\n
7 Alternative Tastenbelegung\n
8 Belegungen mit mehreren Zeichen\n
9 Belegungen der Pfeiltasten\n
10 %-15s->  ist undefiniert\n
11 BUG!!! %s ist mit nichts belegt.\n
12 Benutzung: bindkey [Optionen] [--] [TASTE [BEFEHL]]\n
13     -a   belege Taste in alternativer Tastenbelegung\n
14     -b   akzeptiere symbolische Tastendefinitionen\n
15     -s   belege einen Out-String anstelle eines Befehls\n
16     -c   belege einen Unix-Befehl anstelle eines Befehls\n
17     -v   initialisiere Belegungen mit Standard-Vi-Belegungen\n
18     -e   initialisiere Belegungen mit Standard-Emacs-Belegungen\n
19     -d   initialisiere Belegungen mit Standard-Belegungen\n
20     -l   zeige verfügbare Funktionen mit Beschreibungen an\n
21     -r   entferne Belegung eines Tastes\n
22     -k   belege Pfeiltaste mit Namen in In-String\n
23     --   force a break from option processing\n
24     -u   (or any invalid option) this message\n
25 Wenn kein Out-String oder Befehl angegeben wurde, wir die Belegung für\n
26 den In-String ausgegeben oder alle Belegungen, falls kein in-String gegeben.\n
27 Falsche Tastenangabe -- nicht definierte Zeichenkette\n
28 Falsche Tastenangabe -- leere Zeichenkette\n
29 Falsche Funktionstastenangabe.  Leere Taste nicht erlaubt\n
30 Falsche Tastenangabe -- nicht korrekte Hex-Zahl\n
31 Falsche Tastenangabe -- nicht korrekte Oktal-Zahl\n
32 Falsche Tastenangabe -- nicht korrekte Dezimal-Zahl\n
33 Falsche Funktionstastenangabe.\n
34 Leere Taste nicht erlaubt\n
35 Falsche Tastenangabe -- unbeannter Name "%S"\n
36 Benutzung: bind [TASTE | BEFEHL TASTE | "emacs" | "vi" | "-a"]\n
37 Ungültige Funktion
38  %s\t\tist undefiniert\n
$ $tcsh: set21,v 1.3 2006/03/02 18:46:46 christos Exp $
$ tc.disc.c
$set 21
1 Kann lokale Sonderzeichen nicht auslesen.\n
2 Kann lokale Sonderzeichen nicht setzen.\n
$ $tcsh: set22,v 1.4 2011/02/04 18:19:36 christos Exp $
$ tc.func.c
$set 22
1 %S: \t ein Alias für 
2 \nPasswort nicht korrekt für %s\n
3 Fehlerhafter Alias 'precmd' entfernt.\n
4 Fehlerhafter Alias 'cwdcmd' entfernt.\n
5 Fehlerhafter Alias 'beepcmd' entfernt.\n
6 Fehlerhafter Alias 'periodic' entfernt.\n
7 zerteile Kommandozeile\n
8 Wollen Sie wirklich alle Dateien löschen? [n/j] 
9 Übergehe das Löschen der Dateien!\n
10 Kommandozeile ist nun:\n
11 zerteile Kommandozeile\n
12 in einer der Listen\n
13 Kommandozeile ist nun:\n
14 jJyY
$ $tcsh: set23,v 1.5 2011/02/04 18:19:36 christos Exp $
$ tc.os.c
$set 23
1 Falscher Cpu/Site-Name
2 Site-Pfad zu lang
3 unbekannt
4 Site: %s\n
5 %d: Site nicht gefunden\n
6 setlocal: %s: %s\n
7 Site nicht gefunden
8 Sie sind in einem Universum gefangen, daß Sie nie gemacht haben
9 Getwarp fehlgeschlagen
10 Ungültiger Warp
11 Setwarp fehlgeschlagen
12 Ungültiges Universum
13 Unbekannter Fehler: %d
14 sysname:  %s\n
15 nodename: %s\n
16 release:  %s\n
17 version:  %s\n
18 machine:  %s\n
19 getwd: Kann ".." nicht öffnen (%s)
20 getwd: Kann nicht in ".." wechseln (%s)
21 getwd: Lesefehler in ".." (%s)
22 getwd: Kann nicht zurück zu "." wechseln (%s)
23 getwd: Kann kein stat auf "/" machen (%s)
24 getwd: Kann kein stat auf "." machen (%s)
25 getwd: Kann kein stat auf Verzeichnis "%s" machen (%s)
26 getwd: Kann Verzeichnis "%s" nicht öffnen (%s)
27 getwd: Kann "." nicht in ".." finden (%s)
28 Ungültiger Systemtyp
29 Systemtyp ist nicht gesetzt
30 Too many arguments
31 Invalid argument
$ $tcsh: set24,v 1.3 2006/03/02 18:46:46 christos Exp $
$ tc.sched.c
$set 24
1 Hack!
$ $tcsh: set25,v 1.4 2011/02/04 18:19:36 christos Exp $
$ tc.sig.c
$set 25
1 unser wait %d\n
2 Fehler: bsd_signal(%d) Signal außerhalb der Grenzen\n
3 Fehler: bsd_signal(%d) - sigaction fehlerhaft, errno %d\n
$ $tcsh: set26,v 1.5 2011/02/04 18:19:36 christos Exp $
$ tc.who.c
$set 26
1 Kein Zugriff auf %s.  Bitte "unset watch" eingeben.\n
2 %s kann nicht geöffnet werden.  Bitte "unset watch" eingeben.\n
3 FEHLER! letztes Element ist nicht whotail!\n
4 Zurück: 
5 FEHLER! erstes Element ist nicht whohead!\n
6 neu: %s/%s\n
7 %n hat %a an %l von %m.
8 %n hat %a an %l.
9 sich angemeldet
10 sich abgemeldet
11 %s ersetzt
12 lokal
$ $tcsh: set27,v 1.4 2011/02/04 18:19:36 christos Exp $
$ tw.comp.c
$set 27
1 Befehl
2 Trenner
3 Muster
4 Bereichs
5 Vervollständigung
$ $tcsh: set29,v 1.4 2011/02/04 18:19:36 christos Exp $
$ tw.help.c
$set 29
1 Keine Hilfe-Datei für %S\n
$ $tcsh: set3,v 1.7 2011/02/04 18:19:36 christos Exp $
$ Editor function descriptions
$set 3
1 Ein Zeichen zurück
2 Lösche Zeichen hinter Cursor
3 Lösche vom Anfang des aktuellen Worts bis zum Cursor - in Cut-Puffer
4 Lösche vom Anfang der Zeile bis zum Cursor - in Cut-Puffer
5 Gehe an den Anfang des aktuellen Worts
6 Gehe zum Anfang der Zeile
7 Wandele vom Cursor bis zum Ende des aktuellen Worts in Großbuchstaben um
8 Vi: Ändere Groß/Kleinschreibung des Zeichen unter dem Cursor und bewege Cursor eins nach vorn
9 Vi: Ändere bis zum Ende der Zeile
10 Lösche Bildschirm (aktuelle Zeile oben)
11 Vervollständige aktuelles Wort
12 Gehe mit Tab vorwärts durch die Dateiliste
13 Gehe mit Tab rückwärts durch die Dateiliste
14 Vervollständige Wort (ignoriere programmierbare Vervollständigungen)
15 Kopiere aktuelles Wort zum Cursor
16 Kopiere Area zwischen Marke und Cursor in Cut-Puffer
17 Erweitere zu früherem Wort für das dies ein Anfang ist
18 Lösche Zeichen unter Cursor
19 Lösche Zeichen unter Cursor oder gib EOF-Signal am Ende der Zeile
20 Lösche Zeichen unter Cursor oder zeige Vervollständigungen am Ende der Zeile an
21 Lösche Zeichen unter Cursor oder zeige Vervollständigungen oder gib EOF-Signal
22 Lösche von Cursor bis zum Ende des aktuellen Worts - in Cut-Puffer
23 Füge Argument hinzu, wenn gestartet, oder gib zahl ein
24 Ziffer, die ein Argument beginnt
25 Gehe zur nächsten History-Zeile
26 Wandele vom Cursor bis zum Ende des aktuellen Worts in Kleinbuchstaben um
27 Melde Ende der Datei
28 Gehe zum Ende der Zeile
29 Tausche Cursor und Marke aus
30 Expandiere Wildcards in Dateinamen
31 Expandiere History-Escapes
32 Expandiere History-Escapes in einer Zeile
33 Expandiere Variablen
34 Gehe ein Zeichen vor
35 Gehe vor bis zum Ende des akutellen Worts
36 Vertausche zwei Zeichen vor dem Cursor
37 Suche rückwärts in History nach Zeile mit gleichem Anfang
38 Suche vorwärts in History nach Zeile mit gleichem Anfang
39 Setze letzten Teil des vorherigen Befehls ein
40 Incrementelle Suche (vorwärts)
41 Incrementelle Suche (rückwärts)
42 Lösche Zeile
43 Lösche bis zum Ende der Zeile - in Cut-Puffer
44 Lösche Area zwischen Marke und Cursor - in Cut-Puffer
45 Lösche gesamte Zeile - in Cut-Puffer
46 Zeige Möglichkeiten der Vervollständigung
47 Zeige Möglichkeiten der Vervollständigung (ignoriere programmierbare Vervollständigungen)
48 Zeige Treffer der Dateinamen-Wildcards
49 Zeige Möglichkeiten der Vervollständigung oder gib EOF, falls Zeile leer
50 Zeige durchschnittliche Last und augenblickl. Prozeßzustand
51 Expandiere History-Escape und füge Leerzeichen ein
52 Führe Befehl aus
53 Expandiere Pfadnamen, eliminiere führende . und ..
54 Expandiere Befehle in den entsprechenden Pfadnamen oder Alias
55 Schalte von Insert- auf Einfügemodus oder umgekehrt
56 Füge das achte Bit zu dem nächsten eingegebenen Zeichen hinzu
57 Füge das nächste Eingabezeichen unverändert ein
58 Baue Anzeige neu auf
59 Starte angehaltenen Editor wieder
60 Suche nach Hilfe für den aktuellen Befehl
61 Dieses Zeichen wird zur Zeile hinzugefügt
62 Dieses Zeichen ist das erste einer Folge von Zeichen
63 Setze die Marke an der Stelle des Cursors
64 Korrigiere die Schreibweise des aktuellen Wortes
65 Korrigiere die Schreibweise der gesamten Zeile
66 Sende Zeichen an Tty im "cooked mode"
67 Schalte um zwischen literaler und lexicalischer aktueller History-Zeile
68 Tausche das Zeichen links des Cursors mit dem unter dem Cursor
69 Tausche die zwei Zeichen vor dem Cursor
70 Tty delayed suspend Zeichen
71 Tty flush output Zeichen
72 Tty interrupt Zeichen
73 Tty quit Zeichen
74 Tty suspend Zeichen
75 Tty allow output Zeichen
76 Tty disallow output Zeichen
77 Indicates unbound Zeichen
78 Emacs universelles Argument (Argument mal 4)
79 Gehe zur vorhergehenden History-Zeile
80 Wandele die Zeichen vom Cursor bis zum Ende des akt. Worts in Großbuchst. um
81 Vi gehe zum Anfang des nächsten Wortes
82 Vi gehe in Einfügemodus hinter dem Cursor
83 Vi gehe in Einfügemodus am Ende der Zeile
84 Vi ändere Groß/Kleinschreibung des Zeichens unter dem Cursor und gehe ien vor
85 Vi ändere Prefix-Befehl
86 Vi ändere bis zum Ende der Zeile
87 Vi gehe in Befehlsmodus (benutze alternative Tastenbelegung)
88 Vi Befehlsmodus vervollständige aktuelles Wort
89 Vi gehe zum vorhergehenden Zeichen (Backspace)
90 Vi lösche Prefix-Befehl
91 Vi gehe zum Ende des aktuellen Worts (durch Leerzeichen begrenzt)
92 Vi gehe zum Ende des aktuellen Worts
93 Vi gehe zum angegebenen Zeichen rückwärts
94 Vi gehe zum angegebenen Zeichen vorwärts
95 Vi gehe hoch zum angegebenen Zeichen rückwärts
96 Vi gehe hoch zum angegebenen Zeichen vorwärts
97 Vi gehe in Einfügemodus
98 Vi gehe in Einfügemodus am Anfang der Zeile
99 Vi wiederhole aktuelle Suche in dieselbe Richtung
100 Vi wiederhole aktuelle Suche in entgegengesetzte Richtung
101 Vi wiederhole aktuelle Suche in dieselbe Richtung
102 Vi wiederhole aktuelle Suche in entgegengesetzte Richtung
103 Vi ersetze Zeichen unter dem Cursor mit dem nächsten eingegebenen Zeichen
104 Vi Ersetzungsmodus
105 Vi suche History vorwärts
106 Vi suche History rückwärts
107 Vi ersetze Zeichen unter dem Cursor und gehe in Einfügemodus
108 Vi ersetze gesamte Zeile
109 Vi gehe zum verhergehenden Wort
110 Vi gehe zum nächsten Wort
111 Vi mache letzte Änderung rückgängig
112 Vi gehe zum Anfang der Zeile
113 Mache ein 'which' von dem aktuellen Befehl
114 Füge den Cut-Puffer an der Cursor-Position ein
115 Replace just-yanked text with yank from earlier kill
116 (WIN32 only) Copy cut buffer to system clipboard
117 (WIN32 only) Paste clipboard buffer at cursor position
118 (WIN32 only) Convert each '/' in next word to '\\\\'
119 (WIN32 only) Convert each '/' in previous word to '\\\\'
120 (WIN32 only) Page visible console window up
121 (WIN32 only) Page visible console window down
$ $tcsh: set30,v 1.5 2011/02/04 18:19:37 christos Exp $
$ tw.parse.c
$set 30
1 Anfangsbefehl %d\n
2 vervollständige %d 
3 vervollständige %d %S\n
4 %s: Interner Abgleichsfehler.\n
5 Objekte
6 Spalten
7 Es gibt %d %s, trotzdem anzeigen? [n/j] 
8 looking = %d\n
9 \n%s interner Fehler: Ich weiß nicht, wonach ich suche!\n
10 kein Verzeichnis
11 nicht gefunden
12 nicht lesbar
13 jJyY
$ $tcsh: set31,v 1.4 2011/02/04 18:19:37 christos Exp $
$ vms.termcap.c
$set 31
1 Kann TERMCAP nicht öffnen: [%s]\n
2 Kann %s nicht öffnen.\n
3 Fand %s in %s.\n
4 Kein Eintrag für %s in Datei %s gefunden\n
$ $tcsh: set4,v 1.4 2011/02/04 18:19:37 christos Exp $
$ Termcap strings
$set 4 
1 füge neue, leere Zeile hinzu
2 hörbare Pieps
3 lösche bis zum Ende der Anzeige
4 lösche bis zum Ende der Zeile
5 Cursor zu horizontaler Position
6 lösche Bildschirm
7 lösche ein Zeichen
8 lösche eine Zeile
9 starte Löschemodus
10 beende Löschmodus
11 beende Einfügemodus
12 Cursor aus Statuszeile
13 Cursor in Ursprungsposition
14 füge Zeichen ein
15 starte Einfügemodus
16 setze Füllzeichen ein
17 Cursor nach unten
18 Cursor nach links
19 Cursor nach rechts
20 Cursor nach oben
21 starte Fettschrift
22 beende Attribute
23 nicht zerstörendes Leerzeichen
24 beende hervorgehobene Darstellung
25 beginne hervorgehobene Darstellung
26 Cursor in Statuszeile
27 Cursor eins hoch
28 beginne Unterstreichung
29 beende Unterstreichung
30 sichtbarer Pieps
31 lösche mehrere Zeichen
32 Cursor mehrere Zeichen nach unten
33 füge mehrere Zeichen ein
34 Cursor mehrere Zeichen nach links
35 Cursor mehrere Zeichen nach rechts
36 Cursor mehrere Zeichen nach oben
37 hat automatische Ränder
38 kann physikalische Tabulatoren benutzen
39 Anzahl Zeilen
40 Anzahl Spalten
41 hat Meta-Taste
42 Zeilenumbruch am rechten Rand wird ignoriert
$ $tcsh: set5,v 1.4 2011/02/04 18:19:37 christos Exp $
$ ed.chared.c
$set 5
1 Durchschnittliche Last nicht verfügbar\n
$ $tcsh: set6,v 1.4 2011/02/10 00:13:36 christos Exp $
$ ed.inputl.c
$set 6
1 FEHLER: Illegaler Befehl von Taste 0%o\r\n
2 ja\n
3 editieren\n
4 abbrechen\n
5 nein\n
6 Kein entsprechender Befehl\n
7 Mehrdeutiger Befehl\n
8 *** Editor fataler FEHLER ***\r\n\n
$ $tcsh: set7,v 1.6 2011/02/04 18:19:37 christos Exp $
$ ed.screen.c
$set 7
1 \n\tTcsh meint, Ihr Endgerät hat die\n
2 \tfolgenden Eigenschaften:\n\n
3 \tEs hat %d Spalten und %d Zeilen\n
4 \tEs hat %s Meta-Taste\n
5 eine
6 keine
7 \tEs kann%s Tabulatoren benutzen\n
8 \040keine
9 \tEs %s automatische Ränder\n
10 hat
11 hat nicht
12 \tEs %s magische Ränder\n
13 (leer)
14 ja
15 nein
16 FEHLER: kann nicht löschen\r\n
17 DeleteChars: num ist lächerlich: %d\r\n
18 FEHLER: kann nicht einfügen\r\n
19 StartInsert: num ist lächerlich: %d\r\n
20 %s: Kann /etc/termcap nicht öffnen.\n
21 %s: Kein Eintrag für Terminaltyp "%s"\n
22 %s: benutze minimale Terminaleigenschaften.\n
23 %s: WARNUNG: Ihr Terminal kann den Cursor nicht aufwärts bewegen.\n
24 Lange Zeilen könnten etwas komisch aussehen.\n
25 keine Fähigkeit, bis Zeilenende zu löschen.\n
26 keine Fähigkeit, Zeichen zu löschen.\n
27 keine Fähigkeit, Zeichen einzufügen.\n
$ $tcsh: set8,v 1.4 2011/02/04 18:19:37 christos Exp $
$ ed.term.c
$set 8
1 Unbekannter Schalter
2 Ungültiges Argument
$ $tcsh: set9,v 1.5 2011/02/04 18:19:37 christos Exp $
$ ed.xmap.c
$set 9
1 AddXkey: Null extended-key not allowed.\n
2 AddXkey: sequence-lead-in command not allowed\n
3 DeleteXkey: Null extended-key not allowed.\n
4 Unbound extended key "%S"\n
5 Some extended keys too long for internal print buffer
6 Enumerate: BUG!! Null ptr passed\n!
7 keine Eingabe
8 Es muß noch etwas folgen: %c\n
9 Oktal-Konstante paßt nicht in ein Zeichen.\n
