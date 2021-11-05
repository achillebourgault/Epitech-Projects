# MyTeams (Clone Microsoft Teams)

> Ce projet consiste à heberger un serveur sur le port **P** et permettre à **N** clients de s'y connecter pour pouvoir communiquer.
<br>Les clients peuvent envoyer des **messages privés**, creer un **Channel**, une **Team**, un **Thread**, et poster des **Messages** sur ces derniers.

## Documentation

| Categories  | Document |
| ------------- |:-------------:|
| Requêtes _Client_ <-> _Serveur_    | [.txt](https://github.com/achillebourgault/Epitech-Projects/blob/main/B-NWP-400%20-%20MyTeams/doc/Requetes%20client%20serveur.txt)     |
| Systeme de _Stockage_              | [.txt](https://github.com/achillebourgault/Epitech-Projects/blob/main/B-NWP-400%20-%20MyTeams/doc/Systeme%20de%20stockage.txt)     |

## Utilisation

> Build Client & Server

```sh
make
```

### Serveur

> Lancement depuis un terminal
```sh
./myteams_server <port>
```

### Client

> Lancement depuis un terminal
```sh
./myteams_client <ip> <port>
```

##Requêtes Client / Serveur

> Les commandes disponnibles pour le client:

	• /help : affiche l'aide
	• /login "username" : se connecter avec le nom d'utilisateur défini entre guillemets
	• /logout : se déconnecter
	• /users : lister tous les utilisateurs qui existent
	• /user "user_uid" : obtenir les informations pour l'utilisateur dont l'identifiant unique est donné entre guillemets
	• /send "user_uid" "message" : envoyer le message privé donné en second argument entre guillemets à l'utilisateur dont l'identifiant unique est donné en premier argument entre guillemets
	• /messages "user_uid" : lister tous les messages privés échangés entre soi-même et l'utilisateur dont l'identifiant unique est donné entre guillemets
	• /subscribe "team_uid" : permet de recevoir des notifications d'une équipe (création d'un channel, d'une discussion, réponse à une discussion existante...)
	• /subscribed ?[“team_uuid”] : liste toutes les équipes auquelles l'utilisateur courant est abonné, ou tous les utilisateur abonnés à une équipe (dans le cas ou l'identifiant unique de l'équi est donné entre guillemets)
	• /unsubscribe [“team_uuid”] : se désabonner de l'équipe dont l'identifiant unique est donné entre guillemets
	• /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : permet de définir quel équipe, channel et discussion utiliser. Peut s'utiliser sans arguments (permet alors de créer une équipe, lister toutes les équipes, ou obtenir les informations de l'utilisateur courant), ou avec plusieurs arguments (pour créer, lister et obtenir les informations sur l'élément sélectionné)
	• /create : se base sur les données fournies par /use pour créer une équipe, un channel, une discussion ou une réponse
	• /list : se base sur les données fournies par /use pour lister les équipes existantes, les channels existants, les discussions existantes et les réponses existantes
	• /info : se base sur les données fournies par /use pour afficher les informations de l'utilisateur courant, de l'équipe sélectionnée, du channel sélectionné ou de la discussion sélectionnée

##Evenements

> Le serveur envoie également des requêtes au clients lors d'un événement. Les séparateurs <SP> et <sp> sont utilisés comme chaînes de caratères pour séparer les informations. Voici les différentes requêtes pour chaque événement:

	Réception d'un message privé: 800<SP>sender_uid<SP>message
	Création d'une équipe: 801<SP>name<SP>description<SP>uuid_team
	Création d'un channel: 802<SP>name<SP>description<SP>uuid_channel
	Création d'une discussion: 803<SP>name<SP>description<SP>uuid_channel<SP>uuid_thread
	Connexion d'un utilisateur: 810<SP>username<SP>uuid
	Déconnexion d'un utilisateur: 811<SP>username<SP>uuid

## Auteurs

👤 **Achille Bourgault**

* Github: [@achillebourgault](https://github.com/achillebourgault)
* LinkedIn: [@achille-bourgault](https://fr.linkedin.com/in/achille-bourgault-266514177)

👤 **Frédéric Lawecki--Walkowiak**

* Github: [@fredericlw](https://github.com/fredericlw)
* LinkedIn: [@frederic-lawecki-walkowiak](https://www.linkedin.com/in/frederic-lawecki-walkowiak/)
