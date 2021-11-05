# Documentation Zappy

Vous trouverez ici toutes les informations nécessaires à l'utilisation du programme.


# Utilisation du programme

## Lancement

> Serveur

    USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
     port	 is the port number
     width is the width of the world
     height is the height of the world
     nameX is the name of the team X
     clientsNb is the number of authorized clients per team
     freq is the reciprocal of time unit for execution of actions

> GUI

	./zappy_ai -p port -h machine
    port	 is the port number
    machine	 is the name of the machine; localhost by default

> IA

    USAGE: ./zappy_ai -p port -n name -h machine
    port	 is the port number
    name	 is the name of the team
    machine	 is the name of the machine; localhost by default

## ✅ Utilisation recommandée

	- Lancer le serveur avec une taille carré et non rectangulaire.
	- Lancer dans cet ordre: Serveur -> GUI -> AI


# Informations sur le projet
>  Protocole utilisé: TCP & String avec \n

## Commandes

```
| action                	| Command           	| Time Limit      |
| -----------------------------	|:---------------------:| --------------: |
| move up one tile      	| Forward 	    	| 7/f		  |
| turn 90° right      		| Right      	    	| 7/f		  |
| turn 90° left     		| Left 		    	| 7/f		  |
| look around      		| Look 			| 7/f		  |
| inventory   			| Inventory      	| 1/f		  |
| broadcast text  		| Broadcast text 	| 7/f		  |
| nb of team unused slots   	| Connect_nbr 		| 7/f		  |
| fork a player     		| Fork      		| 42/f		  |
| eject players from tile   	| Eject 		| 7/f		  |
| take object     		| Take object 		| 7/f		  |
| set object down     		| Set object      	| 7/f		  |
| start incantation    		| Incantation 		| 300/f		  |
```

## Auteurs

👤 **Achille Bourgault**

* Github: [@achillebourgault](https://github.com/achillebourgault)
* LinkedIn: [@achille-bourgault](https://fr.linkedin.com/in/achille-bourgault-266514177)

👤 **Frédéric Lawecki--Walkowiak**

* Github: [@fredericlw](https://github.com/fredericlw)
* LinkedIn: [@frederic-lawecki-walkowiak](https://www.linkedin.com/in/frederic-lawecki-walkowiak/)
