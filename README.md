<!DOCTYPE html>
<html lang="it">
<head>
 <meta charset="UTF-8">
</head>
<body>
<h1>PROGETTO CATAN:</h1>
<h2>INTRODUZIONE AL GIOCO:</h2>
<p>
Catan è un popolare gioco da tavolo strategico in cui i giocatori assumono il ruolo 
 di coloni che cercano di sviluppare e far prosperare un'isola ricca di risorse. 
L'obiettivo è costruire insediamenti, strade e città, raccogliendo materie prime 
 come legno, mattoni, grano, pietra e lana.
 </p>
<h2>PROGRAMMA UTILIZZATO:</h2>
<p>
Abbiamo usato Visual Studio Community anche perché dovevamo utilizzare la 
libreria grafica SFML (Simple and Fast Multimedia Library). SFML è una libreria in 
C++ che permette di creare facilmente applicazioni con grafica 2D, suoni e 
gestione degli input da tastiera o mouse. È molto usata per sviluppare piccoli 
giochi o programmi multimediali perché è semplice da usare e funziona bene con 
Visual Studio.
</p>
<h2>REGOLE SEMPLIFICATE:</h2>
<p>
Ogni turno, i giocatori tirano due dadi per determinare quali risorse vengono 
prodotte, e poi possono scambiare materiali tra loro o con la banca per costruire e 
avanzare nel gioco. Vince il primo che raggiunge 10 punti vittoria, ottenuti 
costruendo, commerciando e usando carte sviluppo.
</p>
<h2>COMPONENTI DEL GIOCO:</h2>
<ul>
<li>Tessere esagonali: formano l’isola di Catan, ogni tessera produce una risorsa legno, argilla, grano, lana, minerale).</li>
 <li>Numeri da 2 a 12: ogni tessera ha un numero, tranne il deserto.</li>
 <li>Strade, insediamenti, città (in plastica o legno)</li>
 <li>Il ladro: pedina speciale</li>
 </ul>
<h2>TURNO DI GIOCO:</h2>
<p>Ogni turno si divide in 3 fasi:</p>
<ol>
<li>
<strong>Tiro dei dadi (2 dadi)</strong>
<ul>
<li>La somma determina quale tessera produce risorse.</li>
<li>I giocatori che hanno un insediamento su quella tessera ricevono le risorse.</li>
  </ul>
  </li>
  <li>
  <strong>Costruzione</strong>
  <ul>
  <li>Puoi usare le risorse per costruire:</li>
  <ul>
  <li>Strada (1 legno + 1 argilla)</li>
    <li>Insediamento (1 legno + 1 argilla + 1 grano + 1 lana)</li>
    <li>Città (2 grano + 3 minerali, migliora un insediamento)</li>
    <li>Carta sviluppo (1 grano + 1 lana + 1 minerale)</li>
    </ul>
    </ul>
    </li>
    </ol>
<h2>PUNTI VITTORIA:</h2>
<ul>
<li>Insediamento = 1 punto</li>
<li>Città = 2 punti</li>
</ul>
</body>
</html>
