#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char title[100];
    int duration;
    struct Song *prev, *next;
};

struct Song *first = NULL, *last = NULL, *current = NULL;

void addSong()
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
    newSong->next = newSong->prev = NULL;

    if (first == NULL)
    {
        first = last = current = newSong;
    }//if
    else
    {
        last->next = newSong;
        newSong->prev = last;
        last = newSong;

        if (current == NULL)
        {
            current = newSong;
        }//if
    } // else

    printf("Song added to playlist.\n");
} // add song

void deleteSong()
{
    if (first == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    } // if

    char title[100];
    printf("Enter title of the song to delete: ");
    scanf(" %[^\n]", title);

    struct Song *save = first;
    while (save != NULL)
    {
        if (strcmp(save->title, title) == 0)
        {
            if (save == first)
            {
                first = save->next;
            } // if
            if (save == last)
            {
                last = save->prev;
            } // if
            if (save->prev)
            {
                save->prev->next = save->next;
            } // if
            if (save->next)
            {
                save->next->prev = save->prev;
            } // if

            if (current == save)
            {
                current = save->next ? save->next : save->prev;
            } // if

            free(save);
            printf("Song deleted.\n");
            return;
        } // if
        save = save->next;
    } // while

    printf("Song not found.\n");
} // delete song

void playCurrent()
{
    if (current == NULL)
    {
        printf("No song is currently selected.\n");
        return;
    } // if

    printf("Now Playing: \"%s\" [%d sec]\n", current->title, current->duration);
} // play current

void playNext()
{
    if (current && current->next)
    {
        current = current->next;
        playCurrent();
    } // if
    else
    {
        printf("No next song in the playlist.\n");
    } // else
} // play next

void playPrevious()
{
    if (current && current->prev)
    {
        current = current->prev;
        playCurrent();
    } // if
    else
    {
        printf("No previous song in the playlist.\n");
    } // else
} // play previous

void displayPlaylist()
{
    if (first == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    } // if

    printf("\nPlaylist:\n");
    struct Song *save = first;
    int index = 1;

    while (save != NULL)
    {
        char *label = (save == current) ? "  <-- current" : "";
        printf("%d. \"%s\" [%d sec]%s\n", index++, save->title, save->duration, label);
        save = save->next;
    } // while
} // display

void main()
{
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
            addSong();
            break;
        case 2:
            deleteSong();
            break;
        case 3:
            playCurrent();
            break;
        case 4:
            playNext();
            break;
        case 5:
            playPrevious();
            break;
        case 6:
            displayPlaylist();
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        } // switch case
    } // while
} // main