/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    int result = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    result = s1[i] - s2[i];
    return result;
}