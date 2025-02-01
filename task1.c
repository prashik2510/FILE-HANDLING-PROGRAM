#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char content[100];

    // Create and write to a file
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(file, "Hello, this is the initial content.\n");
    fclose(file);
    printf("File created and data written successfully!\n");

    // Read from the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("File content after writing:\n");
    while (fgets(content, sizeof(content), file)) {
        printf("%s", content);
    }
    fclose(file);

    // Append to the file
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return 1;
    }
    fprintf(file, "This is additional content.\n");
    fclose(file);
    printf("Data appended successfully!\n");

    // Read from the file again
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("File content after appending:\n");
    while (fgets(content, sizeof(content), file)) {
        printf("%s", content);
    }
    fclose(file);

    return 0;
}
