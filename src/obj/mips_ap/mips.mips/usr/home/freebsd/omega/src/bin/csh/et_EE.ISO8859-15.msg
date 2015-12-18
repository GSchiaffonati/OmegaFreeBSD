$ codeset=UTF-8
$set 255
1 UTF-8
$ $tcsh: set1,v 1.4 2011/02/04 18:19:33 christos Exp $
$ Error messages
$set 1 
1 Süntaksi viga
2 %s ei ole lubatud
3 Sõna on liiga pikk
4 $< rida on liiga pikk
5 $0 jaoks pole faili
6 Mittetäielik [] muutja
7 $ laiendus peab lõppema enne ]
8 Halb : täiendaja $ (%c)
9 Viga indeksis
10 Vigane number
11 Sõnad on otsas
12 Faili nimi on puudu
13 Sisemine täiendi viga
14 Käsku pole
15 Liiga vähe argumente
16 Liiga palju argumente
17 Seda aliast on liiga ohtlik luua
18 Tühi if
19 Ebaõige then
20 Sõnad pole sulgudes
21 %s ei leita
22 Vigane mask
23 Pole sellist limiiti
24 Argument on liiga suur
25 Vigane või tundmatu skaleerimis faktor
26 Defineerimata muutuja
27 Kataloogi pinu pole nii sügav
28 Vigane signaali number
29 Tundmatu signaal; kill -l annab signaalid
30 Muutuja nimi peab algama tähega
31 Muutuja nimi on liiga pikk
32 Muutuja nimi võib koosneda ainult tähtedest ja numbritest
33 Sellel käsuinterpretaatoril puudub töökontroll
34 Avaldises on süntaksi viga
35 Kodukataloogi pole
36 Kodukataloogi ei saa minna
37 Vigane tühi käsk
38 Omistamisel pole avaldist
39 Tundmatu operaator
40 Arusaamatu
41 %s: Fail on olemas
42 Võtme -c argumendi lõpus on langkriips
43 Katkestatud
44 Indeks on piiridest väljas
45 Rea ületäitumine 
46 Sellist tööd pole
47 Terminalilt ei saa
48 Pole while/foreach sees
49 Protsessid on otsas
50 Ei leia
51 Puuduv %c
52 Ei leia sümbolit %c
53 Mälu on otsas
54 Toru ei saa luua
55 %s: %s
56 %s
57 Kasuta: jobs [ -l ]
58 Argumendid peavad olema tööde või protsesside identifikaatorid
59 Käesolevat tööd pole
60 Pole eelmist tööd
61 Pole mustrile vastavat tööd
62 Fork süveneb > %d; võibolla `...` tsükkel
63 Alamshellis pole töökontrolli
64 Sünkroniseerimise tõrge: Protsessi %d pole
65 %sTeil on peatatud töid
66 %sTeil on seisatud töid
67 Pole teist kataloogi
68 Kataloogi pinu on tühi
69 Halb kataloog
70 kasuta: %s [-%s]%s
71 -h võtmel puudub operand
72 Pole meldimise shell
73 Nulliga jagamine
74 Jäägi leidmine nulliga
75 Vigane skaala; te mõtlesite ehk "%s"?
76 Login shelli ei saa peatada (praegu)
77 Tundmatu kasutaja: %s
78 $home muutujat pole väärtustatud
79 Kasuta: history [-%s] [# sündmuste number]
80 $, ! või < pole lubatud kasutada koos $# või $?
81 Reavahetus muutuja nimes
82 * pole lubatud kasutada koos $# või $?
83 $?<number> või $#<number> pole lubatud
84 Lubamatu muutuja nimi
85 Reavahetus muutuja indeksis
86 Laiendamise puhvri ületäitumine
87 Muutuja süntaksi viga
88 Vigane ! kasutamine
89 Eelmist asendust pole
90 Vigane asendamine
91 Eelmist vasakut poolt pole
92 Parem pool on liiga pikk
93 Vigane ! modifikaator: %c
94 Modifikaator ebaõnnestus
95 Asenduse puhvri ületäitumine
96 Vigane ! argumendi valik
97 Pole eelmist otsimist
98 %s: Sündmust pole
99 Liiga palju )
100 Liiga palju (
101 Halvasti paigutatud (
102 Suunamisel pole nime antud
103 Segane väljundi suunamine
104 << ei saa () vahel kasutada
105 Segane sisendi suunamine
106 Halvasti paigutatud ()
107 Aliaste tsükkel
108 $watch muutuja pole seatud
109 Plaanitud sündmuseid pole
110 Kasuta: sched -<sündmuse#>.\nKasuta: sched [+]hh:mm <käsk>
111 Niipalju sündmuseid pole
112 Pole käsku, mida käivitada
113 Vigane sündmuseaeg
114 Suhteline aeg ei ole am/pm notatsiooniga kooskõlas
115 Termcap sõne on liiga pikk
116 Kasuta: settc %s [yes|no]
117 Tundmatu omadus `%s'
118 Tundmatu termcap parameeter `%%%c'
119 `%s' jaoks on liiga palju argumente (%d)
120 `%s' nõuab %d argumenti
121 Kasuta: echotc [-v|-s] [<omadus> [<argumendid>]]
122 %s: %s. Vale arhitektuur
123 !# Ajaloo tsükkel
124 Vigane failipäring
125 Valija ületäitumine 
126 Tundmatu võti: `-%s'\nKasuta: %s [ -bcdefilmnqstvVxX -Dnimi[=väärtus] ] [ argument ... ]
127 Tundmatu võti: `-%s'\nKasuta: %s [ -bcdefFilmnqstvVxX ] [ argument ... ]
128 Tundmatu võti: `-%s'\nKasuta: %s [ -bcdefilmnqstvVxX ] [ argument ... ]
129 \nVigane täiendus: "%s"
130 \nVigane %s: '%c'
131 \nEraldaja '%c' puudub pärast %s "%s"
132 \nMittetäielik %s: "%s"
133 -m võtmel pole operandi
134 Kasuta: unlimit [-fh] [limiidid]
135 $%S on ainult lugemiseks
136 Pole sellist tööd
137 Tundmatu colorls muutuja `%c%c'
$ $tcsh: set10,v 1.3 2011/02/04 18:19:33 christos Exp $
$ ma.setp.c
$set 10 
1 setpath: vigane käsk '%s'.\n
2 setpath: käsule '%s' pole piisavalt argumente.\n
3 setpath: teel '%s' pole väärtust\n
4 setpath: %s ei leitud %s's\n
5 setpath: %d ei ole korrektne positsioon %s's\n
$ $tcsh: set11,v 1.3 2011/02/04 18:19:33 christos Exp $
$ sh.c
$set 11 
1 Hoiatus: tty (%s) pole kättesaadav.\n
2 Seega ei saa kasutada tööde kontrolli.\n
3 Teil on %d kirja.\n
4 Teil on %d kirja failis %s.\n
5 Teil on %skiri.\n
6 uus 
7 Teil on %skiri failis %s.\n
$ $tcsh: set12,v 1.2 2006/03/02 18:46:45 christos Exp $
$ sh.dir.c
$set 12 
1 %s: Proovin startida kataloogist "%s"\n
$ $tcsh: set13,v 1.3 2011/02/04 18:19:33 christos Exp $
$ sh.exec.c
$set 13 
1 hash=%-4d dir=%-2d prog=%s\n
2 %d hash buckets of %d bits each\n
3 debug mask = 0x%08x\n
4 %d hits, %d misses, %d%%\n
5 %S: käsuinterpretaatori sisekäsk.\n
6 %S: Käsku pole.\n
7 where: / käsunimes on mõttetu\n
8 %S on tegelikult 
9 %S on sisekäsk\n
10 hash miss: 
$ $tcsh: set14,v 1.3 2011/02/04 18:19:33 christos Exp $
$ sh.file.c
$set 14 
1 \nÄhh!! Liiga palju %s!!\n
2 nimesid paroolifailis
3 faile
$ $tcsh: set15,v 1.3 2011/02/04 18:19:33 christos Exp $
$ sh.func.c
$set 15 
1 %s: %s: Ei õnnestu %s%s piirangut\n
2 eemaldada
3 seada
4 \040kõva
$ $tcsh: set16,v 1.3 2011/02/04 18:19:33 christos Exp $
$ sh.lex.c
$set 16 
1 Seadsin tty pgrp numbrilt %d numbrile %d\n
2 \nKasuta töö lõpetamiseks käsku "logout".\n
3 \nKasuta "exit" käsku %s katkestamiseks.\n
4 seek to eval %x %x\n
5 seek to alias %x %x\n
6 seek to file %x\n
7 Bad seek type %d\n
8 tell eval %x %x\n
9 tell alias %x %x\n
10 tell file %x\n
$ $tcsh: set17,v 1.4 2011/02/04 18:19:33 christos Exp $
$ sh.proc.c
$set 17 
1 BUG: ootan taustatöö järel!\n
2 Exit %d\n
3 BUG: process flushed twice
4 Töötab 
5 Signaal 
6 Exit %-25d
7 Valmis
8 BUG: staatus=%-9o
9 \040(mälupilt päästetud)
10 \040(töökataloog:
11 (töökataloog nüüd: 
12 %S: Juba peatatud\n
13 %S: Juba seisatud\n
14 %S: Badly formed number\n
$ $tcsh: set18,v 1.3 2011/02/04 18:19:33 christos Exp $
$ sh.set.c
$set 18 
1 Hoiatus: nõmedalt pikk PATH sai lühendatud\n
$ $tcsh: set19,v 1.5 2011/02/25 23:58:07 christos Exp $
$ tc.alloc.c
$set 19 
1 nbytes=%d: Mälu on otsas\n
2 free(%lx) kasutati enne mälu haaramist.
3 free(%lx) enne mälu algust.
4 free(%lx) pärast mälu lõppu.
5 free(%lx) halb plokk.
6 free(%lx) vigane piirkonna kontroll.
7 free(%lx) vigane plokkide indeks.
8 %s mälu kasutamine hetkel:\nvaba:\t
9 kasutatud
10 \n\tKokku kasutusel: %d, kokku vaba: %d\n
11 \tMälu vahemikus 0x%lx kuni 0x%lx.  Tegelik algus 0x%lx\n
12 Mälu vahemikus 0x%lx kuni 0x%lx (%ld).\n
13 %s current memory allocation:\n
14 Total space allocated from system: %d\n
15 Number of non-inuse chunks: %d\n
16 Number of mmapped regions: %d\n
17 Total space in mmapped regions: %d\n
18 Total allocated space: %d\n
19 Total non-inuse space: %d\n
20 Top-most, releasable space: %d\n
$ $tcsh: set2,v 1.3 2011/02/04 18:19:33 christos Exp $
$ Signal names
$set 2 
1 Null signaal
2 Hangup
3 Katkestus
4 Quit
5 Vigane instruktsioon
6 Trace/BPT trap
7 Abort
8 IOT trap
9 System Crash Imminent
10 Error exit
11 EMT trap
12 Floating exception
13 Tapetud
14 Kasutaja signaal 1
15 Kasutaja signaal 2
16 Segmenteerimise rike
17 Viga siinil
18 Program range error
19 Operand range error
20 Vigane süsteemifunktsioon
21 Katkenud toru
22 Alarmkell
23 Terminated
24 Alamprotsessi olek muutus
25 Alamprotsessi surm
26 Apollo-spetsiifiline tõrge
27 Alamprotsess peatatud või lõpetas
28 Alamprotsess lõpetas
29 Voolutõrge
30 Resource Lost
31 Break (Ctrl-Break)
32 Sisend/väljund võimalik
33 Asünkroonne S/V (select)
34 Urgent condition on I/O channel
35 Multitasking wake-up
36 Multitasking kill
37 Fortrani asünkroonne S/V lõpetas
38 Recovery
39 Mitteparandatav mälu viga
40 CPU aja piirang on ületatud
41 System shutdown imminent
42 micro-tasking group-no wakeup flag set
43 Thread error - (use cord -T for detailed info)
44 CRAY Y-MP registri paarsuse viga
45 Information request
46 Peatatud (signaal)
47 Seisatud (signaal)
48 Peatatud
49 Seisatud
50 Jätkab
51 Peatatud (tty sisend)
52 Seisatud (tty sisend)
53 Peatatud (tty väljund)
54 Seisatud (tty väljund)
55 Akna olek muutus
56 Akna suurus muutus
57 Telefoni olek muutus
58 Cpu aja piirang on ületatud
59 Faili suuruse piirang on ületatud
60 Virtuaalaja alarm
61 Profiling time alarm
62 DIL signaal
63 Pollable event occured
64 Protsessi lwpd on blokeeritud
65 Spetsiaalne LWP signaal
66 Spetsiaalne CPR Signaal
67 Spetsiaalne CPR Signaal
68 Esimene reaalaja signaal
69 Teine reaalaja signaal
70 Kolmas reaalaja signaal
71 Neljas reaalaja signaal
72 Neljas viimane reaalaja signaal
73 Kolmas viimane reaalaja signaal
74 Teine viimane reaalaja signaal
75 Viimane reaalaja signaal
76 LAN Asünkroonne I/O
77 PTY read/write availability
78 I/O intervention required
79 HFT monitor mode granted
80 HFT monitor mode should be relinguished
81 HFT sound control has completed
82 Data in HFT ring buffer
83 Migrate process
84 Secure attention key
85 Reschedule
86 Signaling SS$_DEBUG
87 Prioriteedi muutus
88 Tuvastati tõeline tupiksituatsioon
89 Uus sisendsümbol
90 Pinu piirang on ületatud
91 Kasutamata signaal
92 LM overlay
93 süsteemi külmutamine
94 süsteemi sulatamine
95 tupiksituatsioon
96 mälu suuruse piirang on ületatud
97 andmete suuruse piirang on ületatud
98 exceeded memory size limit of 32KB
99 exce error for no memory
100 check point start
101 check point start of kernel
102 restart start
103 restart of kernel
104 XMU suuruse piirang on ületatud
105 RLG0 piirang on ületatud
106 RLG1 piirang on ületatud
107 RLG2 piirang on ületatud
108 RLG3 piirang on ületatud
$ $tcsh: set20,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tc.bind.c
$set 20 
1 Vigane klahvi nimi `%S'\n
2 Halb klahv: %S\n
3 Halb käsk: %S\n
4 Halb klahvi spetsifikatsioon %S\n
5 Null sõne spetsifikatsioonis\n
6 Standardsed klahviseosed\n
7 Alternatiivsed klahviseosed\n
8 Mitme-sümbolised seosed\n
9 Seosed nooleklahvidele\n
10 %-15s->  on defineerimata\n
11 BUG!!! %s pole seotud.\n
12 Kasuta: bindkey [võtmed] [--] [KLAHV [KÄSK]]\n
13     -a   esita või seo KLAHVI alternatiivne tabel\n
14     -b   käsitle KLAHVI kui C-, M-, F- või X- klahvi nime\n
15     -s   käsitle COMMAND kui literaalset väljundsõne\n
16     -c   käsitle COMMAND kui sisemist või välist käsku\n
17     -v   seo kõik klahvid vi seostega\n
18     -e   seo kõik klahvid emacsi seostega\n
19     -d   seo kõik klahvid vaikimisi toimeti seostega\n
20     -l   esita toimeti käsud koos kirjeldustega\n
21     -r   kustuta KLAHVILT seos\n
22     -k   kasuta KLAHVI kui noole-klahvi sümbolnime\n
23     --   katkesta võtmete töötlemine\n
24     -u   (või suvaline vigane võti) see teade\n
25 Ilma KLAHVI või KÄSUTA trükib kõik seosed\n
26 Ilma KÄSUTA trükib seosed KLAHVILE.\n
27 Halb klahvi spetsifikatsioon -- null sõne\n
28 Halb klahvi spetsifikatsioon -- tühi sõne\n
29 Halb funktsioon-klahvi spetsifikatsioon.  Null klahv pole lubatud\n
30 Halb klahvi spetsifikatsioon -- vigane kuueteistkümnend number\n
31 Halb klahvi spetsifikatsioon -- vigane kaheksand number\n
32 Halb klahvi spetsifikatsioon -- vigane kümnend number\n
33 Halb funktsioon-klahvi spetsifikatsioon.\n
34 Null klahv pole lubatud\n
35 halb klahvi spetsifikatsioon -- tundmatu nimi "%S"\n
36 kasuta: bind [KLAHV | KÄSK KLAHV | "emacs" | "vi" | "-a"]\n
37 Vigane funktsioon
38  %s\t\ton defineerimata\n
$ $tcsh: set21,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tc.disc.c
$set 21 
1 Lokaalseid sümboleid ei õnnestu lugeda.\n
2 Lokaalseid sümboleid ei õnnestu seada.\n
$ $tcsh: set22,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tc.func.c
$set 22 
1 %S: \t on tegelikult 
2 \nKasutaja %s: vale parool\n
3 Vigane alias 'precmd' eemaldatud.\n
4 Vigane alias 'cwdcmd' eemaldatud.\n
5 Vigane alias 'beepcmd' eemaldatud.\n
6 Vigane alias 'periodic' eemaldatud.\n
7 töötlen käsurida\n
8 Kas te tÕepoolest tahate kustutada kõik failid? [e/j] 
9 katkestan failide kustutamise!\n
10 käsurida on nüüd:\n
11 töötlen käsurida\n
12 ühes loenditest\n
13 käsurida on nüüd:\n
14 jJ
$ $tcsh: set23,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tc.os.c
$set 23 
1 Vigane cpu/saidi nimi
2 Saidi tee on liiga pikk
3 tundmatu
4 sait: %s\n
5 %d: Saiti pole\n
6 setlocal: %s: %s\n
7 Saiti pole
8 Te olete lõksus universumis, mida te pole loonud
9 Getwarp ebaõnnestus
10 Vigane warp
11 Setwarp ebaõnnestus
12 Vigane universum
13 Tundmatu viga: %d
14 sysname:  %s\n
15 nodename: %s\n
16 release:  %s\n
17 versioon:  %s\n
18 masin:  %s\n
19 getwd: ".." ei saa avada (%s)
20 getwd: Ei saa minna kataloogi ".." (%s)
21 getwd: Viga lugedes ".." (%s)
22 getwd: Ei saa tagasi "." kataloogi (%s)
23 getwd: "/" atribuute ei saa lugeda (%s)
24 getwd: "." atribuute ei saa lugeda (%s)
25 getwd: Kataloogi "%s" atribuute ei saa lugeda (%s)
26 getwd: Kataloogi "%s" ei saa avada (%s)
27 getwd: Kataloogis ".." pole kataloogi "." (%s)
28 Vigane süsteemi tüüp
29 Süsteemi tüüp ei ole määratud
30 Liiga palju argumente
31 Vigane argument
$ $tcsh: set24,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tc.sched.c
$set 24 
1 Häkk!
$ $tcsh: set25,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tc.sig.c
$set 25 
1 our wait %d\n
2 viga: bsd_signal(%d) pole signaal\n
3 viga: bsd_signal(%d) - sigaction ebaõnnestus, errno = %d\n
$ $tcsh: set26,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tc.who.c
$set 26 
1 Ei saa lugeda %s atribuute.  Anna käsk "unset watch".\n
2 %s ei saa avada.  Anna käsk "unset watch".\n
3 BUG! viimane element ei ole viimasena registreeritud!\n
4 tagurpidi: 
5 BUG! esimene element ei ole esimesena registreeritud!\n
6 uus: %s/%s\n
7 %n %a terminalil %l masinast %m.
8 %n %a terminalil %l.
9 töötab
10 lõpetas töö
11 asendas %s terminalil
12 kohalik
$ $tcsh: set27,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tw.comp.c
$set 27 
1 käsk
2 eraldaja
3 muster
4 vahemik
5 täiendamine
$ $tcsh: set29,v 1.2 2006/03/02 18:46:45 christos Exp $
$ tw.help.c
$set 29 
1 %S'ile pole abiteksti\n
$ $tcsh: set3,v 1.4 2011/02/04 18:19:33 christos Exp $
$ Editor function descriptions
$set 3 
1 Liigu sümbol tagasi
2 Kustuta sümbol kursori tagant
3 Lõika jooksva sõna algusest kursorini - salvesta lõikepuhvris
4 Lõika rea algusest kursorini - salvesta lõikepuhvris
5 Liigu jooksva sõna algusse
6 Liigu rea algusse
7 Tähed kursorist kuni sõnalõpuni suurteks
8 Vi muuda kursori aluse sümboli suurust ja liigu sümbol edasi
9 Vi muuda realõpuni
10 Puhasta ekraan jättes jooksva rea ülemiseks
11 Täienda jooksev sõna
12 Vali täiendusi liikudes nimekirjas edasi
13 Vali täiendusi liikudes nimekirjas tagasi
14 Täienda jooksev sõna, ignoreeri programmeeritud täiendusi
15 Kopeeri jooksev sõna kursorini
16 Kopeeri ala märgist kursorini lõikepuhvrisse
17 Avalda eelneva sõnani, millele see on prefiks
18 Kustuta sümbol kursori alt
19 Kustuta sümbol kursori alt või teata tühja rea korral faililõpust
20 Kustuta sümbol kursori alt või rea lõpu korral näita täiendusi
21 Kustuta sümbol kursori alt, näita täiendusi või teata faililõpust
22 Lõika kursorist jooksva sõna lõpuni - salvesta lõikepuhvris
23 Kui alustatud, lisab argumendile, muidu lisab numbri
24 Number, mis alustab argumenti
25 Liigu järgmisele ajaloo reale
26 Sümbolid väiketähtedeks kursorist jooksva sõna lõpuni
27 Näita faililõppu
28 Kursor realõppu
29 Vaheta kursor ja märk
30 Avalda faili nimes metasümbolid
31 Avalda ajaloo käsud
32 Avalda real ajaloo käsud
33 Avalda muutujad
34 Liigu sümbol edasi
35 Liigu edasi jooksva sõna lõppu
36 Vaheta kursori ees kaks sümbolit
37 Otsi ajaloos tagasi jooksva rea algusega rida
38 Otsi ajaloos edasi jooksva rea algusega rida
39 Lisa eelmise käsu viimane element
40 Inkrementaalne edaspidi otsing
41 Inkrementaalne tagurpidi otsing
42 Puhasta rida
43 Lõika realõpuni ja salvesta lõikepuhvris
44 Lõika ala märgist kursorini ja salvesta lõikepuhvris
45 Lõika kogu rida ja salvesta lõikepuhvris
46 Näita täiendamise valikud
47 Näita täiendamise valikuid ignoreerides programmeeritud täiendusi
48 Näita faili nimes metasümbolite leide
49 Näita täiendamise valikuid või teavita tühja rea korral faililõpust
50 Näita masina koormust ja jooksva protsessi olekut
51 Avalda ajaloo käsud ja lisa tühik
52 Täida käsklus
53 Avalda failiteed, eemaldades algusest . ja ..
54 Avalda käsk failiteeks või aliaseks
55 Lülita lisamis- või ülekirjutamismood
56 Lisa järgmisele kirjutatavale sümbolile kaheksas bitt
57 Lisa järgmine kirjutatav sümbol reale kvoodituna
58 Näita kõik uuesti
59 Taaskäivita peatatud toimeti
60 Esita jooksva käsu abiinfo
61 See sümbol lisatakse reale
62 See sümbol on sümboljärjendis esimene
63 Sea märk
64 Paranda jooksva sõna õigekirja
65 Paranda terve rea õigekirja
66 Saada sümbol terminalile vahendusmoodis
67 Lülita ajaloo literaalne või leksiline mood
68 Vaheta kursori alune ja kursorist vasakul asuvad sümbolid
69 Vaheta kursori ees kaks sümbolit
70 Tty viivitusega peatamine sümbol
71 Tty tühjenda väljund sümbol
72 Tty katkesta sümbol
73 Tty välju sümbol
74 Tty peata sümbol
75 Tty luba väljund sümbol
76 Tty keela väljund sümbol
77 Tähistab sidumata sümbolit
78 Emacsi universaalne argument (argument korda 4)
79 Liigu eelmisele ajaloo reale
80 Sümbolid suurtähtedeks kursorist jooksva sõna lõpuni
81 Vi liigu järgmise sõna algusse
82 Vi sisene peale kursorit lisamismoodi
83 Vi sisene rea lõpus lisamismoodi
84 Vi muuda kursori aluse sümboli suurust ja liigu ühe sümboli võrra edasi
85 Vi muuda prefiks käsklust
86 Vi muuda realõpuni
87 Sisene vi käsumoodi (kasuta alternatiivseid klahvi seoseid)
88 Vi käsu mood täienda jooksev sõna
89 Vi liigu eelmisele sümbolile (backspace)
90 Vi kustuta prefiks käsklus
91 Vi liigu jooksva tühikuga eraldatud sõna lõppu
92 Vi liigu jooksva sõna lõppu
93 Vi liigu tagasi määratud sümbolini
94 Vi liigu edasi määratud sümbolini
95 Vi liigu tagasi määratud sümbolile
96 Vi liigu edasi määratud sümbolile
97 Sisene vi lisamismoodi
98 Sisene rea alguses vi lisamismoodi
99 Vi korda antud sümboli otsimist samas suunas
100 Vi korda antud sümboli otsimist vastupidises suunas
101 Vi korda antud otsimist samas suunas
102 Vi korda antud otsimist vastupidises suunas
103 Vi asenda kursori alt sümbol järgmisena kirjutatava sümboliga
104 Vi asendusre¸iim 
105 Vi otsi ajaloost tagurpidi
106 Vi otsi ajaloost edaspidi
107 Vi asenda kursori alune sümbol ja mine sisesamisre¸iimi
108 Vi asenda kogu rida
109 Vi mine eelmise sõna juurde
110 Vi mine järgmise sõna juurde
111 Vi taasta viimane muutus
112 Vi mine rea algusse
113 Käivita jooksval sõnal käsk which
114 Kleebi lõikepuhver alates kursori positsioonist
115 Replace just-yanked text with yank from earlier kill
116 (WIN32 only) Copy cut buffer to system clipboard
117 (WIN32 only) Paste clipboard buffer at cursor position
118 (WIN32 only) Convert each '/' in next word to '\\\\'
119 (WIN32 only) Convert each '/' in previous word to '\\\\'
120 (WIN32 only) Page visible console window up
121 (WIN32 only) Page visible console window down
$ $tcsh: set30,v 1.3 2011/02/04 18:19:33 christos Exp $
$ tw.parse.c
$set 30 
1 starting_a_command %d\n
2 complete %d 
3 complete %d %S\n
4 %s: Internal match error.\n
5 elementi
6 veergu
7 Leidsin %d %s, näitan neid? [e/j] 
8 looking = %d\n
9 \n%s sisemine viga: Ma ei tea, mida ma otsin!\n
10 pole kataloog
11 pole leitav
12 loetamatu
13 jJ
$ $tcsh: set31,v 1.2 2006/03/02 18:46:45 christos Exp $
$ vms.termcap.c
$set 31 
1 TERMCAP ei saa avada: [%s]\n
2 %s ei saa avada.\n
3 Leidsin %s failis %s.\n
4 %s pole failis %s\n
$ $tcsh: set4,v 1.3 2011/02/04 18:19:33 christos Exp $
$ Termcap strings
$set 4
1 lisa uus tühi rida
2 kuuldav kell
3 puhasta põhjani
4 puhasta rea lõpuni
5 kursori horisontaal positsioon
6 ekraani puhastamine
7 sümboli kustutamine
8 rea kustutamine
9 alusta kustutamis mood
10 lõpeta kustutamis mood
11 lõpeta vahelekirjutamise mood
12 kursor olekurealt
13 kursor koju
14 lisa sümbol
15 alusta vahelekirjutamise mood
16 lisa täide
17 saadab kursori alla
18 saadab kursori vasakule
19 saadab kursori paremale
20 saadab kursori üles
21 alusta rasvast
22 atribuutide lõpp
23 mitte-purustav tühik
24 lõpeta rõhutatud
25 alusta rõhutatud
26 kursor olekureale
27 kursor ühe võrra üles
28 alusta allajoonimist
29 lõpeta allajoonimine
30 nähtav kell
31 kustuta mitu sümbolit
32 kursor korduvalt alla
33 lisa mitu sümbolit
34 kursor korduvalt vasakule
35 kursor korduvalt paremale
36 kursor korduvalt üles
37 Omab automaatseid ääri
38 Saab kasutada füüsilist tabulaatorit
39 Ridade arv
40 Veergude arv
41 Omab meta klahvi
42 Parem äär ignoreerib uut rida
$ $tcsh: set5,v 1.3 2011/02/04 18:19:33 christos Exp $
$ ed.chared.c
$set 5
1 Tööjärjekorra koormuse info puudub\n
$ $tcsh: set6,v 1.3 2011/02/04 18:19:33 christos Exp $
$ ed.inputl.c
$set 6
1 VIGA: vigane käsk klahvilt 0%o\r\n
2 jah\n
3 paranda\n
4 katkesta\n
5 ei\n
6 Pole sellist käsku\n
7 Arusaamatu käsk\n
8 *** toimeti fataalne VIGA ***\r\n\n
$ $tcsh: set7,v 1.3 2011/02/04 18:19:33 christos Exp $
$ ed.screen.c
$set 7
1 \n\tTcsh arvab, et teie terminal omab\n
2 \tjärgnevaid omadusi:\n\n
3 \tTal on %d veergu ja %d rida\n
4 \tTa %s meta klahvi\n
5 omab
6 ei oma
7 \tTal on%s tabulaatori omadus\n
8  puudu
9 \tTa %s automaatseid ääri\n
10 omab
11 ei oma
12 \tTa %s maagilisi ääri\n
13 (tühi)
14 jah
15 ei
16 VIGA: ei saa kustutada\r\n
17 DeleteChars: num on mõttetu: %d\r\n
18 VIGA: cannot insert\r\n
19 StartInsert: num on mõttetu: %d\r\n
20 %s: Ei saa avada /etc/termcap.\n
21 %s: Terminali tüübil "%s" puudub kirje\n
22 %s: kasutan rumala terminali seadeid.\n
23 %s: HOIATUS: Teie terminal ei saa liikuda üles.\n
24 Pikkade ridade toimetamine võib olla kummaline.\n
25 puudub puhasta EOL omadus.\n
26 puudub kustuta sümbol omadus.\n
27 puudub lisa sümbol omadus.\n
$ $tcsh: set8,v 1.3 2011/02/04 18:19:34 christos Exp $
$ ed.term.c
$set 8
1 Tundmatu võti
2 Vigane argument
$ $tcsh: set9,v 1.3 2011/02/04 18:19:34 christos Exp $
$ ed.xmap.c
$set 9
1 AddXkey: Null pikkusega laiend-klahv ei ole lubatud.\n
2 AddXkey: käsuni viiv järjend pole lubatud\n
3 DeleteXkey: Null pikkusega laiend-klahv ei ole lubatud.\n
4 Sidumata laiendatud klahv "%S"\n
5 Mõned laiendatud klahvid on sisemise trükipuhvri jaoks liiga pikad
6 Enumerate: BUG!! Null viit anti\n!
7 sisendit pole
8 Midagi peab järgnema: %c\n
9 kaheksand-konstant ei mahu sümbolisse.\n
