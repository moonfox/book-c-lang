#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nlist *NotePtr;
typedef struct nlist
{
  NotePtr next;
  char *name;
  char *defn;
} NList;

#define HASHSIZE 101

static NotePtr hashtab[HASHSIZE];

unsigned hash(char *s);
NotePtr lookup(char *s);
NotePtr install(char *name, char *defn);
void print_list(NotePtr np);

int main(int argc, char const *argv[])
{
  char *keys[] = {
      "name",
      "unsigned",
      "static",
      "defn",
      "defn"};

  char *value[] = {
      "for",
      "apple",
      "fun",
      "main",
      "grape"};

  NotePtr np;

  for (int i = 0; i < 5; i++)
  {
    install(keys[i], value[i]);
  }

  for (int i = 0; i < HASHSIZE; i++)
  {
    if ((np = hashtab[i]) != NULL)
      print_list(np);
  }

  return 0;
}

unsigned hash(char *s)
{
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
  {
    hashval = *s + 31 * hashval;
  }

  return hashval % HASHSIZE;
}

NotePtr lookup(char *s)
{
  NotePtr np;
  unsigned hashval = hash(s);

  printf("the %s is %d \n", s, hashval);

  for (np = hashtab[hashval]; np != NULL; np = np->next)
  {
    if ((strcmp(s, np->name)) == 0)
      return np;
  }

  return NULL;
}

NotePtr install(char *name, char *defn)
{
  NotePtr np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL)
  {
    // np = (NotePtr)malloc(sizeof(*np));
    // 注意：用sizeof(*np)也是可以的，*np代表指针指向的对象
    np = (NotePtr)malloc(sizeof(NList));

    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;

    hashval = hash(name);

    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  }
  else
  {
    // np->defn = NULL; 也可以
    free((void *)np->defn);
  }

  if ((np->defn = strdup(defn)) == NULL)
    return NULL;

  return np;
}

void print_list(NotePtr np)
{
  for (; np != NULL; np = np->next)
  {
    printf("%s:%s\n", np->name, np->defn);
  }
}
