#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char title[100];
    int duration;
    struct Song *prev, *next;
};

void addSong(struct Song **first, struct Song **last, struct Song **current)
{
    char title[100];
    int duration;

    printf("Enter Song Title: ");
    scanf(" %[^\n]", title);

    printf("Enter Duration (seconds): ");
    scanf("%d", &duration);

    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));

    strcpy(newSong->title, title);
    newSong->duration = duration;
    newSong->next = NULL;
    newSong->prev = NULL;

    if (*first == NULL)
    {
        *first = *last = *current = newSong;
    }
    else
    {
        (*last)->next = newSong;
        newSong->prev = *last;
        *last = newSong;
    }

    printf("Song added to playlist.\n");
}

void deleteSong(struct Song **first, struct Song **last, struct Song **current)
{
    if (*first == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    char title[100];

    printf("Enter title of the song to delete: ");
    scanf(" %[^\n]", title);

    struct Song *save = *first;

    while (save != NULL)
    {
        if (strcmp(save->title, title) == 0)
        {
            if (save == *first)
                *first = save->next;

            if (save == *last)
                *last = save->prev;

            if (save->prev)
                save->prev->next = save->next;

            if (save->next)
                save->next->prev = save->prev;

            if (*current == save)
                *current = (save->next) ? save->next : save->prev;

            free(save);

            printf("Song deleted.\n");
            return;
        }

        save = save->next;
    }

    printf("Song not found.\n");
}

void playCurrent(struct Song *current)
{
    if (current == NULL)
    {
        printf("No song is currently selected.\n");
        return;
    }

    printf("Now Playing: \"%s\" [%d sec]\n", current->title, current->duration);
}

void playNext(struct Song **current)
{
    if (*current && (*current)->next)
    {
        *current = (*current)->next;
        playCurrent(*current);
    }
    else
    {
        printf("No next song in the playlist.\n");
    }
}

void playPrevious(struct Song **current)
{
    if (*current && (*current)->prev)
    {
        *current = (*current)->prev;
        playCurrent(*current);
    }
    else
    {
        printf("No previous song in the playlist.\n");
    }
}

void displayPlaylist(struct Song *first, struct Song *current)
{
    if (first == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    struct Song *save = first;
    int index = 1;

    printf("\nPlaylist:\n");

    while (save != NULL)
    {
        printf("%d. \"%s\" [%d sec]", index++, save->title, save->duration);

        if (save == current)
            printf(" <-- current");

        printf("\n");

        save = save->next;
    }
}

void main()
{
    struct Song *first = NULL;
    struct Song *last = NULL;
    struct Song *current = NULL;

    int choice;

    while (1)
    {
        printf("\nMusic Player Menu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Current Song\n");
        printf("4. Play Next Song\n");
        printf("5. Play Previous Song\n");
        printf("6. Display Playlist\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSong(&first, &last, &current);
            break;

        case 2:
            deleteSong(&first, &last, &current);
            break;

        case 3:
            playCurrent(current);
            break;

        case 4:
            playNext(&current);
            break;

        case 5:
            playPrevious(&current);
            break;

        case 6:
            displayPlaylist(first, current);
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}