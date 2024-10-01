#include <stdio.h>
#include <string.h>

struct Contact {
    char nom[50];
    char telephone[20];
    char email[50];
};

int main() {
    int choix;
    struct Contact contacts[100];
    int cont=0;
    do {
        printf("\n--- Carnet de Contacts ---\n");
        printf("1. Ajouter un contact\n");
        printf("2. Modifier un contact\n");
        printf("3. Supprimer un contact\n");
        printf("4. Afficher tous les contacts\n");
        printf("5. Rechercher un contact\n");
        printf("6. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:  
                if (cont < 100) {
                    printf("Entrez le nom : ");
                    scanf("%s",contacts[cont].nom);
                    printf("Entrez le numéro de téléphone : ");
                    scanf("%s",contacts[cont].telephone);
                    printf("Entrez l'adresse e-mail : ");
                    scanf("%s",contacts[cont].email);
                    cont++;
                    printf("Contact ajouté avec succès !\n");
                } else {
                    printf("Le carnet de contacts est plein !\n");
                }
                break;

            case 2:
                if (cont == 0) {
                    printf("Aucun contact à modifier.\n");
                } else {
                    printf("Liste des contacts :\n");
                    for (int i = 0; i < cont; i++) {
                        printf("%d. %s (Téléphone: %s, E-mail: %s)\n", i + 1, contacts[i].nom, contacts[i].telephone, contacts[i].email);
                    }

                    int index;
                    printf("Entrez le numéro du contact à modifier: ");
                    scanf("%d", &index);

                    if (index < 1 || index > cont) {
                        printf("Numéro de contact invalide.\n");
                    } else {
                        index--; 
                        printf("Modification du contact %s:\n", contacts[index].nom);
                        printf("Entrez le nouveau numéro de téléphone: ");
                        scanf("%s", contacts[index].telephone);
                        printf("Entrez la nouvelle adresse e-mail: ");
                        scanf("%s", contacts[index].email);
                        printf("Contact modifié avec succès !\n");
                    }
                }
                break;
                
            case 3:
               if (cont == 0) {
                    printf("Aucun contact à supprimer.\n");
                } else {
                    printf("Liste des contacts :\n");
                    for (int i = 0; i < cont; i++) {
                        printf("%d. %s (Téléphone: %s, E-mail: %s)\n", i + 1, contacts[i].nom, contacts[i].telephone, contacts[i].email);
                    }

                    int index;
                    printf("Entrez le numéro du contact à supprimer: ");
                    scanf("%d", &index);

                    if (index < 1 || index > cont) {
                        printf("Numéro de contact invalide.\n");
                    } else {
                        index--;
                        for (int j = index; j < cont - 1; j++) {
                            contacts[j] = contacts[j + 1]; 
                        }
                        cont--;
                        printf("Contact supprimé avec succès !\n");
                    }
                }
                break;

            case 4:
                if (cont == 0) {
                    printf("Aucun contact à afficher.\n");
                } else {
                    for (int i = 0; i < cont; i++) {
                        printf("Contact %d:\n", i + 1);
                        printf("Nom: %s\n", contacts[i].nom);
                        printf("Téléphone: %s\n", contacts[i].telephone);
                        printf("E-mail: %s\n", contacts[i].email);
                        printf("--------------------------\n");
                    }
                }
               
                break;

            case 5:
                {
                char nom[50];
                printf("Entrez le nom du contact à rechercher: ");
                scanf("%s", nom);
                int trouvé = 0;
                for (int i = 0; i < cont; i++) {
                    if (strcmp(contacts[i].nom, nom) == 0) {
                        printf("Nom: %s\n", contacts[i].nom);
                        printf("Téléphone: %s\n", contacts[i].telephone);
                        printf("E-mail: %s\n", contacts[i].email);
                        trouvé = 1;
                        break;
                    }
                }
                if (!trouvé) {
                    printf("Contact non trouvé.\n");
                }
                break;
            }
            case 6:
                printf("Programme terminé.\n");
                break;

            default:
                printf("Option invalide !\n");
                break;
        }

    } while (choix !=6 );

    return 0;
}