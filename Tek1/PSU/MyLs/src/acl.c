/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** acl
*/

#include "my.h"
#include "my_ls.h"

acl_t* set_acl(struct stat sb)
{
    acl_t* acl = malloc(sizeof(acl_t));

    acl->owner = malloc(sizeof(right_t));
    acl->group = malloc(sizeof(right_t));
    acl->other = malloc(sizeof(right_t));
    if (acl == NULL || acl->owner == NULL || acl->group == NULL || \
        acl->other == NULL)
        exit(EPI_FAILURE);
    acl->type = S_ISDIR(sb.st_mode) ? 'd' : '-';
    acl->owner->r = (sb.st_mode & S_IRUSR) ? true : false;
    acl->owner->w = (sb.st_mode & S_IWUSR) ? true : false;
    acl->owner->x = (sb.st_mode & S_IXUSR) ? true : false;
    acl->group->r = (sb.st_mode & S_IRGRP) ? true : false;
    acl->group->w = (sb.st_mode & S_IWGRP) ? true : false;
    acl->group->x = (sb.st_mode & S_IXGRP) ? true : false;
    acl->other->r = (sb.st_mode & S_IROTH) ? true : false;
    acl->other->w = (sb.st_mode & S_IWOTH) ? true : false;
    acl->other->x = (sb.st_mode & S_IXOTH) ? true : false;
    acl->t = (sb.st_mode & S_ISVTX) ? true : false;
    return (acl);
}

void display_acl(acl_t* acl)
{
    my_printf("%c", acl->type);
    my_printf("%c", acl->owner->r ? 'r' : '-');
    my_printf("%c", acl->owner->w ? 'w' : '-');
    my_printf("%c", acl->owner->x ? 'x' : '-');
    my_printf("%c", acl->group->r ? 'r' : '-');
    my_printf("%c", acl->group->w ? 'w' : '-');
    my_printf("%c", acl->group->x ? 'x' : '-');
    my_printf("%c", acl->other->r ? 'r' : '-');
    my_printf("%c", acl->other->w ? 'w' : '-');
    my_printf("%c", acl->other->x ? 'x' : '-');
    my_printf("%s", acl->t ? "t." : ".");
}
