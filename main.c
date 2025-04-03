#include <stdio.h>

const int SIZE = 3; // Taille de la grille (3x3)
char currentPlayer = ' '; // Joueur en cours ('X' ou 'O')
char board[SIZE][SIZE]; // Grille du jeu

/**************************************************
 *             FONCTIONS DU JEU
 **************************************************/

/**
 * @brief Initialise la grille avec des cases vides.
 */
void initBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' '; // Par défaut, chaque case est vide
        }
    }
}

/**
 * @brief Affiche la grille actuelle du morpion.
 */
void printBoard()
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]); // Affichage du symbole ('X', 'O' ou ' ')
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---+---+---\n"); // Séparation entre les lignes
    }
    printf("\n");
}

/**
 * @brief Vérifie si une case est vide.
 * @param row Ligne de la case.
 * @param col Colonne de la case.
 * @return 1 si la case est vide, sinon 0.
 */
int isCellEmpty(int row, int col)
{
    return board[row][col] == ' ';
}

/**
 * @brief Vérifie si le coup est valide.
 * @param row Ligne du coup (0-2).
 * @param col Colonne du coup (0-2).
 * @return 1 si valide, sinon 0.
 */
int validateMove(int row, int col)
{
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) // Hors des limites
    {
        return 0;
    }
    return isCellEmpty(row, col); // Vérifie si la case est vide
}

/**
 * @brief Vérifie si la grille est pleine (match nul).
 * @return 1 si pleine, sinon 0.
 */
int fullBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (isCellEmpty(i, j))
            {
                return 0; // Il reste des cases vides
            }
        }
    }
    return 1; // Grille complète
}

/**
 * @brief Met à jour une case de la grille.
 * @param row Ligne de la case.
 * @param col Colonne de la case.
 * @param symbol Symbole du joueur ('X' ou 'O').
 * @return 1 si la case a été mise à jour, sinon 0.
 */
int updateCell(int row, int col, char symbol)
{
    if (isCellEmpty(row, col))
    {
        board[row][col] = symbol;
        printf("Case remplacée\n");
        return 1;
    }
    printf("Case non remplacée\n");
    return 0;
}

/**
 * @brief Vérifie si un joueur a gagné la partie.
 * @param symbol Symbole du joueur à vérifier.
 * @return 1 si le joueur a gagné, sinon 0.
 */
int checkWinning(char symbol)
{
    for (int i = 0; i < SIZE; i++)
    {
        // Vérification des lignes et des colonnes
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
        {
            return 1;
        }
    }

    // Vérification des diagonales
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Change le joueur en cours.
 * @param player1 Symbole du premier joueur.
 * @param player2 Symbole du deuxième joueur.
 */
void switchPlayer(char player1, char player2)
{
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

/**
 * @brief Vérifie si l'entrée utilisateur est valide.
 * @return Un nombre entre 1 et 3 correspondant à la ligne ou colonne.
 */
int valideInput()
{
    int nombre;

    if (scanf("%d", &nombre) == 1 && nombre >= 1 && nombre <= 3)
    {
        return nombre;
    }
    else
    {
        printf("Veuillez entrer un nombre valide entre 1 et 3 : ");
        scanf("%*s");        // Ignore l'entrée invalide sans la stocker
        return valideInput(); // Relance la fonction (récursivité)
    }
}

/**************************************************
 *               PROGRAMME PRINCIPAL
 **************************************************/

int main()
{
    int row, col;
    char player1 = 'X', player2 = 'O';

    printf("Bienvenue au Morpion !\n");
    initBoard();
    currentPlayer = player1;

    while (1)
    {
        printBoard();

        // Demande la ligne et la colonne au joueur
        printf("Joueur %c, entrez la ligne (1-3) : ", currentPlayer);
        row = valideInput() - 1; // Convertit l'entrée (1-3) en index (0-2)

        printf("Joueur %c, entrez la colonne (1-3) : ", currentPlayer);
        col = valideInput() - 1; // Convertit l'entrée (1-3) en index (0-2)

        if (validateMove(row, col)) // Vérifie si le coup est valide
        {
            updateCell(row, col, currentPlayer);

            if (checkWinning(currentPlayer)) // Vérifie si le joueur a gagné
            {
                printBoard();
                printf("Le joueur %c a gagné !\n", currentPlayer);
                break;
            }

            if (fullBoard()) // Vérifie si la grille est pleine (match nul)
            {
                printBoard();
                printf("Match nul !\n");
                break;
            }

            switchPlayer(player1, player2); // Change de joueur
        }
        else
        {
            printf("Coup non valide, essayez encore.\n");
        }
    }

    return 0;
}
