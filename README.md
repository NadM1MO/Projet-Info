# Projet-Info

Question 4 : 
- Pour les pixels de la 1ère ligne, on initialise la distance avec l'énergie horizontale, et le predecesseur à -1 (pas important) 
- La distance d'un pixel est le poids du chemin le plus court terminant à ce pixel c'est a dire la somme des énergies horizontales cumulées des pixels la plus faible sur un chemin terminant à ce pixel que l'on puisse obtenir.

Question 5 : 
- On retrouve le poids du chemin le plus court en cherchant le minimum des distances des pixels de la dernière ligne.
- Cela nous donne le dernier pixel du chemin le plus court, puis pour retrouver ce chemin on utilise les predecesseurs.

Question 7 :
Pour transformer le tableau de taille N * M, une fois connu le chemin le plus court, en un tab de taille N * (M - 1) : 
 - Pour chaque ligne, pour tous les pixels qui sont à droite du pixel qu'on souhaite supprimer (en l'incluant dans cet ensemble de pixels) on affecte comme valeur celle du pixel de droite. On fait donc ça jusqu'à l'avant dernière colonne.
- Une fois fait, la dernière colonne devient inutile, on la supprime en faisant un free.

