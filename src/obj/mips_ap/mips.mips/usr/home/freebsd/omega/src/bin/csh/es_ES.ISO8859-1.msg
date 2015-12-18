$ codeset=UTF-8
$set 255
1 UTF-8
$ $tcsh: set1,v 1.4 2011/02/04 18:19:42 christos Exp $
$ Mensajes de Error
$set 1 
1 Error de sintaxis
2 %s no está permitido
3 Palabra demasiado larga
4 $< línea demasiado larga
5 No hay fichero para $0
6 Modificador [] incompleto
7 $ expansión debe terminar antes de ]
8 Modificador erróneo : en $ (%c)
9 Error de índice
10 Número erróneamente formado
11 No hay más palabras
12 Falta nombre de fichero
13 Error interno de glob
14 Comando no encontrado
15 Demasiado pocos argumentos
16 Demasiados argumentos
17 Es demasiado peligroso crear un alias para eso
18 `If' vacío
19 `Then' incorrecto
20 Las palabras no están entre paréntesis
21 No se encuentra %s
22 Máscara incorrecta
23 No existe límite de ese tipo
24 Argumento demasiado grande
25 Factor de escala incorrecto o desconocido
26 Variable indefinida
27 La pila de directorios no es tan profunda
28 Mal número de señal
29 Señal desconocida; `kill -l' lista las señales
30 El nombre de la variable debe comenzar con una letra
31 El nombre de la variable es demasiado grande
32 El nombre de la variable debe contener caracteres alfanuméricos
33 No hay control de trabajos en esta shell
34 Sintaxis de la expresión
35 No está el directorio personal
36 No se puede cambiar al directorio personal
37 Comando nulo inválido
38 Expresion carece de asignación
39 Operador desconocido
40 Ambiguo
41 %s: Archivo existente
42 El argumento para `-c' debe terminar en una barra invertida
43 Interumpido
44 Índice fuera del rango válido
45 Sobrepasada la capacidad de la línea
46 No existe ese trabajo
47 No se puede desde una terminal
48 No se encuentra en bucle while/foreach
49 No hay más procesos
50 No existe correspondencia
51 Falta %c
52 No se ha hallado correspondencia con %c
53 Memoria insuficiente
54 No se puede crear la tubería
55 %s: %s
56 %s
57 Uso: jobs [ -l ]
58 Los argumentos deben ser trabajos o identificadores de proceso
59 No hay trabajo en curso
60 No hay trabajo previo
61 No hay trabajo que corresponda con este patrón
62 Llamadas a `fork' entrelazadas > %d; puede ser un bucle `...`
63 No se puede gestionar trabajos en sub-shells 
64 Fallo de sincronización: No se encuentra el proceso %d
65 %shay trabajos interrumpidos
66 %shay trabajos parados
67 No hay más directorios
68 Pila de directorios vacía
69 Directorio erróneo
70 Uso: %s [-%s]%s
71 `-h' necesita operandos
72 No es un shell de ingreso
73 División por 0
74 Módulo por 0
75 Error de escala: Seguro que era "%s"?
76 No se puede suspender un shell de ingreso (aún)
77 Usuario desconocido: %s
78 La variable $home no está definida
79 Uso: history [-%s] [# número de comandos]
80 No esta permitido el uso de $, ! o < con $# o $?
81 Nombre de variable incluye un retorno de carro
82 No esta permitido el uso de * con  $# o $?
83 No esta permitido usar $?<dígito> o $#<dígito>
84 Nombre de variable ilegal
85 Retorno de carro en el índice de variables
86 Desborde en el buffer de expansión
87 Sintaxis de variable
88 Forma ! incorrecta
89 No existe sustituto previo
90 Sustituto erróneo
91 No existe `lado izquierdo' previo
92 Valor de asignación demasiado largo
93 Modificador de ! incorrecto: %c
94 Error de modificador
95 Desborde el el buffer de sustitución
96 Selector de argumento de ! erróneo
97 No existe búsqueda previa
98 %s: No se encuentra el comando
99 Demasiados `)'
100 Demasiados `('
101 Colocación de `(' incorrecta
102 Falta el nombre de la redirección
103 Redirección de salida ambigua
104 No se puede usar << entre paréntesis
105 Redirección de entrada ambigua
106 Colocación de paréntesis errónea
107 Lazo en los `alias'
108 La variable $watch no ha sido definida
109 No hay comandos programados
110 Uso: sched -<item#>.\nUso: sched [+]hh:mm <comando>
111 No hay tantos comandos programados
112 No hay ningún comando a ejecutar
113 Tiempo de ejecución del comando incorrecto
114 Tiempo relativo inconsistente con am/pm
115 Se ha agotado el espacio para cadenas termcap
116 Uso: settc %s [yes|no]
117 Característica `%s' desconocida
118 Parámetro termcap `%%%c' desconocido
119 Demasiados argumentos para `%s' (%d)
120 `%s' requiere %d argumentos
121 Uso: echotc [-v|-s] [<característica> [<args>]]
122 %s: %s. Arquitectura errónea
123 !# Lazo en el historial
124 Consulta de archivo incorrecta
125 Desborde en el selector
126 Opción desconocida: `-%s'\nUso: %s [ -bcdefilmnqstvVxX -Dnombre[=valor] ] [ argumento ... ]
127 Opción desconocida: `-%s'\nUso: %s [ -bcdefFilmnqstvVxX ] [ argumento ... ]
128 Opción desconocida: `-%s'\nUso: %s [ -bcdefilmnqstvVxX ] [ argumento ... ]
129 \nModo de terminación automática inválido: "%s"
130 \nInválido %s: '%c'
131 \nFalta el separador '%c' después %s "%s"
132 \n%s incompleto: "%s"
133 `-m' no necesita operandos
134 Uso: unlimit [-fh] [límites]
135 $%S es de sólo-lectura
136 No existe ese trabajo
137 Unknown colorls variable `%c%c'
$ $tcsh: set10,v 1.3 2011/02/04 18:19:42 christos Exp $
$ ma.setp.c
$set 10 
1 setpath: comando '%s' incorrecto.\n
2 setpath: insuficientes argumentos para el comando '%s'.\n
3 setpath: falta el valor en la ruta '%s'\n
4 setpath: no se encuentra %s en %s\n
5 setpath: %d posición inválida en %s\n
$ $tcsh: set11,v 1.2 2006/03/02 18:46:48 christos Exp $
$ sh.c
$set 11 
1 Aviso: no se puede acceder a la tty (%s).\n
2 Por ello no hay control de trabajos en esta shell.\n
3 Tiene %d mensajes de correo.\n
4 Tiene %d mensajes de correo en %s.\n
5 Tiene correo%s.\n
6  nuevo
7 Tiene correo%s en %s.\n
$ $tcsh: set12,v 1.2 2006/03/02 18:46:48 christos Exp $
$ sh.dir.c
$set 12 
1 %s: Tratando de empezar desde "%s"\n
$ $tcsh: set13,v 1.3 2011/02/04 18:19:42 christos Exp $
$ sh.exec.c
$set 13 
1 hash=%-4d dir=%-2d prog=%s\n
2 %d grupos de hash de %d bits cada uno\n
3 máscara de depurado = 0x%08x\n
4 %d aciertos, %d fallos, %d%%\n
5 %S: comando integrado en la shell.\n
6 %S: Comando inexistente.\n
7 donde: / en el comando carece de sentido\n
8 %S es un alias para 
9 %S es un comando integrado en la shell\n
10 fallo de hash: 
$ $tcsh: set14,v 1.3 2011/02/04 18:19:42 christos Exp $
$ sh.file.c
$set 14 
1 \n¡¡Qué asco!! ¡¡Hay demasiados %s!!\n
2 nombres en el archivo de claves
3 archivos
$ $tcsh: set15,v 1.3 2011/02/04 18:19:42 christos Exp $
$ sh.func.c
$set 15 
1 %s: %s: No se puede %s el límite %s\n
2 quitar
3 poner
4 \040(hard-limit)
$ $tcsh: set16,v 1.3 2011/02/04 18:19:43 christos Exp $
$ sh.lex.c
$set 16 
1 Se ha reinicializado el grupo de procesos de las terminales de %d a %d\n
2 \nUtilice "logout" para desconectarse.\n
3 \nUtilice "exit" para salir de %s.\n
4 seek to eval %x %x\n
5 seek to alias %x %x\n
6 seek to file %x\n
7 Tipo de seek erróneo %d\n
8 tell eval %x %x\n
9 tell alias %x %x\n
10 tell file %x\n
$ $tcsh: set17,v 1.4 2011/02/04 18:19:43 christos Exp $
$ sh.proc.c
$set 17 
1 BUG: ¡en espera de un trabajo en segundo plano!\n
2 Finalizó %d\n
3 BUG: Se ha aplicado "flush" al proceso por segunda vez
4 Ejecutando 
5 Señal 
6 Finalizado %-25d
7 Fin
8 BUG: status=%-9o
9 \040(se ha creado un `core')
10 \040(dt:
11 dt actual: 
12 %S: Ya ha sido suspendido\n
13 %S: Ya ha sido parado\n
14 %S: Badly formed number\n
$ $tcsh: set18,v 1.3 2011/02/04 18:19:43 christos Exp $
$ sh.set.c
$set 18 
1 Aviso: PATH de tamaño ridículo ha sido truncado\n
$ $tcsh: set19,v 1.5 2011/02/25 23:58:08 christos Exp $
$ tc.alloc.c
$set 19 
1 nbytes=%d: Se ha agotado la memoria\n
2 Se ha llamado a free(%lx) antes de asignar nada.
3 free(%lx) por encima del límite superior de la memoria.
4 free(%lx) por debajo del límite inferior de la memoria.
5 free(%lx) bloque erróneo.
6 free(%lx) chequeo de rango erróneo.
7 free(%lx) índice de bloque erróneo.
8 %s asignación actual de memoria:\nfree:\t
9 usada
10 \n\tTotal en uso: %d, total libre: %d\n
11 \tSe ha asignado memoria de  0x%lx a 0x%lx.  Límite superior real en 0x%lx\n
12 Se ha asignado memoria de 0x%lx a 0x%lx (%ld).\n
13 %s current memory allocation:\n
14 Total space allocated from system: %d\n
15 Number of non-inuse chunks: %d\n
16 Number of mmapped regions: %d\n
17 Total space in mmapped regions: %d\n
18 Total allocated space: %d\n
19 Total non-inuse space: %d\n
20 Top-most, releasable space: %d\n
$ $tcsh: set2,v 1.3 2011/02/04 18:19:43 christos Exp $
$ Nombres de señales
$set 2 
1 Señal nula
2 Colgar
3 Interrumpir
4 Salir
5 Instrucción ilegal
6 trap Trace/BPT
7 Abortar
8 trap IOT
9 Caída del sistema inminente
10 Salida con error
11 trap EMT
12 Excepción de punto flotante
13 Terminado
14 Señal de usuario 1
15 Señal de usuario 2
16 Error de segmentación
17 Error de bus
18 Error de rango de programa
19 Error de rango de operando
20 Llamada del sistema errónea
21 Tubería rota
22 Despertador
23 Terminado
24 Cambio de estado en el hijo
25 Muerte del hijo
26 Fallo específico de Apollo
27 El hijo ha parado o terminado
28 Hijo ha terminado
29 Fallo de alimentación
30 Recurso perdido
31 Break (Ctrl-Break)
32 Posible señal de entrada/salida
33 E/S asíncrona (select)
34 Condición urgente en el canal de E/S
35 Despertar mutiltarea
36 Finalización multitarea
37 Final de E/S asíncrona Fortran
38 Recuperación
39 Error incorregible de memoria
40 Excedido el tiempo de CPU
41 Bajada del sistema inminente
42 Grupo micro-tarea-no se ha activado la bandera de despertar
43 Error de hilo de ejecución - (use cord -T para información detallada)
44 Error de paridad de registro CRAY Y-MP
45 Petición de información
46 Suspendido (señal)
47 Parado (señal)
48 Suspendido
49 Parado
50 Continúa
51 Suspendido (entrada tty)
52 Parado (entrada tty)
53 Suspendido (salida tty)
54 Parado (salida tty)
55 Modificado el estado de la ventana
56 Modificado el tamaño de la ventana
57 Modificado el estado del teléfono
58 Excedido el tiempo de CPU
59 Excedido el límite del tamaño de archivo
60 Señal de temporizador virtual
61 Perfilando la alarma de temporizador
62 Señal DIL
63 Ha tenido lugar un evento interrogable
64 Los lwps del proceso están bloqueados
65 Señal LWP especial
66 Señal CPR especial
67 Señal CPR especial
68 Primera señal de tiempo real
69 Segunda señal de tiempo real
70 Tercera señal de tiempo real
71 Cuarta señal de tiempo real
72 Cuarta señal por la cola de tiempo real
73 Antepenúltima señal de tiempo real
74 Penúltima señal de tiempo real
75 Última señal de tiempo real
76 E/S asíncrona LAN
77 Lectura/escritura PTY disponible
78 Intervención E/S requerida
79 Otorgado modo monitor HFT
80 Se debería abandonar el modo monitor HFT
81 Se ha completado el control de sonido HFT
82 Hay datos en el buffer circular HFT
83 Migrar proceso
84 Tecla de atención asegurada
85 Reprogramación
86 Señalar SS$_DEBUG
87 Prioridad cambiada
88 Bloqueo real detectado
89 Nuevo carácter de entrada
$ $tcsh: set20,v 1.4 2011/02/04 18:19:43 christos Exp $
$ tc.bind.c
$set 20 
1 Nombre de tecla no válido `%S'\n
2 Nombre de tecla incorrecto: %S\n
3 Nombre de comando incorrecto: %S\n
4 Especificador de tecla incorrecto %S\n
5 Especificada la cadena nula\n
6 Definiciones de teclas estándar\n
7 Definiciones de teclas alternativas\n
8 Definiciones Multi-carácter\n
9 Definiciones de las teclas de flechas\n
10 %-15s->  indefinida\n
11 ¡¡¡BUG!!! %s no tiene definición asociada.\n
12 Uso: bindkey [opciones] [--] [TECLA [COMANDO]]\n
13     -a   lista o define TECLA en un mapa de teclas alternativo\n
14     -b   acepta definiciones de teclas simbólicas\n
15     -s   asume que COMANDO es una cadena ha de imprimir literalmente\n
16     -c   interpreta COMANDO como comando interno o externo\n
17     -v   usa las definiciones del editor vi\n
18     -e   usa las definiciones del editor vi\n
19     -d   usa las definiciones del editor por defecto\n
20     -l   lista los comandos del editor y sus descripciones\n
21     -r   elimina la definición asociada a TECLA\n
22     -k   interpreta TECLA como nombre simbólico de tecla de flecha\n
23     --   fuerza "break" en el procesamiento de opciones\n
24     -u   (o cualquier opción no válida) este mensaje\n
25 Sin TECLA o COMANDO, imprime todas las asociaciones de teclas\n
26 Sin COMANDO, imprime la asociación de TECLA.\n
27 especificación de tecla inválida -- cadena nula\n
28 especificación de tecla inválida -- cadena vacía\n
29 Especificación de tecla de función inválida. No se permite una tecla nula\n
30 especificación de tecla inválida -- número hexadecimal incorrecto\n
31 especificación de tecla inválida -- número octal incorrecto\n
32 especificación de tecla inválida -- número decimal incorrecto\n
33 Especificación de tecla de función incorrecta.\n
34 No se permite una tecla nula\n
35 especificación de tecla inválida -- nombre desconocido "%S"\n
36 uso: bind [TECLA | COMANDO TECLA | "emacs" | "vi" | "-a"]\n
37 función no válida
38  %s\t\tno está definida\n
$ $tcsh: set21,v 1.2 2006/03/02 18:46:48 christos Exp $
$ tc.disc.c
$set 21 
1 No he podido leer los caracteres locales.\n
2 No he podido establecer los caracteres locales.\n
$ $tcsh: set22,v 1.3 2011/02/04 18:19:43 christos Exp $
$ tc.func.c
$set 22 
1 %S: \t es un alias de 
2 \nClave incorrecta para %s\n
3 Alias erróneo de 'precmd' borrado.\n
4 Alias erróneo de 'cwdcmd' borrado.\n
5 Alias erróneo de 'beepcmd' borrado.\n
6 Alias erróneo de 'periodic' borrado.\n
7 analizando la línea de comandos\n
8 ¿Realmente quiere borrar todos los archivos? [n/s]
9 ¡Anulado el borrado de los archivos!\n
10 ahora, la línea de comandos es:\n
11 analizando la línea de comandos\n
12 en una de las listas\n
13 ahora, la línea de comandos es:\n
14 sSyY
$ $tcsh: set23,v 1.3 2011/02/04 18:19:43 christos Exp $
$ tc.os.c
$set 23 
1 Nombre de cpu/máquina incorrecto
2 Ruta hasta máquina demasiado grande
3 desconocida
4 máquina: %s\n
5 %d: No he encontrado esa máquina\n
6 setlocal: %s: %s\n
7 No he encontrado esa máquina
8 Está atrapado en un universo que nunca creo
9 Getwarp falló
10 Warp inválido
11 Setwarp falló
12 Universo ilegal
13 Error Desconocido: %d
14 nombre_sis:  %s\n
15 nombre_nodo: %s\n
16 release:  %s\n
17 versión:  %s\n
18 máquina:  %s\n
19 getwd: No puedo abrir ".." (%s)
20 getwd: No puedo cambiar a ".." (%s)
21 getwd: Error de lectura en ".." (%s)
22 getwd: No puedo volver a "." (%s)
23 getwd: No puedo ejecutar stat de "/" (%s)
24 getwd: No puedo ejecutar stat de "." (%s)
25 getwd: No puedo ejecutar stat de "%s" (%s)
26 getwd: No puedo abrir el directorio "%s" (%s)
27 getwd: No puedo encontrar "." en ".." (%s)
28 Tipo de sistema inválido
29 No se ha fijado el tipo de sistema
30 Demasiados argumentos
31 Argumento inválido
$ $tcsh: set24,v 1.2 2006/03/02 18:46:48 christos Exp $
$ tc.sched.c
$set 24 
1 chapuza
$ $tcsh: set25,v 1.3 2011/02/04 18:19:43 christos Exp $
$ tc.sig.c
$set 25 
1 nuestro wait %d\n
2 error: bsd_signal(%d) señal fuera de rango\n
3 error: bsd_signal(%d) - sigaction ha fallado, errno %d\n
$ $tcsh: set26,v 1.3 2011/02/04 18:19:43 christos Exp $
$ tc.who.c
$set 26 
1 No se puede completar stat %s.  Por favor, ejecute "unset watch".\n
2 No se puede abrir %s.  Por favor, ejecute "unset watch".\n
3 ¡BUG! El último elemento no es whotail!\n
4 hacia atrás: 
5 ¡BUG! El primer elemento no es whohead!\n
6 nuevo: %s/%s\n
7 %n tiene %a %l de %m.
8 %n tiene %a %l.
9 conectado
10 desconectado
11 sustituido %s en
12 local
$ $tcsh: set27,v 1.3 2011/02/04 18:19:43 christos Exp $
$ tw.comp.c
$set 27 
1 comando
2 separador
3 patrón
4 rango 
5 modo de terminación automática
$ $tcsh: set29,v 1.2 2006/03/02 18:46:48 christos Exp $
$ tw.help.c
$set 29 
1 No hay archivo de ayuda sobre %S\n
$ $tcsh: set3,v 1.4 2011/02/04 18:19:43 christos Exp $
$ Descripción de las funciones de edición
$set 3 
1 Retroceder un carácter
2 Borrar el carácter detrás del cursor
3 Cortar desde el comienzo de la palabra hasta el cursor - se guarda en el buffer
4 Cortar desde el comienzo de la línea hasta el cursor - se guarda en el buffer
5 Ir hasta el comienzo de la palabra
6 Ir hasta el comienzo de la línea
7 Convertir en mayúsculas los caracteres desde el cursor hasta el final de la palabra
8 Vi: cambiar a mayúsculas o minúsculas el carácter bajo el cursor y avanza una posición
9 Vi: cambia hasta el final de la línea
10 Borra la pantalla y coloca la línea actual al comienzo
11 Completa la palabra
12 Avanza mediante `Tab' por los ficheros
13 Retrocede mediante `Tab' por los ficheros
14 Completa la palabra ignorando los modos programables
15 Copia la palabra hasta el cursor
16 Copia el área entre la marca y el cursor al buffer
17 Expande a aquella palabra para la que esto es un prefijo
18 Borra el carácter bajo el cursor
19 Borra el carácter bajo el cursor o señala el fin de archivo en un archivo vacío
20 Borra el carácter bajo el cursor o lista posibles finales si está al final de una línea
21 Borra el carácter bajo el cursor, lista posibles finales o marca final de archivo
22 Corta del cursor al final de la palabra - se guarda en el buffer
23 Se suma al argumento si ha arrancado o introduce el dígito
24 Dígito al comienzo del argumento
25 Ir al final de la línea de historia
26 Convierte en minúsculas los caracteres desde el cursor al final de la palabra
27 Indica el fin de archivo
28 Mover el cursor hasta el final de línea
29 Intercambia el cursor y la marca
30 Expande los comodines de nombre de archivo
31 Expande los escapes del historial
32 Expande los escapes del historial en una línea
33 Expande variables
34 Avanza un carácter
35 Avanza hasta el final de la palabra
36 Intercambia los dos caracteres delante del cursor
37 Busca hacia atrás en el historial una línea que comience igual que la actual
38 Busca hacia delante una línea que comience igual que la actual
39 Inserta el último ítem del comando previo
40 Búsqueda incremental hacia deleante
41 Búsqueda incremental hacia atrás
42 Borra la línea
43 Corta hasta el final de la línea y guarda la información en el buffer
44 Corta el área de la marca al cursor y guarda la información en el buffer
45 Corta la línea completa y la guarda en el buffer
46 Lista opciones para completar
47 Lista opciones para completar ignorando los modos programables
48 Lista los nombres de archivos que concuerdan con el comodín
49 Lista opciones para completar o indica el final de línea si es una línea vacía
50 Imprime la media de carga y es estado de este proceso
51 Expande los escapes del historial e inserta un espacio
52 Ejecuta el comando
53 Expande rutas, eliminando cualquier `.' y `..' que encuentre al comienzo
54 Expande comandos a la ruta o el alias resultante
55 Cambia de modo de inserción a sobre escritura y vice versa
56 Añade el octavo bit al siguiente carácter introducido
57 Añade el siguiente carácter sin modificar a la línea
58 Reimprime todo
59 Reinicia un editor parado
60 Busca ayuda sobre el comando actual
61 Se añade este carácter a la línea
62 Este carácter es el primero de una secuencia de caracteres
63 Establece una marca bajo el cursor
64 Corrige la ortografía de esta palabra
65 Corrige la ortografía de la línea completa
66 Envía el carácter a la terminal en modo `cooked'
67 Cambia entre los modos literal y léxico en esta línea de historial
68 Intercambia el carácter a la izquierda con el que está bajo el cursor
69 Intercambia los dos caracteres que preceden al cursor
70 Carácter tty para suspensión retrasada
71 Carácter tty para `flush' de salida
72 Carácter tty para interrupción
73 Carácter tty para salida
74 Carácter tty para suspensión
75 Carácter tty para permitir salida
76 Carácter tty para impedir salida
77 Indica carácter no asignado
78 Argumento Emacs universal (argumento por 4)
79 Ir a la línea anterior
80 Convierte en mayúsculas los caracteres desde el cursor al final de la palabra
81 Vi: ir al comienzo de la siguiente palabra
82 Vi: entrar en modo de inserción después el cursor
83 Vi: entrar en modo de inserción al final de la línea
84 Vi: cambia a mayúsculas o minúsculas el carácter bajo el cursor y avanza una posición
85 Vi: cambiar el comando de prefijo
86 Vi: cambiar hasta el final de la línea
87 Entrar en modo vi (usa asignación de teclas alternativa)
88 Vi: modo de comando completa la palabra
89 Vi: ir al carácter previo (retroceso)
90 Vi: borrar el comando de prefijo
91 Vi: ir hasta el final de la palabra delimitado por espacios
92 Vi: ir hasta el final de la palabra
93 Vi: retroceder al carácter especificado
94 Vi: avanzar al carácter especificado
95 Vi: retrocede hasta el carácter especificado
96 Vi: avanzar hasta el carácter especificado
97 Entrar en modo de inserción `vi'
98 Entrar en modo de inserción `vi' al comienzo de la línea
99 Vi: repetir la búsqueda de carácter en la misma dirección
100 Vi: repetir la búsqueda de carácter en la dirección contraria
101 Vi: repetir la búsqueda en la misma dirección
102 Vi: repetir la búsqueda en la dirección contraria
103 Vi: reemplazar el carácter bajo el cursor por el que se introduzca
104 Vi: modo de reemplazo
105 Vi: buscar en el historial hacia atrás
106 Vi: buscar en el historial hacia adelante
107 Vi: reemplazar el carácter bajo el cursor cambiando a modo inserción
108 Vi: reemplazar la línea completa
109 Vi: ir a la palabra anterior
110 Vi: ir a la palabra siguiente
111 Vi: deshacer el cambio anterior
112 Vi: ir al comienzo de la línea
113 Ejecutar `which' para el comando actual
114 Pegar el buffer donde el cursor
115 Replace just-yanked text with yank from earlier kill
116 (WIN32 only) Copy cut buffer to system clipboard
117 (WIN32 only) Paste clipboard buffer at cursor position
118 (WIN32 only) Convert each '/' in next word to '\\\\'
119 (WIN32 only) Convert each '/' in previous word to '\\\\'
120 (WIN32 only) Page visible console window up
121 (WIN32 only) Page visible console window down
$ $tcsh: set30,v 1.3 2011/02/04 18:19:43 christos Exp $
$ tw.parse.c
$set 30 
1 comienzo_de_comando %d\n
2 completar %d 
3 completar %d %S\n
4 %s: Error interno de concordancia.\n
5 ítems
6 filas
7 Existen %d %s, ¿listarlas de todos modos? [n/s] 
8 buscando = %d\n
9 \nerror interno de tcsh: ¡No sé lo que busco!\n
10 no es un directorio
11 no he encontrado nada
12 ilegible
13 sSyY
$ $tcsh: set31,v 1.2 2006/03/02 18:46:48 christos Exp $
$ vms.termcap.c
$set 31 
1 No se puede abrir TERMCAP: [%s]\n
2 No se puede abrir %s.\n
3 He encontrado %s en %s.\n
4 No he encontrado ninguna concordancia con %s en el archivo %s\n
$ $tcsh: set4,v 1.3 2011/02/04 18:19:43 christos Exp $
$ cadenas de Termcap
$set 4
1 añade una línea vacía
2 timbre audible
3 borra hasta abajo
4 borra hasta el final de la línea
5 cursor hasta posición horizontal
6 borra la pantalla
7 borra un carácter
8 borra una línea
9 entra en modo de borrado
10 termina modo de borrado
11 termina modo de inserción
12 cursor de línea de estado
13 cursor en posición inicial
14 insertar carácter
15 entra en modo de inserción
16 inserta carácter de relleno
17 envía cursor hacia abajo
18 envía cursor hacia la izquierda
19 envía cursor hacia la derecha
20 envía cursor hacia arriba
21 comienza negrita
22 fin de atributos
23 espacio no destructivo
24 fin de énfasis
25 comienzo de énfasis
26 cursor a la línea de estado
27 mueve el cursor hacia arriba una línea
28 comienza subrayado
29 fin de subrayado
30 timbre visible
31 borra múltiples caracteres
32 mueve el cursor varias líneas hacia abajo
33 inserta múltiples caracteres
34 mueve el cursor varias líneas hacia la izquierda
35 mueve el cursor varias líneas hacia la derecha
36 mueve el cursor varias líneas hacia arriba
37 Tiene márgenes automáticos
38 Puede usar tabuladores físicos
39 Número de líneas
40 Número de columnas
41 Tiene teclas alternativa
42 Ignorando retorno de carro en el margen derecho
$ $tcsh: set5,v 1.3 2011/02/04 18:19:43 christos Exp $
$ ed.chared.c
$set 5
1 No está disponible la carga media\n
$ $tcsh: set6,v 1.3 2011/02/04 18:19:43 christos Exp $
$ ed.inputl.c
$set 6
1 ERROR: comando ilegal asignado a la tecla 0%o\r\n
2 sí\n
3 editar\n
4 abortar\n
5 no\n
6 No se ha encontrado comando que corresponda\n
7 Comando ambiguo\n
8 *** ERROR fatal del editor ***\r\n\n
$ $tcsh: set7,v 1.3 2011/02/04 18:19:43 christos Exp $
$ ed.screen.c
$set 7
1 \n\tTcsh cree que su terminal tiene las\n
2 \tsiguientes características:\n\n
3 \tTiene %d columnas y %d líneas\n
4 \t%s tecla `Alt'\n
5 Tiene
6 No tiene
7 \t%spuede usar tabuladores\n
8 No
9 \t%s márgenes automáticos\n
10 Tiene
11 No tiene
12 \t%s márgenes mágicos\n
13 (vacío)
14 sí
15 no
16 ERROR: no se puede suprimir\r\n
17 DeleteChars: num es ridículo: %d\r\n
18 ERROR: no se puede insertar\r\n
19 StartInsert: num es ridículo: %d\r\n
20 %s: No se puede abrir /etc/termcap.\n
21 %s: No hay ninguna entrada correspondiente a la terminal tipo "%s"\n
22 %s: usando los valores de una terminal tonta.\n
23 %s: Aviso: Su terminal no puede moverse hacia arriba.\n
24 La edición de líneas largas puede resultar extraña.\n
25 no se puede borrar hasta el final de línea.\n
26 no se puede borrar el siguiente carácter.\n
27 no se puede insertar un carácter.\n
$ $tcsh: set8,v 1.3 2011/02/04 18:19:43 christos Exp $
$ ed.term.c
$set 8
1 Interruptor desconocido
2 Argumento inválido
$ $tcsh: set9,v 1.3 2011/02/04 18:19:43 christos Exp $
$ ed.xmap.c
$set 9
1 AddXkey: No se permite una tecla extendida nula.\n
2 AddXkey: No se permite comando introducción de secuencia (sequence-lead-in)\n
3 DeleteXkey: No se permite una tecla extendida nula.\n
4 Tecla de extendida indefinida "%S"\n
5 Algunas teclas extendidas son demasiado grandes para el buffer de impresión interno
6 Enumerate: ¡¡BUG!! Se ha pasado un puntero nulo!\n
7 no hay entrada
8 Falta algo a continuación: %c\n
9 Una constante octal no cabe en un carácter.\n
