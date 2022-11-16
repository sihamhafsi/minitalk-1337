# minitalk
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
# partie obligatoire :
 réaliser un programme de communication sous la forme d’un client et d’un serveur./n
• Le serveur doit être lancé en premier et doit, après le lancement, afficher son PID.
• Le client prend deux paramètres :
  ◦ Le PID du serveur.
  ◦ Une chaîne de caractères à transmettre.
• Le client doit communiquer au serveur la chaîne passée en paramètre.
   Une fois la chaîne entièrement reçue, le serveur doit l’afficher.
• Le serveur doit être capable d’afficher la chaîne rapidement. Par rapidement, on entend que si vous pensez que c’est trop long, alors c’est sûrement trop long.
• Votre serveur doit pouvoir recevoir des chaînes de plusieurs clients à la suite sans nécessiter d’être relancé.
• La communication entre vos programmes doit se faire uniquement à l’aide de signaux UNIX.
• utiliser que les deux signaux suivants : SIGUSR1 et SIGUSR2
# Partie bonus
• Le serveur confirme la réception de chaque message en envoyant un signal au client.
• Le support des caractères Unicode !
