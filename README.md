# Morpion en C

## Description
Ce projet est une implémentation du jeu du **Morpion (Tic-Tac-Toe)** en langage C. Il permet à deux joueurs de s'affronter en plaçant tour à tour leur symbole (**X** ou **O**) sur une grille 3x3. Le premier à aligner trois symboles horizontalement, verticalement ou en diagonale remporte la partie.

## Fonctionnalités
- Initialisation d'une grille vide.
- Affichage de la grille actualisée après chaque tour.
- Validation des entrées utilisateur pour garantir qu'elles sont valides (1-3).
- Vérification des coups joués (case libre et dans la grille).
- Changement de joueur automatique.
- Détection d'une victoire ou d'un match nul.

## Prérequis
- Un compilateur C (GCC, Clang, MinGW, etc.).
- Un terminal pour exécuter le programme.

## Installation et Compilation
1. **Cloner le dépôt** (si applicable) :
   ```sh
   git clone https://github.com/utilisateur/morpion-c.git
   cd morpion-c
   ```

2. **Compiler le programme** avec GCC :
   ```sh
   gcc morpion.c -o morpion
   ```

3. **Exécuter le programme** :
   ```sh
   ./morpion
   ```

## Règles du jeu
1. Le jeu commence avec le joueur **X**.
2. Chaque joueur entre une ligne (1-3) et une colonne (1-3) pour placer son symbole.
3. Si une case est déjà occupée ou si l'entrée est invalide, le joueur doit rejouer.
4. La partie se termine si :
   - Un joueur aligne 3 symboles (→ Victoire).
   - Toutes les cases sont remplies sans vainqueur (→ Match nul).

## Exemple d'affichage
```
Joueur X, entrez la ligne (1-3) : 2
Joueur X, entrez la colonne (1-3) : 2

 X |   |  
---+---+---
   | O |  
---+---+---
   |   |  
```

## Améliorations futures
- Interface graphique en mode console (ncurses).
- Mode contre une IA avec algorithme Minimax.
- Option de rejouer sans relancer le programme.

## Auteur
- **Parfait Fanilohery Evans**

## Licence
Ce projet est sous licence MIT. Vous êtes libre de l'utiliser, le modifier et le partager.